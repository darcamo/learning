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

Para compilar nosso programa, devemos então ir na pasta `src_passo1/` e
digitar o conteúdo abaixo.

```bash
cmake .
make
```

Com o nosso programa compilado podemos rodá-lo para ver a saída "Hello
SDL".


## Passo 2: Criando uma janela ##

Agora vamos incrementar nossa função `main.cpp`.

{{ d['src_passo2/main.cpp|pyg'] }}
