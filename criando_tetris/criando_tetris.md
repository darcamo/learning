---
title: Criando um jogo de Tetris
author:
  Darlan Cavalcante Moreira
---


# Instalando e configurando a biblioteca SDL #

Para criar nosso jogo de tetris nós usaremos a biblioteca SDL.


# Os passos para criar o jogo #

Criaremos nosso jogo como uma sequência de "passos", ou "versões" onde cada
versão é construída a partir da anterior. Dessa forma podemos ver como o
cógigo evolui.

## Passo 1: Compilando e linkando com a SDL ##

O primeiro passo é conseguir apenas compilar nosso programa e linkar com a
biblioteca SDL. Para isso vamos criar uma função `main.cpp` que inclui,
inicializa e finaliza a SDL. Se nosso programa compilar isso mostra que ele
conseguiu enxergar a biblioteca SDL e se ele não tiver problemas de
referências indefinidas isso mostra que ele conseguiu linkar corretamente.

Abaixo temos a nossa função main.

{{ d['src_passo1/main.cpp|pyg'] }}


Para compilar nosso programa usaremos o [CMake](http://www.cmake.org/), que
requer a criação de um arquivo chamado de `CMakeLists.txt`. Nosso arquivo
`CMakeLists.txt` contém o conteúdo abaixo.

{{ d['src_passo1/CMakeLists.txt|pyg'] }}

Para compilar nosso programa, devemos então ir na pasta `src_passo1/`,
rodar o comando `cmake .` seguido de `make`, como abaixo.

{{ d['src_passo1/run_cmake_and_compile.sh|shint|pyg'] }}


Com o nosso programa compilado podemos rodá-lo para ver a saída "Hello
SDL".

{{ d["run_passo1.sh|shint|pyg"] }}


## Passo 2: Criando uma janela ##

Agora vamos incrementar nossa função `main.cpp`. Primeiro definimos algumas constantes usando fora da função main como abaixo.

{{ d['src_passo2/main.cpp|idio']["DefineConstantes"] }}


Agora, dentro da nossa função main, criamos os 3 ponteiros abaixo

{{ d['src_passo2/main.cpp|idio']["DeclaraVariaveis"] }}

O primeiro corresponde a janela que iremos criar para exibir nosso jogo. Os
outros dois são "superfícies" (*surface*) para a janela do jogo e para o
fundo. Qualquer coisa que seja copiada para a *surface* correspondendo a
janela do jogo irá aparecer na tela. Note que por enquanto os ponteiros
estão setados como NULL.

Após a declaração dos 3 ponteiros temos a inicialização da SDL como antes.

{{ d['src_passo2/main.cpp|idio']["InicializaSDL"] }}

Agora podemos criar a janela do jogo além da surface ligada a janela. Para
isso usaremos a função `SDL_CreateWindow` como abaixo, seguida de
`SDL_GetWindowSurface`.

{{ d['src_passo2/main.cpp|idio']["CriaJanelaDoJogo"] }}

Note que usamos as constantes `SCREEN_WIDTH` e `SCREEN_HEIGHT` que
definimos anteriormente e testamos se a janela foi de fato criada (se o
ponteiro `gameWindow` foi setado para um valor diferente de NULL. Fazemos
algo semelhante para criar a surface com o fundo da tela, no qual
carregamos a imagem `assets/background.bmp`.


Agora já podemos mostrar a imagem de fundo na nossa janela. Primeiramente
copiamos o conteúdo da surface contendo a imagem de fundo para a surface
correspondendo a janela usando a função `SDL_BlitSurface`[^1]. Após isso,
chamamos a função `SDL_UpdateWindowSurface`[^2] para que o conteúdo da janela
seja atualizado e possamos finalmente ver a imagem na nossa janela. Note
que chamamos a função `SDL_Delay` apenas para que o programa não termine
logo e nós possamos ver nossa janela.

[^1]: O que a função SDL_BlitSurface faz é pegar uma surface de origem (primeiro argumento) e copiar na surface de destino (terceiro argumento). Vamos nos preocupar com o segundo e quarto argumentos depois.

[^2]: Quando você copiar algo para a surface da janela você não está realmente copiando para a imagem que você vê na tela, mas sim para o *back* buffer. Normalmente há o *front* e o *back* buffer e a imagem na tela corresponde ao *front* buffer. Quando você chama `SDL_UpdateWindowSurface` o conteúdo do *back* buffer é finalmente copiado para o *front* buffer de forma que você finalmente pode ver a imagem.


{{ d['src_passo2/main.cpp|idio']["AplicaTelaDeFundo"] }}


Por fim nós limpamos as variáveis criadas dinamicamente. Em geral,
variáveis criadas com `SDL_Create*` possuem uma função equivalente
`SDL_Destroy*` e variáveis criadas com `SDL_Get*` possuem uma função
equivalente `SDL_Free*`. Quais quer outras variáveis criadas dinamicamente
com `new` ou com `malloc` devem ser liberadas normalmente com `delete` e
`free`.


Para finalizar, finalizamos a SDL como antes.

{{ d['src_passo2/main.cpp|idio']["FinalizaSDL"] }}
