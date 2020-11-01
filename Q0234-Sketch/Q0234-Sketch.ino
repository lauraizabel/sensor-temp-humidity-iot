<<<<<<< HEAD
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor

#define FIREBASE_HOST "dht11-f269b.firebaseio.com"
#define FIREBASE_AUTH "V2QD9kmBl26c1diIFWuog3WqtDNe28JKuGsDW83Q"
#define WIFI_SSID "WIFI_LAURA"
#define WIFI_PASSWORD "laura2001"
#define DHTTYPE DHT11   // Definindo o tipo do sensor dht como DHT 11
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
=======
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor

#define FIREBASE_HOST "dht11-f269b.firebaseio.com"
#define FIREBASE_AUTH "V2QD9kmBl26c1diIFWuog3WqtDNe28JKuGsDW83Q"
#define WIFI_SSID "WIFI_LAURA"
#define WIFI_PASSWORD "laura2001"
#define DHTTYPE DHT11   // Definindo o tipo do sensor dht como DHT 11
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

>>>>>>> 565e5980519988a38b69063816bb7f1f2f488089
