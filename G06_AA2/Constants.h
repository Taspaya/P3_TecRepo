#pragma once
#include <string>

#define SCREEN_FPS 60.0f
#define SCREEN_TICKS_PER_FRAME (1.0f / SCREEN_FPS)

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 704

#define LVL1 0
#define LVL2 2
// ==== >PLAYER< ======
#define PLAYER_START_N_LIFES 3
#define PLAYER_START_SCORE 0
#define PLAYER_START_VELOCITY 3
#define PLAYER_TEXTURE_WIDTH 144
#define PLAYER_TEXTURE_HEIGHT 192

// ==== >MAPA< ======
#define NUM_ROWS 13
#define NUM_COLUMNS 11

#define RELATIVE_START_X 48
#define RELATIVE_START_Y 128

#define RELATIVE_END_X 624
#define RELATIVE_END_Y 608

// ==== >CELDAS< ====
#define VALOR_X_GRIS 48
#define VALOR_Y_GRIS 0

#define VALOR_X_ROJO 100
#define VALOR_Y_ROJO 0

#define VALOR_X_INDES 0
#define VALOR_Y_INDES 0

#define VALOR_X_VACIO 48
#define VALOR_Y_VACIO 128

#define VALOR_X_CASC 96
#define VALOR_Y_CASC 48

#define VALOR_X_PATINS 48
#define VALOR_Y_PATINS 48

struct Point { int x; int y; }; //punto compuesto por 2 int
enum class Mov { A, D, S, W, Nula, Space, Left, Right, Up, Down, CTRL};//enum class de las teclas del usuario P1

const std::string MENU_BG = "MENU_BG";
const std::string PLAY_BG = "PLAY_BG";
const std::string PLAY_GOLD = "PLAY_GOLD";
const std::string PLAYER_SPRITE = "PLAYER_SPRITE";
const std::string PLAY_TEXT_SCORE_PLAYER1 = "PLAY_TEXT_SCORE_PLAYER1";
const std::string MENU_TEXT_BUTTON_PLAY = "MENU_TEXT_BUTTON_PLAY";
const std::string MENU_TEXT_BUTTON_EXIT = "MENU_TEXT_BUTTON_EXIT";

const std::string PATH_IMG = "../../res/img/";
const std::string PATH_FONT = "../../res/ttf/";
const std::string PATH_AU = "../../res/au/";

const std::string SAIYAN_80 = "SAIYAN_80";
const std::string LUIGI_40 = "LUIGI_40";


enum TipoCelda { VACIO, GRIS, ROJO, INDES, PATINS, CASC };