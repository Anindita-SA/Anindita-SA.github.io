/*
  Arduino Nano All-Pin Loop-Back Test
  Connect a jumper wire from Pin 2 (Reference) to the target pin 
  when prompted by the Serial Monitor.
*/

const int refPin = 2; // Our "Receiver" pin
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

    // Wait for the user to connect the wire (Logic: Pin 2 goes LOW when connected)
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