param(
    [Parameter(Mandatory=$true)][string]$MingwPrefix,
    [string]$BuildDirectory='build',
    [string]$Destination='dist-packages/Fenix-Emulator-0.0.1-Windows-x64'
)
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$buildRoot=[System.IO.Path]::GetFullPath((Join-Path $root $BuildDirectory))
$outputRoot=[System.IO.Path]::GetFullPath((Join-Path $root $Destination))
if(Test-Path -LiteralPath $outputRoot){throw 'La carpeta de salida ya existe. Utiliza una carpeta nueva.'}
$exe=Join-Path $buildRoot 'bin/eden.exe'
if(-not (Test-Path -LiteralPath $exe)){throw 'Compila primero el objetivo yuzu.'}
$prefix=(Resolve-Path -LiteralPath $MingwPrefix).Path
$env:PATH=(Join-Path $prefix 'bin')+';'+$env:PATH
New-Item -ItemType Directory -Path $outputRoot | Out-Null
Copy-Item -LiteralPath $exe -Destination (Join-Path $outputRoot 'fenix.exe')
& (Join-Path $prefix 'bin/windeployqt6.exe') --release --no-translations --no-system-d3d-compiler --no-opengl-sw --dir $outputRoot (Join-Path $outputRoot 'fenix.exe')
if($LASTEXITCODE -ne 0){throw 'Falló windeployqt6.'}
Set-Content -LiteralPath (Join-Path $outputRoot 'qt.conf') -Value "[Paths]`nPlugins = ." -Encoding ascii
$queue=[System.Collections.Generic.Queue[string]]::new()
$seen=[System.Collections.Generic.HashSet[string]]::new([System.StringComparer]::OrdinalIgnoreCase)
Get-ChildItem -LiteralPath $outputRoot -Recurse -File | Where-Object {$_.Extension -in '.dll','.exe'} | ForEach-Object {$queue.Enqueue($_.FullName)}
while($queue.Count -gt 0){
    $file=$queue.Dequeue()
    if(-not $seen.Add($file)){continue}
    $imports=& (Join-Path $prefix 'bin/objdump.exe') -p $file | Select-String 'DLL Name:\s*(\S+)'
    if($LASTEXITCODE -ne 0){throw "No se pudieron leer imports: $file"}
    foreach($entry in $imports){
        $name=$entry.Matches[0].Groups[1].Value
        $library=Join-Path $prefix "bin/$name"
        if(Test-Path -LiteralPath $library){
            $target=Join-Path $outputRoot $name
            if(-not (Test-Path -LiteralPath $target)){Copy-Item -LiteralPath $library -Destination $target}
            $queue.Enqueue($target)
        }
    }
}
foreach($file in @('LICENSE.txt','NOTICE.md','CHANGELOG.md')){Copy-Item -LiteralPath (Join-Path $root $file) -Destination $outputRoot}
Copy-Item -LiteralPath (Join-Path $root 'LICENSES') -Destination $outputRoot -Recurse
$licenses=Join-Path $outputRoot 'LICENSES/MSYS2-libraries'
New-Item -ItemType Directory -Path $licenses -Force | Out-Null
Get-ChildItem -LiteralPath (Join-Path $prefix 'share/licenses') -Directory | ForEach-Object {Copy-Item -LiteralPath $_.FullName -Destination $licenses -Recurse}
New-Item -ItemType Directory -Path (Join-Path $outputRoot 'user') | Out-Null
Set-Content -LiteralPath (Join-Path $outputRoot 'user/PORTABLE.txt') -Value 'Datos portables locales. La entrega pública no incluye datos de usuario.'
$hash=(Get-FileHash -LiteralPath (Join-Path $outputRoot 'fenix.exe') -Algorithm SHA256).Hash
[ordered]@{product='Fenix Emulator';version='0.0.1';identity='FenixPoderoso';executable_sha256=$hash} | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $outputRoot 'build-info.json') -Encoding utf8
Write-Output "Paquete creado: $outputRoot"
Write-Output "SHA256 fenix.exe: $hash"
