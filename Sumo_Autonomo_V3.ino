// Projeto: Robo Sumo Autonomo
// Programador: Thiago Ramos Bernardo
//Número 1 eh preto // 0 branco
//Biblioteca Ultrassonico
#include <Ultrasonic.h>
//Portas Ultrassonico
#define PIN_TRIG 3
#define PIN_ECHO 2
//Definindo Trig e Echo
Ultrasonic Sumo_Main(PIN_TRIG, PIN_ECHO);
//PWM:
int ENA = 11 ; int ENB = 6;
//Motores DC na ponte H

int IN1 = 10; int IN2 = 9; int IN3 = 8; int IN4 = 7;
//Sensores de cor:
int IR_COR1 = 5; int IR_COR2 = 4; // 2   12
void setup() {
  Serial.begin(9600);

  //Define os pinos da Ponte H
  pinMode(ENA, OUTPUT);  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);  pinMode(IN2, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);

  //Define as entradas digitais
  pinMode(IR_COR1, INPUT); pinMode(IR_COR2, INPUT);

}

void loop() {
    delay(2000);
  long Dist_1 = Sumo_Main.Ranging(CM);
  long Dist_2 = Sumo_Main.Ranging(CM);
  long Dist_3 = Sumo_Main.Ranging(CM);
  long Dist_4 = Sumo_Main.Ranging(CM);
  long Dist_T = (((Dist_1) + (Dist_2) + (Dist_3)) / 3);
  //Serial.println(Dist_T);
  int S_IR_COR1 = digitalRead(IR_COR1);
  int S_IR_COR2 = digitalRead(IR_COR2);
//  analogWrite(ENA, 255);
//  digitalWrite(IN3, HIGH); //Motor B - Lado direito
//  digitalWrite(IN4, LOW);
//  delay(25);
//  analogWrite(ENB, 255);
//  digitalWrite(IN1, HIGH); //Motor A - Lado esquerdo
//  digitalWrite(IN2, LOW);
//  delay(500);
//  analogWrite(ENA, 255);
//  digitalWrite(IN3, HIGH); //Motor B - Lado direito
//  digitalWrite(IN4, LOW);
//  delay(25);
//  analogWrite(ENB, 255);
//  digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
//  digitalWrite(IN2, HIGH);

      if ((S_IR_COR2 == 0) && (S_IR_COR2 == 0)) {
        analogWrite(ENA, 255);
        digitalWrite(IN3, HIGH); //Motor B - Lado direito
        digitalWrite(IN4, LOW);
        delay(25);
        analogWrite(ENB, 255);
        digitalWrite(IN1, HIGH); //Motor A - Lado esquerdo
        digitalWrite(IN2, LOW);
        delay(250);
        analogWrite(ENA, 255);
        digitalWrite(IN3, HIGH); //Motor B - Lado direito
        digitalWrite(IN4, LOW);
        delay(25);
        analogWrite(ENB, 255);
        digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
        digitalWrite(IN2, LOW);
  
        //    delay(500);
      } else if ((S_IR_COR2 == 1) && (S_IR_COR2 == 0)) {
        analogWrite(ENA, 255);
        digitalWrite(IN3, HIGH); //Motor B - Lado direito
        digitalWrite(IN4, LOW);
        delay(25);
        analogWrite(ENB, 255);
        digitalWrite(IN1, HIGH); //Motor A - Lado esquerdo
        digitalWrite(IN2, LOW);
        //delay(500);
      } else if ((S_IR_COR2 == 0) && (S_IR_COR2 == 1)) {
        analogWrite(ENA, 255);
        digitalWrite(IN3, HIGH); //Motor B - Lado direito
        digitalWrite(IN4, LOW);
        delay(25);
        analogWrite(ENB, 255);
        digitalWrite(IN1, HIGH); //Motor A - Lado esquerdo
        digitalWrite(IN2, LOW);
        //    delay(500);
      } else if ((S_IR_COR2 == 1) && (S_IR_COR2 == 1)) {
        if (Dist_T > 50) {
          analogWrite(ENA, 255);
          digitalWrite(IN3, LOW); //Motor B - Lado direito
          digitalWrite(IN4, HIGH);
          delay(25);
          analogWrite(ENB, 255);
          digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
          digitalWrite(IN2, HIGH);
        } else {
          analogWrite(ENA, 255);
          digitalWrite(IN3, LOW); //Motor B - Lado direito
          digitalWrite(IN4, HIGH);
          delay(25);
          analogWrite(ENB, 255);
          digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
          digitalWrite(IN2, HIGH);
          //     delay(4000);
        }
      }

}
