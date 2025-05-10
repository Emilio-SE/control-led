#include "secrets.h"
#include "uart.h"
#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

void enviarComando(char comando);

// VIRTUAL PINS
BLYNK_WRITE(V0) { if(param.asInt()) enviarComando('B'); }
BLYNK_WRITE(V1) { if(param.asInt()) enviarComando('I'); }
BLYNK_WRITE(V2) { if(param.asInt()) enviarComando('L'); }
BLYNK_WRITE(V3) { if(param.asInt()) enviarComando('R'); }
BLYNK_WRITE(V4) { if(param.asInt()) enviarComando('S'); }

void enviarComando(char comando) {
  Serial.println(comando);
  Serial1.write(comando);
}

void setup() {
  Serial.begin(UART_BAUDRATE);
  Serial1.begin(UART_BAUDRATE, SERIAL_8N1, TX_PIN, RX_PIN);
  Blynk.begin(auth, ssid, password);
}

void loop() {
  Blynk.run();
  delay(50);
}
