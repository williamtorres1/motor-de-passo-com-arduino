## Motor-de-Passo-com-Arduino

Este repositório foi criado para versionar e armazenar o código da primeira avaliação da disciplina de Robótica.

Os equipamentos utilizados foram:
        3 Drivers XXXXX (os nomes serão inseridos em breve, quando tivermos conhecimento).
        3 Motores de Passo.
        1 Arduino UNO.
        1 Fonte para alimentação dos motores (especificações em breve).
        Fios para conexões.

## Princípio de funcionamento

Para um motor de passo funcionar, é preciso Ligar e Desligar o clock. Esta ação é 1 (um) pulso.

Porém, precisamos de um tempo entre esse "ligar" e "desligar", senão esse pulso é muito rápido e o motor não sai do lugar.

Logo, utilizamos a função delayMicroseconds(), pois iremos trabalhar na ordem de grandeza dos Microssegundos.

