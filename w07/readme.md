# Treasure Hunt Game

Treasure Hunt é um jogo interativo baseado em texto onde o jogador explora um caminho, encontra tesouros, evita bombas e tenta sobreviver até o final.

## Sobre o Jogo

- **Gênero:** Jogo de estratégia baseado em texto.
- **Objetivo:** Acumular o máximo de tesouros possível sem perder todas as vidas.
- **Características:** 
  - Configuração personalizada de jogador e jogo.
  - Colocação de bombas e tesouros em um mapa.
  - Feedback visual ao explorar posições.

## Como Jogar

1. **Configuração do Jogador:**
   - Escolha um símbolo para representar o jogador.
   - Defina o número de vidas (entre 1 e 10).

2. **Configuração do Jogo:**
   - Defina o comprimento do caminho (múltiplo de 5 entre 10 e 70).
   - Estabeleça o limite de movimentos permitido (mínimo de 3).

3. **Colocação de Bombas e Tesouros:**
   - Insira posições para bombas e tesouros no mapa.

4. **Exploração:**
   - Escolha uma posição no mapa para explorar.
   - Encontre tesouros, evite bombas ou revise áreas já exploradas.

## Controles

- Insira números correspondentes às posições no mapa para se mover.
- Siga as instruções na tela para configurar e explorar.

## Regras do Jogo

- Cada movimento reduz o número de movimentos restantes.
- Bombas reduzem suas vidas.
- Tesouros aumentam sua pontuação.
- O jogo termina quando todas as vidas são perdidas ou os movimentos se esgotam.

## Estrutura do Código

O jogo é desenvolvido em C e utiliza as seguintes estruturas:

- **Struct PlayerInfo:** Armazena informações do jogador.
- **Struct GameInfo:** Contém a configuração e o estado do jogo.
- **ANSI Escape Codes:** Utilizados para colorir mensagens no terminal.

## Requisitos

- **Compilador:** GCC ou equivalente.
- **Sistema Operacional:** Windows, Linux ou macOS com suporte ao terminal.

## Compilação e Execução

1. Compile o jogo com o seguinte comando:
   ```bash
   gcc w7p2.c -o treasure_hunt
