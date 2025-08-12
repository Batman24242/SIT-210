#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
#include "DHT.h"
#include <ThingSpeak.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "Redmi Note 10";
char pass[] = "dxwh34ma47xkvtp";
const char serverAddress[] = "api.thingspeak.com";
int port = 80;
String apiKey = "P9VHG486XASWMIKQ";

WiFiClient wifi;
HttpClient client(wifi, serverAddress, port);

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(2000); // give DHT time to stabilize

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWi-Fi connected");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor read failed");
  } else {
    String postData = "api_key=" + apiKey +
                      "&field1=" + String(temp) +
                      "&field2=" + String(hum);

    client.post("/update", "application/x-www-form-urlencoded", postData);

    int statusCode = client.responseStatusCode();
    Serial.print("Response code: ");
    Serial.println(statusCode);

    String response = client.responseBody();
    Serial.println(response);
  }

  delay(15000); // Respect ThingSpeak's limit
}