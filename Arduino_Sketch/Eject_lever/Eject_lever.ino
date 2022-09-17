#include <TinyPICO.h>
#include <BleKeyboard.h>

#define DOTSTAR_PWR 13
bool lastState = HIGH;

BleKeyboard bleKeyboard("Eject_lever", "Moragor", 69);      //Define device name, Manufacturer and reported battery level
TinyPICO tp = TinyPICO();     //TinyPico helper library setup

void setup() {
  pinMode(33, INPUT_PULLUP);
  tp.DotStar_SetPower(false);     //Turns off the RGB LED on the TinyPico to save power
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    int buttonState = digitalRead(33);
    if ((buttonState != lastState) && (buttonState == LOW)) {
      bleKeyboard.press(KEY_RIGHT_ALT);
      delay(10);
      bleKeyboard.press('y');
      delay(10);
      bleKeyboard.releaseAll();
      delay(200);
    }
    lastState = buttonState;
  }
}