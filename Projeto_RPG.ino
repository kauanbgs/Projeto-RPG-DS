#define pinLed1 8
#define pinLed2 9
#define pinLed3 10
#define pinLed4 11
#define button1 2
#define button2 3
#define button3 4
#define buttonFunction 5

int estado = 0;






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
  delay(1000);
}

void loop() {
  digitalWrite(pinLed4, 0);
  if (digitalRead(buttonFunction) == 1) { // Botão é pressionado
    delay(200); // Debounce
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
    // Função 1
  } 
  else if (estado == 2) {
    // Função 2
  } 
  else if (estado == 3) {
    // Função 3
  }
}

// void function_selector (void) {
//   if 
// }

void dice (int delay_piscada){

    while(true){
      if(digitalRead(button1) == 1){
      digitalWrite(pinLed4, 0);
      delay(700);

      int randomNumber = random(1,7);
      
      Serial.print("O D6 rolou: ");
      Serial.println(randomNumber);

      for(int i = 0; i < randomNumber; i++){
        digitalWrite(pinLed1, 1);
        delay(delay_piscada);
        digitalWrite(pinLed1, 0);
        delay(delay_piscada);
      }
      delay(500);

    }

    else if(digitalRead(button2) == 1) {
      digitalWrite(pinLed4, 0);
      delay(700);
      int randomNumber = random(1,11);
      
      Serial.print("O D10 rolou: ");
      Serial.println(randomNumber);

      for(int i = 0; i < randomNumber; i++){
        digitalWrite(pinLed2, 1);
        delay(delay_piscada);
        digitalWrite(pinLed2, 0);
        delay(delay_piscada);
      }
      delay(500);

    }
    else if(digitalRead(button3) == 1) {
      digitalWrite(pinLed4, 0);
      delay(700);
      int randomNumber = random(1,21);
      
      Serial.print("O D20 rolou: ");
      Serial.println(randomNumber);

      for(int i = 0; i < randomNumber; i++){
        digitalWrite(pinLed3, 1);
        delay(delay_piscada);
        digitalWrite(pinLed3, 0);
        delay(delay_piscada);
      }
      delay(500);
    }
    else if(digitalRead(buttonFunction) == 1){
      break;
    }
    else{
      digitalWrite(pinLed4, 1);
    }
  }

}