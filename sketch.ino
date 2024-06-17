#include <LiquidCrystal_I2C.h>

#define TRIGGER_PIN1  3  
#define ECHO_PIN1     2  
#define TRIGGER_PIN2  5 
#define ECHO_PIN2     4  
#define velocidadesom 0.034 

LiquidCrystal_I2C lcd(0x27, 16, 2);  

unsigned long tempo1;
unsigned long tempo2;
float velocidade;

void setup() {
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight(); 

  pinMode(TRIGGER_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIGGER_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
}

float calcdistancia(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Calcula o tempo de retorno do pulso
  long duracao = pulseIn(echoPin, HIGH);
  
  // Calcula a distância em cm
  float distancia = duracao * velocidadesom / 2;
  
  return distancia;
}

void loop() {
  delay(1000); 
  
  // Primeiro sensor
  tempo1 = millis();
  float distancia1 = calcdistancia(TRIGGER_PIN1, ECHO_PIN1);
  Serial.print("Distancia 1: ");
  Serial.print(distancia1);
  Serial.println(" cm");
  
  delay(1000); 
  
  // Segundo sensor
  tempo2 = millis();
  float distancia2 = calcdistancia(TRIGGER_PIN2, ECHO_PIN2);
  Serial.print("Distancia 2: ");
  Serial.print(distancia2);
  Serial.println(" cm");
  
  delay(1000); 

  // v = d/t
  if (distancia1 > 0 && distancia2 > 0) {
    float tempo = (tempo2 - tempo1) / 1000.0; 
    float distancia = distancia2 - distancia1;
    velocidade = distancia / tempo; 
    
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("Velocidade: ");
    lcd.setCursor(0, 1);  
    lcd.print(velocidade);
    lcd.print(" cm/s");

    Serial.print("Velocidade: ");
    Serial.print(velocidade);
    Serial.println(" cm/s");
  } else {

    Serial.println("Erro: Distancias invalidas");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro nas leituras");
  }
}
