#include "secrets.h"
#include <BlynkSimpleEsp32.h>
#include "nube.h"

// VIRTUAL PINS
BLYNK_WRITE(V0) { if(param.asInt()) procesarComando('B'); }
BLYNK_WRITE(V1) { if(param.asInt()) procesarComando('I'); }
BLYNK_WRITE(V2) { if(param.asInt()) procesarComando('L'); }
BLYNK_WRITE(V3) { if(param.asInt()) procesarComando('R'); }
BLYNK_WRITE(V4) { if(param.asInt()) procesarComando('S'); }

void iniciarConexion() {
    Blynk.begin(auth, ssid, password);
}

void escucha(void *pvParameters) {
    while(true){
        Blynk.run();
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

void procesarComando(char comando) {
    EstadoAnimacion nuevoEstado = estadoActual;

    Serial.print("Comando recibido: ");
    Serial.println((char)comando);

    switch (comando) {
        case 'B':
            nuevoEstado = (estadoActual == REVERSA) ? EFECTO_RGB : REVERSA;
            break;
        case 'I':
            nuevoEstado = (estadoActual == INTERMITENTES) ? EFECTO_RGB : INTERMITENTES;
            break;
        case 'L':
            ledActual = 0;
            nuevoEstado = (estadoActual == IZQUIERDA) ? EFECTO_RGB : IZQUIERDA;
            break;
        case 'R':
            ledActual = NUM_LEDS - 1;
            nuevoEstado = (estadoActual == DERECHA) ? EFECTO_RGB : DERECHA;
            break;
        case 'S':
            nuevoEstado = (estadoActual == ALTO) ? EFECTO_RGB : ALTO;
            break;
        default:
            Serial.println("Comando desconocido");
            break;
    }

    estadoActual = nuevoEstado;
}
