#include <SDL2/SDL.h>
#include <iostream>
#include "general_defs.h"


/// "Prototipos"
//  Inicializa a SDL e cria nossa janela
bool init();

// Carrega media (imagens)
bool loadMedia();

// Apaga media (free) e finaliza a SDL
void close();


/// "DeclaraVariaveisGlobais"
// Janela do nosso jogo
SDL_Window* gameWindow = NULL;
  
// surface contendo a "janela". Tudo que "copiarmos" para essa surface
// mais tarde vai aparecer na janela do jogo
SDL_Surface* gScreenSurface = NULL;

// surface para o fundo do jogo
SDL_Surface* backgroundSDLSurface = NULL;


/// "DefineAFuncaoInit"
bool init()
{
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Não foi possível inicializar a SDL: " << SDL_GetError() << std::endl;
    success = false;
  }
  else
    {
      gameWindow = SDL_CreateWindow("My Game Window",
                                    SDL_WINDOWPOS_UNDEFINED, // Posição (coord x)
                                    SDL_WINDOWPOS_UNDEFINED, // Posição (coord y)
                                    SCREEN_WIDTH,  // Largura da janela
                                    SCREEN_HEIGHT, // Altura da Janela
                                    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
      if (gameWindow == NULL)
        {
          std::cout << "Não foi possível criar janela" << std::endl;
          success = false;
        }
      else
        {
          // Pega uma surface para a janela do jogo
          gScreenSurface = SDL_GetWindowSurface( gameWindow );
        }
    }
  return success;
}


/// "DefineAFuncaoLoadMedia"
bool loadMedia()
{
  bool success = true;
  
  // Carrega o background de um arquivo bmp
  backgroundSDLSurface = SDL_LoadBMP("assets/background.bmp");
  if( backgroundSDLSurface == NULL )
    {
      std::cout << "Não foi possível carregar imagem" << "assets/background.bmp\n"
                << "SDL Error: " << SDL_GetError() << std::endl;
      success = false;
    }
  
  return success;
}

/// "DefineAFuncaoClose"
void close()
{
  // Libera a memória de variáveis criadas dinamicamente
  SDL_DestroyWindow(gameWindow);
  gameWindow = NULL;

  // Não precisamos chamar SDL_FreeSurface para a surface da tela pois
  // SDL_DestroyWindow vai fazer isso para a gente
  SDL_FreeSurface(backgroundSDLSurface);
  backgroundSDLSurface = NULL;

  /// "FinalizaSDL"
  // Deve ser chamado por último
  SDL_Quit();
}


/// "MainFunction"
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxx Nossa função main xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int main(int argc, char *argv[])
{

  // Inicializa SDL e cria a janela
  if( !init() )
    {
      std::cout << "Failed to initialize!" << std::endl;
    }
  else
    {
      // Carrega media
      if( !loadMedia() )
        {
          std::cout << "Failed to load media!" << std::endl;
        }
      else
        {
          //Apply the image
          SDL_BlitSurface( backgroundSDLSurface, NULL, gScreenSurface, NULL );
  
          // Copia a surface da janela para a tela
          SDL_UpdateWindowSurface( gameWindow );
          SDL_Delay(2000);
        }
    }

  close();
  /// "RetornoDaMain"
  return 0;
}
