# ESP32 IoT 智能監控系統

使用 ESP32 開發的環境監測裝置，整合溫濕度、煙霧感測、OLED 顯示、伺服馬達控制，並透過 MQTT 將數據上傳至雲端，再由 n8n 進行自動化判斷與通知。

## 功能

- 讀取 DHT22 溫濕度感測器
- 讀取 MQ-2 煙霧感測器
- 0.96 吋 OLED 即時顯示數據
- SG90 伺服馬達（溫度超過門檻時自動動作）
- Wi-Fi 連線
- 透過 MQTT 上傳數據至 CloudAMQP
- 使用 n8n 接收數據，並在溫度異常時自動發送 Email 通知

## 硬體清單

- ESP32 開發板
- DHT22 溫濕度感測器
- MQ-2 煙霧感測器
- 0.96 吋 OLED（I2C）
- SG90 伺服馬達
- 麵包板與杜邦線

## 軟體與工具

- PlatformIO（VS Code）
- EasyEDA（原理圖與 PCB 設計）
- Autodesk Fusion 360（外殼設計）
- n8n（自動化流程）
- CloudAMQP（MQTT Broker）

## 目前進度

- [x] 硬體接線與感測器讀取
- [x] OLED 顯示
- [x] MQTT 數據上傳
- [x] n8n 自動化與 Email 通知
- [x] EasyEDA 原理圖與 PCB 設計
- [x] Fusion 360 外殼設計
- [ ] 實體電路板焊接與組裝
- [ ] 3D 列印外殼與最終測試

## 說明

本專案從硬體 bring-up、感測器整合、雲端數據傳輸、自動化流程，到 PCB 設計與外殼建模，完整走過一次 IoT 產品開發流程。
