<<<<<<< HEAD
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor

#define FIREBASE_HOST //your firebase host
#define FIREBASE_AUTH //your fire base auth of database
#define WIFI_SSID //wifi name
#define WIFI_PASSWORD //wifi password
#define DHTTYPE DHT11   //sensor dht = DHT 11
#define dht_dpin 0
#define led 5
#define buzzer 4

DHT dht_function(dht_dpin, DHTTYPE);

void setup(void) {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(dht_dpin, OUTPUT);
  dht_function.begin();
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(void) {
  check();
  delay(500);
}

void check() {
  float h = dht_function.readHumidity();
  float t = dht_function.readTemperature();

  if (isnan(t) || isnan(h)) {
    Serial.print("Falha ao obter dados.");
  } else if (h >= 0 && h <= 60 && t >= 15 && t <= 35) {
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t);
    Serial.println("C  ");
    digitalWrite(led, LOW);
    noTone(buzzer);
    Firebase.setFloat("humidity", h);
    Firebase.setFloat("temperature", t);
  } else {
    Serial.println("Alguma coisa esta alta");
  }
}

