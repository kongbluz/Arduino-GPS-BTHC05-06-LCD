#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino with HC-06 is ready");
 
    // HC-06 default baud rate is 9600
    BTSerial.begin(9600);  
    Serial.println("BTserial started at 9600");
}
 
void loop()
{
//  if (BTSerial.available())
    Serial.write(BTSerial.read());
//  if (Serial.available())
//    BTSerial.write(Serial.read());
}
