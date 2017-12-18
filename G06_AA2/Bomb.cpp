#pragma once
#include "Bomb.h"



Bomb::Bomb()
{
	timeBomb = 2;
	plantedBomb = false;
	Explosion = false; //inicializado en false
	Renderer::Instance();
	Renderer::Instance()->LoadTexture("Bomb", "../../res/img/items.png");//cargamos su textura 
	Renderer::Instance()->LoadTexture("Explozion", "../../res/img/explosion.png");//cargamos la textura de explosion
}


Bomb::~Bomb()
{
}

void Bomb::DamagePlayers(int PosPlayerX, int PosPlayerY, int _x, int _y, int &_vida, int &_punts) { // Funcio que fa dany al player a un rang de 2 caselles cada eix
	
	_x = (int)((RELATIVE_START_X - _x) / -RELATIVE_START_X);
	_y = (int)((RELATIVE_START_Y - _y) / -RELATIVE_START_X);

	if (PosPlayerX == _x && PosPlayerY == _y || PosPlayerX == _x + 1 && PosPlayerY == _y || PosPlayerX == _x + 2 && PosPlayerY == _y || PosPlayerX == _x && PosPlayerY == _y + 1 || PosPlayerX == _x && PosPlayerY == _y + 2 || PosPlayerX == _x - 1 && PosPlayerY == _y || PosPlayerX == _x - 2 && PosPlayerY == _y || PosPlayerX == _x && PosPlayerY == _y - 1 || PosPlayerX == _x && PosPlayerY == _y - 2) {
		Toched = true;
		std::cout << "Tocado" << std::endl;
		_vida--;
		_punts = _punts + 100;
	}

}

void Bomb::Init(int _x, int _y)
{
	textWidth = 144;//tamaño de la spritesheet
	textHeight = 96;//tamañod de la spritesheet
	frameWidth = textWidth / 3;//el tamaño del frame de la animacion es el tamaño total /3 por que hay 3 sprites y solo queremos coger el de la bomba
	frameHeight = textHeight / 2;//exactamente lo mismo pero con el largo
	bombrect.x = 0;//posicionamos el rectangulo para coger el sprite de la bomba
	bombrect.y = 48;
	selector.x = _x;//le decimos donde pintar la bomba
	selector.y =_y;
	bombrect.h = selector.h = frameHeight;
	bombrect.w = selector.w = frameWidth;

}

void Bomb::AutoDraw() {
	Renderer::Instance()->PushSprite("Bomb", bombrect, selector);//llamamos a la funcion pasandole el nombre y los dos rectangulos
}




