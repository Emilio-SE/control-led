#pragma once
#include <Arduino.h>
#include <FastLED.h>
#include <FreeRTOS.h>
#include <task.h> 

#define NUM_LEDS 40
#define DATA_PIN PA1
#define BRIGHTNESS 240

extern CRGB leds[NUM_LEDS];

// Enumeración de estados
enum EstadoAnimacion {
    EFECTO_RGB,
    REVERSA,
    INTERMITENTES,
    IZQUIERDA,
    DERECHA,
    ALTO,
    NINGUNO
};

extern volatile EstadoAnimacion estadoActual;
extern volatile int ledActual;

// Declaración de funciones de efectos
void efectoArcoiris ();
void parpadeo(CRGB Color);
void rangoParpadeo(CRGB Color, bool cambio);
void izquierda();
void derecha();
void alto();
void manejarAnimaciones(void *pvParameters);