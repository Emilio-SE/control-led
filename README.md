# Act. 3 - Tema 4

### Práctica IoT

En el presente repositorio encontrará todo el código generado para este proyecto. Como base, se tomo el framework de arduino programando en C++.

El proyecto se realizó en 2 partes, primero simulado mediante Wokwi utilizando led WS2812 con un ESP32, después, el código se pasó a código utilizado en un STM32 (Blue Pill).

Observará que hay 5 carpetas:

- **controlador-led-esp32**: contiene el código utilizado para realizar pruebas. Este código sí fue probado y es funcional en la simulación con Wokwi, se realizó utilizando FreeRTOS y Fastled.

- **controlador-led-stm32**: contiene el código convertido de ESP32 a STM32 utilizando las librerias de STM32duino freeRTOS y Fastled. Este código no fue probado bajo simulación (no fue posible simularlo), pero toma de base el código funcional utilizado en el ESP32.

- **controlador peticiones**: contiene el código utilizado para realizar la conexión con la nube y manejar las solicitudes. Se comunica con el STM32 para brindarle los comandos recibidos. 

- **esp32-cloud**: contiene el código para manejar tanto las peticiones como la comunicación con los leds. Simula la comunicación en conjunto.

- **docs**: contiene toda la documentación generada para este diagrama.

El código convertido a stm32 debería ser lo suficientemente funcional, tomando de base el código funcional en esp32.
