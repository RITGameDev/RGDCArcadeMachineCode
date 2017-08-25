#include <Joystick.h>

// Create the Joystick
Joystick_ Joystick;

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 0;
const int pinToButtonMap2 = 1;

void setup() {
  // Initialize Button Pins
  Serial.begin(9600);
  //pinMode(pinToButtonMap, INPUT_PULLUP);
  //pinMode(pinToButtonMap2, INPUT_PULLUP);
  // Initialize Joystick Library
  Joystick.begin();
}

// Last state of the button
float lastButtonState = 0;
float lastButtonState2 = 0;

void loop() {
  float currentButtonState = analogRead(pinToButtonMap);
  if(currentButtonState>500)
    currentButtonState = 1;
  else
    currentButtonState = 0;
  float currentButtonState2 = analogRead(pinToButtonMap2);
  if(currentButtonState2>500)
    currentButtonState2 = 1;
  else
    currentButtonState2 = 0;
  
  Serial.print(currentButtonState);
  Serial.print(" "); 
  Serial.print(currentButtonState2);
  if (currentButtonState != lastButtonState)
  {
    Joystick.setButton(0, currentButtonState);
    lastButtonState = currentButtonState;
  }
  if (currentButtonState2 != lastButtonState2){
    Joystick.setButton(1, currentButtonState2);
    lastButtonState2 = currentButtonState2;
  }
  Serial.print("\n"); 
  delay(20);
}

