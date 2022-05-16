////////////////////////////////////////////////////////////////////////////////
// CUEcontrol - Test routines                                     http://bela.me
////////////////////////////////////////////////////////////////////////////////



//setup routine
void setupTest() {
  ioLeds.begin();
  ioLeds.show();
  ioLeds.setBrightness(16);

  #if defined(NEO_PWR)
    pinMode(NEO_PWR, OUTPUT);
    digitalWrite(NEO_PWR, true);
  #endif
}

//main loop
void loopTest() {
  testIoNeo(20);
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
