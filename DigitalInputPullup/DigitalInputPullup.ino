/*
  Waveshare ESP32C3 mini

  Input Pull-up Serial:
  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pinButton and prints the results to the Serial Monitor.
*/
const int pinButton = 9;  // the number of the pushbutton pin (the boot button)
const int pinLED = 10;  // the number of the LED pin
const int rgbBrightness = 8;  // brightness (max 255)
int buttonState = LOW;  // variable for reading the pushbutton status
bool isOn = false;


void setup() {
  //start serial connection
  Serial.begin(9600);
  Serial.println("Please press the boot button ...");
  //configure pinButton as an input and enable the internal pull-up resistor
  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {
  //read the pushbutton value into a variable
  buttonState = !digitalRead(pinButton);
  if (buttonState == HIGH && !isOn) {
    isOn = true;
    Serial.println("LED on");
    neopixelWrite(pinLED, rgbBrightness, 0, rgbBrightness);  // blue-green
  } else if (buttonState == LOW && isOn) {
    isOn = false;
    Serial.println("LED off");
    neopixelWrite(pinLED, 0, 0, 0);  // Off
  }
  delay(100);
}
