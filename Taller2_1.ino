#define derecha 22
#define izquierda 23
#define S1 30
#define S2 31
#define S3 32
#define S4 33
#define START 35
#define STOP 36

void setup() {
  Serial.begin(9600);
  pinMode(derecha, OUTPUT);
  pinMode(izquierda, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(START, INPUT);
  pinMode(STOP, INPUT);
}

void loop() {

  if (digitalRead(START)) {

    if (digitalRead(STOP)) {
      goto end;
    }

    while (digitalRead(S1) == LOW) {
      digitalWrite(derecha, HIGH);

      if (digitalRead(STOP)) {
        digitalWrite(derecha, LOW);
        goto end;
      }
    }

    if (digitalRead(STOP)) {
      goto end;
    }

    digitalWrite(derecha, LOW);

    delay(3000);

    if (digitalRead(STOP)) {
      goto end;
    }

    while (digitalRead(S4) == LOW) {
      digitalWrite(izquierda, HIGH);
      if (digitalRead(STOP)) {
        digitalWrite(izquierda, LOW);
        goto end;
      }
    }

    digitalWrite(izquierda, LOW);

    if (digitalRead(STOP)) {
      goto end;
    }

    while (digitalRead(S2) == LOW) {
      digitalWrite(derecha, HIGH);
      if (digitalRead(STOP)) {
        digitalWrite(derecha, LOW);
        goto end;
      }
    }


    digitalWrite(derecha, LOW);
    if (digitalRead(STOP)) {
      goto end;
    }


    for (int i = 0; i < 3; i++) {
      if (digitalRead(STOP)) {
        goto end;
      }
      while (digitalRead(S4) == LOW) {
        digitalWrite(izquierda, HIGH);
        if (digitalRead(STOP)) {
          digitalWrite(izquierda, LOW);
          goto end;
        }
      }
      digitalWrite(izquierda, LOW);

      if (digitalRead(STOP)) {
        goto end;
      }

      while (digitalRead(S2) == LOW) {
        digitalWrite(derecha, HIGH);
        if (digitalRead(STOP)) {
          digitalWrite(derecha, LOW);
          goto end;
        }
      }

      digitalWrite(derecha, LOW);

      if (digitalRead(STOP)) {
        goto end;
      }
    }

    if (digitalRead(STOP)) {
      goto end;
    }

    while (digitalRead(S3) == LOW) {
      digitalWrite(izquierda, HIGH);
      if (digitalRead(STOP)) {
         digitalWrite(izquierda, LOW);
        goto end;
      }
    }
    
    digitalWrite(izquierda, LOW);
    if (digitalRead(STOP)) {
      goto end;
    }
  }

end:
  delay(1);
}
