int eixo_X= 4;//A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
int eixo_Y = 2;//A1; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
int botao = 15; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)

int val = 0;

void setup(){
  pinMode (botao, INPUT_PULLUP); //DEFINE A PORTA COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  Serial.begin (115200); //INICIALIZA O MONITOR SERIAL

}

void loop(){
  Serial.println("===============");
  Serial.print("Eixo x:");
  Serial.println(analogRead(eixo_X));
  Serial.print("Eixo x:");
  Serial.println(analogRead(eixo_X));
  Serial.print("botao:");
  Serial.println(digitalRead(botao));
  Serial.println("===============");

    delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}
