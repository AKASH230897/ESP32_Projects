int ledPin = 4;     // external LED Pin


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);  // LED ON
  delay(1000);                 //wait 1 sec
  digitalWrite(ledPin, LOW);   // LED OFF
  delay(1000);                 //wait 1 sec
}
