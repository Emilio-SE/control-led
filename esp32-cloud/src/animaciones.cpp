#include "animaciones.h"

CRGB leds[NUM_LEDS];
volatile int ledActual = 0;
volatile EstadoAnimacion estadoActual = EFECTO_RGB;
static bool cambio = false;
static int tiempoDeCambio = 450;

void efectoArcoiris() {
    static uint8_t hue = 0;
    for (ledActual = 0; ledActual < NUM_LEDS; ledActual++) {
        leds[ledActual] = CHSV(hue + (ledActual * 10), 255, BRIGHTNESS);
    }
    FastLED.show();
    hue += 3;
}

// Inversa - Intermitentes
void parpadeo(CRGB color) {
    rangoParpadeo(color, cambio);
    cambio = !cambio;
    vTaskDelay(pdMS_TO_TICKS(tiempoDeCambio));
}

void rangoParpadeo(CRGB color, boolean mostrarColor) {
    FastLED.clear();

    for (ledActual = 0; ledActual < 15; ledActual++){
        leds[ledActual] = leds[NUM_LEDS - 1 - ledActual] = mostrarColor ? color : CRGB::Black;
    } 

    FastLED.show();
}


void derecha() {
    FastLED.clear();

    ledActual = (ledActual < 0) ? NUM_LEDS - 2 : ledActual - 1;

    if(ledActual >= 0) {
        leds[ledActual + 1] = CRGB::Red;      
        leds[ledActual] = CRGB::Red;  
    }

    FastLED.show();
    vTaskDelay(pdMS_TO_TICKS(50));

}

void izquierda() {
    FastLED.clear();

    ledActual = (ledActual == NUM_LEDS) ? 1 : ledActual + 1; 

    if(ledActual <= NUM_LEDS - 1) {
        leds[ledActual - 1] = CRGB::Red;      
        leds[ledActual] = CRGB::Red;  
    }

    FastLED.show();
    vTaskDelay(pdMS_TO_TICKS(50));
}

void alto() {
    rangoParpadeo(CRGB::Red, true);
    vTaskDelay(pdMS_TO_TICKS(tiempoDeCambio));
}

void manejarAnimaciones(void *pvParameters) {
    while (1) {
        switch (estadoActual) {
            case EFECTO_RGB:
                efectoArcoiris();
                break;

            case REVERSA:
                parpadeo(CRGB::White);
                break;

            case INTERMITENTES:
                parpadeo(CRGB::Orange);
                break;

            case IZQUIERDA:
                izquierda();
                break;

            case DERECHA:
                derecha();
                break;

            case ALTO:
                alto();
                break;

            default:
                estadoActual = EFECTO_RGB;
                break;
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}