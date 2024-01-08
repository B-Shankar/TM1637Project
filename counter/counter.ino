// Include the libraries
#include <TM1637Display.h>

// Define the connections pins
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO); // Create an instance of the TM1637Display


void setup() {
  display.setBrightness(5);  // Set the display brightness (0-7)
};


void loop() {
  display.clear();           // Clear the display
  
  for (int i=0; i <= 9999; i++){
     display.showNumberDec(i, true);  // i=value, true to padd the blank segments with 0
     delay(100);
  };
    
  delay(1000);
};
