# ESP32 IoT Smart Monitoring System  
ESP32 智能監控系統

Environment monitoring device with temperature, humidity, smoke sensing, OLED display, servo control, MQTT upload, and n8n automation with email alerts.

溫濕度與煙霧監測裝置，具備 OLED 顯示、伺服馬達控制、MQTT 上傳，以及 n8n 自動通知。

## Features / 功能

- DHT22 temperature & humidity / 溫濕度讀取
- MQ-2 smoke sensor / 煙霧感測
- 0.96" OLED real-time display / OLED 即時顯示
- SG90 servo (triggers on high temperature) / 高溫時控制伺服馬達
- MQTT upload to CloudAMQP / MQTT 數據上傳
- n8n automation with email alert / n8n 自動 Email 通知

## Hardware / 硬體

- ESP32
- DHT22
- MQ-2
- 0.96" OLED (I2C)
- SG90 Servo
- Breadboard & Dupont wires

## Tools / 工具

- PlatformIO (VS Code)
- EasyEDA (Schematic & PCB)
- Fusion 360 (Enclosure)
- n8n
- CloudAMQP

## Progress / 進度

- [x] Sensor reading & wiring / 感測器接線與讀取
- [x] OLED display
- [x] MQTT upload
- [x] n8n automation & email
- [x] EasyEDA PCB design
- [x] Fusion 360 enclosure
- [ ] PCB soldering & assembly / 電路板焊接組裝
- [ ] 3D print & final test / 3D 列印與最終測試

## Notes / 說明

Full process from hardware bring-up, sensor integration, cloud upload, automation, PCB design to enclosure modeling.

從硬體測試、感測器整合、雲端上傳、自動化、PCB 設計到外殼建模的完整流程。
