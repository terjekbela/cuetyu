////////////////////////////////////////////////////////////////////////////////
// CUEcontrol - Test routines                                     http://bela.me
////////////////////////////////////////////////////////////////////////////////



//setup routine
void setupTest() {
  Keyboard.begin();

  ioLeds.begin();
  ioLeds.show();
  ioLeds.setBrightness(16);

  #if defined(RGB_RED)
    pinMode(RGB_RED, OUTPUT);
  #endif
  #if defined(RGB_GRN)
    pinMode(RGB_GRN, OUTPUT);
  #endif
  #if defined(RGB_BLU)
    pinMode(RGB_BLU, OUTPUT);
  #endif
  #if defined(NEO_PWR)
    pinMode(NEO_PWR, OUTPUT);
    digitalWrite(NEO_PWR, true);
  #endif
}

//main loop
void loopTest() {
  //testIoRGB(500);
  //testIoNeo(20);
  testKeySend(5000);
}

void testIoNeo(int wait) {
  for(long firstHue = 0; firstHue < 5*65536; firstHue += 256) {
    for(int i=0; i<ioLeds.numPixels(); i++) {
      int pixelHue = firstHue + (i * 65536L / ioLeds.numPixels());
      ioLeds.setPixelColor(i, ioLeds.gamma32(ioLeds.ColorHSV(pixelHue)));
    }
    ioLeds.show();
    delay(wait);
  }
}

#if defined(RGB_RED)
void testIoRGB(int wait) {
  analogWrite(RGB_RED, 32); delay(wait); digitalWrite(RGB_RED, true);
  analogWrite(RGB_GRN, 64); delay(wait); digitalWrite(RGB_GRN, true);
  analogWrite(RGB_BLU, 32); delay(wait); digitalWrite(RGB_BLU, true);
}
#endif

void testKeySend(int wait) {
  Keyboard.press('a');
  delay(100);
  Keyboard.releaseAll();
  delay(wait);
}
