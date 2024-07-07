/*
  BlinkRGB

  Demonstrates usage of onboard RGB LED on some ESP dev boards.

  Calling digitalWrite(RGB_BUILTIN, HIGH) will use hidden RGB driver.
    
  RGBLedWrite demonstrates controll of each channel:
  void neopixelWrite(uint8_t pin, uint8_t red_val, uint8_t green_val, uint8_t blue_val)

  WARNING: After using digitalWrite to drive RGB LED it will be impossible to drive the same pin
    with normal HIGH/LOW level
*/
#define RGB_BRIGHTNESS 10 // Change white brightness (max 255)

// the setup function runs once when you press reset or power the board
#ifdef RGB_BUILTIN
#undef RGB_BUILTIN
#endif
#define RGB_BUILTIN 10

void setup() {
  Serial.begin(115200);
  Serial.println("Lightening the LED ...");
}

// the loop function runs over and over again forever
void loop() {
#ifdef RGB_BUILTIN
  Serial.println("White");
  neopixelWrite(RGB_BUILTIN, RGB_BRIGHTNESS, RGB_BRIGHTNESS, RGB_BRIGHTNESS); // White
  delay(1000);
  Serial.println("Red");
  neopixelWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0); // Red
  delay(1000);
  Serial.println("Green");
  neopixelWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0); // Green
  delay(1000);
  Serial.println("Blue");
  neopixelWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS); // Blue
  delay(1000);
  Serial.println("Off");
  neopixelWrite(RGB_BUILTIN, 0, 0, 0); // Off
  delay(1000);
#endif
}