#include "animaciones.h"
#include "nube.h"
#include <Arduino.h>

void setup() {
    Serial.begin(115200);

    iniciarConexion();

    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear();
    FastLED.show();

    xTaskCreate(manejarAnimaciones, "Animaciones", 4096, NULL, 1, NULL);
    xTaskCreate(escucha, "observadorNube", 2048, NULL, 1, NULL);
}

void loop() {
     vTaskDelay(portMAX_DELAY);
}