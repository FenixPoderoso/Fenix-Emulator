# Compilar Fenix Emulator en Windows

Fenix 0.0.1 usa el sistema CMake/Ninja de la base. El nombre interno del objetivo sigue siendo `yuzu` y el enlace genera `eden.exe`; el empaquetado lo entrega como `fenix.exe`. Esos identificadores internos se conservan para limitar esta versión a cambios de interfaz.

## Entorno utilizado

- Windows x64 y MSYS2 MINGW64.
- GCC 16.2.0, CMake 4.4.5 y Qt 6.12.0 en el entorno local original.
- Ninja, Git, pkg-config, Qt Widgets/Charts/Concurrent/SVG, SDL3, FFmpeg, Boost, OpenSSL y dependencias declaradas por CMake.
- Las dependencias adicionales se resuelven mediante CPM. La primera compilación necesita acceso a sus repositorios.

Consultar también [las dependencias de la base](Deps.md). Las versiones de paquetes de MSYS2 pueden cambiar; no se ha verificado una compilación limpia con otra combinación.

## Compilación

En una terminal MSYS2 MINGW64, desde la raíz del repositorio:

```sh
export SSL_CERT_FILE="$(cygpath -m /etc/pki/ca-trust/extracted/pem/tls-ca-bundle.pem)"
export CURL_CA_BUNDLE="$SSL_CERT_FILE"
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF -DYUZU_TESTS=OFF \
  -DENABLE_WERROR=OFF -DYUZU_ROOM=OFF -DYUZU_CMD=OFF \
  -DENABLE_LIBUSB=OFF -Denet_FORCE_BUNDLED=ON \
  -Dlibusb_FORCE_BUNDLED=ON -DVulkanMemoryAllocator_FORCE_BUNDLED=ON \
  -DUSE_DISCORD_PRESENCE=OFF -DENABLE_WEB_SERVICE=OFF \
  -DYUZU_USE_BUNDLED_QT=OFF -DENABLE_QT_TRANSLATION=ON \
  -DCMAKE_TLS_CAINFO="$SSL_CERT_FILE"
cmake --build build --target yuzu -j 6
```

No desactivar la verificación TLS para resolver un fallo de certificados.

## Distribución portable

Copiar `build/bin/eden.exe` a una carpeta nueva con el nombre `fenix.exe`. Ejecutar `windeployqt6 --release` sobre ese archivo y acompañar las bibliotecas de ejecución de MSYS2 requeridas por los imports del ejecutable. Incluir `qt.conf`, `LICENSE.txt`, `LICENSES/`, los avisos de terceros y el código fuente correspondiente a la versión distribuida. Crear una carpeta vacía `user/` para el modo portable.

No incluir datos personales, claves, firmware, juegos, partidas ni configuraciones de desarrollo en una entrega pública. El ejecutable no funciona aislado de sus DLL y plugins.

## Pruebas del parche previo

La opción local `-DEDEN_BANANZA_SHADER_TESTS=ON` habilita `bananza_shader_tests`. El filtro `[bananza-half]` y la unión `*packed half predicates*,[bananza-half]` validan el parche HSETP2 heredado del trabajo local. En la preparación original se observaron problemas de orden de enlace de este ejecutable; el motor normal sí enlazó. Ver [el historial técnico](FENIX_HISTORY.md).

El script `scripts/package-fenix-windows.ps1` automatiza el empaquetado desde una compilación y un prefijo MINGW64 existentes. Crea una carpeta nueva y no copia datos de usuario. Su sintaxis fue comprobada; esta entrega se empaquetó con las bibliotecas de la compilación local existente. El icono puede regenerarse con `scripts/generate-fenix-icon.ps1`.
