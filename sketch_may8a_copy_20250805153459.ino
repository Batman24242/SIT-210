const int ledPin = LED_BUILTIN;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Blink each letter of "ARPIT" in Morse Code
  blinkA();
  delay(700);
  blinkR();
  delay(700);
  blinkP();
  delay(700);
  blinkI();
  delay(700);
  blinkT();
  delay(3000); // Wait before repeating
}

void blinkA() {
  dot();
  delay(300);
  dash();
}

void blinkR() {
  dot();
  delay(300);
  dash();
  delay(300);
  dot();
}

void blinkP() {
  dot();
  delay(300);
  dash();
  delay(300);
  dash();
  delay(300);
  dot();
}

void blinkI() {
  dot();
  delay(300);
  dot();
}

void blinkT() {
  dash();
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
  delay(200);
}