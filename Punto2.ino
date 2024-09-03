// Definición de variables y pines a usar
#define sensor_temp 32
#define red 27
#define green 26
#define blue 25
float lectura;
float voltaje;
float C;

// Función que creamos nosotros para controlar el color del LED
void ponerColores(int x, int y, int z) {
  analogWrite(red, x);
  analogWrite(green, y);
  analogWrite(blue, z);
}

void setup() {
  // Setup para el ESP32, sensor de temperatura y LED
  Serial.begin(9600);
  pinMode(sensor_temp, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // Conversión de la lectura del sensor de temperatura a grados centígrados
  // Como el sensor LM35 funciona con más de 4.0V (no 3.3V) y el ESP32dev-kit soporta 5.0V si se conecta en VIN, entonces usamos 5.0V en la conversión y no 3.3V
  // Adicionalmente, el ESP32 tiene una arquitectura de 12 bits, y el factor de conversión es 2^12 - 1 = 4095 para la entrada análoga
  lectura = analogRead(sensor_temp);
  voltaje = (lectura * 5.0) / 4095.0;
  C = voltaje/0.01;

  // Esto es adicional al taller, pero sirve para tener un control sobre los datos del problema al ser mostrados en la pantalla
  delay(500);
  Serial.println(String(C) + ", " + String(voltaje) + ", " + String(lectura));

  // Lógica para controlar el color del LED usando la temperatura
  if (20 <= C && C < 26) {
    ponerColores(0, 0, 255);
  }
  else if (26 <= C && C < 30) {
    ponerColores(255, 127, 0);
  }
  else if (C >= 30) {
    ponerColores(255, 0, 0);
  }
  else {
    ponerColores(0, 0, 0);
  }

}
