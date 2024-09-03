#define derecha 22        // Define el pin 22 para el movimiento a la derecha.
#define izquierda 23      // Define el pin 23 para el movimiento a la izquierda.
#define S1 30             // Define el pin 30 para el sensor S1.
#define S2 31             // Define el pin 31 para el sensor S2.
#define S3 32             // Define el pin 32 para el sensor S3.
#define S4 33             // Define el pin 33 para el sensor S4.
#define START 35          // Define el pin 35 para el botón de inicio.
#define STOP 36           // Define el pin 36 para el botón de parada.

void setup() {
  Serial.begin(9600);     // Inicia la comunicación serie a 9600 baudios.
  pinMode(derecha, OUTPUT);  // Configura el pin 'derecha' como salida.
  pinMode(izquierda, OUTPUT); // Configura el pin 'izquierda' como salida.
  pinMode(S1, INPUT);         // Configura el pin S1 como entrada.
  pinMode(S2, INPUT);         // Configura el pin S2 como entrada.
  pinMode(S3, INPUT);         // Configura el pin S3 como entrada.
  pinMode(S4, INPUT);         // Configura el pin S4 como entrada.
  pinMode(START, INPUT);      // Configura el pin START como entrada.
  pinMode(STOP, INPUT);       // Configura el pin STOP como entrada.
}

void loop() {
  if (digitalRead(START)) {   // Si se presiona el botón de inicio (START)...
    if (digitalRead(STOP)) {  // ... y si también se presiona el botón de parada (STOP), va al final.
      goto end;
    }

    // Movimiento hacia la derecha mientras el sensor S1 está bajo.
    while (digitalRead(S1) == LOW) {
      digitalWrite(derecha, HIGH);  // Activa el movimiento hacia la derecha.
      if (digitalRead(STOP)) {      // Si se presiona STOP, desactiva el movimiento y va al final.
        digitalWrite(derecha, LOW);
        goto end;
      }
    }

    if (digitalRead(STOP)) {  // Si se presiona STOP, va al final.
      goto end;
    }

    digitalWrite(derecha, LOW);  // Detiene el movimiento hacia la derecha.
    delay(3000);                 // Espera 3 segundos.

    if (digitalRead(STOP)) {     // Si se presiona STOP, va al final.
      goto end;
    }

    // Movimiento hacia la izquierda mientras el sensor S4 está bajo.
    while (digitalRead(S4) == LOW) {
      digitalWrite(izquierda, HIGH);  // Activa el movimiento hacia la izquierda.
      if (digitalRead(STOP)) {        // Si se presiona STOP, desactiva el movimiento y va al final.
        digitalWrite(izquierda, LOW);
        goto end;
      }
    }

    digitalWrite(izquierda, LOW);  // Detiene el movimiento hacia la izquierda.

    if (digitalRead(STOP)) {       // Si se presiona STOP, va al final.
      goto end;
    }

    // Movimiento hacia la derecha mientras el sensor S2 está bajo.
    while (digitalRead(S2) == LOW) {
      digitalWrite(derecha, HIGH);  // Activa el movimiento hacia la derecha.
      if (digitalRead(STOP)) {      // Si se presiona STOP, desactiva el movimiento y va al final.
        digitalWrite(derecha, LOW);
        goto end;
      }
    }

    digitalWrite(derecha, LOW);  // Detiene el movimiento hacia la derecha.

    if (digitalRead(STOP)) {     // Si se presiona STOP, va al final.
      goto end;
    }

    // Repetir el movimiento de izquierda a derecha 3 veces.
    for (int i = 0; i < 3; i++) {
      if (digitalRead(STOP)) {    // Si se presiona STOP, va al final.
        goto end;
      }

      while (digitalRead(S4) == LOW) {  // Movimiento hacia la izquierda mientras el sensor S4 está bajo.
        digitalWrite(izquierda, HIGH);
        if (digitalRead(STOP)) {        // Si se presiona STOP, desactiva el movimiento y va al final.
          digitalWrite(izquierda, LOW);
          goto end;
        }
      }

      digitalWrite(izquierda, LOW);  // Detiene el movimiento hacia la izquierda.

      if (digitalRead(STOP)) {       // Si se presiona STOP, va al final.
        goto end;
      }

      while (digitalRead(S2) == LOW) {  // Movimiento hacia la derecha mientras el sensor S2 está bajo.
        digitalWrite(derecha, HIGH);
        if (digitalRead(STOP)) {        // Si se presiona STOP, desactiva el movimiento y va al final.
          digitalWrite(derecha, LOW);
          goto end;
        }
      }

      digitalWrite(derecha, LOW);  // Detiene el movimiento hacia la derecha.

      if (digitalRead(STOP)) {     // Si se presiona STOP, va al final.
        goto end;
      }
    }

    if (digitalRead(STOP)) {     // Si se presiona STOP, va al final.
      goto end;
    }

    // Movimiento hacia la izquierda mientras el sensor S3 está bajo.
    while (digitalRead(S3) == LOW) {
      digitalWrite(izquierda, HIGH);  // Activa el movimiento hacia la izquierda.
      if (digitalRead(STOP)) {        // Si se presiona STOP, desactiva el movimiento y va al final.
        digitalWrite(izquierda, LOW);
        goto end;
      }
    }

    digitalWrite(izquierda, LOW);  // Detiene el movimiento hacia la izquierda.

    if (digitalRead(STOP)) {       // Si se presiona STOP, va al final.
      goto end;
    }
  }

end:
  delay(1);  // Espera un milisegundo antes de reiniciar el ciclo.
}
