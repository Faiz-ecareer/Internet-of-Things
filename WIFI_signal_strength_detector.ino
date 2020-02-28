#include <ESP8266WiFi.h>
const char* SSID = "Hotshot";
#define relay1 16

int32_t getRSSI(const char* target_ssid)
{
  byte available_networks = WiFi.scanNetworks();
  for(int network = 0; network < available_networks; network++)
  {
    if(WiFi.SSID(network).compareTo(target_ssid) == 0)
    {
      return WiFi.RSSI(network);
    }
  }
  return 0;
}
void setup()
{
  Serial.begin(115200);
  pinMode(relay1, OUTPUT);
}
void loop()
{
  int32_t rssi = getRSSI(SSID);
  Serial.print("Signal strength: ");
  Serial.print(rssi);
  Serial.print("dBm");

 if (rssi > (-70) && rssi != 0)
 {
  digitalWrite(relay1, LOW);
  Serial.println("ON");
 }
 else
 {
  digitalWrite(relay1, HIGH);
  Serial.println("OFF");
 }
}

