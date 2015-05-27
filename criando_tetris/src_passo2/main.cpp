#include <SDL2/SDL.h>
#include <iostream>


/// "DefineConstantes"
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxx Define algumas constants xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// Tamanho (número de columnas e linhas) que nosso jogo de tetris vai ter
#define VALID_SCREEN_WIDTH 11
#define VALID_SCREEN_HEIGHT 15

// Contantantes com o tamanho da tela
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Constante com a profundidade de cores
#define COLOR_DEPTH 32


/// "MainFunction"
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxx Nossa função main xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int main(int argc, char *argv[])
{
  /// "DeclaraVariaveis"
  // Janela do nosso jogo
  SDL_Window* gameWindow = NULL;
  
  // surface contendo a "janela". Tudo que "copiarmos" para essa surface
  // mais tarde vai aparecer na janela do jogo
  SDL_Surface* gScreenSurface = NULL;

  // surface para o fundo do jogo
  SDL_Surface* backgroundSDLSurface = NULL;
  
  /// "InicializaSDL"
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Não foi possível inicializar a SDL: " << SDL_GetError() << std::endl;
    return 1;
	}

  /// "CriaJanelaDoJogo"
  gameWindow = SDL_CreateWindow("My Game Window",
                            SDL_WINDOWPOS_UNDEFINED, // Posição (coord x)
                            SDL_WINDOWPOS_UNDEFINED, // Posição (coord y)
                            SCREEN_WIDTH,  // Largura da janela
                            SCREEN_HEIGHT, // Altura da Janela
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (gameWindow == NULL)
    {
      std::cout << "Não foi possível criar janela" << std::endl;
      return 0;
    }
  // Pega uma surface para a janela do jogo
  gScreenSurface = SDL_GetWindowSurface( gameWindow );

  // Carrega o background de uma bmp xxxxxxxxxxxxxxxxxxxxxxxxx
  backgroundSDLSurface = SDL_LoadBMP("assets/background.bmp");
  if( backgroundSDLSurface == NULL )
    {
      std::cout << "Não foi possível carregar imagem" << "assets/background.bmp\n"
                << "SDL Error: " << SDL_GetError() << std::endl;
      return 0;
    }


  /// "AplicaTelaDeFundo"
  //Apply the image
  SDL_BlitSurface( backgroundSDLSurface, NULL, gScreenSurface, NULL );
  
  // Copia a surface da janela para a tela
  SDL_UpdateWindowSurface( gameWindow );
  SDL_Delay(2000);
  
  /// "LimpaVariaveis"
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
  
  /// "RetornoDaMain"
  return 0;
}
