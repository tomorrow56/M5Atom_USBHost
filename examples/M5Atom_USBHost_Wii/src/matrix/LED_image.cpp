#include <M5Atom.h>
#include "LED_image.h"

LEDImage::LEDImage(){

}

LEDImage::~LEDImage(){

}

void LEDImage::arrow(int arrow){
  M5.dis.clear();

  switch(arrow){
    case 1:
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
    case 2:
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
    case 3:
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
    case 4:
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

void LEDImage::num(int led_num){
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

void LEDImage::txt(char txt){
  M5.dis.clear();

  if(txt == '+'){
      M5.dis.drawpix(2, 0x707070);
      M5.dis.drawpix(7, 0x707070);
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(13, 0x707070);
      M5.dis.drawpix(14, 0x707070);
      M5.dis.drawpix(17, 0x707070);
      M5.dis.drawpix(22, 0x707070);
  }else if(txt == '-'){
      M5.dis.drawpix(10, 0x707070);
      M5.dis.drawpix(11, 0x707070);
      M5.dis.drawpix(12, 0x707070);
      M5.dis.drawpix(13, 0x707070);
      M5.dis.drawpix(14, 0x707070);
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
