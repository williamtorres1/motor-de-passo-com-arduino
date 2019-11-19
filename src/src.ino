/***********************************************************
*   File:    src.ino                                       *
*   Authors: William Torres     || @williamtorres1         *
*            Arthur Brito       || @ArthurBrito1           *
*            Gabriel Pedro                                 *
*            Guilherme Vinícius || @Swagmaster696969       *
************************************************************/
// definição do tempo mínimo
const int tempoMinimo = 0.000005;

// definição dos pinos   MOTOR 1
const int sentidoRotacaoMotor1 = 3;//pinos
const int clockMotor1 = 2; 
const int enableMotor1 = 4;

// definição dos pinos   MOTOR2
const int sentidoRotacaoMotor2 = 6;//pinos
const int clockMotor2 = 7; 
const int enableMotor2 = 5;


// definição dos pinos   MOTOR3
const int sentidoRotacaoMotor3 = 9;//pinos
const int clockMotor3 = 10; 
const int enableMotor3 = 8;


unsigned int tempo1 = 0;
unsigned int tempo2 = 0;
unsigned int tempo3 = 0;


void setup() {

  tempo1 = millis();
  tempo2 = millis();
  tempo3 = millis();


  
  // Define os dois pinos como Saídas

  /**MOTOR 1**/
  pinMode(sentidoRotacaoMotor1,OUTPUT);
  pinMode(clockMotor1,OUTPUT);
  pinMode(enableMotor1,OUTPUT);
  digitalWrite(enableMotor1,LOW);
  digitalWrite(sentidoRotacaoMotor1,LOW);

  /**MOTOR 2**/
  pinMode(sentidoRotacaoMotor2,OUTPUT);
  pinMode(clockMotor2,OUTPUT);
  pinMode(enableMotor2,OUTPUT);
  digitalWrite(enableMotor2,LOW);
  digitalWrite(sentidoRotacaoMotor2,HIGH);

  /**MOTOR 3**/
  pinMode(sentidoRotacaoMotor3,OUTPUT);
  pinMode(clockMotor3,OUTPUT);
  pinMode(enableMotor3,OUTPUT);
  digitalWrite(enableMotor3,LOW);
  digitalWrite(sentidoRotacaoMotor3,HIGH);

  //Serial.begin(9600);
}
void loop() {
  
  
  unsigned int quantidadeVoltasMotor1 = 50;
  unsigned int quantidadeVoltasMotor2 = 0;
  unsigned int quantidadeVoltasMotor3 = 0;

  unsigned int numeroPulsosMotor1 = 0;
  unsigned int numeroPulsosMotor2 = 0;
  unsigned int numeroPulsosMotor3 = 0;

  unsigned int velocidadeMotor1 = 20;//velocidade em tempo - inverso da frequencia
  unsigned int velocidadeMotor2 = 50;
  unsigned int velocidadeMotor3 = 10;  

//conversao


  numeroPulsosMotor1 = 200 * quantidadeVoltasMotor1;
  numeroPulsosMotor2 = 200 * quantidadeVoltasMotor2;
  numeroPulsosMotor3 = 200 * quantidadeVoltasMotor3;

  while(1)
  {
    if(numeroPulsosMotor1 != 0 )
    {
      if(millis() - tempo1 >= velocidadeMotor1 && (millis() - tempo1) <= (velocidadeMotor1 + 5))
      {
        digitalWrite(clockMotor1,HIGH);
        tempo1 = millis();
      }
      if(millis() - tempo1 >= velocidadeMotor1)
      {
        digitalWrite(clockMotor1,LOW);
        numeroPulsosMotor1--;
      }
      
    }
    if(numeroPulsosMotor2 != 0 )
    {
      if(millis() - tempo2 >= velocidadeMotor2)
      {
        digitalWrite(clockMotor2,HIGH);
        tempo2 = millis();
      }
      if(millis() - tempo2 >= velocidadeMotor2)
      {
        digitalWrite(clockMotor1,LOW);
        numeroPulsosMotor2--;
      }
    }
    if(numeroPulsosMotor3 != 0 )
    {
      if(millis() - tempo3 >= velocidadeMotor3)
      {
        digitalWrite(clockMotor3,HIGH);
        tempo3 = millis();
      }
      if(millis() - tempo3 >= velocidadeMotor3)
      {
        digitalWrite(clockMotor3,LOW);
        numeroPulsosMotor3--;
      }
    }
    if(numeroPulsosMotor1 == 0 && numeroPulsosMotor2 == 0 && numeroPulsosMotor3 == 0)
    {
      digitalWrite(enableMotor1,HIGH);
      digitalWrite(enableMotor2,HIGH);
      digitalWrite(enableMotor3,HIGH);
    }
    
    
  }
  
}
