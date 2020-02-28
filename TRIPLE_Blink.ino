/*
 ESP8266 Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain
 
 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
#define led_D0 16
#define led_D1 5
#define led_D2 4

void setup() {
  pinMode(led_D0, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(led_D1, OUTPUT);
  pinMode(led_D2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led_D0, HIGH); // Turn the LED on (Note that LOW is the voltage level
  digitalWrite(led_D1, LOW);
  digitalWrite(led_D2, HIGH);
  delay(1000); // but actually the LED is on; this is because 
                                    // it is active low on the ESP-01)
                                    // Wait for a second
  digitalWrite(led_D0, HIGH); // Turn the LED on (Note that LOW is the voltage level
  digitalWrite(led_D1, HIGH);
  digitalWrite(led_D2, LOW);
  delay(1000);


  digitalWrite(led_D0, LOW); // Turn the LED on (Note that LOW is the voltage level
  digitalWrite(led_D1, HIGH);
  digitalWrite(led_D2, HIGH);
  delay(1000);                                  
}
