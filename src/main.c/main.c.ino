
#include <Servo.h>
#include <Console.h>
#define SERVO 6
 

Servo s; // Variável Servo
int pos; // Posição Servo

void setup ()
{
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
  
  Bridge.begin();
  Console.begin();
}

void loop()
{
  /*
    for(pos = 0; pos < 90; pos++)
    {
      s.write(pos);
    delay(15);
    }
      delay(1000);
    for(pos = 90; pos >= 0; pos--)
    {
      s.write(pos);
      delay(15);
    }
  */
  
    if (Console.available() > 0) {


    char c = Console.read(); // read the next char received


    // look for the newline character, this is the last character in the string


    if (c == '\n') {


      //print text with the name received


      Console.print("Hi ");


      Console.print(name);


      Console.println("! Nice to meet you!");


      Console.println();


      // Ask again for name and clear the old name


      Console.println("Hi, what's your name?");


      name = "";  // clear the name string


    } else {     // if the buffer is empty Console.read() returns -1


      name += c; // append the read char from Console to the name string


    }


  } else {


    delay(100);


  }
}
