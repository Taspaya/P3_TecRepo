#include "HUD.h"



HUD::HUD()		// Inicializamos valores del HUD
{
	
	timeStart = clock();
	game_over.id = "gameover";
	game_over.path = "../../res/ttf/game_over.ttf";
	game_over.size = 100;

	MarioLuigi.id = "marioluigi";
	MarioLuigi.path = "../../res/ttf/MarioLuigi2.ttf";
	MarioLuigi.size = 50;

	TimeColor.a = 0;
	TimeColor.r = 0;
	TimeColor.g = 0;
	TimeColor.b = 0;

	ColorP1.a = 0;
	ColorP1.r = 255;
	ColorP1.g = 255;
	ColorP1.b = 255;

	ColorP2.a = 0;
	ColorP2.r = 165;
	ColorP2.g = 0;
	ColorP2.b = 0;


	Time.id = "Time";
	Time.color = TimeColor;
	Time.w = 100;
	Time.h = 100;

	LifeP1.id = "VidaP1";
	LifeP1.color = ColorP1;
	LifeP1.w = 100;
	LifeP1.h = 100;

	LifeP2.id = "VidaP2";
	LifeP2.color = ColorP2;
	LifeP2.w = 100;
	LifeP2.h = 100;

	PointP1.id = "PuntosP1";
	PointP1.color = ColorP1;
	PointP1.w = 50;
	PointP1.h = 50;

	PointP2.id = "PuntosP2";
	PointP2.color = ColorP2;
	PointP2.w = 50;
	PointP2.h = 50;

	GAMEOVER.id = "GameOver";
	GAMEOVER.color = TimeColor;
	GAMEOVER.w = 200;
	GAMEOVER.h = 200;

	TextTime = { SCREEN_WIDTH/2-50, -20, Time.w, Time.h };
	P1Rect = { 100, -20, LifeP1.w, LifeP1.h };
	P2Rect = { 450, -20, LifeP2.w, LifeP2.h };
	Point1Rect = { 240, 20, PointP1.w, PointP1.h};
	Point2Rect = { 580, 20, PointP2.w, PointP2.h };
	GameOverRect = { SCREEN_WIDTH/2-50, SCREEN_HEIGHT/2-50, GAMEOVER.w, GAMEOVER.h };
	Renderer::Instance()->LoadFont(game_over);
	Renderer::Instance()->LoadFont(MarioLuigi);
	timeOver = false;
}


HUD::~HUD()
{
}

void HUD::GameTime() { // SI EL TIEMPO DE JUEGO LLEGA A 80, SE CIERRA EL JUEGO
	
	time = (clock() - timeStart) / (double)CLOCKS_PER_SEC;
	
	if (time >= 80) { 
		timeOver = true;
		GameOver(); 
	}
	Time.text = "TIME : " + std::to_string(int(time));
	Renderer::Instance()->LoadTextureText(game_over.id, Time);
	Renderer::Instance()->PushImage("Time", TextTime);

}

void HUD::LifesHUD(int x, int y) {				// PINTAMOS LAS VIDAS DEL PLAYER
	LifeP1.text = "LIFES P1 : " + std::to_string(x);
	LifeP2.text = "LIFES P2 : " + std::to_string(y);
	Renderer::Instance()->LoadTextureText(game_over.id, LifeP1);
	Renderer::Instance()->LoadTextureText(game_over.id, LifeP2);
	Renderer::Instance()->PushImage("VidaP1", P1Rect);
	Renderer::Instance()->PushImage("VidaP2", P2Rect);
}

void HUD::PointsHUD(int x, int y) {			// PINTAMOS LA SCORE DE LOS PLAYERS
	PointP1.text = std::to_string(x);
	PointP2.text = std::to_string(y);
	Renderer::Instance()->LoadTextureText(MarioLuigi.id, PointP1);
	Renderer::Instance()->LoadTextureText(MarioLuigi.id, PointP2);
	Renderer::Instance()->PushImage("PuntosP1", Point1Rect);
	Renderer::Instance()->PushImage("PuntosP2", Point2Rect);
}

void HUD::GameOver() {		// PINTA GAME OVER AL ACABAR LA PARTIDA
	GAMEOVER.text = "GAME OVER!";
	Renderer::Instance()->LoadTextureText(game_over.id, GAMEOVER);
	Renderer::Instance()->PushImage("GameOver", GameOverRect);
	
}
