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

void loop(){
//  // analogWrite(servoX_port, val);
//  servoX.write(val);
//  // analogWrite(servoY_port, val);
//  servoY.write(val);
//    delay(100);
//  val = val+5;
//  if (val==180){
//    val = 0;
//  }

  
   if (analogRead(eixo_X) < 330){
     Serial.println("ESQUERDA"); //IMPRIME O TEXTO NO MONITOR SERIAL;
     servoX.write(0);
   }
   else if (analogRead(eixo_X) > 370){
     Serial.println("DIREITA"); //IMPRIME O TEXTO NO MONITOR SERIAL;
     servoX.write(180);
   }
   else if (analogRead(eixo_Y) < 330){
     Serial.println("BAIXO"); //IMPRIME O TEXTO NO MONITOR SERIAL;
     servoY.write(180);
   }
   else if (analogRead(eixo_Y) > 370){
     Serial.println("CIMA"); //IMPRIME O TEXTO NO MONITOR SERIAL;
     servoY.write(0);
   }
   else if(digitalRead(botao) == LOW){ //SE LEITURA FOR IGUAL A HIGH, FAZ
     Serial.println("RESET POSICOES"); //IMPRIME O TEXTO NO MONITOR SERIAL
     servoX.write(90);
     servoY.write(90);

   }  
   else{
     Serial.print(analogRead(eixo_X)); //IMPRIME O TEXTO NO MONITOR SERIAL;
     Serial.print(" - "); //IMPRIME O TEXTO NO MONITOR SERIAL;
     Serial.println(analogRead(eixo_Y)); //IMPRIME O TEXTO NO MONITOR SERIAL;
   }

    delay(1000); //INTERVALO DE 500 MILISSEGUNDOS
}
