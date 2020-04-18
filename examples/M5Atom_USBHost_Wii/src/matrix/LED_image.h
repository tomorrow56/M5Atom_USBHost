#ifndef _LED_IMAGE_H_
#define _LED_IMAGE_H_

class LEDImage
{
private:

public:
  LEDImage();
  ~LEDImage();

  void arrow(int arrow);
  void num(int led_num);
  void txt(char txt);
};

#endif
