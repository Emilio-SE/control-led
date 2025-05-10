#pragma once
#include <Arduino.h>
#include "animaciones.h"
#include <WiFi.h>

void iniciarConexion();
void escucha(void *pvParameters); 
void procesarComando(char comando); 
