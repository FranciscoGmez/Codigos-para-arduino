#include <Wire.h>      // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 32       // reemplaza ocurrencia de ALTO por 32
#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 display(ANCHO, ALTO, &Wire, OLED_RESET); 
int pot = A0;
float val = 0;
int reg = 0;
void setup() {
  Wire.begin();         // inicializa bus I2C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  pinMode(pot,INPUT);
}
void loop() {
   val = analogRead(pot); // leer la salida del pot
   reg = (val * 100) / 1023; // regla de 3 para el 100%
   display.clearDisplay(); // limpia pantalla  
   display.drawRect(14,2,reg,12,WHITE); // dibuja la gráfica
   display.setTextSize(2); //establece el tamaño de fuente, admite tamaños de 1 a 8
   display.setTextColor(WHITE); //establece el color 
   display.setCursor(14,17); //establecer las coordenadas para mostrar la posición del texto
   display.println(reg);
   delay(100);
   display.display(); 
}