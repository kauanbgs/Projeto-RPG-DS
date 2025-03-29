#define pinLed1 8
#define pinLed2 9
#define pinLed3 10
#define pinLed4 11
#define button1 2
#define button2 3
#define button3 4
#define buttonFunction 5
#define buzzer 6

int estado = 0;
int personagem = 1;
int vida1 = 100;
int vida2 = 100;
int vida3 = 100;
int vida4 = 100;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(buttonFunction, INPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(buzzer, OUTPUT);
  delay(1000);
}

void loop() {
  // Apagar leds antes de mudar de estado/função
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);

  if (digitalRead(buttonFunction) == HIGH) { 
    delay(200);
    estado++;
    if (estado > 3) {
      estado = 0;
    }
    Serial.print("Modo alterado para: ");
    Serial.println(estado);
  }

  if (estado == 0) {
    dice(350);
  } 
  else if (estado == 1) {
    actions(1800);
  } 
  else if (estado == 2) {
    vida_func();
  }
  else if (estado == 3) {
    // Função 3
  }
}

void vida_func(void){
  // Se botão for pressionado, troca de personagem
  if (digitalRead(button1) == HIGH) { 
    personagem++;
    if (personagem > 4) personagem = 1;
    Serial.print("Selecionado: Personagem ");
    Serial.println(personagem);
    delay(300);
    for (int i = 0; i < personagem; i++) {
      digitalWrite(pinLed2, HIGH);   // Acende o LED
      delay(250);                    // Mantém o LED aceso por 250 ms
      digitalWrite(pinLed2, LOW);    // Apaga o LED
      delay(250);                    // Mantém o LED apagado por 250 ms
    }
  }

  if(personagem == 1){
    if(digitalRead(button3) == HIGH){
      vida1 -= 10;
      if(vida1 < 0) vida1 = 0;
      Serial.print("PERSO 1: Sua vida e: ");
      Serial.println(vida1);
      delay(300);
    }
    else if(digitalRead(button2) == HIGH){
      vida1 += 10;
      if(vida1 > 100) vida1 = 100;
      Serial.print("PERSO 1: Sua vida e: ");
      Serial.println(vida1);
      delay(300);
    

    }

  if(vida1 > 70){
    digitalWrite(pinLed4, HIGH);  // LED verde (vida alta)
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed1, LOW);
  }
  else if(vida1 >= 40){
    digitalWrite(pinLed3, HIGH);  // LED amarelo (vida média)
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed1, LOW);
  }
  else if(vida1 > 0){
    digitalWrite(pinLed1, HIGH);  // LED vermelho (vida baixa)
    digitalWrite(pinLed4, LOW); 
    digitalWrite(pinLed3, LOW);
  }
  else {
    // Se a vida for muito baixa, apaga todos os LEDs
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
  }
}


  else if(personagem == 2){
    if(digitalRead(button3) == HIGH){
      vida2 -= 10;
      if(vida2 < 0) vida2 = 0;
      Serial.print("PERSO 2: Sua vida e: ");
      Serial.println(vida2);
      delay(300);
    }
    else if(digitalRead(button2) == HIGH){
      vida2 += 10;
      if(vida2 > 100) vida2 = 100;
      Serial.print("PERSO 2: Sua vida e: ");
      Serial.println(vida2);
      delay(300);
    }
  if(vida2 > 70){
    digitalWrite(pinLed4, HIGH);  // LED verde (vida alta)
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed1, LOW);
  }
  else if(vida2 >= 40){
    digitalWrite(pinLed3, HIGH);  // LED amarelo (vida média)
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed1, LOW);
  }
  else if(vida2 > 0){
    digitalWrite(pinLed1, HIGH);  // LED vermelho (vida baixa)
    digitalWrite(pinLed4, LOW); 
    digitalWrite(pinLed3, LOW);
  }
  else {
    // Se a vida for muito baixa, apaga todos os LEDs
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
  }
  }

  else if(personagem == 3){
    if(digitalRead(button3) == HIGH){
      vida3 -= 10;
      if(vida3 < 0) vida3 = 0;
      Serial.print("PERSO 3: Sua vida e: ");
      Serial.println(vida3);
      delay(300);
    }
    else if(digitalRead(button2) == HIGH){
      vida3 += 10;
      if(vida3 > 100) vida3 = 100;
      Serial.print("PERSO 3: Sua vida e: ");
      Serial.println(vida3);
      delay(300);
    }
  if(vida3 > 70){
    digitalWrite(pinLed4, HIGH);  // LED verde (vida alta)
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed1, LOW);
  }
  else if(vida3 >= 40){
    digitalWrite(pinLed3, HIGH);  // LED amarelo (vida média)
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed1, LOW);
  }
  else if(vida3 > 0){
    digitalWrite(pinLed1, HIGH);  // LED vermelho (vida baixa)
    digitalWrite(pinLed4, LOW); 
    digitalWrite(pinLed3, LOW);
  }
  else {
    // Se a vida for muito baixa, apaga todos os LEDs
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
  }
  }

  else if(personagem == 4){
    if(digitalRead(button3) == HIGH){
      vida4 -= 10;
      if(vida4 < 0) vida4 = 0;
      Serial.print("PERSO 4: Sua vida e: ");
      Serial.println(vida4);
      delay(300);
    }
    else if(digitalRead(button2) == HIGH){
      vida4 += 10;
      if(vida4 > 100) vida4 = 100;
      Serial.print("PERSO 4: Sua vida e: ");
      Serial.println(vida4);
      delay(300);
    }
  if(vida4 > 70){
    digitalWrite(pinLed4, HIGH);  // LED verde (vida alta)
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed1, LOW);
  }
  else if(vida4 >= 40){
    digitalWrite(pinLed3, HIGH);  // LED amarelo (vida média)
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed1, LOW);
  }
  else if(vida4 > 0){
    digitalWrite(pinLed1, HIGH);  // LED vermelho (vida baixa)
    digitalWrite(pinLed4, LOW); 
    digitalWrite(pinLed3, LOW);
  }
  else {
    // Se a vida for muito baixa, apaga todos os LEDs
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
  }
  }


}

void actions(int tempo_ligado){
  while(true){
    digitalWrite(pinLed3, HIGH); 

    if(digitalRead(buttonFunction) == HIGH){
      break;
    }

    if(digitalRead(button1) == HIGH){
      int randomNumber = random(1, 21);

      if(randomNumber >= 10){
        Serial.print("Sucesso no ataque! PARA TESTES, TIROU: ");
        Serial.println(randomNumber);
        digitalWrite(pinLed4, HIGH);
        tone(buzzer, 800);
        delay(tempo_ligado);
        digitalWrite(pinLed4, LOW);
        noTone(buzzer);
      }
      else{
        Serial.print("Falha no ataque! PARA TESTES, TIROU: ");
        Serial.println(randomNumber);
        digitalWrite(pinLed1, HIGH);
        tone(buzzer, 400);
        delay(tempo_ligado);
        digitalWrite(pinLed1, LOW);
        noTone(buzzer);
      }
    }

    if(digitalRead(button2) == HIGH){
      int randomNumber = random(1, 21);

      if(randomNumber >= 10){
        Serial.print("Sucesso na defesa! PARA TESTES, TIROU: ");
        Serial.println(randomNumber);
        digitalWrite(pinLed4, HIGH);
        tone(buzzer, 800);
        delay(tempo_ligado);
        digitalWrite(pinLed4, LOW);
        noTone(buzzer);
      }
      else{
        Serial.print("Falha na defesa! PARA TESTES, TIROU: ");
        Serial.println(randomNumber);
        digitalWrite(pinLed1, HIGH);
        tone(buzzer, 400);
        delay(tempo_ligado);
        digitalWrite(pinLed1, LOW);
        noTone(buzzer);
      }
    }

    if(digitalRead(button3) == HIGH){
      int randomNumber = random(1, 21);

      if(randomNumber >= 10){
        Serial.print("Sucesso na interacao! PARA TESTES, TIROU: ");
        Serial.println(randomNumber);
        digitalWrite(pinLed4, HIGH);
        tone(buzzer, 800);
        delay(tempo_ligado);
        digitalWrite(pinLed4, LOW);
        noTone(buzzer);
      }
      else{
        Serial.print("Falha na interacao! PARA TESTES, TIROU: ");
        Serial.println(randomNumber);
        digitalWrite(pinLed1, HIGH);
        tone(buzzer, 400);
        delay(tempo_ligado);
        digitalWrite(pinLed1, LOW);
        noTone(buzzer);
      }
    }
  }
}

void dice(int delay_piscada){
  while(true){
    if(digitalRead(buttonFunction) == HIGH){
      break;
    }

    if(digitalRead(button1) == HIGH){
      digitalWrite(pinLed4, LOW);
      delay(700);

      int randomNumber = random(1, 7);
      
      Serial.print("O D6 rolou: ");
      Serial.println(randomNumber);

      for(int i = 0; i < randomNumber; i++){
        tone(buzzer, 600);
        digitalWrite(pinLed1, HIGH);
        delay(delay_piscada);
        noTone(buzzer);
        digitalWrite(pinLed1, LOW);
        delay(delay_piscada);
      }
      delay(500);
    }
    else if(digitalRead(button2) == HIGH) {
      digitalWrite(pinLed4, LOW);
      delay(700);
      int randomNumber = random(1, 11);
      
      Serial.print("O D10 rolou: ");
      Serial.println(randomNumber);

      for(int i = 0; i < randomNumber; i++){
        tone(buzzer, 600);
        digitalWrite(pinLed2, HIGH); 
        delay(delay_piscada);
        noTone(buzzer);
        digitalWrite(pinLed2, LOW);
        delay(delay_piscada);
      }
      delay(500);
    }
    else if(digitalRead(button3) == HIGH) {
      digitalWrite(pinLed4, LOW);
      delay(700);
      int randomNumber = random(1, 21);
      
      Serial.print("O D20 rolou: ");
      Serial.println(randomNumber);

      for(int i = 0; i < randomNumber; i++){
        tone(buzzer, 600);
        digitalWrite(pinLed3, HIGH); 
        delay(delay_piscada);
        noTone(buzzer);
        digitalWrite(pinLed3, LOW);
        delay(delay_piscada);
      }
      delay(500);
    }
    else if(digitalRead(buttonFunction) == HIGH){
      break;
    }
    else{
      digitalWrite(pinLed4, HIGH); 
    }
  }
}
