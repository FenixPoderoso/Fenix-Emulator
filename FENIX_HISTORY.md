# Historial técnico

## Base y procedencia

Proyecto mantenido bajo la identidad **FenixPoderoso**. Fenix Emulator 0.0.1 es una modificación de [Eden-NS2](https://github.com/0x2593/Eden-NS2), commit `e2d416602f0c2a72e3af2b6c81b40b56e6f752bd`. Se conserva la historia del repositorio y los avisos de sus autores; el cambio de marca no atribuye a Fenix la autoría del motor original.

## Avance anterior: HSETP2

Antes del diseño Fenix, Bananza rechazaba shaders compute con opcode nativo `0x234`. Se añadió su traducción a HSETP2 Maxwell, se incrementó la identidad de caché del traductor y se añadió una prueba de igualdad ordenada binary16.

Resultados históricos: 652 comprobaciones específicas y 39.698 comprobaciones de regresión en dos casos. El usuario confirmó que el escenario apareció y estimó una mejora visual aproximada del 30 %. Es una valoración subjetiva, no una medición de velocidad ni de compatibilidad.

## Defecto pendiente observado

El 31 de octubre de 2026 se observó terreno negro en una mina, frente a un arco rojo INGOT ISLE. Personajes y otros objetos conservaban materiales visibles. El registro de esa escena no mostraba rechazos de shaders, opcodes no admitidos ni QMD omitidos. No se ha demostrado la causa del terreno negro.

## Fenix 0.0.1: alcance de interfaz

- Identidad, icono, versión y metadatos de Windows propios.
- Cabecera y navegación lateral para la biblioteca.
- Tema oscuro con acentos ámbar y turquesa.
- Presentación de la configuración conservando sus controles y valores.
- Créditos y licencias accesibles en un diálogo separado.

El cambio visual no modifica CPU, GPU, audio, servicios emulados, formatos de juego ni la semántica del parche HSETP2. Los identificadores técnicos internos permanecen por compatibilidad.

## Petición futura

Detectar automáticamente juegos extraídos y elegir el `main` correspondiente desde la biblioteca, con nombre e icono cuando existan. Debe distinguir juego base y actualizaciones. Esta función queda pendiente; añadir una carpeta en la interfaz actual utiliza el comportamiento ya existente.

## Registro de validación

La evidencia final de compilación y revisión visual se añade al preparar la entrega. No confundir la existencia del código con una comprobación de compatibilidad completa.

La compilación y las comprobaciones se registran en [VALIDATION.md](VALIDATION.md). Incluye el hash final y la revisión visual pendiente del ajuste de botones.
