#pragma once
#include "Play.h"
#include "Game.h"
#include "Mapa.h"




Play::Play(int _nScena)
{ 
	srand(time(NULL));	
	
	readConfig(_nScena);
	if (_nScena != 2)  // Dependiendo del nivel que queramos cargar, el mapa se inicializa de una forma o de otra
		currentScene = PLAY1;
	else currentScene = PLAY2; 
	
	
	
	Mix_Music* cancionGAME{ Mix_LoadMUS("../../res/au/game_theme.mp3") }; // cargamos la cancion
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2); // volumen de la cancion
	Mix_PlayMusic(cancionGAME, -1);		// ponemos la cancion el bucle

	P1.Pos.x = RELATIVE_START_X;		//ponemos a cada player en su sitio 
	P1.Pos.y = RELATIVE_START_Y;		
	P2.Pos.x = RELATIVE_END_X - 10;			
	P2.Pos.y = RELATIVE_END_Y - 10;

	Renderer::Instance();
	Renderer::Instance()->LoadTexture("FondoPlay", PATH_IMG + "bgGame.jpg");//Cargamos las texturas de BG y de ambos players dentro del vector de render
	Renderer::Instance()->LoadTexture("Player1", PATH_IMG + "player1.png");
	Renderer::Instance()->LoadTexture("Player2", PATH_IMG + "player2.png");
}

void Play::readConfig(int _x)
{
	std::ifstream file("../../res/files/config.xml");
	buffer << file.rdbuf();
	file.close();
	std::string ids;
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);
	int id;
	int time;
	/*std::cout << "arrel: " << doc.first_node()->name() << std::endl;*/
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_attribute<> *pAttr;


	/*pRoot = pRoot->next_sibling();*/
	for (rapidxml::xml_node<> *pNode = pRoot->first_node("Level"); pNode; pNode = pNode->next_sibling())
	{
		pAttr = pNode->first_attribute("id");
		ids = pAttr->value();
		id = stoi(ids);

		if (id == _x) {
			switch (id)
			{
			case LVL1:
				std::cout << "SE CARGA EL LVL 1" << std::endl;
				pAttr = pNode->first_attribute("lives");
				ids = pAttr->value();
				P1.nLifes = P2.nLifes = id = stoi(ids);

				pAttr = pNode->first_attribute("time");
				ids = pAttr->value();
				Hud.timetoplay = time = stoi(ids);
				


				MapGame.InitMapa(_x);
				return;

			case LVL2:
				std::cout << "SE CARGA EL LVL 2" << std::endl;
				pAttr = pNode->first_attribute("lives");
				ids = pAttr->value();
				P1.nLifes = P2.nLifes = id = stoi(ids);

				pAttr = pNode->first_attribute("time");
				ids = pAttr->value();
				Hud.timetoplay = time = stoi(ids);
				MapGame.InitMapa(_x);
				MapGame.ModifyCellXML(1, 1, TipoCelda::VACIO);
				return;
			default:
				break;
			}
		}
	}



}


Play::~Play()
{
}

void Play::HandleEvents() {

	while (SDL_PollEvent(&event)) {
		
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) currentScene = typeScene::MENU;

		P1.GetEventKey(event);
		P2.GetEventKey(event);
	}
}

void Play::Update() {
	
	
	if (P1.d && P1.Pos.x >= RELATIVE_START_X && !P1.colLeft) // comprovamos que no sale de los limites
	{	
		
		// movemos el player hacia la direccion correspondiente (Lo mismo con la resta de condiciones)
		P1.Pos.x -= P1.vel;	
		//Colisiones con las celdas (Lo mismo con la resta de condiciones)
		if (MapGame.GetTypeCell(P1.RelativePos.x , P1.RelativePos.y) == TipoCelda::GRIS || MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::INDES) {
			P1.Pos.x += 2*P1.vel;
			P1.KEY = Mov::Nula;
		}
		// comprovamos si tiene o no tiene powerUP (Lo mismo con la resta de condiciones)
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::PATINS && !P1.onPwup)
		{
			P1.isPatin = true;
			MapGame.ModifyCell((P1.RelativePos.x), (P1.RelativePos.y), TipoCelda::VACIO, P1.score);
		}
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::CASC && !P1.onPwup)
		{
			P1.isCasc = true;
			MapGame.ModifyCell((P1.RelativePos.x), (P1.RelativePos.y), TipoCelda::VACIO, P1.score);
		}
	}
	else if (P1.a && P1.Pos.x <= (RELATIVE_END_X-5) && !P1.colRight)
	{
		
		P1.Pos.x += P1.vel;
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::GRIS || MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::INDES) {
			P1.Pos.x -= 2*P1.vel;
			P1.KEY = Mov::Nula;
		}
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::PATINS && !P1.onPwup)
		{
			P1.isPatin = true;
			MapGame.ModifyCell((P1.RelativePos.x), (P1.RelativePos.y), TipoCelda::VACIO, P1.score);
		}
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::CASC && !P1.onPwup)
		{
			P1.isCasc = true;
			MapGame.ModifyCell((P1.RelativePos.x), (P1.RelativePos.y), TipoCelda::VACIO, P1.score);
		}
	}
	else if (P1.w && P1.Pos.y <= (RELATIVE_END_Y -5) && !P1.colDown)
	{
		
		P1.Pos.y += P1.vel;
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::GRIS || MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::INDES) 
		{
			P1.Pos.y -= 2*P1.vel;
			P1.KEY = Mov::Nula;
		}
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::PATINS && !P1.onPwup)
		{
			P1.isPatin = true;
			MapGame.ModifyCell((P1.RelativePos.x), (P1.RelativePos.y), TipoCelda::VACIO, P1.score);
		}
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::CASC && !P1.onPwup)
		{
			P1.isCasc = true;
			MapGame.ModifyCell((P1.RelativePos.x), (P1.RelativePos.y), TipoCelda::VACIO, P1.score);
		}

	}
	else if (P1.s && P1.Pos.y >= RELATIVE_START_Y && !P1.colUp) 
	{
		
		P1.Pos.y -= P1.vel;
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::GRIS || MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::INDES) 
		{
			P1.Pos.y += 2*P1.vel;
			P1.KEY = Mov::Nula;
		}
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::PATINS && !P1.onPwup)
		{
			P1.isPatin = true;
			MapGame.ModifyCell((P1.RelativePos.x), (P1.RelativePos.y), TipoCelda::VACIO, P1.score);
		}
		if (MapGame.GetTypeCell(P1.RelativePos.x, P1.RelativePos.y) == TipoCelda::CASC && !P1.onPwup)
		{
			P1.isCasc = true;
			MapGame.ModifyCell((P1.RelativePos.x), (P1.RelativePos.y), TipoCelda::VACIO, P1.score);
		}
	}
	else if (P1.KEY == Mov::Space && !P1.cBoom)
	{	
		//PLANTAMOS LA BOMBA
		P1.cBoom = true;
		//PILLAMOS LA POSICION RELATIVA DE LA BOMBA Y LA TRANSFORMAMOS EN PIXELES PARA PODER PLANTARLA CORRECTAMENTE
		P1.posBombX = MapGame.GetCelda(P1.RelativePos.x, P1.RelativePos.y).x;
		P1.posBombY = MapGame.GetCelda(P1.RelativePos.x, P1.RelativePos.y).y;
		P1.Mybomb.Init(P1.posBombX, P1.posBombY);
		//FUNCION QUE MATA PLAYER deberia ir P1.posBombY pero por alguna razon no coge la cuadricula cuando en init si que la coje
		P1.KEY = Mov::Nula;
	}
	if (P1.cBoom){
	
		P1.Mybomb.timeBomb -= SCREEN_TICKS_PER_FRAME;
		if (P1.Mybomb.timeBomb <= 0) {
			P1.Mybomb.plantedBomb = true;
			if (P1.Mybomb.plantedBomb) {
				if (!P2.isCasc) P1.Mybomb.DamagePlayers(P2.RelativePos.x, P2.RelativePos.y, P1.posBombX, P1.posBombY, P2.nLifes, P1.score);
				//LA BOMBA DESTRUEIX TOTS ELS BLOCS DESTRUIBLES EN UN RANG DE 2 CASELLES
				P1.ControlMovement(Mov::Nula);
				MapGame.ModifyCell((P1.posBombX), (P1.posBombY), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P1.posBombX), (P1.posBombY + (2* RELATIVE_START_X)), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P1.posBombX), (P1.posBombY + (1* RELATIVE_START_X)), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P1.posBombX), (P1.posBombY - (2* RELATIVE_START_X)), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P1.posBombX), (P1.posBombY - (1* RELATIVE_START_X)), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P1.posBombX + (2* RELATIVE_START_X)), (P1.posBombY), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P1.posBombX + (1* RELATIVE_START_X)), (P1.posBombY), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P1.posBombX - (2* RELATIVE_START_X)), (P1.posBombY), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P1.posBombX - (1* RELATIVE_START_X)), (P1.posBombY), TipoCelda::VACIO, P1.score);
			}
			P1.Mybomb.timeBomb = 2;
			P1.cBoom = false;
		}
	}
	else if (P2.right && P2.Pos.x >= RELATIVE_START_X && !P2.colLeft)
	{
		
		P2.Pos.x -= P2.vel;
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::GRIS || MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::INDES) {
			P2.Pos.x += 2*P2.vel;
			P2.KEY = Mov::Nula;
		}
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::PATINS && !P2.onPwup)
		{
			P2.isPatin = true;
			MapGame.ModifyCell((P2.RelativePos.x), (P2.RelativePos.y), TipoCelda::VACIO, P2.score);
		}
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::CASC && !P2.onPwup)
		{
			P2.isCasc = true;
			MapGame.ModifyCell((P2.RelativePos.x), (P2.RelativePos.y), TipoCelda::VACIO, P2.score);
		}
	}
	else if (P2.left && P2.Pos.x <= (RELATIVE_END_X - 5 ) && !P2.colRight)
	{
		
		P2.Pos.x += P2.vel;
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::GRIS || MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::INDES) {
			P2.Pos.x -= 2 * P2.vel;
			P2.KEY = Mov::Nula;
		}
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::PATINS && !P2.onPwup)
		{
			P2.isPatin = true;
			MapGame.ModifyCell((P2.RelativePos.x), (P2.RelativePos.y), TipoCelda::VACIO, P2.score);
		}
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::CASC && !P2.onPwup)
		{
			P2.isCasc = true;
			MapGame.ModifyCell((P2.RelativePos.x), (P2.RelativePos.y), TipoCelda::VACIO, P2.score);
		}
	}
	else if (P2.up && P2.Pos.y <= (RELATIVE_END_Y - 5) && !P2.colDown)
	{
		
		P2.Pos.y += P2.vel;
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::GRIS || MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::INDES) 
		{
			P2.Pos.y -= 2 * P2.vel;
			P2.KEY = Mov::Nula;
		}
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::PATINS && !P2.onPwup)
		{
			P2.isPatin = true;
			MapGame.ModifyCell((P2.RelativePos.x), (P2.RelativePos.y), TipoCelda::VACIO, P2.score);
		}
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::CASC && !P2.onPwup)
		{
			P2.isCasc = true;
			MapGame.ModifyCell((P2.RelativePos.x), (P2.RelativePos.y), TipoCelda::VACIO, P2.score);
		}
	}
	else if (P2.down && P2.Pos.y >= RELATIVE_START_Y && !P2.colUp)
	{
	
		P2.Pos.y -= P2.vel;
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::GRIS || MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::INDES) 
		{
			P2.Pos.y += 2 * P2.vel;
			P2.KEY = Mov::Nula;
		}
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::PATINS && !P2.onPwup)
		{
			P2.isPatin = true;
			MapGame.ModifyCell((P2.RelativePos.x), (P2.RelativePos.y), TipoCelda::VACIO, P2.score);
		}
		if (MapGame.GetTypeCell(P2.RelativePos.x, P2.RelativePos.y) == TipoCelda::CASC && !P2.onPwup)
		{
			P2.isCasc = true;
			MapGame.ModifyCell((P2.RelativePos.x), (P2.RelativePos.y), TipoCelda::VACIO, P2.score);
		}
	}
	else if (P2.KEY == Mov::CTRL && !P2.cBoom)
	{

		P2.cBoom = true;
		P2.posBombX = MapGame.GetCelda(P2.RelativePos.x, P2.RelativePos.y).x;
		P2.posBombY = MapGame.GetCelda(P2.RelativePos.x, P2.RelativePos.y).y;
		P2.Mybomb.Init(P2.posBombX, P2.posBombY);
		P2.KEY = Mov::Nula;
	}
	if (P2.cBoom) {

		P2.Mybomb.timeBomb -= SCREEN_TICKS_PER_FRAME;
		if (P2.Mybomb.timeBomb <= 0) {
			P2.Mybomb.plantedBomb = true;
			if (P2.Mybomb.plantedBomb) {
				if (!P1.isCasc)P2.Mybomb.DamagePlayers(P1.RelativePos.x, P1.RelativePos.y, P2.posBombX, P2.posBombY, P1.nLifes, P2.score);
				//LA BOMBA DESTRUEIX TOTS ELS BLOCS DESTRUIBLES EN UN RANG DE 2 CASELLES
				MapGame.ModifyCell((P2.posBombX), (P2.posBombY), TipoCelda::VACIO, P1.score);
				MapGame.ModifyCell((P2.posBombX), (P2.posBombY + (2 * RELATIVE_START_X)), TipoCelda::VACIO, P2.score);
				MapGame.ModifyCell((P2.posBombX), (P2.posBombY + (1 * RELATIVE_START_X)), TipoCelda::VACIO, P2.score);
				MapGame.ModifyCell((P2.posBombX), (P2.posBombY - (2 * RELATIVE_START_X)), TipoCelda::VACIO, P2.score);
				MapGame.ModifyCell((P2.posBombX), (P2.posBombY - (1 * RELATIVE_START_X)), TipoCelda::VACIO, P2.score);
				MapGame.ModifyCell((P2.posBombX + (2 * RELATIVE_START_X)), (P2.posBombY), TipoCelda::VACIO, P2.score);
				MapGame.ModifyCell((P2.posBombX + (1 * RELATIVE_START_X)), (P2.posBombY), TipoCelda::VACIO, P2.score);
				MapGame.ModifyCell((P2.posBombX - (2 * RELATIVE_START_X)), (P2.posBombY), TipoCelda::VACIO, P2.score);
				MapGame.ModifyCell((P2.posBombX - (1 * RELATIVE_START_X)), (P2.posBombY), TipoCelda::VACIO, P2.score);
			}
			P2.Mybomb.timeBomb = 2;
			P2.cBoom = false;
		}
	}
	
	P1.IsDead(); // comprovamos si el player esta muerto
	P2.IsDead();
	P1.ControlMovement(P1.KEY);
	P2.ControlMovement(P2.KEY);
	if (P1.isDead || P2.isDead || Hud.timeOver) currentScene = MENU; // comprovamos si ha acabado el juego y canviamos la currentScene
	P1.PowerUps();		//si tiene powerups		
	P2.PowerUps();
}

void Play::Draw() {
	
	SDL_Rect fondoRect{ 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	Renderer::Instance()->PushImage("FondoPlay", fondoRect);//pintamos el fondo



	Hud.GameTime();//llamamos a la funcion del HUD para dibujarse
	Hud.LifesHUD(P1.nLifes, P2.nLifes);
	Hud.PointsHUD(P1.score, P2.score);

	MapGame.DrawMap();

	P1.AutoPaint("Player1");//funcion que autipinta al player1
	P2.AutoPaint("Player2");//funcion que autipinta al player2

	Renderer::Instance()->Render();
}
