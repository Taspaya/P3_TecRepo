#pragma once
#include "Score.h"



Score::Score()
{
	currentScene = SCORE;
	Renderer::Instance();
	Renderer::Instance()->LoadTexture("Fondo", PATH_IMG + "bgGame.jpg");
}


Score::~Score()
{
}

void Score::HandleEvents() {


}

void Score::Update() {


}
void Score::Draw() {
	SDL_Rect fondoRectSCORE{ 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	Renderer::Instance()->PushImage("Fondo", fondoRectSCORE);
	Renderer::Instance()->Render();
}