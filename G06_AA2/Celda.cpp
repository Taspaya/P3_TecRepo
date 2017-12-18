#pragma once
#include "Celda.h"


Celda::Celda()
{
	textWidth = 144;//tamaño de la spritesheet
	textHeight = 96;//tamañod de la spritesheet
	Renderer::Instance();
	Renderer::Instance()->LoadTexture("wall", "../../res/img/items.png");//cargamos su textura 
	cellID = TipoCelda::VACIO;
}


Celda::~Celda()
{
}

//LE DICES EN EL PARAMETRO A QUE LO QUIERES METER
void Celda::CellMorfer(TipoCelda e) { // Metodo que nos permite canviar el sprite de la celda
	switch (e)
	{
	case VACIO:
		celRect.x = RELATIVE_START_X;
		celRect.y = VALOR_Y_VACIO;
		cellID = TipoCelda::VACIO;
		break;
	case GRIS:
		celRect.x = VALOR_X_GRIS;
		celRect.y = VALOR_Y_GRIS;
		cellID = TipoCelda::GRIS;
		break;
	case ROJO:
		celRect.x = VALOR_X_ROJO;
		celRect.y = VALOR_Y_ROJO;
		cellID = TipoCelda::ROJO;
		break;
	case INDES:
		celRect.x = VALOR_X_INDES;
		celRect.y = VALOR_Y_INDES;
		cellID = TipoCelda::ROJO;
		break;
	case PATINS:
		celRect.x = VALOR_X_PATINS;
		celRect.y = VALOR_Y_PATINS;
		cellID = TipoCelda::PATINS;
		break;
	case CASC:
		celRect.x = VALOR_X_CASC;
		celRect.y = VALOR_Y_CASC;
		cellID = TipoCelda::CASC;
		break;
	}

}

void Celda::InitINDES(int x, int y) { // inicialitzem valor de la celda
	cellID = TipoCelda::INDES;
	frameWidth = textWidth / 3;//el tamaño del frame de la animacion es el tamaño total /3 por que hay 3 sprites y solo queremos coger el de la bomba
	frameHeight = textHeight / 2;//exactamente lo mismo pero con el largo
	celINDESTRect.x = VALOR_X_INDES;//posicionamos el rectangulo para coger el sprite de la bomba
	celINDESTRect.y = VALOR_Y_INDES;
	selectorINDEST.x = x;//le decimos donde pintar la bomba
	selectorINDEST.y = y;
	celINDESTRect.h = selectorINDEST.h = frameHeight;
	celINDESTRect.w = selectorINDEST.w = frameWidth;
}

void Celda::AutoDrawINDES() {
	Renderer::Instance()->PushSprite("wall", celINDESTRect, selectorINDEST);//llamamos a la funcion pasandole el nombre y los dos rectangulos
}


void Celda::InitGRIS(int x, int y)
{
	cellID = TipoCelda::GRIS;
	frameWidth = textWidth / 3;//el tamaño del frame de la animacion es el tamaño total /3 por que hay 3 sprites y solo queremos coger el de la bomba
	frameHeight = textHeight / 2;//exactamente lo mismo pero con el largo
	celRect.x = VALOR_X_GRIS;//posicionamos el rectangulo para coger el sprite de la bomba
	celRect.y = VALOR_Y_GRIS;
	selector.x = x;//le decimos donde pintar la bomba
	selector.y = y;
	celRect.h = selector.h = frameHeight;
	celRect.w = selector.w = frameWidth;

}


void Celda::InitVOID(int x, int y)
{
	cellID = TipoCelda::VACIO;
	frameWidth = 0;//el tamaño del frame de la animacion es el tamaño total /3 por que hay 3 sprites y solo queremos coger el de la bomba
	frameHeight = 0;//exactamente lo mismo pero con el largo
	celRect.x = RELATIVE_START_X;//posicionamos el rectangulo para coger el sprite de la bomba
	celRect.y = 128;
	selector.x = x;//le decimos donde pintar la bomba
	selector.y = y;
	celRect.h = selector.h = frameHeight;
	celRect.w = selector.w = frameWidth;

}



void Celda::AutoDrawGRIS()
{
	Renderer::Instance()->PushSprite("wall", celRect, selector);//llamamos a la funcion pasandole el nombre y los dos rectangulos

}

void Celda::InitROJA(int x, int y) {
	
	
	cellID = TipoCelda::ROJO;
	frameWidth = textWidth / 3;//el tamaño del frame de la animacion es el tamaño total /3 por que hay 3 sprites y solo queremos coger el de la bomba
	frameHeight = textHeight / 2;//exactamente lo mismo pero con el largo
	
	celROJARect.x = VALOR_X_ROJO;//posicionamos el rectangulo para coger el sprite de la bomba
	celROJARect.y = VALOR_Y_ROJO;
	selectorROJA.x = x;//le decimos donde pintar la bomba
	selectorROJA.y = y;
	celROJARect.h = selectorROJA.h = frameHeight;
	celROJARect.w = selectorROJA.w = frameWidth;

}

void Celda::AutoDrawROJA()
{
	Renderer::Instance()->PushSprite("wall", celROJARect, selectorROJA);//llamamos a la funcion pasandole el nombre y los dos rectangulos

}


Point Celda::GetCellLocation() // funcion para saber la posicion de la celda
{
	return Location = { selector.x,selector.y }; 

}