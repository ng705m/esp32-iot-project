#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <HTTPClient.h>
#include <ESP32Servo.h>          // 新增

// Wi-Fi
const char* ssid = "Lam";
const char* password = "91393082";

// MQTT
const char* mqtt_server = "gerbil.rmq.cloudamqp.com";
const int mqtt_port = 1883;
const char* mqtt_user = "xlitltmu:xlitltmu";
const char* mqtt_password = "meovAgvm1UrsyiGb-iOLYkwGdO2kwW0p";
const char* mqtt_topic = "sensor/data";

// DHT22
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// MQ-2
#define MQ2_PIN 32

// Servo
#define SERVO_PIN 13             // 新增
Servo myServo;                   // 新增

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED 啟動失敗");
    while (1);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Connecting...");
  display.display();

  // 馬達初始化
  myServo.attach(SERVO_PIN);     // 新增
  myServo.write(0);              // 新增

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi OK");

  client.setServer(mqtt_server, mqtt_port);
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
      Serial.println("MQTT OK");
    } else {
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int smoke = analogRead(MQ2_PIN);

  // 如果讀取失敗就跳過這次
if (isnan(temperature) || isnan(humidity)) {
  Serial.println("DHT 讀取失敗，跳過");
  delay(2000);
  return;
}

  // 溫度控制馬達
  if (!isnan(temperature)) {
    if (temperature > 28.0) {
      myServo.write(90);
      Serial.println("高溫！馬達轉到 90 度");
    } else {
      myServo.write(0);
      Serial.println("正常，馬達回到 0 度");
    }
  }

  // OLED 顯示
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Temp / Hum / Smoke");

  display.setTextSize(2);
  if (isnan(temperature) || isnan(humidity)) {
    display.setCursor(0, 20);
    display.println("DHT Err");
  } else {
    display.setCursor(0, 16);
    display.print(temperature, 1);
    display.println("C");

    display.setCursor(0, 38);
    display.print(humidity, 1);
    display.println("%");
  }

  display.setTextSize(1);
  display.setCursor(70, 52);
  display.print("S:");
  display.println(smoke);
  display.display();

  // 發送 MQTT
  String payload = "{";
  payload += "\"temp\":" + String(temperature, 1) + ",";
  payload += "\"hum\":" + String(humidity, 1) + ",";
  payload += "\"smoke\":" + String(smoke);
  payload += "}";

  client.publish(mqtt_topic, payload.c_str());
  Serial.println("已發送: " + payload);

  // 傳送到 n8n
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://192.168.99.146:5678/webhook/5cfa950b-7bc7-4d68-96a1-5ba397041c9b");
    http.addHeader("Content-Type", "application/json");
    
    int httpCode = http.POST(payload);
    if (httpCode > 0) {
      Serial.println("n8n 已收到");
    } else {
      Serial.println("n8n 傳送失敗");
    }
    http.end();
  }

  delay(5000);
}