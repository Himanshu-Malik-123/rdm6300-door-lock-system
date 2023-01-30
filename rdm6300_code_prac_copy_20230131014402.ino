#include <Arduino.h>
#include <rdm6300.h>

#define RDM6300_RX_PIN 4   // rx pin of rdm6300
#define READ_LED_PIN 13    // lock pin 

Rdm6300 rdm6300;  // class object

void setup()
 {
   Serial.begin(115200);           // Begin serial monitor
   pinMode(READ_LED_PIN, OUTPUT);  
   digitalWrite(13, LOW);         // initial
   rdm6300.begin(RDM6300_RX_PIN);
   Serial.println("\nPlace RFID tag near the rdm6300...");
 }
void loop()
{
  digitalWrite(13,HIGH);
  if (rdm6300.get_new_tag_id()==4983391){             // for single tag id , can be extended
    Serial.println(rdm6300.get_tag_id(), DEC);        // scan for tags and print its id
    digitalWrite(13,LOW);
    delay(6000);
    digitalWrite(13,HIGH);
   }
  delay(100);
} 