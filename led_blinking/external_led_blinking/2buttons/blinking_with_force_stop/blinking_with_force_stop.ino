#define ledPin 4
#define Toggle_button 5
#define stop_button 18

bool isBlinking = false;
bool lastToggleState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(Toggle_button, INPUT);
  pinMode(stop_button, INPUT);
  Serial.begin(115200);
}

void loop() {
  bool toggleState = digitalRead(Toggle_button);
  bool stopState = digitalRead(stop_button);

  // Detect button press (rising edge)
  if (toggleState == HIGH && lastToggleState == LOW) {
    isBlinking = !isBlinking;  // Toggle blinking
    Serial.println(isBlinking ? "Blinking ON" : "Blinking OFF");
    delay(50); // debounce delay
  }
  lastToggleState = toggleState;

  // Stop button pressed
  if (stopState == HIGH) {
    isBlinking = false;
    Serial.println("Blinking STOPPED");
    delay(50); // debounce delay
  }

  // Blinking logic
  if (isBlinking) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}
