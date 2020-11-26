#include <SPI.h>    // incluye libreria bus SPI
#include <Adafruit_GFX.h> // incluye libreria para manejo de graficos
#include <Adafruit_ILI9341.h> // incluye libreria para controlador ILI9341
 
#define TFT_DC 9    // define constante TFT_DC con numero 9
#define TFT_CS 10   // define constante TFT_CS con numero 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);  // crea objeto

int SENSOR;
float TEMPERATURA;
int MOTOR = 3;
float REFERENCIA;

void setup() {
  pinMode(MOTOR, OUTPUT);
  REFERENCIA = ((41.246337*5000.0)/1023)/10;;
  tft.begin();          // inicializa pantalla
  tft.setRotation(0);       // establece posicion vertical con pines hacia abajo
  tft.fillScreen(ILI9341_BLACK);    // fondo de pantalla de color negro
  tft.fillRect(0, 0, 240, 30, ILI9341_NAVY);  // rectangulo azul naval a modo de fondo de titulo 
  tft.setTextColor(ILI9341_WHITE);    // color de texto en blanco
  tft.setTextSize(2);       // escala de texto en 2
  tft.setCursor(25,6);        // ubica cursor
  tft.print("Panel de control");    // imprime texto
  tft.setCursor(50,50);        // ubica cursor
  tft.print("Temperatura");   // imprime texto
  tft.setCursor(0,280);
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);  // texto en color amarillo
  tft.setTextSize(1); 
  tft.print("El valor de referencia de la temperatura es: ");
  tft.println(REFERENCIA,1);
}

void loop() {
  SENSOR = analogRead(A0);
  TEMPERATURA = ((SENSOR*5000.0)/1023)/10;
  tft.setTextColor(ILI9341_YELLOW, ILI9341_BLACK);  // texto en color amarillo
  tft.setTextSize(6);   // escala de texto en 6
  tft.setCursor(50,80);   // ubica cursor
  tft.println(TEMPERATURA, 1);    // valor que representa la temperatura del sensor
  if(TEMPERATURA > REFERENCIA){
      digitalWrite(MOTOR, HIGH);
      tft.setCursor(25,170);        // ubica cursor
      tft.setTextColor(ILI9341_RED, ILI9341_BLACK);  // texto en color amarillo
      tft.setTextSize(1); 
      tft.print("Ventilador encendido!");
            
   } else{
    digitalWrite(MOTOR, LOW);
    tft.setCursor(25,170);        // ubica cursor
      tft.setTextColor(ILI9341_RED, ILI9341_BLACK);  // texto en color amarillo
      tft.setTextSize(1); 
      tft.print("                     ");  
   }
   delay(1000);  
}
