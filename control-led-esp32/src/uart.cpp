#include "uart.h"

void iniciarUART() {
    Serial2.begin(UART_BAUDRATE, SERIAL_8N1, RX_PIN, TX_PIN);
}

void observadorUART(void *pvParameters) {

    while(true){
        if (Serial2.available()) {
            char comando = Serial2.read();
            procesarUART(comando);
        }

        if (Serial.available()) {
            char comando = Serial.read();
            procesarUART(comando);
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }
    
}

void procesarUART(char comando) {
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
