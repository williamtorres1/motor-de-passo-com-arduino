# Motor de passo com arduino

Este repositório foi criado para versionar e armazenar o código da primeira avaliação da disciplina de Robótica.

## Indice

- [Materiais utilizados](#materiais-utilizados)
- [Princípio de funcionamento](#princípio-de-funcionamento)
- [Controle de posição](#controle-de-posição)
- [Controle de velocidade](#controle-de-velocidade)

## Materiais utilizados

Os equipamentos utilizados foram:

- 3 Drivers TB6560 v2.
- 3 Motores de Passo - UNIPOLAR 9kg - nema23 - BIPOLAR 12kgf - nema23.
- 1 Arduino UNO.
- 1 Fonte para alimentação dos motores (especificações em breve).
- Fios para conexões.

## Princípio de funcionamento

Para um motor de passo funcionar, é preciso Ligar e Desligar o clock. Esta ação é 1 (um) pulso.

Porém, precisamos de um tempo entre esse "ligar" e "desligar", senão esse pulso é muito rápido e o motor não sai do lugar.

Logo, utilizamos a função delayMicroseconds(), pois iremos trabalhar na ordem de grandeza dos Microssegundos.


## Controle de posição

Fizemos o controle de posição dos motores da seguinte forma:

200 pulsos = 1 volta

Logo, se queremos 20 voltas, conseguimos descobrir quandos pulsos nós temos que enviar para o motor.
```c++
    if(numeroPulsos != 0 )
    {
        Liga o pino de clock do motor 1
        delay()
        Desliga o pino de clock do motor 1
        delay()
        //Nessa linha de código, concluímos 1 (um) passo. Então iremos decrementar a variável.
        numeroPulsos = numeroPulsos - 1

    }
```
Para fazer os 3 motores irem para posições diferentes, é somente repetir o código acima. E quando os 3 motores chegarem nas suas posições definidas, iremos desativar os drivers (porque, como são de alta corrente (A), esquentam MUITO).

```c++
    if(numeroPulsosMotor1 == 0 && numeroPulsosMotor2 == 0 && numeroPulsosMotor3 == 0)
        {
            desativa o driver do motor 1
            desativa o driver do motor 2
            desativa o driver do motor 3
        }
```

## Controle de velocidade

O controle de velocidade dos motores já foi mostrado em #Controle de Posição, porém iremos adicionar alguns detalhes.

Temos conhecimento que o passo da rosca que será percorrida é de 0,1 mm (10^-4).

Então, pela fórmula de velocidade, teremos:
```
    Vm = ΔS/ΔT
    (Speed) = (Space)/(Time)
```
Deduzindo, teremos que:
```
    ΔT = ΔS/Vm
```
A velocidade será inserida pelo usuário. Então teremos o valor do tempo.

O que é esse tempo? o tempo do começo do período.

Estamos usando a função [millis()](https://www.arduino.cc/reference/pt/language/functions/time/millis/) do arduino.
Após a verificação entre millis() e a nossa variável tempo, reatribuímos o valor de millis() para a nossa variável.
Sendo assim, teremos controle da frequência do motor.

```c++
{
   if(millis() - tempo >= velocidadeMotor)
      {
        clock -> HIGH
        tempo = millis();
      }
      if(millis() - tempo >= velocidadeMotor)
      {
        clock -> LOW
        numeroPulsosMotor--;
      }
}
```
