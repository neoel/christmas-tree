
#pragma once

#include "program.h"
#include "RGBW.h"

float positive(float value) {
	return value > 0 ? value : 0;
}


class Trickle : public Program {
  CRGBW *leds;

  public:
  Trickle(CRGBW *leds) {
    this->leds = leds;
  }
  
  void tick() {

    for (float i=0; i<NUM_LEDS; i++) {
      float m = millis();
      float w1 = sin(i + m/100);
      float w2 = sin(i/20 - m/600) ;

      float w3 = sin(i/5 + m/350);

      leds[(int) i].white = positive(w1 + w2) * positive(w3) * 10;
    }

  }
};
