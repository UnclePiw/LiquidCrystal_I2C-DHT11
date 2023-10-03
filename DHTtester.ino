#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
#define DHTPIN 2 

#define DHTTYPE DHT11  


// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
    Serial.begin(9600); 
    Serial.println("DHTxx test!");
    lcd.init();
    lcd.backlight();
    
    dht.begin();
}

void loop() 
{
   
   float h = dht.readHumidity();
   float t = dht.readTemperature();

   
   if (isnan(t) || isnan(h)) {
       Serial.println("Failed to read from DHT");
   } else {
       Serial.print("Humidity: "); 
       Serial.print(h);
       Serial.print(" %\t");
       Serial.print("Temperature: "); 
       Serial.print(t);
       Serial.println(" *C");
       lcd.setCursor (0, 0); 
       lcd.print ("Temp: "); 
       lcd.setCursor (7,0); 
       lcd.print (t); 
       lcd.setCursor (13, 0); 
       lcd.print ("C"); 
       lcd.setCursor (0,1); 
       lcd.print ("Humi: "); 
       lcd.setCursor (7,1); 
       lcd.print (h); 
       lcd.setCursor (13, 1); 
       lcd.print ("%");
   }

}