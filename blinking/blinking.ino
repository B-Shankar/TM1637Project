#include <Arduino.h>
#include <TM1637Display.h>

// Define the connections pins
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO); // Create an instance of the TM1637Display


void setup() {
  display.setBrightness(5);  // Set the display brightness (0-7)
};


void loop() {
  ////// Scroll String 
  display.clear();           // Clear the display
  uint8_t data[] = {
      SEG_G,                                  // -
      SEG_G,                                  // -
      SEG_G,                                  // -
      SEG_G,                                  // -
      SEG_A | SEG_B | SEG_C,                  // T
      SEG_A | SEG_F | SEG_G | SEG_E | SEG_D,  // E
      SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,  // S
      SEG_A | SEG_F | SEG_E,                  // T
      SEG_G,                                  // -
      SEG_G,                                  // -
      SEG_G,                                  // -
      SEG_G                                   // -
  };
  for ( int i=0; i<(sizeof(data)-3); i++ ) {
    display.setSegments(data+i); // Display the data
    delay(500);
  };

  ////// Blink String
  for ( int i=0; i<5; i++ ) {
    display.setSegments(data+4); // Display the data
    delay(400);
    display.clear();             // Clear the display
    delay(250);
  };
};
