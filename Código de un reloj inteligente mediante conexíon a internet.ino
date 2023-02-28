#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

// Declaración de constantes
const char* ssid = "Nombre de tu red";  // Nombre de tu red Wi-Fi
const char* password = "Contraseña de tu red ";  // Contraseña de tu red Wi-Fi
const long utcOffsetInSeconds = -6*3600;  // Zona horaria de la Ciudad de México, en segundos (-5 horas)
const char* ntpServer = "pool.ntp.org";  // Servidor NTP
const int ntpPort = 123;  // Puerto NTP

// Declaración de objetos
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer, utcOffsetInSeconds);
Adafruit_SSD1306 display(128, 32);

DHT dht(2, DHT11);

float temperatura, humedad;

void setup() {
  // Inicialización de objetos
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  // Conexión a la red Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wi-Fi...");
  }
  Serial.println("Conexión exitosa a la red Wi-Fi");

  // Inicialización del cliente NTP
  timeClient.begin();

  // Inicialización del sensor DHT11
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Actualización de la hora desde el servidor NTP
  timeClient.update();
  // Obtiene la hora actual y la almacena en las variables correspondientes
  int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();
  int seconds = timeClient.getSeconds();

  // Muestra la hora actual en la pantalla OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Hora CDMX:");
  display.setCursor(0, 10);
  if (hours < 10) {
    display.print("0");
  }
  display.print(hours);
  display.print(":");
  if (minutes < 10) {
    display.print("0");
  }
  display.print(minutes);
  display.print(":");
  if (seconds < 10) {
    display.print("0");
  }
  display.print(seconds);


  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C\tHumedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  display.setCursor(0, 20);
  display.print("Temperatura: ");
  display.print(temperatura);
  display.print(" C");
 // display.setCursor(0, 30);
 // display.print("Humedad: ");
  //display.print(humedad);
 // display.print(" %");
  display.display();
  
  delay(1000);  // Espera 1 segundo antes de actualizar la hora nuevamente

  // Desarrollo del sensor DHT11
  humedad = dht.readHumidity();
  temperatura = dht.readTemperature();
}