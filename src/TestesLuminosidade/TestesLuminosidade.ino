int luminosidade = A2;
int leds = 8;
int nLeituras = 0;
int totalLeituras = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leds, OUTPUT);
}

void loop() {
  //digitalWrite(leds, HIGH);

  luminosidade = analogRead(luminosidade);
  Serial.println(luminosidade);
  // put your main code here, to run repeatedly:
  totalLeituras = totalLeituras + luminosidade;
  nLeituras++;
  float media = totalLeituras/nLeituras;
  Serial.print("Média: ");
  Serial.println(media);
  if (luminosidade>=media) {
    digitalWrite(leds, HIGH);
    delay(5000);
    digitalWrite(leds, LOW);
  }
  else {
    digitalWrite(leds, LOW);
  }
  delay(500);
}
