/*
 * Subscribe Tech Vegan for More Hardware & Software Tech Videos
 * Program by: Ashish Vegan https://www.ashishvegan.com
 * For Help - Contact WhatsApp +919890345539
 * technologyvegan@gmail.com
 * Get Harware & Software Academic Projects
 * Code Courtesy: Lora.h
 */
 #include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#include <ESP8266HTTPClient.h>
#include <LoRa.h>
#define SS 15
#define RST 16
#define DIO0 2
String data1 = "Wake_Up";
String data2 = "Sleep";
const char *ssid = "Realme_8_5G";
const char *password = "8319067226";
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "time.google.com", 19800); // UTC offset for New Delhi is 5 hours and 30 minutes (19800 seconds)

void printWifiDetails();

void setup()
{
  Serial.begin(115200);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  printWifiDetails();

  // Initialize and synchronize time
  timeClient.begin();
  timeClient.update();
  setTime(timeClient.getEpochTime());


  while (!Serial);
  Serial.println("Sender Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    delay(100);
    while (1);
  }
}
void loop()
{  timeClient.update();
 
  // Get current time in HH:MM:SS format
  char currentTime[9];
  sprintf(currentTime, "%02d:%02d:%02d", hour(), minute(), second());
    if (strcmp(currentTime, "06:42:20") >= 0 && strcmp(currentTime, "23:45:09") < 0 ) {  
            Serial.print("Sending Data: ");
            Serial.println(data1);
            LoRa.beginPacket();
            LoRa.print(data1);
            LoRa.endPacket();
            delay(5000);}
     else{
              Serial.print("Sending Data: ");
            Serial.println(data2);
            LoRa.beginPacket();
            LoRa.print(data2);
            LoRa.endPacket();
            delay(5000);}
           
}


void printWifiDetails() {
  // Print the connected SSID
  Serial.print("Connected to SSID: ");
  Serial.println(WiFi.SSID());

  // Print the MAC address of the ESP
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  // Print the local IP address
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Print the subnet mask
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());

  // Print the gateway IP address
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());

  // Print the connection speed
  Serial.print("Connection Speed: ");
  Serial.print(WiFi.getPhyMode() == WIFI_PHY_MODE_11B ? "11b" :
               WiFi.getPhyMode() == WIFI_PHY_MODE_11G ? "11g" :
               WiFi.getPhyMode() == WIFI_PHY_MODE_11N ? "11n" : "unknown");
  Serial.println();

  // Print connection time
  Serial.print("Connection Time: ");
  Serial.print(millis() / 1000);  // Convert milliseconds to seconds
  Serial.println(" seconds");
}

