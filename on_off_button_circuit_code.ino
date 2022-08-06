// Define the pins being used
int pin_LEDgreen = 10;
int pin_LEDyellow = 9;
int pin_LEDred = 8;
int pin_switch = 2;
// variables to hold the new and old switch states
boolean oldSwitchState = LOW;
boolean newSwitchState = LOW;
byte state = 0;



void setup()
{

  pinMode(pin_LEDgreen, OUTPUT);    digitalWrite(pin_LEDgreen, LOW);
  pinMode(pin_LEDyellow, OUTPUT);   digitalWrite(pin_LEDyellow, LOW);
  pinMode(pin_LEDred, OUTPUT);      digitalWrite(pin_LEDred, LOW);
  pinMode(pin_switch, INPUT);
}
void loop()
{
  newSwitchState = digitalRead(pin_switch);
  if ( newSwitchState != oldSwitchState )

    
  {
    // has the button switch been closed?
    if ( newSwitchState == HIGH )
    {
      // increase the value of state
      state++;
      if (state > 3) {
        state = 0;
      }
      // turn all LEDs off. Doing it this way means we do not need to care about the individual LEDs
      // simply turn them all off and then turn on the correct one.
      digitalWrite(pin_LEDgreen, LOW);
      digitalWrite(pin_LEDyellow, LOW);
      digitalWrite(pin_LEDred, LOW);
      // Turn on the next LED
      // Because the value of state does not change while we are testing it we don't need to use else if
      if (state == 1) {
        digitalWrite(pin_LEDgreen, HIGH);
      }
      if (state == 2) {
        digitalWrite(pin_LEDyellow, HIGH);
      }
      if (state == 3) {
        digitalWrite(pin_LEDred, HIGH);
      }
    }
    oldSwitchState = newSwitchState;
  }
}
