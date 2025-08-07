#define ledPin 4
#define buttonPin 5

bool lastButtonState= LOW;
bool ledState= false;

void blinkfeedback(int times, int delaytime )
{
  for(int i=0;i<times;i++)
  {
    digitalWrite(ledPin,HIGH);
    delay(delaytime);
    digitalWrite(ledPin,LOW);
    delay(delaytime);
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(115200);

}

void loop()
{
  // put your main code here, to run repeatedly:
  boolean btnState = digitalRead( buttonPin );
  if(btnState==HIGH && lastButtonState==LOW)
  {
    ledState=!ledState;
    if(ledState)
    {
      blinkfeedback(2,100);
      Serial.println("button pressed : LED turned ON");
    }
    else{
      blinkfeedback(1,300);
      Serial.println("button pressed: LED turned OFF");
    }
    delay(300);
  }
    lastButtonState=btnState;
    
  }


