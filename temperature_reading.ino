#define BLYNK_TEMPLATE_ID "TMPL3StjIcBt5"
#define BLYNK_TEMPLATE_NAME "dhtiot"
#define BLYNK_AUTH_TOKEN "tM0XNeShVvkgGMNbcUBhBh5wRPfMN1S_"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 //data pin is connected to d2 on ESP
#define DHTTYPE DHT11//name the sensor as an object(dht11 sensor is beign used)'
//just a commit



char auth[] = "tM0XNeShVvkgGMNbcUBhBh5wRPfMN1S_";
char ssid[] = "Pranav";
char pass[] = "Pranav_01";
DHT dht(DHTPIN,DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT test successful!");
  Blynk.begin(auth,ssid,pass);
  Serial.println("Blynk connected Successfully");
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float humidity=dht.readHumidity();
  float temp = dht.readTemperature();
  float f = dht.readTemperature(true);
  if(isnan(humidity) || isnan(temp) ||isnan(f))
  {
    Serial.println("something is not working as intended");
    return;
  }
  Serial.println("Humidity: ");
  Serial.print(humidity);
  Serial.print("%");
  Serial.println("Temperature: ");
  Serial.print(temp);
  Serial.print("degree celsius");
  Blynk.virtualWrite(V0,temp);
  Blynk.virtualWrite(V1,humidity);
  delay(1000);
}  
