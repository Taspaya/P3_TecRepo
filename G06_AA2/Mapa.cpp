#pragma once
#include "Mapa.h"
#include "Renderer.h"
#include <iostream>
#include <time.h>


Mapa::Mapa()
{
}

void Mapa::InitMapa(int _nLevel) 
{
	nLevel = _nLevel;
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			Map[i][j] = new Celda;	
			if(i == 0 || i == NUM_ROWS - 1)	Map[i][j]->InitVOID(RELATIVE_START_X + (RELATIVE_START_X * i), RELATIVE_START_Y + (RELATIVE_START_X * j));					// extremos de arriba y abajo vacios
			else if (j == 0 || j == 10)	Map[i][j]->InitVOID(RELATIVE_START_X + (RELATIVE_START_X * i), RELATIVE_START_Y + (RELATIVE_START_X * j));						// extremos de izquierda y derecha vacios
			else  if (i % 2 == 0 && nLevel != 2)	Map[i][j]->InitVOID(RELATIVE_START_X + (RELATIVE_START_X * i), RELATIVE_START_Y + (RELATIVE_START_X * j));			// filas pares de lvl 1 vacios
			else  if (i % 2 == 0 && nLevel == 2)	Map[i][j]->InitGRIS(RELATIVE_START_X + (RELATIVE_START_X * i), RELATIVE_START_Y + (RELATIVE_START_X * j));			// filas pares de lvl 2 ladrillos grises
			else if (j % 2 == 0)	Map[i][j]->InitVOID(RELATIVE_START_X + (RELATIVE_START_X * i), RELATIVE_START_Y + (RELATIVE_START_X * j));							// columnas pares vacias
			else  Map[i][j]->InitINDES(RELATIVE_START_X + (RELATIVE_START_X * i), RELATIVE_START_Y + (RELATIVE_START_X * j));											// inicialitzem la resta com indestructibles				
		}
	}
}

Point Mapa::GetCelda(int _x, int _y) 
{
	return { Map[_x][_y]->selector.x, Map[_x][_y]->selector.y }; // getter de la posicion de la celda que queramos del mapa
}


void Mapa::ModifyCell(int _x, int _y, TipoCelda _e, int &_c)	// FUNCION QUE NOS PERMITE MODIFICAR LA CELDA QUE QUERAMOS DEL MAPA Y MODIFICA ALEATORIAMENTE LOS DROPEOS DE LAS DESTRUIBLES
{
	/*_x = (int)((RELATIVE_START_X - _x) / -RELATIVE_START_X);
	_y = (int)((RELATIVE_START_Y - _y) / -RELATIVE_START_X);*/
	
	if (_x > 0 && _x < NUM_ROWS &&  _y > 0 && _y < NUM_COLUMNS) {
		if (Map[_x][_y]->cellID == TipoCelda::GRIS) {
			_c = _c+ 15;
			random = rand() % 10 + 1;
			if (random <= 2) {
				random = rand() % 2;
					if(random < 1)
					Map[_x][_y]->CellMorfer(TipoCelda::PATINS);
					else Map[_x][_y]->CellMorfer(TipoCelda::CASC);
			}
			else Map[_x][_y]->CellMorfer(_e);	
		}
		else Map[_x][_y]->CellMorfer(_e);
	}
}

TipoCelda Mapa::GetTypeCell(int _x, int _y) // GETTER DEL TIPO DE LA CELDA QUE QUERAMOS
{
	return  Map[_x][_y]->cellID;
}

void Mapa::DrawMap()	// PINTA TODO EL MAPA
{

	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			if(nLevel != 2)	Map[i][j]->AutoDrawINDES();
			else { Map[i][j]->AutoDrawGRIS(); Map[i][j]->AutoDrawINDES();
			}
		}
	}


}

Mapa::~Mapa()
{
}
