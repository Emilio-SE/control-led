#pragma once
#include <Arduino.h>
#include "animaciones.h"

#define UART_BAUDRATE 115200

void iniciarUART();
void observadorUART(void *pvParameters); 
void procesarUART(char comando); 
