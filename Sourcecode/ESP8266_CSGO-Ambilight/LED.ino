void InitLED() {
  // Uncomment/edit one of the following lines for your leds arrangement.
  // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);

  FastLED.setBrightness(  BRIGHTNESS );

  for (short i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }

  FastLED.show();

  return;
}

void WiFiLED() {
  for (short i = 0; i <= NUM_LEDS; i++) {
    leds[i].setHue(ColorMover);
  }

  if (ColorMover++ > 256) ColorMover = 0;

  MovingDot( map( ColorMover, 0, 255, 0, NUM_LEDS ) );

  FastLED.show();

  return;
}

void MovingDot(short Position) {
  leds[Position] = CRGB(255, 255, 255);

  return;
}

void FillLED(int r, int g, int b) {
  for (short i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(r, g, b);
  }

  FastLED.show();

  return;
}

void ClearLED() {
  for (short i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }

  FastLED.show();

  return;
}

// ------ All kind of Lightning FX ------ //

void Life(short START, short END) {
  ColorMover = map( Player.health, 100, 0, 96, 0 );
  if (Player.health != 0) {
    for (short i = START; i <= END; i++) {
      leds[i].setHue(ColorMover);
    }
  } else {
    for (short i = START; i <= END; i++) {
      leds[i] = CRGB(0, 0, 0);
    }
  }

  FastLED.show();

  return;
}

void BigLife(short START, short END) {
  ClearLED();
  short New_Max = map( Player.health, 0, 100, END, START );
  ColorMover = map( Player.health, 100, 0, 96, 0 );
  if (Player.health != 0) {
    for (short i = New_Max; i <= END; i++) {
      leds[i].setHue(ColorMover);
    }
  } else {
    for (short i = START; i <= END; i++) {
      leds[i] = CRGB(0, 0, 0);
    }
  }

  FastLED.show();

  return;
}

void Armor(short START, short END) {
  ColorMover = map( Player.armor, 100, 0, 255, 0 );
  if (Player.armor != 0) {
    for (short i = START; i <= END; i++) {
      leds[i] = CHSV(160, 255, ColorMover);
    }
  } else {
    for (short i = START; i <= END; i++) {
      leds[i] = CRGB(0, 0, 0);
    }
  }

  FastLED.show();

  return;
}

void Helmet(short START, short END) {
  if (Player.helmet == "true") {
    for (short i = START; i <= END; i++) {
      leds[i] = CRGB::Blue;
    }
  } else {
    for (short i = START; i <= END; i++) {
      leds[i] = CRGB(0, 0, 0);
    }
  }

  FastLED.show();

  return;
}

void Flashed() {
  int Offset = map( Player.flashed, 255, 0, 255, 128 );
  
  FillLED(Offset, Offset, Offset);

  FastLED.show();

  return;
}
