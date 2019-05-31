int Pinbuzzer = 9; //PINO UTILIZADO PELO BUZZER
int Pinled = 7; //PINO UTILIZADO PELO LED
int PinA0 = A0;//PINO UTILIZADO PELO SENSOR DE GÁS MQ-2

int leitura_sensor_baixo = 300;//DEFININDO UM VALOR LIMITE PARA NIVEL BAIXO DE GÁS 
int leitura_sensor_alto = 800; //DEFININDO UM VALOR LIMITE PARA NIVEL ALTO DE GÁS 

void setup() {
  pinMode(PinA0, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(Pinbuzzer, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(Pinled, OUTPUT); //DEFINE O PINO COMO SAÍDA
  Serial.begin(9600);//INICIALIZA A SERIAL
}
void loop() {
  int valor_analogico = analogRead(PinA0); //VARIÁVEL RECEBE O VALOR LIDO NO PINO ANALÓGICO
  Serial.print("Leitura: "); //EXIBE O TEXTO NO MONITOR SERIAL
  Serial.println(valor_analogico);// MOSTRA NO MONITOR SERIAL O VALOR LIDO DO PINO ANALÓGICO
  if (valor_analogico > leitura_sensor_baixo && valor_analogico < leitura_sensor_alto) { //SE VALOR LIDO NO PINO ANALÓGICO FOR MAIOR QUE O VALOR LIMITE PARA BAIXO E MAIOR QUE O VALOR LIMITE PARA ALTO
    digitalWrite(Pinled, HIGH); //ACENDE O LED
    tone(Pinbuzzer, 300); //ACIONA O BUZZER
    delay(1000); //ESPERA 1 SEGUNDO
    noTone(Pinbuzzer); //PARA O BUZZER
    digitalWrite(Pinled, LOW); //DESLIGA O LED
    delay(1000);
  }
  else if(valor_analogico > leitura_sensor_alto){
    digitalWrite(Pinled, HIGH);
    tone(Pinbuzzer, 500);
    delay(200);
    noTone(Pinbuzzer);
    digitalWrite(Pinled, LOW);
    delay(200);
  }
  else { 
    digitalWrite(Pinled, LOW);//LED DESLIGADO
    noTone(Pinbuzzer); //BUZZER DESLIGADO
  }
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
}
