#pragma once
#include "Renderer.h"


class Button
{
public:
	
	//SDL_Rect recto;

	Text btnText;
	bool isHover;

	Button();
	~Button();

	void Init( Text _text);
	void AutoPaint(std::string, SDL_Rect _rect);
};

