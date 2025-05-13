#pragma once
#include "animaciones.h"

#define UART_BAUDRATE 115200
#define RX_PIN 16
#define TX_PIN 17

void iniciarUART();
void observadorUART(void *pvParameters); 
void procesarUART(char comando); 
