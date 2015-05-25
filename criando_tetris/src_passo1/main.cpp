#include <SDL2/SDL.h>
#include <iostream>


int main(int argc, char *argv[])
{
  /// "InicializaSDL"
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Não foi possível inicializar a SDL: " << SDL_GetError() << std::endl;
    return 1;
	}

  //
  // Vamos colocar nosso código aqui
  // ... ... ...
  //
  
  /// "FinalizaSDL"
  // Deve ser chamado por último
  SDL_Quit();

  /// "RetornoDaMain"
  std::cout << "Hello SDL" << std::endl;
  return 0;
}
