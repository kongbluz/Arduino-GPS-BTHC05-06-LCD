# Arduino-GPS-BTHC05-06-LCD
  Send Latitude and Longtitude to another arduino by bluetooth and show on LCD
## 1. Setup Bluetooth
  more detail [here](http://www.martyncurrey.com/connecting-2-arduinos-by-bluetooth-using-a-hc-05-and-a-hc-06-pair-bind-and-link/ "Title")
### 1.1 setup HC06
  Upload BTHC06Setup.ino to arduino and open Serial Monitor
  ```
  send : AT
  response : OK
  ```
  if HC-06 Ready to use. You should get reply if "OK" <br /> 
  Set pin
  ```
  send : AT+PINxxxx
  response : OKsetPIN
  ```
  more HC-06 AT commands [here](www.micro4you.com/files/ElecFreaks/Bluetooth%20HC-06.pdf "Title")
### 1.2 setup HC05
  Upload BTHC05Setup.ino to another arduino and open Serial Monitor <br /> 
  and set pin 34 of HC-06 is high
  ```
  send : AT
  response : OK
  ```
  if HC-05 Ready to use. You should get reply if "OK"__
  and [more](http://www.martyncurrey.com/connecting-2-arduinos-by-bluetooth-using-a-hc-05-and-a-hc-06-pair-bind-and-link/ "Title") <br /> 
  more HC-05 AT command [here](www.pridopia.co.uk/pi-doc/commandes_AT_HC05.pdf)
## 2. download TinyGPS++
  Can download [here](http://arduiniana.org/libraries/tinygpsplus/ "Title") <br /> 
  Use for Master_HC05_.ino
## 3. download LiquidCrystal_I2C.
  Can download [here](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library "Title") <br /> 
  Use for Slave_HC06_.ino
