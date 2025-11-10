# CloudComputingBlinkingLight
CSC452 Project 

Cloud-Controlled LED (ESP32 + Blynk) — with Simple Passcode Lock

Authors: Ernesto Auerbach & Devin Walton
Board: ESP32/ESP32-C6 (tested on Seeed Studio XIAO ESP32-C6)
IDE: Arduino IDE
Cloud: Blynk

This project demonstrates controlling an LED over the internet using the Blynk Cloud. A simple passcode “soft lock” blocks LED control until a valid code is entered in the app.

⸻

Features
	•	Remote LED ON/OFF from the Blynk mobile app
	•	Simple passcode gate: app must be “unlocked” before control is allowed
	•	Auto-relock after a configurable timeout (default 5 minutes)
	•	Status feedback to the app (LOCKED / UNLOCKED / LED state)

⸻

Hardware
	•	ESP32 / ESP32-C6 dev board (e.g., Seeed XIAO ESP32-C6)
	•	1× LED + 220–330 Ω resistor (if not using an onboard LED)
	•	Breadboard + jumper wires
	•	Default LED pin: GPIO16 (changeable via ledPin)

