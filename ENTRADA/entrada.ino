int ledPin = 6; 
int buzzer = 5;
int sensorPin = 7; 
int leitura = 0; //Variável para armazenar a leitura do sensor
bool estadoSensor = false; //Variável para armazenar o estado do sensor

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
    if (Serial.available() > 0) {
      char recive = Serial.read();

    
      if (recive == 'P') {
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        
      }
    }
    delay(1000); 

  } else { //Se leitura for igual a LOW, não houve movimento detectado e desliga o led após os 5s
    digitalWrite(ledPin, LOW);
    if (estadoSensor == true) { //Compara o valor de estado do LED
      
      estadoSensor = false; //Altera o valor de estadoSensor para HIGH
    }
  }

}
