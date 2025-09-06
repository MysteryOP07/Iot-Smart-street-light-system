# Iot-Smart-street-light-system

🌃 IoT Smart Street Light System

An IoT-based Smart Street Light System using LoRa communication that automatically controls street lights based on ambient light and motion detection, while enabling remote wake/sleep control. This project optimizes energy consumption and provides a scalable solution for smart cities.

✨ Features

🌞 Ambient Light Detection → Lights turn on only in dark conditions using LDR.

🚶 Motion Detection → Lights activate when motion is detected, ensuring safety and saving energy.

📡 LoRa-based Communication → Long-range, low-power connectivity between control node and street light nodes.

🔄 Wake/Sleep Commands → Sender can remotely control receiver states.

💡 Energy Efficient → Lights are active only when required.

🛠️ Hardware Requirements

ESP32 / ESP8266 (LoRa-enabled) modules

LoRa SX1278 (433 MHz) module

LDR (Light Dependent Resistor)

PIR Motion Sensor

LEDs / Street Light model

Resistors & jumper wires

Power Supply (Li-ion / USB / regulated source)

🔌 Pin Connections
Receiver (Street Light Node)
Component Pin (ESP)
LoRa NSS (SS) 15
LoRa RST 16
LoRa DIO0 2
LDR Sensor A0
PIR Motion D4
LED Output D3
Sender (Control Node)
Component Pin (ESP)
LoRa NSS (SS) 15
LoRa RST 16
LoRa DIO0 2
⚙️ Software Requirements

Arduino IDE with:

LoRa Library

ESP32 / ESP8266 board support installed

🚀 Setup & Installation

Clone the repository:

git clone https://github.com/MysteryOP07/Iot-Smart-street-light-system.git
cd Iot-Smart-street-light-system

Open Sender_ra02.ino and Receiver_ra02.ino in Arduino IDE.

Install required libraries (LoRa).

Select correct Board (ESP32/ESP8266) and Port.

Upload Sender code to the transmitting ESP module.

Upload Receiver code to the streetlight ESP module.

Power up both modules.

📖 How It Works

The Sender Node transmits "Wake_Up" or "Sleep" signals using LoRa.

The Receiver Node listens for commands.

If "Wake_Up" is received:

It enables motion + LDR-based control:

If it’s dark and motion is detected → Light turns ON.

Otherwise → Light stays OFF.

If "Sleep" is received → Light remains OFF regardless of sensors.

📷 Demo Flow

Daytime, No Motion → Light OFF.

Nighttime, No Motion → Light OFF (saves energy).

Nighttime, Motion Detected → Light ON.

Remote Command: Sleep → Force lights OFF.

📜 License

This project is open-source under the MIT License.
