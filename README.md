# Fenix Emulator

**0.0.1 · FenixPoderoso · Windows x64 · Experimental**

Una interfaz propia para tu biblioteca de juegos, con diseño oscuro y acentos ámbar y turquesa. Conserva el motor y los ajustes de video, audio y controles de la base.

![Biblioteca de Fenix Emulator](fenix-library.png)

## Descargas y código fuente

En [Releases](https://github.com/FenixPoderoso/fenix-emulator/releases) están:

- **Fenix-Emulator-0.0.1-Windows-x64.zip**: programa portable completo, DLL, plugins y licencias.
- **Fenix-Emulator-0.0.1-source.zip**: código fuente completo correspondiente, documentación y scripts de compilación y empaquetado.
- **SHA256SUMS.txt**: hashes de ambos ZIP.

El código completo se proporciona como archivo adjunto de la versión. Estos archivos de la portada contienen la documentación consultable; no representan por sí solos todo el árbol del motor.

## Uso

Extrae el paquete Windows completo y abre `fenix.exe`. Usa **Abrir juego** o las opciones de carga de archivo/carpeta. En **Configuración** se conservan las secciones de video, audio y controles.

La entrega no contiene claves, firmware, juegos ni partidas. Los datos de cada instalación portable se guardan en su carpeta `user/`.

## Estado comprobado y pendientes

Compilación Windows x64 completada. Regresión HSETP2: **39.698 comprobaciones aprobadas en dos casos**. Biblioteca, paneles, detección del mando, versión y créditos revisados. El usuario confirmó la carga del juego en la primera prueba.

El terreno negro de Bananza sigue pendiente. También queda la revisión visual del último ajuste de espaciado de botones y una prueba prolongada del ejecutable final. No se declara compatibilidad completa ni una mejora de rendimiento por el cambio de interfaz.

La detección automática del `main` de respaldos extraídos todavía no está implementada. Añadir carpeta mantiene el comportamiento de la base.

## Documentación

- [Compilar y empaquetar](FENIX_BUILD.md)
- [Avances y procedencia](FENIX_HISTORY.md)
- [Historial de cambios](CHANGELOG.md)
- [Comprobaciones y límites](VALIDATION.md)
- [Licencias y atribuciones](NOTICE.md)

## Proyecto y licencia

Identidad del proyecto: **FenixPoderoso**. Fenix Emulator deriva de Eden-NS2, Eden y yuzu. Se conservan los copyrights, las licencias y la procedencia del motor. Consulta [LICENSE.txt](LICENSE.txt), [NOTICE.md](NOTICE.md) y los avisos SPDX del código.

Los cambios Fenix se ofrecen bajo GPL-3.0-or-later. Se utilizó Codex para preparar interfaz y documentación. Proyecto independiente sin afiliación con Nintendo ni con los proyectos originales.
