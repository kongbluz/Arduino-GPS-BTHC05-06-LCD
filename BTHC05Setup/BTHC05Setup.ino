#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3);
char c = ' ';
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Arduino with HC-05 is ready");

  BTserial.begin(38400);
  Serial.println("BTserial started at 38400");
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
}

void loop() 
{
     // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {  
        c = BTserial.read();
        Serial.write(c);
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();
        Serial.write(c);   
        BTserial.write(c);  
    }
}
