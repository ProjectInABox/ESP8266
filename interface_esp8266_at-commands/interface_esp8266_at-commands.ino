// Basic serial communication with ESP8266
// Uses serial monitor for communication with ESP8266
//
//  Pins
//  Arduino pin 2 (RX) to ESP8266 TX
//  Arduino pin 3 to voltage divider then to ESP8266 RX
//  Connect GND from the Arduiono to GND on the ESP8266
//  Pull ESP8266 CH_PD HIGH
//
// When a command is entered in to the serial monitor on the computer 
// the Arduino will relay it to the ESP8266
//
 
#include <SoftwareSerial.h>
SoftwareSerial ESPserial(3, 2); // RX | TX
 
void setup() 
{
//    Serial.begin(9600);     // communication with the host computer
    //while (!Serial)   { ; }
 
    // Start the software serial for communication with the ESP8266
//    ESPserial.begin(115200);
//    delay(1000);
//    Serial.println("Changing baud rate");
//    ESPserial.println("AT+IPR=9600");
//    delay(1000);
//    ESPserial.begin(9600);
//    delay(2000);

    Serial.begin(9600);
  delay(500);
  ESPserial.begin(115200);
  delay(1000);
  Serial.println("Changing baud rate");
  ESPserial.println("AT+IPR=9600");
  delay(1000);
  ESPserial.begin(9600);
  delay(2000);
 
    Serial.println("");
    Serial.println("Remember to set Both NL & CR in the serial monitor.");
    Serial.println("Ready");
    Serial.println("");
}
 
void loop() 
{
    // listen for communication from the ESP8266 and then write it to the serial monitor
    if ( ESPserial.available() )   {  Serial.write( ESPserial.read() );  }
 
    // listen for user input and send it to the ESP8266
    if ( Serial.available() )       {  ESPserial.write( Serial.read() );  }
}
