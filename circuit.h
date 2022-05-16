////////////////////////////////////////////////////////////////////////////////
// CUEcontrol - hardware abstraction                              http://bela.me
////////////////////////////////////////////////////////////////////////////////

#if defined(HW_REV_A1)                   // rev.A1 hw with waveshare rp2040
  #define NEO_PIN    16
#elif defined(HW_REV_A2)                 // rev.A2 hw with seeeduino xiao rp2040
  #define NEO_PIN    12
  #define NEO_PWR    11
  #define RGB_RED    17
  #define RGB_GRN    16
  #define RGB_BLU    25
#endif
