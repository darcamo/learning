#include "game.h"

Game::Game() : gameTable(VALID_SCREEN_HEIGHT, VALID_SCREEN_WIDTH)
{
	// Seta um modo de vídeo com 16 bits
	screenSDLSurface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16, NULL /*SDL_FULLSCREEN*/);
    if ( screenSDLSurface == NULL) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		exit(1);
    }

	// Seta o título da janela com o nome do jogo
	SDL_WM_SetCaption("Blocos", "Blocos");

// 	screenSDLSurface = pScreen;
// 	valid_screen_width = 440; // 11 blocos
// 	valid_screen_height = 760; // 19 blocos
// 
	
	load_data();
	 
	prevTicksInt = 0;
	curTicksInt = 0;
	updateDelayInt = 600;
	figurePtr = 0;
	srand(time(NULL));
	pointsInt = 0;
	
	// Cria um objeto figure para nextFigurePtr
	newFigure(nextFigurePtr);
}


Game::~Game()
{
	delete nextFigurePtr;
	SDL_FreeSurface(backgroundSDLSurface);
	SDL_FreeSurface(blockSDLSurface);
	SDL_FreeSurface(boardSDLSurface);
	SDL_FreeSurface( textSDLSurface );
	//Close the font that was used
	TTF_CloseFont( font );
}


void Game::load_data()
{
	// Carrega o background e converte para o formato da tela.
	load_SDLSurface("background.bmp", backgroundSDLSurface);
	
	
	// Carrega blocos e converte para o formato da tela
	load_SDLSurface("block.bmp", blockSDLSurface);
	
	
	load_SDLSurface("board.bmp", boardSDLSurface);
	
	

	font = TTF_OpenFont( "Comic_Sans_MS_Bold.ttf", 28 );
	//If there was an error in loading the font
	 if( font == NULL )
	 {
		 std::cout << "Não foi possível carregar fonte" << std::endl;
		 exit(2);
	 }
	 
	 
	///@todo carregar o resto das coisas.

	// Carrega sons

}



void Game::draw_background()
{
	SDL_Rect rect_background, rect_valid_screen_src, rect_valid_screen_dest;
	   /* The SDL blitting function needs to know how much data to copy.
       We provide this with SDL_Rect structures, which define the
       source and destination rectangles. The areas should be the
       same; SDL does not currently handle image stretching. */
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = backgroundSDLSurface->w; /* copy the entire image */
    rect_background.h = backgroundSDLSurface->h;

	rect_valid_screen_src.x = 0;
	rect_valid_screen_src.y = 0;
	rect_valid_screen_src.w = boardSDLSurface->w; /* copy the entire image */
	rect_valid_screen_src.h = boardSDLSurface->h;

	rect_valid_screen_dest.x = 100;
	rect_valid_screen_dest.y = 0;
	rect_valid_screen_dest.w = boardSDLSurface->w; /* copy the entire image */
	rect_valid_screen_dest.h = boardSDLSurface->h;

	SDL_BlitSurface(backgroundSDLSurface, &rect_background, screenSDLSurface, &rect_background);
	SDL_BlitSurface(boardSDLSurface, &rect_valid_screen_src, screenSDLSurface, &rect_valid_screen_dest);
}



void Game::draw_Board(int pXOffsetInt, int pYOffsetInt, Board *pBoard)
{
	SDL_Rect rect_block_src, rect_block_dest;
	
	rect_block_src.x = 0;
	rect_block_src.y = 0;
	rect_block_src.w = blockSDLSurface->w; /* copy the entire image */
	rect_block_src.h = blockSDLSurface->h;
	
	rect_block_dest.w = blockSDLSurface->w; /* copy the entire image */
	rect_block_dest.h = blockSDLSurface->h;
	
	for(int i=0;i<pBoard->get_nRows();i++)
	{
		for(int k=0;k<pBoard->get_nCols();k++)
		{
			if(pBoard->get_value(i,k)==true)
			{
				rect_block_dest.x = k*40 + pXOffsetInt;
    			rect_block_dest.y = i*40 + pYOffsetInt;
				SDL_BlitSurface(blockSDLSurface, &rect_block_src, screenSDLSurface, &rect_block_dest);
			}
		}
	}
}


void Game::draw_score(int pXOffsetInt, int pYOffsetInt)
{
	SDL_Rect rect_block_src, rect_block_dest;
	// Cor que será utilizada para a pontuação
	SDL_Color textColor = {255,255,255};
	
	// Converte a pontuação para um array de char para poder usar a função TTF_RenderText_Solid
	char buf[16];
	snprintf(buf, 16, "%d", pointsInt);
	// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	
	
	//Render the text 
	textSDLSurface = TTF_RenderText_Solid( font, buf, textColor );
	
	//Apply the images to the screenSDLSurface 
	rect_block_src.x = 0;
	rect_block_src.y = 0;
	rect_block_src.w = textSDLSurface->w; /* copy the entire image */
	rect_block_src.h = textSDLSurface->h;
	rect_block_dest.w = blockSDLSurface->w; /* copy the entire image */
	rect_block_dest.h = blockSDLSurface->h;
	rect_block_dest.x = pXOffsetInt;
	rect_block_dest.y = pYOffsetInt;
	SDL_BlitSurface(textSDLSurface, &rect_block_src, screenSDLSurface, &rect_block_dest);
}



void Game::draw_everything()
{
	draw_background();
	
	draw_Board(100,0, &gameTable);
	
	draw_Board(600,80, nextFigurePtr->get_figureGrid());
	
	draw_score(600,20);
	
}


void Game::play()
{

	Uint8 *keystate;
	int quit = 0;

    /* framerate counter variables */
	curTicksInt = SDL_GetTicks(); /* for keeping track of timing */
	prevTicksInt = curTicksInt;
	
	int lastRefreshTic, actualRefreshTic;
	lastRefreshTic = actualRefreshTic = curTicksInt;
	
	draw_everything();


	while (quit == 0) {
	
		actualRefreshTic = SDL_GetTicks();
				
		/* Update SDL's internal input state information. */
		SDL_PumpEvents();
		
		if(actualRefreshTic - lastRefreshTic > 65)
		{
			lastRefreshTic = actualRefreshTic;
			if(update() == true)
			{
				player_lost();
			}
			
			/* Grab a snapshot of the keyboard. */
			keystate = SDL_GetKeyState(NULL);
			
			/* Respond to input. */
			if (keystate[SDLK_q] || keystate[SDLK_ESCAPE]) quit = 1;
			
			/* Left and right arrow keys control turning. */
			if (keystate[SDLK_LEFT]) {
				move_left();}
			if (keystate[SDLK_RIGHT]) {
				move_right();}
			if (keystate[SDLK_DOWN]) {
				move_down();}
			if (keystate[SDLK_UP]) {
				change_right();}
			if (keystate[SDLK_f]) {
				fill_last_line();}
			if (keystate[SDLK_SPACE]) {
				move_to_bottom();}
		}

    	draw_everything();
		/* Ask SDL to update the entire screenSDLSurface. */
    	SDL_UpdateRect(screenSDLSurface, 0, 0, 0, 0);
	}

    std::cout << "Pontos = " << pointsInt << std::endl;
    exit(0);
}


void Game::player_lost()
{
	std::cout << "Você perdeu" << std::endl;
	std::cout << "Pontos = " << pointsInt << std::endl;
	exit(0);
}


void Game::fill_last_line()
{
	gameTable.set_line(VALID_SCREEN_HEIGHT-1, true);
}


bool Game::update()
{
	if(figurePtr == 0)
	{
		figurePtr = nextFigurePtr;
		newFigure(nextFigurePtr);

		figurePtr->set_position(0,5);
		nextFigurePtr->set_position(4,3);
		
		if(figurePtr->detect_collision())
		{
			delete figurePtr;
			figurePtr = 0;
			return true;
		}
		figurePtr->draw();
	}


	curTicksInt = SDL_GetTicks();
	if(curTicksInt - prevTicksInt > updateDelayInt)
	{
		prevTicksInt = curTicksInt;

		// Se houver colisão tá na hora de deletar essa figura e criar outra.
		if(figurePtr->move_down() == true)
		{
			delete figurePtr;
			figurePtr = 0;
			detect_full_line();
		}
	}
	
	return false;
}


bool Game::move_down()
{
	if(figurePtr == 0)
	{
		return true;
	}
	return figurePtr->move_down();
}

void Game::move_to_bottom()
{
	while(move_down() == false)
	{}
}


bool Game::move_left()
{
	if(figurePtr == 0)
	{
		return true;
	}
	return figurePtr->move_left();
}


bool Game::move_right()
{
	if(figurePtr == 0)
	{
		return true;
	}
	return figurePtr->move_right();
}



bool Game::change_right()
{
	if(figurePtr == 0)
	{
		return true;
	}
	return figurePtr->change_right();
}


void Game::detect_full_line()
{
	int n = 0; //quantas linhas serão deletadas de uma só vez
	for(int i = 0; i < VALID_SCREEN_HEIGHT; i++)
	{
		if(gameTable.is_line_set(i) == true)
		{
			n++;
			gameTable.delete_line(i);
		}
	}
	
	if(n != 0)
	{
		pointsInt += 100*(int)(pow(3,n-1));
	}

}



void Game::load_SDLSurface(const char * pBitmapFileName, SDL_Surface * &pSurfacePtr)
{
	SDL_Surface *temp;
	
	//Carrega o arquivo de bitmap na superfície temporária
	temp = SDL_LoadBMP(pBitmapFileName);
	if (temp == NULL) {
		printf("Unable to load backgroundSDLSurface.\n");
		exit(1);
	}
	
	//Converte a superfície para em outra superfície adequada para o formato de tela (possibilitar blits mais rápidos)
	pSurfacePtr = SDL_DisplayFormat(temp);
	
	// Libera memória da superfície temporária
	SDL_FreeSurface(temp);
}


void Game::newFigure(Figure * &pFigurePtr)
{
	int Nfigures = 9;
	
	switch(random() % Nfigures)
		{
			case 0:
				pFigurePtr = new FigureBolt(&gameTable);
				break;
			case 1:
				pFigurePtr = new FigureBolt2(&gameTable);
				break;
			case 2:
				pFigurePtr = new FigureLDireito(&gameTable);
				break;
			case 3:
				pFigurePtr = new FigureLEsquerdo(&gameTable);
				break;
			case 4:
				pFigurePtr = new FigureLine(&gameTable);
				break;
			case 5:
				pFigurePtr = new FigureV(&gameTable);
				break;
			case 6:
				pFigurePtr = new FigureSquare(&gameTable);
				break;
			case 7:
				pFigurePtr = new FigureT(&gameTable);
				break;
			case 8:
				pFigurePtr = new FigurePlus(&gameTable);
				break;
		}
}

