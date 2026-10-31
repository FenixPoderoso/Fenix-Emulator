# Validación de Fenix Emulator 0.0.1

Fecha: 31-10-2026, America/Punta_Arenas. Identidad del proyecto: **FenixPoderoso**.

## Ejecutable final

- Plataforma: Windows x64.
- Nombre de archivo distribuido: `fenix.exe`.
- Metadatos de Windows: Fenix Emulator / 0.0.1 / FenixPoderoso.
- SHA-256: `623101CB2AC570FDD59E7BE61AF388F4ABA2589EA626CD5F11F3FF6515501258`.
- Compilación incremental con las herramientas existentes: completada.
- La compilación muestra el aviso heredado de despliegue Qt sobre dxcompiler.dll/dxil.dll; el ejecutable abrió usando Vulkan. No se verificó Direct3D 12.

## Comprobaciones realizadas

| Comprobación | Resultado |
|---|---|
| Inicio de la copia final | Biblioteca abierta con identidad e icono Fenix; no apareció el aviso de perfiles de la primera copia mezclada. |
| Biblioteca y navegación | Acceso a Configuración y Acerca de comprobado. Abrir juego y Añadir carpeta conservan las acciones existentes. |
| Video | Panel visible y legible; Vulkan, RTX 4070 Laptop y resolución 1x reconocidos. No se cambiaron valores. |
| Audio | Panel visible; dispositivos automáticos, estéreo y volumen conservado. No se evaluó acústicamente la salida. |
| Controles | Panel visible; Xbox One Controller 0 reconocido y asignaciones conservadas. No se probó cada botón físico. |
| Nombre y versión | Acerca de muestra Fenix Emulator 0.0.1 y FenixPoderoso. |
| Licencias | Diálogo de atribuciones abierto y comprobado. |
| Regresión HSETP2 | 39.698 comprobaciones aprobadas en dos casos con el ejecutable de pruebas existente. |
| Código preparado | Los archivos Fenix y del parche local se compararon por hash con las fuentes usadas en la compilación. |
| Formato del diff | `git diff --check` sin errores; Git avisa de la normalización habitual LF/CRLF en Windows. |
| Remoto/publicación | Sin remoto configurado en esta copia; sin commit Fenix, etiqueta, push ni publicación. |

## Prueba del usuario y límites

El usuario informó que el juego cargó en la primera compilación Fenix. Esa confirmación corresponde a la primera prueba; no debe presentarse como una sesión completa de juego con el hash final.

En la inspección de controles se observaron textos de botones recortados con el estilo general. Se añadió una regla de espaciado y tipografía específica para el panel de controles, y se recompiló. La captura posterior no pudo completarse: la herramienta de control de ventanas devolvió «foreground window did not report a process id», también tras recuperar la ventana. Esa última revisión visual sigue pendiente. La captura conservada de biblioteca corresponde a la compilación anterior al ajuste de espaciado. Video, audio y Acerca de se inspeccionaron en pantalla; sus capturas separadas no quedaron conservadas correctamente.

El terreno negro de Bananza sigue pendiente. No se ejecutó toda la batería del emulador, una prueba prolongada de estabilidad, una compilación limpia desde la copia de GitHub ni CI. No se ha verificado compatibilidad completa.

## Datos locales y entrega pública

La copia de uso tiene datos portables independientes. La primera prueba produjo un aviso de perfiles al combinar datos de dos inicios; se conservaron los datos de esa prueba y se preparó una carpeta final nueva a partir de la referencia confirmada. No se modificaron las partidas originales para resolverlo.

El paquete público se prepara a partir de una carpeta separada con `user/PORTABLE.txt` únicamente. Las claves, firmware, partidas, configuraciones y registros locales no forman parte de la entrega pública.
