#pragma once
#include "Character.h"
#include "Renderer.h"
#include <time.h>
#include "Constants.h"



class HUD
{
public:
	
	bool timeOver;
	clock_t timeStart;
	Text LifeP1; //texto de las vidas del player 1
	Text LifeP2; //texto de las vidas del player 2
	Text PointP1; //texto de la puntuacion del player 1
	Text PointP2; //texto de la puntuacion del player 2
	Text GAMEOVER; //texto de fin del juego
	SDL_Rect P1Rect; //Rectangulo vidas P1
	SDL_Rect P2Rect; //Rectangulo vidas P2
	SDL_Rect Point1Rect; //Rectangulo Puntuacion P1
	SDL_Rect Point2Rect; //Rectangulo Puntuacion P2
	SDL_Rect GameOverRect;
	float time; //tiempo de duracion de la partida
	Font game_over; //STRUCT DEFINIDO POR TONA EN TYPES.H
	Font MarioLuigi;
	SDL_Rect TextTime;
	Text Time; //STRUCT DEFINIDO POR TONA EN TYPES.H
	Color TimeColor; //STRUCT DEFINIDO POR TONA EN TYPES.H
	Color ColorP1;
	Color ColorP2;

public:
	void GameTime();//funcion que controlara el tiempo de la partida
	void LifesHUD(int x, int y);//funcion que mostrara las vidas de los jugadores
	void PointsHUD(int x, int y);//funcion que mostrara los puntos de ambos jugadores
	void GameOver();
	HUD();
	~HUD();
};

