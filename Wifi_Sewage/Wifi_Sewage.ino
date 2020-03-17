#include <SPI.h>
#include <RH_NRF24.h>
#include <Wire.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>



String apiKey = "FJWJR9Q4JOCC5FGI";
const char* ssid = "AndroidAP92C0";
const char* password = "ghfr3729";


WiFiClient client;
HTTPClient http; 
int gatewayID = EEPROM.read(0);
const char* server = "api.thingspeak.com";


// Singleton instance of the radio driver


RH_NRF24 nrf24(2, 4); // use this for NodeMCU Amica/AdaFruit Huzzah ESP8266 Feather



void setup()
{
Serial.begin(9600);
Serial.print("Receiver Started, ID: ");
Serial.print("Connecting to ");
Serial.println(ssid);
Serial.print(gatewayID);
Serial.println();
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
nrf24.init();
nrf24.setChannel(3);
nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm);

}



void loop()
{
if (nrf24.available())
{
// Should be a message for us now
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
uint8_t len = sizeof(buf);
if (nrf24.recv(buf, &len))
{
// Send a reply
uint8_t sdata[] = "Data Received.";
nrf24.send(sdata, sizeof(sdata));
nrf24.waitPacketSent();

int Level = buf[0];
int deviceID = buf[1];

Serial.println("--- Data retrieved from device ---");
if (client.connect(server, 80)) { // "184.106.153.149" or api.thingspeak.com
  
String postStr = apiKey;
postStr += "&field1=";
postStr += String(Level);
postStr += "\r\n\r\n";

client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);

Serial.print("Water Level:");
Serial.print(Level);
Serial.print(", Device ID: ");
Serial.println(deviceID);
Serial.println("---- Data sent to Thingspeak ----");
Serial.println();
Serial.println("...................................................");
Serial.println();
Serial.println(WiFi.localIP());
IPAddress ip = WiFi.localIP();
String ipString = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
}
client.stop();
}
} else {
// no new message, turn off LED
}
// delay is due to ThingSpeak's limitations
delay(15000);
}
