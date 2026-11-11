# ESP32 · Respuesta de una LDR

Captura 3000 muestras a 1 kHz del ADC GPIO 34 después de cambiar la iluminación de tres a dos LEDs. Exporta CSV por puerto serie a 115200 baudios.

## Hardware

ESP32, LDR con divisor resistivo y cuatro LEDs con resistencias en GPIO 16, 17, 18 y 19. Verifica que la entrada analógica permanezca dentro del rango eléctrico de tu placa.

## Uso

Abre `ldr_step_response/ldr_step_response.ino` en Arduino IDE con soporte ESP32. Selecciona tu placa, carga el programa y abre el monitor serie. Tras ocho segundos comienza la captura. El escalón ocurre a los 500 ms.

Salida: `t_ms,n_leds,y_V`, seguida por `FIN`. La frecuencia depende del tiempo de ejecución del firmware; no es una medición certificada.

Validación física pendiente con el circuito original.
