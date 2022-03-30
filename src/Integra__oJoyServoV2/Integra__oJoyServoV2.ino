#include <Servo.h>

int eixo_X= A1; //PINO REFERENTE AO JOYSTICK LIGAÇÃO DO EIXO X
int eixo_Y = A0; //PINO REFERENTE AO JOYSTICK LIGAÇÃO DO EIXO X
int botao = 2; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)

Servo servoX;
Servo servoY;

int val = 0;

float ang_x, ang_y; 

void setup(){
  pinMode (botao, INPUT_PULLUP); //DEFINE A PORTA COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  Serial.begin (9600); //INICIALIZA O MONITOR SERIAL

  servoX.attach(6);
  servoY.attach(5);

  servoX.write(90);
  servoY.write(90);

}

void loop(){
//  Serial.print(analogRead(eixo_X));
//  Serial.print(" - ");
//  Serial.println(analogRead(eixo_Y));
  joyServo(analogRead(eixo_X), analogRead(eixo_Y));
  delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}

void joyServo(int x_axis, int y_axis){
  // float coeff = 180/1020;
  float coeff = 0.2608695;  // Se 3av  
  //float coeff = 0.1764705882352941; // Se 5V

  if (x_axis < 500 or x_axis > 550){
    ang_x = x_axis*coeff;
    ang_x = ang_x + (ang_x * 0.001);
    servoX.write(ang_x);
  }

  if (y_axis < 500 or y_axis > 550) {
      ang_y = (180 - y_axis*coeff);
      ang_y = ang_y + (ang_y * 0.001);
      servoY.write(ang_y);
  }

  if (digitalRead(botao)==0){
    servoX.write(90);
    servoY.write(90);
  }
  
  Serial.print(coeff);
  Serial.print("-");
  Serial.print(x_axis);
  Serial.print("-");
  Serial.print(y_axis);
  Serial.print(" | ");
  Serial.print(ang_x);
  Serial.print("-");
  Serial.println(ang_y);
}
