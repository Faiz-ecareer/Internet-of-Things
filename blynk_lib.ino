#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "ca15cab840bb45dabeba4ce2f1159879";

char ssid[] = "Hotshot";
char pass[] = "technahar";

#define DHTPIN 5

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t))
  {
    Serial.println("failed tp read the DHT sensor");
    return;
  }

  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  }
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  dht.begin();
  timer.setInterval(1000L,sendSensor);
}
void loop()
{
  Blynk.run();
  timer.run();
}  


