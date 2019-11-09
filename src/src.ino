/***********************************************************
*   File:    src.ino                                       *
*   Authors: William Torres     || @williamtorres1         *
*            Arthur Brito       || @ArthurBrito1           *
*            Gabriel Pedro                                 *
*            Guilherme Vinícius || @Swagmaster696969       *
***********************************************************/

// definição dos pinos   MOTOR 1
const int sentido_CW1 = 2;//pinos
const int clock1 = 3; 
const int enable1 = 4;

// definição dos pinos   MOTOR2
const int sentido_CW2 = 2;//pinos
const int clock2 = 3; 
const int enable2 = 4;


// definição dos pinos   MOTOR3
const int sentido_CW3 = 2;//pinos
const int clock3 = 3; 
const int enable3 = 4;
void setup() {
  
  // Define os dois pinos como Saídas

  /**MOTOR 1**/
  pinMode(sentido_CW1,OUTPUT);
  pinMode(clock1,OUTPUT);
  pinMode(enable1,OUTPUT);
  digitalWrite(enable1,LOW);

  /**MOTOR 2**/
  pinMode(sentido_CW2,OUTPUT);
  pinMode(clock2,OUTPUT);
  pinMode(enable2,OUTPUT);
  digitalWrite(enable2,LOW);

  /**MOTOR 3**/
  pinMode(sentido_CW3,OUTPUT);
  pinMode(clock3,OUTPUT);
  pinMode(enable3,OUTPUT);
  digitalWrite(enable3,LOW);

  Serial.begin(2600);
}
void loop() {
  
  
  unsigned int quantidade_voltas_motor1 = 0;
  unsigned int quantidade_voltas_motor2 = 0;
  unsigned int quantidade_voltas_motor3 = 0;
  unsigned int numero_pulsos1 = 0;
  unsigned int numero_pulsos2 = 0;
  unsigned int numero_pulsos3 = 0;
  Serial.print("Digite a quantidade de voltas do motor 1: ");
  //quantidade_voltas_motor1 = input

  Serial.print("Digite a quantidade de voltas do motor 2: ");
  //quantidade_voltas_motor2 = input

  Serial.print("Digite a quantidade de voltas do motor 3: ");
  //quantidade_voltas_motor3 = input


  //validação


//conversao


  numero_pulsos1 = 200 * quantidade_voltas_motor1;
  numero_pulsos2 = 200 * quantidade_voltas_motor2;
  numero_pulsos3 = 200 * quantidade_voltas_motor3;



  //loop infinito

  while(1)
  {
    if(numero_pulsos1 != 0 )
    {
      digitalWrite(sentido_CW1,HIGH);
    }
    if(numero_pulsos2 != 0 )
    {
      digitalWrite(sentido_CW2,HIGH);
    }
    if(numero_pulsos3 != 0 )
    {
      digitalWrite(sentido_CW3,HIGH);
    }

    delayMicroseconds(500);

    if(numero_pulsos1 != 0 )
    {
      digitalWrite(sentido_CW1,LOW);
      numero_pulsos1--;
    }
    if(numero_pulsos2 != 0 )
    {
      digitalWrite(sentido_CW2,LOW);
      numero_pulsos2--;
    }
    if(numero_pulsos3 != 0 )
    {
      digitalWrite(sentido_CW3,LOW);
      numero_pulsos3--;
    }
    if(numero_pulsos1 == 0 && numero_pulsos2 == 0 && numero_pulsos3 == 0)
    {
      break;
    }
    
    
  }
  
}
