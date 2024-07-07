// ABrobot ESP32C3 mini
const int buttonPin = 9;  // the number of the pushbutton pin (the boot button)
const int ledPin = 8;  // the number of the LED pin
const int rgbBrightness = 10;  // brightness (max 255)

int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  Serial.println("Please press the boot button ...");
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value
  buttonState = !digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    Serial.println("LED on");    
    neopixelWrite(ledPin, 0, rgbBrightness, rgbBrightness);  // blue-green
  } else {
    // turn LED off
    Serial.println("LED off");
    neopixelWrite(ledPin, 0, 0, 0);  // Off
  }
  delay(1 * 1000);
}
