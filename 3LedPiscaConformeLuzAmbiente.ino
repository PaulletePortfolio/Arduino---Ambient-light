int buzzer = 8; 
int led1 = 10;
int led2 = 9;
int led3 = 11; 
int portaLDR = A5; 
int valorsensor;    

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
}

void loop() {
  valorsensor = analogRead(portaLDR); 
  Serial.print("LDR : ");   
  Serial.println(valorsensor);

  if (valorsensor < 500) {     
    digitalWrite(led1, HIGH);  
  } else {                   
    digitalWrite(led1, LOW);   
  }
  delay(100);   

  if (valorsensor < 350) {     
    digitalWrite(led2, HIGH);  
  } else {                   
    digitalWrite(led2, LOW);   
  }
  delay(100); 

  if (valorsensor < 100) {     
    digitalWrite(led3, HIGH);  
  } else {                   
    digitalWrite(led3, LOW);   
  }
  delay(100);             

//MUSIQUINHA ENTRADA CASAMENTO KSKSKKS
   if (valorsensor < 10) {
    int ritmo[] = {392, 392, 523, 392, 523, 659, 523, 392, 659, 523, 392, 659, 523, 392, 659};
    int duracao[] = {200, 200, 400, 200, 400, 600, 200, 200, 400, 200, 200, 400, 200, 200, 400}; 
    int pausa[] = {100, 100, 200, 100, 200, 400, 100, 100, 200, 100, 100, 200, 100, 100, 200}; 

    int totalTime = 0;
    for (int i = 0; i < 15; i++) {
      tone(buzzer, ritmo[i]);
      delay(duracao[i]);
      noTone(buzzer);
      delay(pausa[i]);
      totalTime += duracao[i] + pausa[i];
    }

    if (totalTime < 10000) {
      delay(10000 - totalTime);
    }
  }
}
  


