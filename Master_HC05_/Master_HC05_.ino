#include <TinyGPS++.h>
#include <SoftwareSerial.h>

/////// Config GPS setup /////////
#define GPS_RX_PIN 5   // RX pin
#define GPS_TX_PIN 6   // TX pin
#define GPSBaud    9600// GPS Baud rate
//////////////////////////////////

/////// Config Bluetooth setup ///
#define BT_RX_PIN  2   // RX pin
#define BT_TX_PIN  3   // TX pin
#define BTBaud     9600// BT Baud rate
//////////////////////////////////


SoftwareSerial GPSserial(GPS_RX_PIN, GPS_TX_PIN);
TinyGPSPlus gps;

SoftwareSerial BTserial(BT_RX_PIN, BT_TX_PIN);
int c = 0;
int latk = 0;
int lngk = 0;
void setup() 
{
  Serial.begin(9600);
  BTserial.begin(BTBaud);
  GPSserial.begin(GPSBaud);
}

void loop() {
  
   while(GPSserial.available())
   {
      gps.encode(GPSserial.read());
   }
   if(gps.location.isValid())
   {
      latk = int(gps.location.lat());
      lngk = int(gps.location.lng());
      BTserial.write(182);
      delay(100);
      BTserial.write(latk);
      delay(100);
      BTserial.write(183);
      delay(100);
      BTserial.write(lngk);
      delay(100);
   }
   else
   {
      BTserial.write(184);
      delay(100);
   }
}

