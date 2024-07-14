/*
  Waveshare ESP32C3 mini
*/
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

#define MAX_BRIGHTNESS 10
const int pinButton = 9;  // the number of the pushbutton pin (the boot button)
const int pinLED = 10;  // the number of the LED pin
long rBrightness = 0;  // red brightness (max 255)
long gBrightness = 0;  // green brightness (max 255)
long bBrightness = 0;  // blue brightness (max 255)
int buttonState = LOW;  // variable for reading the pushbutton status
bool isOn = false;


void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pinButton as an input and enable the internal pull-up resistor
  pinMode(pinButton, INPUT_PULLUP);
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  Serial.println("Starting ESP32 Keyboard ...");
  bleKeyboard.begin();
  while (!bleKeyboard.isConnected()) {
      Serial.print(".");
      delay(1000);
  }
  Serial.println();
  Serial.println("ESP32 Keyboard connected.");
}

long getBrightness() {
  return random(2) > 0 ? MAX_BRIGHTNESS : 0;
}

void loop() {
  if(bleKeyboard.isConnected()) {
    //read the pushbutton value into a variable
    buttonState = !digitalRead(pinButton);
    if (buttonState == HIGH && !isOn) {
      isOn = true;
      bleKeyboard.press(KEY_LEFT_CTRL);
      Serial.println("Ctrl pressed ( LED on ) -->");
      gBrightness = getBrightness();
      rBrightness = getBrightness();
      bBrightness = getBrightness();
      if (gBrightness == 0 && rBrightness == 0) {
        bBrightness = MAX_BRIGHTNESS;
        gBrightness = getBrightness();
      }
      neopixelWrite(pinLED, gBrightness, rBrightness, bBrightness);
    } else if (buttonState == LOW && isOn) {
      isOn = false;
      bleKeyboard.release(KEY_LEFT_CTRL);
      Serial.println("Ctrl released ( LED off )");
      neopixelWrite(pinLED, 0, 0, 0);  // Off
    }
  }
  delay(100);
}
