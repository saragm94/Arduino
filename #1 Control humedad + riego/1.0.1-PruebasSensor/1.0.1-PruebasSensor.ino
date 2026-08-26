const int sensorPin = A0;

const int valorSeco = 620;    // Tierra seca
const int valorHumedo = 310;  // Sensor en agua

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(sensorPin);
  int porcentaje = map(lectura, valorSeco, valorHumedo, 0, 100); //Pasamos a porcentaje
  
  porcentaje = constrain(porcentaje, 0, 100); //Controlamos que no sea más de 100
  
  //Muestra mensajes por terminal
  Serial.print("Humedad: ");
  Serial.print(porcentaje);
  Serial.println("%");
  
  delay(1000);
}