#include "src\usb\usbhub.h"
#include "src\usb\Wii.h"
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

#include <M5Atom.h>
#include "src\matrix\LED_image.h"

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
WII Wii(&Btd, PAIR); // This will start an inquiry and then pair with your Wiimote - you only have to do this once
//WII Wii(&Btd); // After that you can simply create the instance like so and then press any button on the Wiimote

bool printAngle;

LEDImage Matrix;

// Matrix LED set
#define U_arrow 1
#define D_arrow 2
#define L_arrow 3
#define R_arrow 4

void setup() {
/*
 * M5.begin(SerialEnable, I2CEnable, DisplayEnable);
 */
  M5.begin(true, true, true);
  delay(50);
  Serial.println("USB Host test");

  M5.dis.clear();

  #if !defined(__MIPSEL__)
    while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  #endif

  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    for(int i = 0; i < 25; i++){
      M5.dis.drawpix(i, 0x00f000);
    }
    while(1); //halt
  }
  Serial.print(F("\r\nWiimote Bluetooth Library Started"));

  Serial.print(F("Press 1 & 2 on the Wiimote\r\n"));
  for(int i = 0; i < 25; i++){
    M5.dis.drawpix(i, 0x0000f0);
  }
}

int SkipCount = 0;
int SkipCountNun = 0;
int WiiPitch;
int WiiRoll;
int NunchuckPitch;
int NunchuckRoll;
int AnalogHatX;
int AnalogHatY;
boolean WiiRemoteConnected = false;

void loop() {
  Usb.Task();

  if (Wii.wiimoteConnected) {
    if(WiiRemoteConnected == false){
      Serial.print(F("WiiRemoteConnected\r\n"));
      WiiRemoteConnected = true;
      for(int i = 0; i < 25; i++){
        M5.dis.drawpix(i, 0xf00000);
      }
    }
    if (Wii.getButtonClick(HOME)) { // You can use getButtonPress to see if the button is held down
      Serial.print(F("\r\nHOME"));
      Serial.print(F("Wii disconnect\r\n"));
      WiiRemoteConnected = false;
      Wii.disconnect();
    for(int i = 0; i < 25; i++){
      M5.dis.drawpix(i, 0x00f000);
    }
    }
    else {
      if (Wii.getButtonClick(LEFT)) {
        Wii.setLedOff();
        Wii.setLedOn(LED1);
        Serial.print(F("\r\nLeft"));
        Matrix.arrow(L_arrow);
      }
      if (Wii.getButtonClick(RIGHT)) {
        Wii.setLedOff();
        Wii.setLedOn(LED3);
        Serial.print(F("\r\nRight"));
        Matrix.arrow(R_arrow);
    }
      if (Wii.getButtonClick(DOWN)) {
        Wii.setLedOff();
        Wii.setLedOn(LED4);
        Serial.print(F("\r\nDown"));
        Matrix.arrow(D_arrow);
      }
      if (Wii.getButtonClick(UP)) {
        Wii.setLedOff();
        Wii.setLedOn(LED2);
        Serial.print(F("\r\nUp"));
        Matrix.arrow(U_arrow);
      }

      if (Wii.getButtonClick(PLUS)) {
        Serial.print(F("\r\nPlus"));
        Matrix.txt('+');
      }
      if (Wii.getButtonClick(MINUS)) {
        Serial.print(F("\r\nMinus"));
        Matrix.txt('-');
      }

      if (Wii.getButtonClick(ONE)) {
        Serial.print(F("\r\nOne"));
        Matrix.num(1);
      }
      if (Wii.getButtonClick(TWO)) {
        Serial.print(F("\r\nTwo"));
        Matrix.num(2);
      }

      if (Wii.getButtonClick(A)) {
        printAngle = !printAngle;
        Serial.print(F("\r\nA"));
        Matrix.txt('A');
     }
      if (Wii.getButtonClick(B)) {
        Wii.setRumbleToggle();
        Serial.print(F("\r\nB"));
        Matrix.txt('B');
     }
    }
#if 1 // Set this to 1 in order to see the angle of the controllers
    if (printAngle) {
      SkipCount++;
      WiiPitch = Wii.getPitch();
      WiiRoll = Wii.getRoll();

      if (Wii.nunchuckConnected) {
        NunchuckPitch = Wii.getNunchuckPitch();
        NunchuckRoll = Wii.getNunchuckRoll();
      }
      if(SkipCount > 3000){
        M5.dis.clear();
        Serial.print(F("\r\nPitch: "));
        Serial.print(WiiPitch);
        Serial.print(F("\tRoll: "));
        Serial.print(WiiRoll);

        int x_pos = int((WiiRoll - 150) * 5 / (250 - 150));

        if(x_pos > 4){
          x_pos = 4;
        }else if(x_pos < 0){
          x_pos = 0;
        }

        int y_pos = 4 - int((WiiPitch - 150) * 5 / (250 - 150));
        if(y_pos > 4){
          y_pos = 4;
        }else if(y_pos < 0){
          y_pos = 0;
        }

        M5.dis.drawpix(x_pos, y_pos, 0x707070);

        if (Wii.nunchuckConnected) {
          Serial.print(F("\tNunchuck Pitch: "));
          Serial.print(NunchuckPitch);
          Serial.print(F("\tNunchuck Roll: "));
          Serial.print(NunchuckRoll);
        }
        SkipCount = 0;
      }
    }
#endif
  }
#if 1 // Set this to 1 if you are using a Nunchuck controller
  if (Wii.nunchuckConnected) {
    if (Wii.getButtonClick(Z)) {
      Serial.print(F("\r\nZ"));
      Matrix.txt('Z');
    }
    if (Wii.getButtonClick(C)) {
      Serial.print(F("\r\nC"));
      Matrix.txt('C');
    }
    if (Wii.getAnalogHat(HatX) > 137 ||  Wii.getAnalogHat(HatX) < 117 || Wii.getAnalogHat(HatY) > 137 || Wii.getAnalogHat(HatY) < 117) {
      SkipCountNun++;
      AnalogHatX = Wii.getAnalogHat(HatX);
      AnalogHatY = Wii.getAnalogHat(HatY);

      if(SkipCountNun > 5000){
        Serial.print(F("\r\nHatX: "));
        Serial.print(AnalogHatX);
        Serial.print(F("\tHatY: "));
        Serial.print(AnalogHatY);
        SkipCountNun = 0;
      }
    }
  }
#endif
}
