#include <LiquidCrystal.h> // Librería pantalla LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // pines pantalla (RS, E, D4, D5, D6, D7)

const int sensorPin = A0;     //Pin
const int valorSeco = 310;    // Tierra seca
const int valorHumedo = 620;  // Sensor en agua

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Tamaño pantalla
  lcd.print("Iniciando...");
  delay(1500);
  lcd.clear();
}

void loop() {
  int lectura = analogRead(sensorPin);
  int porcentaje = map(lectura, valorSeco, valorHumedo, 0, 100); //Pasamos a porcentaje
  
  porcentaje = constrain(porcentaje, 0, 100); //Controlamos que no sea más de 100
  lcd.print("Iniciando...");
  //Muestra mensajes por terminal
  Serial.print("Humedad: ");
  Serial.print(porcentaje);
  Serial.println("%");

  //Muestra mensajes por pantalla
  lcd.setCursor(0, 0);      // Columna 0, fila 0 (primera línea)
  lcd.print("Humedad:      "); // Los espacios en blanco borran texto viejo más largo
  lcd.setCursor(9, 0);      // Nos movemos a la posición donde va el número
  lcd.print(porcentaje);
  lcd.print("%");
  
  delay(1000);
}