#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <BlynkSimpleEsp8266.h>
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <Servo.h>


Servo servo;
char auth [] = "d7ac5ca2768b4c6593f204cb408efd74";
BLYNK_WRITE(V3)
{
  servo.write(param.asInt());
  Serial.println(param.asInt()); 
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //reset saved settings
    //wifiManager.resetSettings();
    
    //set custom ip for portal
    //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    wifiManager.autoConnect("Power","password");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
   
    
    Blynk.begin(auth,WiFi.SSID().c_str(),WiFi.psk().c_str());
    servo.attach(15);

    //Serial.println(WiFi.SSID().c_str());
    //Serial.println(WiFi.psk().c_str());
    
}

void loop() {
    // put your main code here, to run repeatedly:
    
}
