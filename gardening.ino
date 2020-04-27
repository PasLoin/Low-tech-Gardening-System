int moistureSensor = 0; //one nail goes to voltage pin, the other nail goes to this analogue pin
int moisture_val;
const int voltage = 8;             // the voltage nail is on pin D8
long int dodo = 900000;  // délais entre prise de mesure 900000 15 minutes
int light = 0; // store the current light value
// Setup runs on boot
void setup() {
Serial.begin(9600); //open serial port
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
delay(dodo);
}
