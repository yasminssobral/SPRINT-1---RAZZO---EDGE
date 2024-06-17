# 🏎️ Projeto: Medição de Velocidade com Sensores Ultrassônicos

Este projeto utiliza dois sensores ultrassônicos para medir a velocidade de um objeto em movimento. A distância medida por cada sensor é usada para calcular a velocidade com base no tempo decorrido entre as duas leituras.

## 📦 Componentes Necessários

- 🛠️ 2 Sensores Ultrassônicos HC-SR04
- 🖥️ 1 Display LCD I2C 16x2
- 🔌 Arduino (Uno, Mega, etc.)
- 🔗 Jumpers
- 🧰 Protoboard (opcional)

## 📝 Descrição do Código

O código é escrito em Arduino C++ e utiliza a biblioteca `LiquidCrystal_I2C` para controlar o display LCD. O código realiza as seguintes funções:

### 📚 Bibliotecas

```cpp
#include <LiquidCrystal_I2C.h>
````

1. **⚙️ Configuração Inicial (`setup`):**
   - Inicializa a comunicação serial.
   - Inicializa o display LCD.
   - Define os pinos de TRIGGER e ECHO para os sensores ultrassônicos.

2. **📏 Cálculo da Distância (`calcdistancia`):**
   - Gera um pulso de ultrassom pelo pino TRIGGER.
   - Calcula o tempo que o pulso leva para retornar ao pino ECHO.
   - Converte o tempo em distância.

3. **🔄 Loop Principal (`loop`):**
   - Lê a distância do primeiro sensor e marca o tempo.
   - Lê a distância do segundo sensor e marca o tempo.
   - Calcula a velocidade do objeto com base na diferença de distância e no tempo decorrido.
   - Exibe a velocidade no display LCD.
   - Exibe mensagens de erro se as leituras de distância não forem válidas.

## 🔌 Conexões

### 🌐 Sensores Ultrassônicos
- **Sensor 1:**
  - TRIGGER_PIN1 -> Pino 3 do Arduino
  - ECHO_PIN1 -> Pino 2 do Arduino
- **Sensor 2:**
  - TRIGGER_PIN2 -> Pino 5 do Arduino
  - ECHO_PIN2 -> Pino 4 do Arduino

### 🖥️ Display LCD
- SDA -> Pino A4 do Arduino
- SCL -> Pino A5 do Arduino

## 📖 Como Usar

1. Conecte os componentes de acordo com as instruções acima.
2. Carregue o código no Arduino.
3. Abra o monitor serial para ver as distâncias e a velocidade calculada.
4. Observe o display LCD para ver a velocidade do objeto em movimento.

## Desenvolvedores :alien:
- **Eliseu Fernando Mendes dos Santos - RM98493**
- **Ana Clara Melo de Sousa - RM559021**
- **Yasmin Sobral - RM558757**
- **Henrique Azevedo - RM556707**
- **Gustavo Ikeda - RM554718**
