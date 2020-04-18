#include "usbhub.h"
#include "Wii.h"

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

#include <M5Atom.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
WII Wii(&Btd, PAIR); // This will start an inquiry and then pair with your Wiimote - you only have to do this once
//WII Wii(&Btd); // After that you can simply create the instance like so and then press any button on the Wiimote

bool printAngle;

// Matrix LED set
#define U_allow 1
#define D_allow 2
#define L_allow 3
#define R_allow 4

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
        LEDallow(L_allow);
      }
      if (Wii.getButtonClick(RIGHT)) {
        Wii.setLedOff();
        Wii.setLedOn(LED3);
        Serial.print(F("\r\nRight"));
        LEDallow(R_allow);
    }
      if (Wii.getButtonClick(DOWN)) {
        Wii.setLedOff();
        Wii.setLedOn(LED4);
        Serial.print(F("\r\nDown"));
        LEDallow(D_allow);
      }
      if (Wii.getButtonClick(UP)) {
        Wii.setLedOff();
        Wii.setLedOn(LED2);
        Serial.print(F("\r\nUp"));
        LEDallow(U_allow);
      }

      if (Wii.getButtonClick(PLUS)) {
        Serial.print(F("\r\nPlus"));
        LEDchar('+');
      }
      if (Wii.getButtonClick(MINUS)) {
        Serial.print(F("\r\nMinus"));
        LEDchar('-');
      }

      if (Wii.getButtonClick(ONE)) {
        Serial.print(F("\r\nOne"));
        LEDnum(1);
      }
      if (Wii.getButtonClick(TWO)) {
        Serial.print(F("\r\nTwo"));
        LEDnum(2);
      }

      if (Wii.getButtonClick(A)) {
        printAngle = !printAngle;
        Serial.print(F("\r\nA"));
        LEDchar('A');
     }
      if (Wii.getButtonClick(B)) {
        Wii.setRumbleToggle();
        Serial.print(F("\r\nB"));
        LEDchar('B');
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
      LEDchar('Z');
    }
    if (Wii.getButtonClick(C)) {
      Serial.print(F("\r\nC"));
      LEDchar('C');
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

void LEDallow(int allow){
  M5.dis.clear();

  switch(allow){
    case U_allow:
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(6, 0x707070);
      M5.dis.drawpix(7, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(14, 0x707070);
      M5.dis.drawpix(17, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case D_allow:
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(7, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(14, 0x707070);
      M5.dis.drawpix(16, 0x707070);
      M5.dis.drawpix(17, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case L_allow:
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(6, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(13, 0x707070);
      M5.dis.drawpix(14, 0x707070);
      M5.dis.drawpix(16, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case R_allow:
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(13, 0x707070);
      M5.dis.drawpix(14, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
  }
}

void LEDnum(int led_num){
  M5.dis.clear();

  switch(led_num){
    case 1:
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(6, 0x707070);
      M5.dis.drawpix(7, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(17, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      M5.dis.drawpix(23, 0x707070);
      break;
    case 2:
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(16, 0x707070);
      M5.dis.drawpix(20, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      M5.dis.drawpix(23, 0x707070);
      break;
    case 3:
      M5.dis.drawpix(0, 0x707070);
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(20, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case 4:
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(6, 0x707070);
      M5.dis.drawpix(7, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(15, 0x707070);
      M5.dis.drawpix(16, 0x707070);
      M5.dis.drawpix(17, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case 5:
      M5.dis.drawpix(0, 0x707070);
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(20, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case 6:
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(15, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case 7:
      M5.dis.drawpix(0, 0x707070);
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(3, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(16, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      break;
    case 8:
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(15, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case 9:
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(13, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
    case 0:
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(13, 0x707070);
      M5.dis.drawpix(15, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      break;
  }
}

void LEDchar(char txt){
  M5.dis.clear();

  if(txt == '+'){
      M5.dis.drawpix(7, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(13, 0x707070);
      M5.dis.drawpix(17, 0x707070);
  }else if(txt == '-'){
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(13, 0x707070);
  }else if(txt == 'A'){
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(13, 0x707070);
      M5.dis.drawpix(15, 0x707070);
      M5.dis.drawpix(16, 0x707070);
      M5.dis.drawpix(17, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(20, 0x707070);
      M5.dis.drawpix(23, 0x707070);
  }else if(txt == 'B'){
      M5.dis.drawpix(0, 0x707070);
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(15, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(20, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
  }else if(txt == 'C'){
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(5, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(15, 0x707070);
      M5.dis.drawpix(18, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
  }else if(txt == 'Z'){
      M5.dis.drawpix(0, 0x707070);
      M5.dis.drawpix(1, 0x707070);
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(3, 0x707070);
      M5.dis.drawpix(8, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(15, 0x707070);
      M5.dis.drawpix(20, 0x707070);
      M5.dis.drawpix(21, 0x707070);
      M5.dis.drawpix(22, 0x707070);
      M5.dis.drawpix(23, 0x707070);
  }
}
