#include <DHT.h>


/*Humidity, Temperature and Foto sensors
 * YL-38 e YL69
 * Hackaton project 
 */

#define pin_DHT11 D0
#define pin_foto A0

int foto_data, DHT11_temp_data, DHT11_hum_data;
DHT dht;

void setup() {
  Serial.begin(9600);
  pinMode(pin_foto,INPUT);
  dht.setup(pin_DHT11);  

}

void loop() {

  //reads values on pins
  DHT11_temp_data = dht.getTemperature();
  DHT11_hum_data = dht.getHumidity();
  foto_data = analogRead(pin_foto);

  //sends data by serial
  Serial.print("\nUmidade: \n");
  Serial.print(DHT11_hum_data);
  Serial.print("\nTemperatura\n");
  Serial.print(DHT11_temp_data);
  Serial.print("\nFotoincidencia\n");
  Serial.print(foto_data);
  
  delay(10000);
}
