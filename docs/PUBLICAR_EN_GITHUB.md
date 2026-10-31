# Publicar Fenix Emulator

El repositorio es https://github.com/FenixPoderoso/fenix-emulator y tiene visibilidad pública por petición de FenixPoderoso. La versión experimental v0.0.1 está publicada. Tras autenticar Git se integra el árbol completo conservando los commits existentes. Las instrucciones siguientes sirven de referencia para futuras versiones; no recrear ni forzar la etiqueta v0.0.1.

1. Revisar los cambios y los resultados de validación. El usuario debe revisar, entender y probar el código antes de presentarlo como versión pública.
2. Crear el repositorio desde la cuenta de **FenixPoderoso**. Elegir nombre, visibilidad y descripción; esta documentación no presupone una dirección de GitHub concreta.
3. Revisar los archivos que se incluirán. Mantener fuera `user/`, claves, firmware, juegos, partidas, logs personales, cachés, herramientas portátiles y binarios de desarrollo. Conservar código, licencias, atribuciones y documentación.
4. Crear los commits y publicar desde la cuenta del usuario. La base pide que el autor humano escriba los mensajes y divulgue el uso de IA; ver `docs/policies/AI.md`. La interfaz y esta documentación se prepararon con asistencia de Codex.
5. Crear la etiqueta `v0.0.1` únicamente cuando la revisión esté terminada y el ejecutable corresponda exactamente al código publicado.
6. Preparar una Release con notas, paquete Windows x64, SHA-256 y el código fuente correspondiente. Adjuntar todas las licencias requeridas por las bibliotecas distribuidas.

## Notas de versión sugeridas

Fenix Emulator 0.0.1, identidad FenixPoderoso. Primera presentación Fenix: nueva biblioteca, navegación y tema. Conserva el motor de la base y el parche local HSETP2. El terreno negro en Bananza sigue pendiente. La detección automática de respaldos extraídos todavía no está implementada. No declarar compatibilidad completa ni una mejora de rendimiento por este cambio visual.

## Automatizaciones

Los workflows de la base se conservan como referencia fuera de `.github/workflows`. No se ha validado CI ni configurado publicación automática para Fenix. No habilitar una automatización de releases hasta revisar sus permisos, destinos y dependencias.
