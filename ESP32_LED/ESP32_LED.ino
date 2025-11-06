// ============================================================
// Author: Ernesto Auerbach
// Date: 01-Nov-2025
// Description: ESP32 LED Blinker w/ Arduino
// ============================================================

// ===== BLYNK SETTINGS =====
#define BLYNK_TEMPLATE_ID "TMPL2RB9z9Ck0"
#define BLYNK_TEMPLATE_NAME "LED ESP32"
#define BLYNK_AUTH_TOKEN "ZxkBIlIXNYYHpm_EBbGkUt4zKQgGNWDY"
#define BLYNK_PRINT Serial

// ===== INCLUDES =====
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ===== WIFI =====
char ssid[] = "";        // Change this
char pass[] = "";    // Change this

// ===== LED PIN =====
int ledPin = 22;

// ===== SETUP =====
void setup()
{
  Serial.begin(115200);
  delay(100);
  
  Serial.println("\n\nLED Control Starting...");
  
  // Setup LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  Serial.println("Ready!");
}

// ===== LOOP =====
void loop()
{
  if (Blynk.connected())
  {
    Blynk.run();
  }
  delay(10);
}

// ===== LED CONTROL =====
BLYNK_WRITE(V1)
{
  int ledState = param.asInt();
  
  if (ledState == 1)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
  }
}

// ===== END =====
