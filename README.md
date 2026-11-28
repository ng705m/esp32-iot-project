
IoT Smart Monitoring System / 智能監控系統

Environment monitoring device with temperature, humidity, smoke sensing, OLED display, servo control, MQTT upload, and n8n automation with email alerts.

溫濕度與煙霧監測裝置，具備 OLED 顯示、伺服馬達控制、MQTT 上傳，以及 n8n 自動通知。

[ESP32 Environment Monitoring System Demo](https://youtu.be/v3MZA-vUCO8)

## Features 

- DHT22 temperature & humidity / 溫濕度讀取
- MQ-2 smoke sensor / 煙霧感測
- 0.96" OLED real-time display / OLED 即時顯示
- SG90 servo (triggers on high temperature) / 高溫時控制伺服馬達
- MQTT upload to CloudAMQP / MQTT 數據上傳
- n8n automation with email alert / n8n 自動 Email 通知

## Hardware 

- ESP32
- DHT22
- MQ-2
- 0.96" OLED (I2C)
- SG90 Servo
- Breadboard & Dupont wires

## Tools 

- PlatformIO (VS Code)
- EasyEDA (Schematic & PCB)
- Fusion 360 (Enclosure)
- n8n
- CloudAMQP

## Progress

- [x] **Sensor reading & wiring**  
  Successfully connected and read data from DHT22 (temperature & humidity) and MQ-2 (smoke sensor) on ESP32.

- [x] **OLED display**  
  Real-time display of temperature, humidity, and smoke values on a 0.96" OLED screen via I2C.

- [x] **MQTT upload**  
  Sensor data is packaged in JSON and continuously uploaded to CloudAMQP via MQTT.

- [x] **n8n automation & email**  
  Self-hosted n8n (Docker) receives data and sends automated email alerts when temperature exceeds the threshold.

- [x] **EasyEDA PCB design**  
  Designed custom PCB schematic and layout in EasyEDA based on the breadboard prototype.

- [x] **Fusion 360 enclosure**  
  Designed a 3D-printable enclosure with cutouts for OLED, sensors, and servo motor.

- [ ] **PCB soldering & assembly**  
  Waiting for PCB to arrive. Next step is soldering components and assembling the board.

- [ ] **3D print & final test**  
  Enclosure will be 3D printed, followed by full system integration and final testing.

https://github.com/user-attachments/assets/40baa2ea-6b87-4b77-9cc9-2a9f893a4632

<img width="965" height="716" alt="n8n" src="https://github.com/user-attachments/assets/870e6692-0afe-4065-8da4-445b462f6560" />

<img width="668" height="566" alt="PCB" src="https://github.com/user-attachments/assets/45a4ead2-55c3-4926-815c-47ba28a2de46" />

<img width="706" height="534" alt="3D print" src="https://github.com/user-attachments/assets/e2c33704-92fd-432f-af53-b3133e886a4c" />


## Notes 

Full process from hardware bring-up, sensor integration, cloud upload, automation, PCB design to enclosure modeling.

從硬體測試、感測器整合、雲端上傳、自動化、PCB 設計到外殼建模的完整流程。
