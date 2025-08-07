
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT); //GPIO as output

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH); // LED ON
  delay(5000); //wait 1 sec
  digitalWrite(2,LOW); // LED OFF
  delay(5000);//wait 1 sec

}
