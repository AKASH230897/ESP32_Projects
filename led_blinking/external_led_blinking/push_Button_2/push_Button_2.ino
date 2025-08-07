#define ledPin 4
#define buttonPin 5

bool ledState= 0; // stores LED ON/OFF state


void setup() {
  pinMode( ledPin, OUTPUT );
  pinMode( buttonPin, INPUT );
}

void loop() 
{
  boolean btnState = digitalRead( buttonPin );
   if ( btnState==HIGH )
   {
    ledState=!ledState; //toggle led state
    digitalWrite(ledPin,ledState);
    delay(300); // delay to avoid multiple toggles
    }
}