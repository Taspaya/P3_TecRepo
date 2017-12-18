#pragma once
#include "Scene.h"
#include "Button.h"


class Menu : public Scene
{
public:
	int mouseX;
	int mouseY;

	bool PausedMusic;

	Button Btn_Play1;	
	Button Btn_Play2;
	Button Btn_Score;
	Button Btn_Music;
	Button Btn_Exit;

	Mix_Music *menusong;

	SDL_Rect btnRectPlay1;
	SDL_Rect btnRectPlay2;
	SDL_Rect btnRectScore;
	SDL_Rect btnRectMusic;
	SDL_Rect btnRectExit;

	SDL_Event event;
	
	/*Button *Btn_Play1;
	Button *Btn_Play2;
	Button *Btn_Exit;*/
	
	void HandleEvents() override;//permite sobreescribir las virtual 
	void Update() override;
	void Draw() override;

	Menu();
	~Menu();

};

