//temp.sensor

#include <DHT.h>

#define DHT_PIN A0
#define LED_PIN 13

DHT dht(DHT_PIN, DHT11);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    delay(1000);
}

void loop() {
    dht.begin();
    float temperature = dht.readTemperature();
    
    Serial.print("Humidity: ");
    Serial.print(dht.readHumidity());
    Serial.print("%, Temp: ");
    Serial.print(temperature);
    Serial.println("C");

    digitalWrite(LED_PIN, (temperature > 30) ? HIGH : LOW);
    delay(1000);
}
