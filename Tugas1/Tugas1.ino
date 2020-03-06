#include <dht.h>


int sensorSuhu = D4; //sesuaikan dengan GPIO pin yang anda gunakan
dht DHT;
void setup() {
Serial.begin(115200);
Serial.println("Praktikum sensor suhu dan kelembaban");
delay(500);
}
void loop() {
DHT.read11(sensorSuhu);
Serial.print("Kelembaban udara = ");
Serial.print(DHT.humidity);
Serial.print("% ");
Serial.print("Suhu = ");
Serial.print(DHT.temperature);
Serial.print(" C ");
Serial.print("Fahrenheit = ");
Serial.print((1.8*DHT.temperature+32));
Serial.println(" F ");
delay(3000);
}
