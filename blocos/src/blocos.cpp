

#include "config.h"

#include <iostream>
#include <stdlib.h>
#include "general_defs.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
	// Inicializa SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	
	// Inicializa SDL_ttf 
	if( TTF_Init() == -1 ) 
	{
		return 1;
	}
	
	
	// xxxxxxxxxx Chama o jogo xxxxxxxxxx
	Game game;
	game.play();
	// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	
	
	// Fecha as bibiotecas TTF e SDL corretamente
	TTF_Quit();
	SDL_Quit();
}
