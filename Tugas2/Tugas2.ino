#include <dht.h>

int sensorSuhu = D4; //sesuaikan dengan GPIO pin yang anda gunakan
int temperature;
int humidity;
int merah = D1;
int kuning = D2;
int hijau = D0;
dht DHT;

void setup() {
  Serial.begin(115200);
  Serial.println("Praktikum sensor suhu dan kelembaban");
  pinMode(merah, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(kuning, OUTPUT);
  delay(500);
}

double Fahrenheit(double celsius) {
  return (int)round(1.8 * celsius + 32);  
}

void loop() {
  DHT.read11(sensorSuhu);
  temperature = (int)round(DHT.temperature);
  humidity = DHT.humidity;
  Serial.print("Kelembaban udara = ");
  Serial.print(humidity);
  Serial.print(" %");
  Serial.println(" ");
  Serial.print("Suhu C = ");
  Serial.print(temperature);
  Serial.print(" °C ");
  Serial.println(" ");
  Serial.print("Suhu F = ");
  Serial.print((int)round(Fahrenheit(temperature)));
  Serial.println(" °F ");

  if (temperature >= 30) {
    digitalWrite(hijau, HIGH);
    digitalWrite(kuning, HIGH);
    digitalWrite(merah, HIGH);    
    Serial.println("Suhu Sangat Panas ! ");
  } else if (temperature > 27 && temperature <= 29 ) {
    digitalWrite(kuning, LOW);
    digitalWrite(hijau, LOW);
    digitalWrite(merah, HIGH);    
    Serial.println("Suhu Panas ! ");
  } else if (temperature > 24 && temperature <= 27 ) {
    digitalWrite(merah, LOW);
    digitalWrite(hijau, LOW);
    digitalWrite(kuning, HIGH);    
    Serial.println("Suhu Normal ! ");
  } else if (temperature <= 25) {
    digitalWrite(kuning, LOW);
    digitalWrite(merah, LOW);
    digitalWrite(hijau, HIGH);    
    Serial.println("Suhu Dingin ! ");
  }
   
  Serial.println(" ");
  delay(3000);
}
