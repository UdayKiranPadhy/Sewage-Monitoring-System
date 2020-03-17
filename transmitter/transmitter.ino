#include <Arduino.h>
#include <SPI.h>
#include <RH_NRF24.h>
#include <EEPROM.h>

// Singleton instance of the radio driver
RH_NRF24 nrf24;


const int trigPin = 5;
const int echoPin = 6;
// defines variables
long duration;
int distance;


int deviceID = EEPROM.read(0);

void setup()
{

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
Serial.begin(9600);

while (!Serial)
; // wait for serial port to connect. Needed for Leonardo only
if (!nrf24.init()) {
Serial.println("init failed");

}
// Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
if (!nrf24.setChannel(3)) {
Serial.println("setChannel failed");

}
if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm)) {
Serial.println("setRF failed");

}

Serial.println("Transmitter started");
}
// This wrapper is in charge of calling
// mus be defined like this for the lib work
//void dht11_wrapper() {
//DHT11.isrCallback();
//}

void loop() {

Serial.println("Sending to gateway");
uint8_t data[3];
data[0] = distance;
data[1] = 101;



// Clears the trigPin
digitalWrite(trigPin, LOW);
delay(1000);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delay(2000);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);


nrf24.send(data, sizeof(data));
nrf24.waitPacketSent();
// Now wait for a reply
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
uint8_t len = sizeof(buf);
if (nrf24.waitAvailableTimeout(1000))
{
// Should be a reply message for us now
if (nrf24.recv(buf, &len))
{
Serial.print("got reply: ");
Serial.println((char*)buf);
}
else
{
Serial.println("recv failed");
}
}
else
{
Serial.println("No reply.");
}
delay(3000);
}
