/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

String getTime() {
  unsigned long tmpTime = millis() / 1000;
  String m = String(tmpTime / 60);
  if (m.length() == 1) {
    m = '0' + m;
  }
  String s = String(tmpTime % 60);
  if (s.length() == 1) {
    s = '0' + s;
  }
  return '[' + m + ':' + s + ']';
}

void loop() {
  if(bleKeyboard.isConnected()) {
    // Below is an example of pressing a keyboard modifier ( ctrl )
    Serial.print(getTime());
    Serial.println(" ~ Sending Ctrl ...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    delay(10 * 1000); // hold it for 10s
    bleKeyboard.releaseAll();
    Serial.println("Release Ctrl");
  }

  Serial.println("Waiting 0.3 second(s)...");
  delay(0.3 * 1000);
}
