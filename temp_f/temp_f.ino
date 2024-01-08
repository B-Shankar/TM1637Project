
#include <DHT.h>
#include <TM1637Display.h>

// Define the connections pins
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO); // Create an instance of the TM1637Display

// Create the °C Symbol
const uint8_t Celsius[] = {
  // SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_G | SEG_E | SEG_F   // C
};

// Uncomment the type of sensor you are using
//#define DHTTYPE DHT11         // DHT 11 
#define DHTTYPE DHT22          // DHT 22
#define DHTPIN 5

DHT dht = DHT(DHTPIN , DHTTYPE); // Create an DHT object


void setup() {
  display.setBrightness(5);  // Set the display brightness (0-7)
  dht.begin(); // Setup the DHT sensor
};


void loop() {
  display.clear();           // Clear the display
  
  // Read the temperature as Celsius from the sensor
  int temp = dht.readTemperature();
  int temp_f =(temp*9/5)+32;

  // Display the temperature in Celsius
  display.showNumberDec(temp_f, false, 2, 0);
  display.setSegments(Celsius, 2, 2);
  
  delay(1000);
};
