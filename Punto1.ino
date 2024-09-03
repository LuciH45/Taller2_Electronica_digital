#define DERECHA 22
#define IZQUIERDA 23
#define S1 30
#define S2 31
#define S3 32
#define S4 33
#define START 27
#define STOP 26
int t_1;
int t_2;

void setup() {
  Serial.begin(9600);
  pinMode(DERECHA, OUTPUT);
  pinMode(IZQUIERDA, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(START, INPUT);
  pinMode(STOP, INPUT);
}

void loop() {
  // Por defecto, la banda tiene que estar quieta
  digitalWrite(IZQUIERDA, LOW);
  digitalWrite(DERECHA, LOW);

 // Esperamos a que el botón START sea presionado. Si el bloque no esta en S1, este se tiene que mover a la derecha
  while(true) {
    if (digitalRead(START) == HIGH) {
      if (digitalRead(S1) == LOW) {
        digitalWrite(DERECHA, HIGH);
      }
      break;
    }
  }

  // Esperamos a que el bloque llegue a S1 para que se comienze a mover a la izquierda
  // En caso de presionar el botón STOP, el proceso se finaliza (se detiene).
  while(true) {
    if (digitalRead(S1) == HIGH) {
      digitalWrite(DERECHA, LOW);
      // Aquí se podría pensar que deberíamos usar delay(3000), pero en el caso que se pulse STOP mientras pasan los 3 segundos, pues el proceso
      // tendría que volver a comenzar. Por esto se coloca manualmente.
      t_1 = millis();
      t_2 = t_1;
      while (t_2 - t_1 < 3000) {
        t_2 = millis();
        if (digitalRead(STOP) == HIGH) {
          loop();
        }
      }
      digitalWrite(IZQUIERDA, HIGH);
      break;
    } else if (digitalRead(STOP) == HIGH) {
      loop();
    }
  }

  // El bloque va desde S1 a S4 y luego de S4 a S2 (i=1). Luego, se repite este proceso tres veces (i=1, i=2, i=3).
  // En caso de presionar el botón STOP, el proceso se finaliza (se detiene).
  for (int i = 0; i < 4; i++) {
    while(true) {
      if (digitalRead(S4) == HIGH) {
        digitalWrite(IZQUIERDA, LOW);
        digitalWrite(DERECHA, HIGH);
        break;
      } else if (digitalRead(STOP) == HIGH) {
        loop();
      }
    }
    while(true) {
      if (digitalRead(S2) == HIGH) {
        digitalWrite(DERECHA, LOW);
        digitalWrite(IZQUIERDA, HIGH);
        break;
      } else if (digitalRead(STOP) == HIGH) {
        loop();
      }
    }
  }

  // Cuando el bloque llega a S3, el proceso se finaliza (se detiene).
  while(true) {
    if (digitalRead(S3) == HIGH) {
      digitalWrite(IZQUIERDA, LOW);
      loop();
    }
  }

}

