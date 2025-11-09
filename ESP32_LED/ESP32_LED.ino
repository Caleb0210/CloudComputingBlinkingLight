// ============================================================
// Author: Ernesto Auerbach & Devin Walton
// Date: 01-Nov-2025
// Description: ESP32 LED Blinker w/ Arduino IDE
// ============================================================

// ===== BLYNK SETTINGS =====
#define BLYNK_TEMPLATE_ID "TMPL2CJLQhsjV"
#define BLYNK_TEMPLATE_NAME "Quickstart Device"
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial

// ===== INCLUDES =====
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ===== WIFI =====
char ssid[] = "";        // Change this
char pass[] = "";    // Change this

// ===== LED PIN =====
int ledPin = 16;

// --- simple soft lock ---
const char* PASSCODE = "1234";   // <-- set passcode here
bool unlocked = false;
unsigned long unlockUntilMs = 0;
const unsigned long UNLOCK_WINDOW_MS = 5UL * 60UL * 1000UL; // 5 minutes

void lockIfExpired() {
  if (unlocked && millis() > unlockUntilMs) {
    unlocked = false;
    Blynk.virtualWrite(V2, "LOCKED");   // optional status label
  }
}

// Passcode entry from Text Input on V3
BLYNK_WRITE(V3) {
  String s = param.asStr();            // read text
  s.trim();
  if (s.equals(PASSCODE)) {
    unlocked = true;
    unlockUntilMs = millis() + UNLOCK_WINDOW_MS;
    Blynk.virtualWrite(V2, "UNLOCKED");
  } else {
    unlocked = false;
    Blynk.virtualWrite(V2, "LOCKED (bad code)");
  }
}

// LED control from Switch on V1 (only when unlocked)
BLYNK_WRITE(V1) {
  lockIfExpired();
  if (!unlocked) {
    // ignore command; optionally flip the switch back off so UI reflects lock
    Blynk.virtualWrite(V1, 0);
    return;
  }
  int ledState = param.asInt();
  digitalWrite(ledPin, ledState ? HIGH : LOW);
  Blynk.virtualWrite(V2, ledState ? "UNLOCKED: LED ON" : "UNLOCKED: LED OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Blynk.virtualWrite(V2, "LOCKED");
}

void loop() {
  Blynk.run();
  lockIfExpired();
}

// ===== END =====
