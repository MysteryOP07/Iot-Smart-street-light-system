
#include <LoRa.h>
#define SS 15
#define RST 16
#define DIO0 2
int ledPin = D3;
 int ldrPin = A0;
 int ldrThreshold = 500;
 int motionPin = D4;
 bool checkLDR = false;

String expectedData1 = "Wake_Up"; // Set the expected data 1
String expectedData2 = "Sleep"; // Set the expected data 2

// Function declaration
void sendFeedbackToSender();
void handleWakeup();
void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Receiver Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    while (1);
  }
}
void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Receiving Data: ");
     String data = LoRa.readString();
      Serial.println(data);
      if(data == expectedData1){
        Serial.println("Data matched ! sending Feedback to sender.");
        sendFeedbackToSender();
        handleWakeup();
      }else if(data == expectedData2){
        Serial.println("Going Into Sleep Mode");
        analogWrite(ledPin, 0);}
        else if(data != expectedData1){
        Serial.println("Data Error");
      }
    
    // Blink the LED when data is received
    
  }
}


void sendFeedbackToSender() {
  LoRa.beginPacket();
  LoRa.print("Data received successfully!");
  LoRa.endPacket();
}

void handleWakeup() {
  Serial.println("Received wake-up signal");
  
  // Implement actions for wake-up
  checkLDR = true;  // Set the flag to check LDR reading

 // Read LDR value
    int ldrReading = analogRead(ldrPin);

    // Read motion sensor
    

    // Include LDR and motion sensor status in the response
    if (ldrReading > ldrThreshold) {
      int motionReading = digitalRead(motionPin);
        if (motionReading == HIGH) {
              analogWrite(ledPin, 1023);
              Serial.println("LED_ON MOTION DETECTED");
              } 
        else {
            analogWrite(ledPin, 0);
            Serial.println("LED_OFF MOTION NOT DETECTED");
        }
    } else {
        analogWrite(ledPin, 0);
        Serial.println("LED_OFF");
        checkLDR = false;
    }
  
}
