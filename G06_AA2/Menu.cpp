#pragma once
#pragma warning

#include "Menu.h"
#include "Game.h"



Menu::Menu()
{
	currentScene = MENU;
	Renderer::Instance();
	Renderer::Instance()->LoadTexture("FondoPlay", PATH_IMG + "bgGame.jpg");		//Cargamos las texturas de BG y de ambos players dentro del vector de render
	
	PausedMusic = false;
	Mix_Music* cancionmenu { Mix_LoadMUS("../../res/au/menu.mp3") };
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	Mix_PlayMusic(cancionmenu, -1);

	Btn_Play1.Init({ "Play1", "Play1" ,{ 0,0,250,1 } ,100 ,100 });
	Btn_Play2.Init({ "Play2", "Play2" ,{ 50,0,200,1 } ,100 ,100 });
	Btn_Score.Init({ "Score", "Score" ,{ 150,0,200,1 } ,100 ,100 });
	Btn_Music.Init({ "Music", "Music",{ 100,10,200,1 } ,100 ,100 });
	Btn_Exit.Init({ "Exit", "Exit",{ 100,10,200,1 } ,100 ,100 });
	
	btnRectPlay1 = {(SCREEN_WIDTH/2 - 50), 150, 100,100};
	btnRectPlay2 = { (SCREEN_WIDTH / 2 - 50), 250, 100,100 };
	btnRectScore = { (SCREEN_WIDTH / 2 - 50), 350, 100, 100 };
	btnRectMusic = { (SCREEN_WIDTH / 2 - 50), 450, 100, 100 };
	btnRectExit = { (SCREEN_WIDTH / 2 - 50), 550, 100, 100 };

}


Menu::~Menu()
{
}

void Menu::HandleEvents() {
	
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_MOUSEMOTION) {
			mouseX = event.motion.x;
			mouseY = event.motion.y;
			std::cout << mouseX << "	|	" << mouseY << std::endl;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN) 
		{
			if ((mouseX >= btnRectPlay1.x && mouseX <= btnRectPlay1.x + 100) && (mouseY <= btnRectPlay1.y + 100 && mouseY >= btnRectPlay1.y)) { Btn_Play1.isHover = true; } // hover mouse 1
			else if ((mouseX >= btnRectPlay2.x && mouseX <= btnRectPlay2.x + 100) && (mouseY <= btnRectPlay2.y + 100 && mouseY >= btnRectPlay2.y)) { Btn_Play2.isHover = true; } // hover mouse 2
			else if ((mouseX >= btnRectScore.x && mouseX <= btnRectScore.x + 100) && (mouseY <= btnRectScore.y + 100 && mouseY >= btnRectScore.y)) { Btn_Score.isHover = true; } // hover mouse Score
			else if ((mouseX >= btnRectMusic.x && mouseX <= btnRectMusic.x + 100) && (mouseY <= btnRectMusic.y + 100 && mouseY >= btnRectMusic.y)) { Btn_Music.isHover = true; } // hover mouse Score
			else if ((mouseX >= btnRectExit.x && mouseX <= btnRectExit.x + 100) && (mouseY <= btnRectExit.y + 100 && mouseY >= btnRectExit.y)) { Btn_Exit.isHover = true; } // hover mouse Score
			else
			{
				Btn_Play1.isHover = false;
				Btn_Play2.isHover = false;
				Btn_Score.isHover = false;
				Btn_Music.isHover = false;
				Btn_Exit.isHover = false;
			}
		}

	}

}


void Menu::Update() {
	
	if (Btn_Exit.isHover){	// QUAN PRESIONEM CLICK SOBRE EL BOTÓ, CANVIEM D'ESCENA
		std::cout << "SALISTE" << std::endl;
		currentScene = EXIT;
		SDL_Quit();
		Btn_Exit.isHover = false;
	}
	else if (Btn_Play1.isHover) {
		std::cout << "CANVIEM ESCENA A PLAY1" << std::endl;
		currentScene = PLAY1;
		Btn_Play1.isHover = false;
		/*CANVIEM ESCENA A PLAY1 */
	}
	else if (Btn_Play2.isHover) {
		std::cout << "CANVIEM ESCENA A PLAY2" << std::endl;
		currentScene = PLAY2;/*CANVIEM ESCENA A PLAY2 */
		Btn_Play2.isHover = false;
	}
	else if (Btn_Score.isHover) {
		std::cout << "CANVIEM ESCENA A SCORE" << std::endl;
		currentScene = SCORE;
		Btn_Score.isHover = false;
	}
	else if (Mix_PausedMusic() == 0){
		if (Btn_Music.isHover) {
			std::cout << "MUSICA" << std::endl;
			std::cout << "Musica Activada" << std::endl;
			Mix_PauseMusic();
			Btn_Music.isHover = false;
		}
	}
	else if (Mix_PausedMusic() == 1) {
		if (Btn_Music.isHover) {
			std::cout << "MUSICA" << std::endl;
			std::cout << "Musica Activada" << std::endl;
			Mix_ResumeMusic();
			Btn_Music.isHover = false;
		}
	}
}


void Menu::Draw() {

	SDL_Rect fondoRect{ 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	Renderer::Instance()->PushImage("FondoPlay", fondoRect);	
	
	Btn_Play1.AutoPaint("Play1", btnRectPlay1);
	Btn_Play2.AutoPaint("Play2", btnRectPlay2);
	Btn_Score.AutoPaint("Score", btnRectScore);
	Btn_Music.AutoPaint("Music", btnRectMusic);
	Btn_Exit.AutoPaint("Exit", btnRectExit);

	Renderer::Instance()->Render();
}
