#include <Servo.h>

int eixo_X= A1; //PINO REFERENTE A LIGAÇÃO DO EIXO X
int eixo_Y = A0; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
int botao = 2; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)

Servo servoX;
Servo servoY;

int val = 0;

void setup(){
  pinMode (botao, INPUT_PULLUP); //DEFINE A PORTA COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  Serial.begin (9600); //INICIALIZA O MONITOR SERIAL

  servoX.attach(6);
  servoY.attach(5);

  servoX.write(90);
  servoY.write(90);

}

void loop() {
  // put your main code here, to run repeatedly
  servoX.write(val);
  analogWrite(6, val);
  
  servoY.write(val);
  analogWrite(6, val);

    
  delay(100);
  val = val+5;
  Serial.println(val);
  if (val==180){
    val = 0;
  }
  delay(15);
}
