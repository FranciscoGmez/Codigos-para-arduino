#include <Adafruit_MPU6050.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

float anguloG, anguloR;

void setup() {
  Serial.begin(115200);
  // while (!Serial);
  Serial.println("MPU6050 OLED demo");

  if (!mpu.begin()) {
    Serial.println("Sensor init failed");
    while (1)
      yield();
  }
  Serial.println("Found a MPU-6050 sensor");

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.display();
  delay(500); // Pause for 2 seconds
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  anguloG = 90 * a.acceleration.y/9.81;
  anguloR = anguloG * 3.14 / 180;

  display.clearDisplay();
  display.setCursor(0, 0);

  display.println("Inclinacion - Grados");
  display.print(anguloG, 2);

  display.drawLine(0,16,128 * cos(anguloR), 16*(1+sin(anguloR)), WHITE)

 ; 
  display.display();
  delay(100);
}
