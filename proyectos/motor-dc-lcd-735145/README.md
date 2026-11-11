# Motor DC con LCD

Control de motor y visualización en pantalla LCD I2C.

## Tecnologías

C++, GPIO, sensores, actuadores y puerto serie.

## Archivos disponibles

- [motor_dc_lcd.ino](motor_dc_lcd.ino)

## Cómo ejecutarlo

Instala Arduino IDE y el paquete de placas correspondiente. Cada archivo `.ino` representa una variante: colócalo en una carpeta con el mismo nombre y abre solo esa variante. Selecciona placa y puerto; revisa los GPIO y bibliotecas `#include` antes de cargar. No combines todos los sketches en una sola compilación.

Prueba física pendiente; los pines y el cableado dependen del sketch seleccionado.

## Dependencias identificadas en el código

```text
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

## Estado

Fuente académica recuperada.  No se ha comprobado su funcionamiento completo en esta revisión. Las variantes se mantienen separadas para conservar su contenido.
