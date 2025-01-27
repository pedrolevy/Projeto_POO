# Testes

<!-- >[!NOTE]
> Relatar o processo de testes do sistema, especificando quais testes foram realizados e os resultados obtidos. -->

O desenvolvimento do jogo foi permeado por uma série de testes para garantir o pleno funcionamento dos objetos que o compõe. Segue abaixo, os principais testes realizados e os resultados obtidos.

- **Teste de Movimentação do Jogador**: Realizado para assegurar o personagem do jogador pudesse se mover corretamente em todas as direções ao utilizar as teclas de seta (esquerda, direita, cima, baixo) dentro dos limites estabelecidos. Ao final, o jogador se moveu corretamente nas quatro direções, e os limites da tela foram respeitados, impedindo que o personagem saísse da área visível ou avançasse para a porção superior da tela.

- **Teste de Geração e Movimentação de Zumbis**: Realizado para assegurar que os zumbis iriam ser gerados em posições aleatórias do eixo X na borda superior da tela e se mover corretamente através da tela, de cima para baixo. Ao final, a geração e movimentação dos zumbis passou a ocorrer normalmente e ao ultrapassar a margem inferior o zumbi é deletado e a partida é encerrada.

- **Teste de Disparo**: Realizado para verificar se os disparos do jogador são gerados corretamente e se seu movimento é preciso. O tiro deve ser disparado na direção correta (para cima) e deve se mover de forma contínua até desaparecer. Ao final, o disparo ocorreu corretamente, com os tiros se movendo para cima e desaparecendo quando saíam da tela ou colidiam com um zumbi.

- **Teste de Colisão e Score**: Realizado para verificar se as colisões entre os tiros e os inimigos eram detectadas corretamente. Quando um tiro atingir um zumbi, o inimigo deve ser removido da tela e a pontuação deve ser incrementada. Ao final,- as colisões foram detectadas com precisão, os zumbis passaram a ser removidos corretamente da tela ao serem atingidos e a pontuação era atualizada conforme esperado.

- **Teste de Pause**: Realizado para verificar se a funcionalidade de pausa do jogo funciona corretamente e se o jogo retorna normalmente ao estado anterior após a pausa. O estado pausado ocorre através da tecla "P" e sua desabilitação ocorre através do pressionamento da mesma tecla. Ao final, ao acionar o Pause os zumbis, o personagem e os disparos deixam de ocorrer e são retomados após novo acionamento da tecla "P". Foi observado que o pause afeta o deslocamento dos zumbis corredores, de modo que após desabilitado, estes retomam o deslocamento em velocidade normal. Além do mais, caso ocorra um disparo em momento anterior ao pause, este irá concluir sua trajetória, seja atingindo um alvo ou deixando a tela.

- **Teste de Reinício de Jogo**: Realizado para garantir que o jogo reinicie corretamente após a finalização ou após o pressionamento da tecla "R", que deve resetar todos os elementos e iniciar uma nova partida. Ao final, o jogo reiniciou corretamente, com todos os elementos em suas posições de origem e contador de score zerado. Foi observado que entre a tela de Game Over e o reinício da partida, embora cesse a geração de inimigos, o personagem do jogador permanece em movimento e pode até mesmo atingir algum zumbi gerado pouco antes do encerramento da partida, computando-o ao score.

<div align="center">

[Retroceder](implementacao.md) | [Início](README.md)

</div>