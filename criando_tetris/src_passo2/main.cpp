#include <SDL2/SDL.h>
#include <iostream>

#define VALID_SCREEN_WIDTH 11
#define VALID_SCREEN_HEIGHT 15
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define COLOR_DEPTH 32


int main(int argc, char *argv[])
{
  bool quit = false;
  
  // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // xxxxxxxxxxxxxxx Inicializa SDL xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Não foi possível inicializar a SDL: " << SDL_GetError() << std::endl;
    return 1;
	}

  // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // xxxxxxxxxxxxxxx Cria uma janela xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  SDL_Window* screen = NULL;
  screen = SDL_CreateWindow("My Game Window",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
                            // SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
  if (screen == NULL)
    {
      std::cout << "Não foi possível criar janela" << std::endl;
      return 0;
    }

  // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // xxxxxxxxxxxxxxx Cria um "renderer" xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  SDL_Renderer* renderer = NULL;
  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);



  SDL_Event* mainEvent = new SDL_Event();
  while (!quit && mainEvent->type != SDL_QUIT) {
    // SDL_QUIT ocorre quando você fecha a janela
    SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
  
  // Load a background image

  
  // Libera a memória de variáveis criadas dinamicamente
  SDL_DestroyWindow(screen);
  SDL_DestroyRenderer(renderer);
  delete mainEvent;  // Sempre que for criado com o new nós deletamos com "delete"
  
  // Limpa antes de sair
  SDL_Quit();

  return 0;
}
