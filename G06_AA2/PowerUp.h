#pragma once
#include "Renderer.h"
#include "Character.h"

class PowerUp
{
public:
	SDL_Rect CasRect, SelectorCasc;
	SDL_Rect SpeedRect, SelectorSpeed;
	int textWidth, textHeight, frameWidth, frameHeight;//tamaños

public:
	void InitCasc(int x, int y);
	void InitSpeed(int x, int y);

	void AutodrawCasc();
	void AutodrawSpeed();
	
	PowerUp();
	~PowerUp();
};

