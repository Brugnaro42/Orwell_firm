#include <Servo.h>

Servo servo1;
int angulo = 0;
int eixo_X= A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
int eixo_Y = A1; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
int botao = 2; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)

void setup() {
  // put your setup code here, to run once:
  servo1.attach(6);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  servo1.write(angulo);
  delay(100);
  angulo = angulo+5;
  Serial.println(angulo);
  if (angulo==180){
    angulo = 0;
  }
  delay(15);
//      if((analogRead(eixo_X)) == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
//      Serial.println("PARA BAIXO"); //IMPRIME O TEXTO NO MONITOR SERIAL
//    }else{
//          if((analogRead(eixo_X)) == 1023){ //SE LEITURA FOR IGUAL A 1023, FAZ
//              Serial.println("PARA CIMA"); //IMPRIME O TEXTO NO MONITOR SERIAL
//          }else{
//                if((analogRead(eixo_Y)) == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
//                  Serial.println("ESQUERDA"); //IMPRIME O TEXTO NO MONITOR SERIAL
//               }else{
//                      if((analogRead(eixo_Y)) == 1023){ //SE LEITURA FOR IGUAL A 1023, FAZ
//                        Serial.println("DIREITA"); //IMPRIME O TEXTO NO MONITOR SERIAL
//                      }else{
//                            if(digitalRead(botao) == LOW){ //SE LEITURA FOR IGUAL A HIGH, FAZ
//                               Serial.println("BOTAO PRESSIONADO"); //IMPRIME O TEXTO NO MONITOR SERIAL
//                            }  
//                      }
//                }
//          }
//    }
//    delay(50); //INTERVALO DE 500 MILISSEGUNDOS
}
