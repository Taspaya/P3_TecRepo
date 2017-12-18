#pragma once
#include "Button.h"
#include "Renderer.h"


Button::Button()
{

}
Button::~Button()
{

}

void Button::AutoPaint(std::string _text,SDL_Rect _rect) {

	//recto = _rect;
	Renderer::Instance()->PushImage(_text, _rect);
}

void Button::Init(Text _text) {
	
	Renderer::Instance();
	Renderer::Instance()->LoadFont({ _text.id , "../../res/ttf/MarioLuigi2.ttf", 80 });
	Renderer::Instance()->LoadTextureText(_text.id, _text);
	

}


