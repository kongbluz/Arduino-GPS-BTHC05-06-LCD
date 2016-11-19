#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>


/////////  LCD Pin Setup /////////////
#define LCD_ADDRS 0x27
#define LCD_SDA   20
#define LCD_SCL   4
///////////////////////////////////////

/////////  Bluetooth Pin Setup ////////
#define BT_RX_PIN  2  // RX pin
#define BT_TX_PIN  3  // TX pin
#define BTBaud     9600// BT Baud rate
///////////////////////////////////////
bool BTtimeout();
/*
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

const int buzzerPin = 8;
int buzzerState = LOW;
SoftwareSerial BTserial(BT_RX_PIN, BT_TX_PIN);     
LiquidCrystal_I2C lcd(LCD_ADDRS, LCD_SDA, LCD_SCL);

int BTlat = 0;
int BTlng = 0;
int check = 404;
int   i = 0;
int   timeout = 0;
long  previousmillis = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  
  BTserial.begin(BTBaud);  // Set Baudrate
 
  
}

void loop() 
{
        if(!BTtimeout()) check = BTserial.read();
        switch(check)
        {
          case 182 : 
            if(!BTtimeout()) BTlat = BTserial.read();
            break;
          case 183 :
            if(!BTtimeout()) BTlng = BTserial.read();
            break;
          case 184 :
            lcd.print("GPS Fail               "); 
            lcd.setCursor(0, 0);
            break;
            
        }
        if(check != 184)
        {
            lcd.print(BTlat);
            lcd.print(", ");
            lcd.print(BTlng);
            lcd.print("                                   ");
            lcd.setCursor(0, 0);
        }
        buzzerState = LOW;
        digitalWrite(buzzerPin, buzzerState);
}

bool BTtimeout()
{
  timeout = 0;
  while(!BTserial.available())
  {
     unsigned long currentmillis = millis();
        if(currentmillis - previousmillis > 1000)
        {
          if(timeout < 5) timeout++;
          previousmillis = currentmillis;   
        }
        if(timeout >= 5)
        {
          buzzerState = HIGH;
          digitalWrite(buzzerPin, buzzerState);
          lcd.print(BTlat);
          lcd.print(", ");
          lcd.print(BTlng);
          lcd.print(",Bluetooth ,Timeout "); 
          lcd.setCursor(0, 0);
        }
  }
  return false;
}

