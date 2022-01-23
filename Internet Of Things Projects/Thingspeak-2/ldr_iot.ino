#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;

const char* ssid = "Redmi Note 9"; //Your Network SSID

const char* password = "Sylvan@701"; //Your Network Password

int val;

int LDRpin = A0; //LDR Pin Connected at A0 Pin



WiFiClient client;

unsigned long myChannelNumber =1229825 ; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "SWK2XWRFXYM9S5V4"; //Your Write API Key

void setup()

{

Serial.begin(115200);

delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);



ThingSpeak.begin(client);

}



void loop()

{

val = analogRead(LDRpin); //Read Analog values and Store in val variable

Serial.print(val); //Print on Serial Monitor

delay(1000);

ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak



delay(100);

}
