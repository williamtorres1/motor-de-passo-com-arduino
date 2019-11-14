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
const int sentidoRotacaoMotor1 = 12;//pinos
const int clockMotor1 = 11; 
const int enableMotor1 = 13;

// definição dos pinos   MOTOR2
const int sentidoRotacaoMotor2 = 9;//pinos
const int clockMotor2 = 10; 
const int enableMotor2 = 8;


// definição dos pinos   MOTOR3
const int sentidoRotacaoMotor3 = 6;//pinos
const int clockMotor3 = 7; 
const int enableMotor3 = 5;
void setup() {
  
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
  digitalWrite(sentidoRotacaoMotor3,LOW);

  //Serial.begin(9600);
}
void loop() {
  
  
  unsigned int quantidadeVoltasMotor1 = 50;
  unsigned int quantidadeVoltasMotor2 = 20;
  unsigned int quantidadeVoltasMotor3 = 5;
  unsigned int numeroPulsosMotor1 = 0;
  unsigned int numeroPulsosMotor2 = 0;
  unsigned int numeroPulsosMotor3 = 0;
  float tempo1 = 0;
  float tempo2 = 0;
  float tempo3 = 0;
  unsigned int velocidadeMotor1 = 500;
  unsigned int velocidadeMotor2 = 900;
  unsigned int velocidadeMotor3 = 3000;
  
//  Serial.print("Digite a quantidade de voltas do motor 1: ");
  //quantidade_voltas_motor1 = input
  //input da velocidade
//  Serial.print("Digite a quantidade de voltas do motor 2: ");
  //quantidade_voltas_motor2 = input
  //input da velocidade
//  Serial.print("Digite a quantidade de voltas do motor 3: ");
  //quantidade_voltas_motor3 = input
  //input da velocidade

  //validação


//conversao


  numeroPulsosMotor1 = 200 * quantidadeVoltasMotor1;
  numeroPulsosMotor2 = 200 * quantidadeVoltasMotor2;
  numeroPulsosMotor3 = 200 * quantidadeVoltasMotor3;
  
//conversao
  tempo1 = 0.0001/velocidadeMotor1;
  tempo2 = 0.0001/velocidadeMotor2;
  tempo3 = 0.0001/velocidadeMotor3;

//validação do time
  if(tempo1 <= 0.000005)
  {
    tempo1 = 0.00005;
  }

 if(tempo2 <= 0.000005)
  {
    tempo2 = 0.00005;
  }
 if(tempo3 <= 0.000005)
  {
    tempo3 = 0.00005;
  }
  //loop infinito

  while(1)
  {
    if(numeroPulsosMotor1 != 0 )
    {
      digitalWrite(clockMotor1,HIGH);
      delayMicroseconds(tempo1/2);
      digitalWrite(clockMotor1,LOW);
      delayMicroseconds(tempo1/2);
      numeroPulsosMotor1 --;
    }
    if(numeroPulsosMotor2 != 0 )
    {
      digitalWrite(clockMotor2,HIGH);
       delayMicroseconds(tempo2/2);
      digitalWrite(clockMotor2,LOW);
      delayMicroseconds(tempo2/2);
      numeroPulsosMotor2 --;
    }
    if(numeroPulsosMotor3 != 0 )
    {
      digitalWrite(clockMotor3,HIGH);
      delayMicroseconds(tempo3/2);
      digitalWrite(clockMotor3,LOW);
      delayMicroseconds(tempo3/2);
      numeroPulsosMotor3 --;
    }
    if(numeroPulsosMotor1 == 0 && numeroPulsosMotor2 == 0 && numeroPulsosMotor3 == 0)
    {
      //digitalWrite enable high(para desativar os drivers)
      digitalWrite(enableMotor1,HIGH);
      digitalWrite(enableMotor2,HIGH);
      digitalWrite(enableMotor3,HIGH);
    }
    
    
  }
  
}
