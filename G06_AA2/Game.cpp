#pragma once
#include "Game.h"



Game::Game()
{
	MyScene = new Menu();	//generamos el new de play	
	tipoEscena = MENU;		// Empezamos en Menu
}


Game::~Game()
{
}

void Game::Run() {
	while (tipoEscena != EXIT) // Mientras no salgamos del juego....
	{
		switch (tipoEscena)		
		{
		case PLAY1:
			MyScene = new Play(1);						// MyScene pasa a apuntar a un nuevo objeto Play, que recibe un caracter que no es 2, por lo tanto, es lvl 1
			while (tipoEscena == PLAY1) {				// Escena que nos movera al nivel 1 del juego
				tipoEscena = MyScene->GetTypeScene();	// Pillamos el tipoEscena de la clase hijo
				MyScene->HandleEvents();				
				MyScene->Update();
				MyScene->Draw();
				
			}
			break;
		case PLAY2:
			MyScene = new Play(2);						//  MyScene pasa a apuntar a un nuevo objeto Play, que recibe un 2
			while (tipoEscena == PLAY2) {				
				tipoEscena = MyScene->GetTypeScene();
				MyScene->HandleEvents();
				MyScene->Update();
				MyScene->Draw();

			}
			break;
		case MENU:
			MyScene = new Menu();						//  MyScene pasa a apuntar a un nuevo objeto Menu
			while (tipoEscena == MENU) {//control de los eventos		
				tipoEscena = MyScene->GetTypeScene();
				MyScene->HandleEvents();
				MyScene->Update();
				MyScene->Draw();

			}
			break;
		case SCORE:
			MyScene = new Score();
			while (tipoEscena == SCORE) {//control de los eventos
				tipoEscena = MyScene->GetTypeScene();
				MyScene->HandleEvents();
				MyScene->Update();
				MyScene->Draw();
			}
			break;
		case EXIT:
		default:
			break;
		}
	}
	


	
}