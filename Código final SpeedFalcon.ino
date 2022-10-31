//Equipe: Speed Falcon
//Autor: Jorge Barbosa Freitas
//Data:30/10/2022


/*Aqui você pode informar o Arduino sobre onde cada componente foi conectado. 
Estamos usando pinos digitais, então apenas tome esse cuidado na hora de escolher seus pinos.*/ 

int TILT1_PINO = 5;   // Pino do sensor de tilt 1
int TILT2_PINO = 7;   // Pino do sensor de tilt 2
int BUZZER_PINO = 3;  // Pino do buzzer
int LDR_PINO = 8;     // Pino do sensor de iluminação
int LED_FRENTE = 9;   // Pino dos leds dianteiros
int LED_ATRAS = 10;   // Pino dos leds traseiros

/*Aqui podemos configurar algumas informações sobre as medidas que são tomadas quando o veiculo é capotado ou quando ameaça ser capotado.*/

int FREQUENCIA_BUZZER = 200; // Frequência de oscilação do buzzer. Isso dá o tom do alerta de possibilidade de capotamento.
int DURACAO_BUZZER = 300; // Duração do periodo ligado (HIGH) do buzzer. Isso altera quanto tempo o buzzer fica ligado.
int INTERVALO_BUZZER = 300 ;// Duração do periodo desligado (LOW) do buzzer. Isso altera quanto tempo o buzzer fica desligado.

int VELOCIDADE_SOS = 1; // Velocidade de reprodução da emissão do pedido de socorro em código morse (SOS) nas lanternas e buzzer.
int INTERVALO_SOS_CURTO = 200 ;// Intervalo curto do SOS
int INTERVALO_SOS_LONGO = 400 ;// Intervalo longo do SOS

/*Aqui começam algumas configurações mais avançadas do programa, como a função de cada pino (entrada ou saida).*/

void setup(){ //Aqui declaramos onde começa essa parte avançada da configuração para o Arduino.
  Serial.begin(9600); //Opção de "Debug", usada a fins de diagnósticos dos sensores.
  pinMode(TILT1_PINO, INPUT_PULLUP); // O pino do tilt 1 está sendo declarado como um pino de entrada de dados (sensor)
  pinMode(TILT2_PINO, INPUT_PULLUP); // O pino do tilt 2 está sendo declarado como um pino de entrada de dados (sensor)
  pinMode(LDR_PINO, INPUT); // O pino do sensor de iluminação (LDR) está sendo declarado como um pino de entrada de dados (sensor)
  pinMode(BUZZER_PINO, OUTPUT); // O pino do buzzer está sendo declarado como um pino de saida de dados (acionador)
  pinMode(LED_FRENTE, OUTPUT); // O pino dos leds frontais está sendo declarado como um pino de saida de dados (acionador)
  pinMode(LED_ATRAS, OUTPUT); // O pino dos leds traseiros está sendo declarado como um pino de saida de dados (acionador)
}

/*Aqui começam as funções do programa em si.*/

void loop(){ //Especificamos quais tarefas são recorrentes, pois o programa precisa agir e pensar constantemente.
  int STATUS_LDR = digitalRead(LDR_PINO); //Atribuindo uma leitura do sensor a uma variavel
  int STATUS_TILT1 = digitalRead(TILT1_PINO); //Atribuindo uma leitura do sensor a uma variavel
  int STATUS_TILT2 = digitalRead(TILT2_PINO); //Atribuindo uma leitura do sensor a uma variavel
  if (STATUS_TILT1==HIGH && STATUS_TILT2==HIGH){ //Se os dois sensores de capotamento estiverem ativos, inicia-se a sequência de SOS
    digitalWrite(LED_FRENTE, HIGH); //Liga led
    digitalWrite(LED_ATRAS, HIGH); //Liga led
    tone(BUZZER_PINO, FREQUENCIA_BUZZER, INTERVALO_SOS_CURTO); //Buzzer ativo com duração curta (Para "S" em código morse)
    delay(200); //Espera 200ms
    digitalWrite(LED_FRENTE, LOW); //Desliga led
    digitalWrite(LED_ATRAS, LOW); //Desliga led
    delay(200); //Espera 200ms
    digitalWrite(LED_FRENTE, HIGH); //Liga led
    digitalWrite(LED_ATRAS, HIGH); //Liga led
    tone(BUZZER_PINO, FREQUENCIA_BUZZER, INTERVALO_SOS_CURTO); //Buzzer ativo com duração curta (Para "S" em código morse)
    delay(200); //Espera 200ms
    digitalWrite(LED_FRENTE, LOW); //Desliga led
    digitalWrite(LED_ATRAS, LOW); //Desliga led
    delay(200); //Espera 200ms
    digitalWrite(LED_FRENTE, HIGH); //Liga led
    digitalWrite(LED_ATRAS, HIGH); //Liga led
    tone(BUZZER_PINO, FREQUENCIA_BUZZER, INTERVALO_SOS_CURTO); //Buzzer ativo com duração curta (Para "S" em código morse)
    delay(200); //Espera 200ms
    digitalWrite(LED_FRENTE, LOW); //Desliga led
    digitalWrite(LED_ATRAS, LOW); //Desliga led
    delay(200); //Espera 200ms
    digitalWrite(LED_FRENTE, HIGH); //Liga led
    digitalWrite(LED_ATRAS, HIGH); //Liga led
    tone(BUZZER_PINO, FREQUENCIA_BUZZER, INTERVALO_SOS_LONGO); //Buzzer ativo com duração longa (Para "O" em código morse)
    delay(400); //Espera 400ms
    digitalWrite(LED_FRENTE, LOW); //Desliga led
    digitalWrite(LED_ATRAS, LOW); //Desliga led
    delay(400); //Espera 400ms
    digitalWrite(LED_FRENTE, HIGH); //Liga led
    digitalWrite(LED_ATRAS, HIGH); //Liga led
    tone(BUZZER_PINO, FREQUENCIA_BUZZER, INTERVALO_SOS_LONGO); //Buzzer ativo com duração longa (Para "O" em código morse)
    delay(400); //Espera 400ms
    digitalWrite(LED_FRENTE, LOW); //Desliga led
    digitalWrite(LED_ATRAS, LOW); //Desliga led
    delay(400); //Espera 400ms
    digitalWrite(LED_FRENTE, HIGH); //Liga led
    digitalWrite(LED_ATRAS, HIGH); //Liga led
    tone(BUZZER_PINO, FREQUENCIA_BUZZER, INTERVALO_SOS_LONGO); //Buzzer ativo com duração longa (Para "O" em código morse)
    delay(400); //Espera 400ms
    digitalWrite(LED_FRENTE, LOW); //Desliga led
    digitalWrite(LED_ATRAS, LOW); //Desliga led
    delay(200); //Espera 200ms
    digitalWrite(LED_FRENTE, HIGH); //Liga led
    digitalWrite(LED_ATRAS, HIGH); //Liga led
  }
  else{ //Caso contrário:
    if (STATUS_TILT1==HIGH){ //Somente seguir se o primeiro sensor estiver ativo
      delay(200); //Espera 115ms a fim de previnir uma ativação falsa, faz parte da checagem dupla da ativação
      int STATUS_TILT1 = digitalRead(TILT1_PINO); //Ler valor novamente, para uma nova consulta
        if (STATUS_TILT1==HIGH){ //Somente seguir se o primeiro sensor AINDA estiver ativo
          delay(200); //Espera 115ms a fim de previnir uma ativação falsa, faz parte da checagem dupla da ativação
          int STATUS_TILT1 = digitalRead(TILT1_PINO); //Ler valor novamente, para uma nova consulta
            if (STATUS_TILT1==HIGH){ //Somente seguir se o primeiro sensor AINDA estiver ativo
              Serial.println("Risco de capotamento para a esquerda. Alerta ativo."); //Comando para debug, assim temos também uma resposta apenas verbal
              tone(BUZZER_PINO, FREQUENCIA_BUZZER, DURACAO_BUZZER); //Buzzer em alerta
              digitalWrite(LED_FRENTE, HIGH); //Liga led
              digitalWrite(LED_ATRAS, HIGH); //Liga led
              delay(INTERVALO_BUZZER); //Espera esse intervalo
              digitalWrite(LED_FRENTE, LOW); //Desliga led
              digitalWrite(LED_ATRAS, LOW); //Desliga led
            }
        }
      }
    else{ //Caso contrário:
      if (STATUS_TILT2==HIGH){ //Somente seguir se o segundo sensor estiver ativo
      delay(200); //Espera 115ms a fim de previnir uma ativação falsa, faz parte da checagem dupla da ativação
      int STATUS_TILT2 = digitalRead(TILT2_PINO); //Ler valor novamente, para uma nova consulta
        if (STATUS_TILT2==HIGH){ //Somente seguir se o segundo sensor AINDA estiver ativo
          delay(200); //Espera 115ms a fim de previnir uma ativação falsa, faz parte da checagem dupla da ativação
          int STATUS_TILT2 = digitalRead(TILT2_PINO); //Ler valor novamente, para uma nova consulta
            if (STATUS_TILT2==HIGH){ //Somente seguir se o segundo sensor AINDA estiver ativo
              Serial.println("Risco de capotamento para a esquerda. Alerta ativo."); //Comando para debug, assim temos também uma resposta apenas verbal
              tone(BUZZER_PINO, FREQUENCIA_BUZZER, DURACAO_BUZZER); //Buzzer em alerta
              digitalWrite(LED_FRENTE, HIGH); //Liga led
              digitalWrite(LED_ATRAS, HIGH); //Liga led
              delay(INTERVALO_BUZZER); //Espera esse intervalo
              digitalWrite(LED_FRENTE, LOW); //Desliga led
              digitalWrite(LED_ATRAS, LOW); //Desliga led
            }
        }
      }
    else{ //Caso contrário:
      if(STATUS_LDR==HIGH){ //Se o sensor de iluminação estiver sinalizando falta de luz:
        digitalWrite(LED_FRENTE, HIGH); //Liga led
        digitalWrite(LED_ATRAS, HIGH); //Liga led
        }
      else{ //Caso contrário:
        digitalWrite(LED_FRENTE, LOW); //Desliga led
        digitalWrite(LED_ATRAS, LOW); //Desliga led
        }
      }
    }
  }
}