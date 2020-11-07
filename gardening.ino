int moistureSensor = 0; //one nail goes to voltage pin, the other nail goes to this analogue pin
int moisture_val;
const int voltage = 8;             // the voltage nail is on pin D8
long int dodo = 900000;  // délais entre prise de mesure 900000 15 minutes
int light = 0; // store the current light value

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6 // 
#define BRIGHTNESS 255  // value between 1 and 255
#define NUMPIXELS      22  // How many NeoPixels are attached to the Arduino?
#define BRIGHTNESS2 250  // value between 1 and 255

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 5000; // delay color1 in milliseconds
int delayval2 = 5000; //delay color2 in milliseconds

// Setup runs on boot
void setup() {
Serial.begin(9600); //open serial port
pixels.setBrightness(BRIGHTNESS);
pixels.begin(); // This initializes the NeoPixel library.
pixels.show(); // Initialize all pixels to 'off' 
}

// Loop is the main application loop
void loop() {
digitalWrite(voltage, HIGH);
delay(500);
moisture_val = analogRead(moistureSensor); // read the value from the nails
Serial.print("moisture sensor reads ");
Serial.println( moisture_val ); // print the moisture level to the serial monitor
digitalWrite(voltage, LOW);
light = analogRead(A2); // read and save value from PR
Serial.print("Luminosite ");
Serial.println(light); // print current light value
Serial.print("Sensor is off for ");
Serial.print(dodo);
Serial.println(" millisecondes");
  
for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setBrightness(BRIGHTNESS);
    pixels.setPixelColor(i, pixels.Color(0,255,0)); // Purple light
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    pixels.setBrightness(BRIGHTNESS2);
    pixels.setPixelColor(i, pixels.Color(255,0,255)); // green
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval2); // Delay for a period of time (in milliseconds). 
 
// delay(dodo);this delay is not more mandatory : the read of moisture is make after each loop of the led strip
}
}
