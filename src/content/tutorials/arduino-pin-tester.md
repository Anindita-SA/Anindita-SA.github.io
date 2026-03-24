---
title: "Testing All Analog and Digital Pins on an Arduino"
description: "A simple sketch to verify every digital and analog pin on your Arduino is working correctly, useful before starting any new project."
category: ["Step-by-Step", "Concept"]
tags: ["Arduino", "Embedded", "Debugging"]
date: "2025-03-01"
difficulty: Beginner
duration: "15 min"
---

## Why Test Your Pins?

Before wiring up a complex circuit, it's worth knowing which pins on your Arduino are actually functional. Boards get damaged, pins get burnt out, and a 5-minute pin test can save hours of debugging later.

## What You'll Need

- Arduino Uno (or any Arduino-compatible board)
- Arduino IDE installed
- A Jumper wire (female to male)
- A multimeter (optional but helpful)
- An LED + 220Ω resistor, or just the built-in LED

## Arduino Nano Pinout
![Arduino Nano Pinout](/public/tutorials/arduino-pin-tester/arduino_nano_pinout.png)

## Explanation

The sketch cycles through every digital pin (2–13) and analog pin (A0–A5). The test is done by setting the digital D2(used as a test reference pin) high and connecting all the pins one by one to test their functionality as the code cycles through all the pins. 

By connecting a jumper from the test pin to the pin you want to test, the serial monitor will show if it passes or not. If a pin is functional, the serial monitor will show "RESULT: PASS ✅". If a pin is dead, it will show "RESULT: FAIL ❌".

## The Code

```cpp
/*
  Arduino Nano All-Pin Loop-Back Test
  Connect a jumper wire from Pin 2 (Reference) to the target pin 
  when prompted by the Serial Monitor.
*/

const int refPin = 2; // Our "Receiver" pin, Pin 2 is labeled as Digital Pin (D2)
const int pinsToTest[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};
const int pinCount = sizeof(pinsToTest) / sizeof(pinsToTest[0]);

void setup() {
  Serial.begin(9600);
  pinMode(refPin, INPUT_PULLUP); // Use internal pullup to prevent floating
  
  Serial.println("--- Arduino Nano Pin Integrity Test ---");
  Serial.println("Instructions:");
  Serial.println("1. Keep one end of a jumper wire in Pin D2.");
  Serial.println("2. Move the other end to the pin requested below.");
  Serial.println("---------------------------------------");
  delay(2000);
}

void loop() {
  for (int i = 0; i < pinCount; i++) {
    int currentPin = pinsToTest[i];
    
    Serial.print("Testing Pin: ");
    Serial.print(currentPin < 14 ? "D" : "A");
    Serial.print(currentPin < 14 ? currentPin : currentPin - 14);
    Serial.println("... Connect jumper now.");

    // Wait for the user to connect the wire 
    // (Logic: Pin 2 goes LOW when connected)
    pinMode(currentPin, OUTPUT);
    digitalWrite(currentPin, LOW); 
    
    while (digitalRead(refPin) == HIGH) {
      // Wait for connection
    }

    // Perform High/Low Toggle Test
    bool pass = true;
    
    // Test HIGH
    digitalWrite(currentPin, HIGH);
    delay(50);
    if (digitalRead(refPin) == LOW) pass = false;

    // Test LOW
    digitalWrite(currentPin, LOW);
    delay(50);
    if (digitalRead(refPin) == HIGH) pass = false;

    if (pass) {
      Serial.println(">> RESULT: PASS ✅");
    } else {
      Serial.println(">> RESULT: FAIL ❌");
    }
    
    Serial.println("Disconnecting... move to next pin.");
    pinMode(currentPin, INPUT); // Reset pin
    delay(2000); 
    Serial.println("---------------------------------------");
  }
  
  Serial.println("Testing Cycle Complete. Restarting in 5 seconds...");
  delay(5000);
}
```
<a href="/public/tutorials/arduino-pin-tester/pin_integrity_tester.ino" download>📋Download .ino file</a>

## How the Code Actually Works
This script performs a Loop-Back Test. It essentially asks Pin 2 to "listen" while it tells another pin to "talk," verifying if the message gets through the jumper wire.

1. The Setup (Pin 2 as the Reference)
Pin 2 is set to INPUT_PULLUP. This means it stays "HIGH" (5V) by default using an internal resistor. It acts as the steady reference point for the entire test.

2. The "Handshake" (Waiting for Connection)
The code picks a target pin (e.g., D3) and sets it to OUTPUT and LOW.

Because Pin 2 is High and the target pin is Low, nothing happens until you connect them with a jumper wire.

Once you bridge them, the target pin "pulls" Pin 2 down to LOW. The code sees this change and knows you’ve moved the wire.

3. The Toggle Test (The Verification)
To ensure the pin isn't just "stuck" or shorted, the code performs a quick two-step check:

High Test: It sets the target pin to HIGH. Pin 2 should now read HIGH.

Low Test: It sets the target pin to LOW. Pin 2 should now read LOW.

If Pin 2 perfectly mimics whatever the target pin is doing, the code confirms the pin is healthy and outputs PASS ✅.

## How to Use It

1. Copy the code into the Arduino IDE.
2. Select your board under **Tools → Board**.
3. Select your port under **Tools → Port**.
4. Click **Upload** .
5. Open the **Serial Monitor** (Ctrl+Shift+M) at 9600 baud in the bottom-right corner.
6. Connect the pins one by one according to the testing method you are using. Watch the Serial Monitor. It will prompt you for a specific pin. Once you connect the jumper from D2 to that pin, the test will begin automatically.
    **[eg: Connecting a jumper wire from Reference Pin (D2) to the test pin A0]**
7. You'll see each pin being tested in real time. The monitor will display PASS ✅ if the signal is clean or FAIL ❌ if there's a connection issue or a dead pin.
>[P.S.: If your board isn't accepting the upload you could try changing the bootloader to old bootloader, accessed via **Tools → Processor → Type (Old Bootloader)**]
8. To restart the whole test from Pin 3, simply press the physical RESET button on the Nano.

## Reading the Results

**With Serial Monitor only:** Watch the output, if a pin name appears but you're not getting 5V at that pin with a multimeter, that pin is likely damaged. The serial monitor output will read "RESULT: PASS ✅" or "RESULT: FAIL ❌".


## Notes

- Pin 13 has a built-in LED on most Arduino boards. You'll see it blink during the test without connecting anything.
- Pins 0 and 1 (TX/RX) are excluded to avoid interfering with Serial communication.
- This sketch doesn't test PWM functionality, that's a separate test.
