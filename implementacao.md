# Implementação

<!-- >Relatar o processo de implementação do problemas, incluindo as ferramentas e bibliotecas utilizadas -->

O jogo foi implementado utilizando o framework **Qt**, que dispõe de ferramentas para gerenciamento gráficos, timers, tratamento de *inputs* e controle de eventos. 

## Estrutura do Jogo

A mecânica do jogo é simples. O jogador controla um personagem que se move pela base da tela, efetuando disparos para destruir zumbis que descem do topo da tela. A implementação é segmentada em **classes**, cada uma responsável por um aspecto do jogo:

- **Player**: Responsável pela movimentação do personagem do jogador e demais comandos de interação.
- **Enemy**: Gerencia os zumbis gerados randomicamente no topo da teal. Eles se movem para baixo e são destruídos quando atingidos pelos tiros do jogador.
- **Shot**: Gerencia os tiros realizado pelo jogador, incluindo sua movimentação,colisões entre tiros e inimigos e exclusão ao deixar o limiar da tela.
- **Score**: Exibe a pontuação do jogador e a atualiza conforme os inimigos são atingidos.
- **Game**: Gerencia o fluxo geral do jogo, a criação de objetos, o controle da pausa e reinício do jogo, e a exibição dos textos "PAUSE" e "GAME OVER".

Ao carregar, o jogo exibe uma tela de introdução utilizando o **QSplashScreen** do Qt. A tela de introdução é exibida por dois segundos antes que o jogo comece, contendo os dados do autor, proporcionando uma transição visual mais suave.
As animações são feitas utilizando a classe **QMovie**, que permite exibir imagens em formato .GIF. 

Também foram utilizados componentes gráficos como **QGraphicsScene**,  **QGraphicsView** e **QGraphicsTextItem** para impressão de textos customizados na cena. A movimentação do jogador e dos inimigos é controlada pelo **QTimer**, que define intervalos de tempo regulares para a atualização das posições dos objetos na tela. Já os controles ocorrem através dos seguintes *inputs* de teclado:

- **Teclas ←↑↓→**: O jogador pode mover o personagem com as teclas de seta até certos limites estabelecidos.
- **Barra de espaço**: Dispara.
- **Tecla P**: Pausa o jogo.
- **Tecla R**: Reinicia o jogo.

## Lógica do Jogo

Quando um zumbi é atingido por um tiro, a pontuação do jogador aumenta e o zumbi é removido da cena. Os zumbis também são removidos de cena ao ultrapassarem a margem inferior da tela. Neste caso o jogo encerra e a mensagem "GAME OVER" é exibida no centro da tela. O jogador pode reiniciar o jogo a qualquer momento, o que irá limpar a tela e começas uma nova partida com o personagem e a pontuação resetados. Os zumbis são gerados aleatoriamente e há 1/3 de chance de ser gerado um zumbi corredor.

<div align="center">

[Retroceder](projeto.md) | [Início](testes.md)

</div>