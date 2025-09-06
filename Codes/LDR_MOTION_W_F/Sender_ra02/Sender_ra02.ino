
#include <LoRa.h>
#define SS 15
#define RST 16
#define DIO0 2
String data1 = "Wake_Up";
String data2 = "Sleep";
void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("Sender Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6))
  {
    Serial.println("LoRa Error");
    delay(100);
    while (1)
      ;
  }
}
void loop()
{
  Serial.print("Sending Data: ");
  Serial.println(data1);
  LoRa.beginPacket();
  LoRa.print(data1);
  LoRa.endPacket();
  delay(5000);
}