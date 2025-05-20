int ledPin = 6; 
int buzzer = 5;
int sensorPin = 7; 
int leitura = 0; //Variável para armazenar a leitura do sensor
bool estadoSensor = false; //Variável para armazenar o estado do sensor
char recive = Serial.read();

void setup() {
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzer, OUTPUT);
  pinMode(sensorPin, INPUT); 
}

void loop() {
  leitura = digitalRead(sensorPin); 

  if (leitura == HIGH) { //Se leitura for igual a HIGH, o movimento foi detectado e liga o led

    if (estadoSensor == false) { //Compara o valor de estado do LED
      Serial.println("Movimento detectado"); //Imprime a mensagem no monitor serial
      estadoSensor = true; //Altera o valor de estadoSensor para HIGH
    }
    delay(5000); 

  } else { //Se leitura for igual a LOW, não houve movimento detectado e desliga o led após os 5s
    digitalWrite(ledPin, LOW);
    if (estadoSensor == true) { //Compara o valor de estado do LED
      Serial.println("Sem movimento"); //Imprime a mensagem no monitor serial
      estadoSensor = false; //Altera o valor de estadoSensor para HIGH
    }
  }
  if (recive == "P") {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
  }
}