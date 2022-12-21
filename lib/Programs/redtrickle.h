
#pragma once

#include "program.h"


class RedTrickle : public Program {
  CRGBW *leds;

  public:
  RedTrickle(CRGBW *leds) {
    this->leds = leds;
  }
  
  void tick() {

    for (float i=0; i<NUM_LEDS; i++) {
      float m = millis();
      float w1 = sin(i + m/120);
      float w2 = sin(i/2 - m/372) ;

      float w3 = sin(i/5 + m/1709);

      CRGBW color = leds[(int) i];
      CRGB existing = CRGB(color.r, color.g, color.b);

      float value = positive(w1 + w2) * positive(w3) * 100;
      // float value = positive(w1 + w2)  * 100;

      if (value > 0) {
        leds[(int) i] = CHSV(0, 220, value);
      }

    }

  }
};
