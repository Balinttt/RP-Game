#ifndef PLAYERS_H
#define PLAYERS_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include"Maps.h"

typedef struct Player {
	int posx;
	int posy;
	int level;
	int hp;
	char standingOn;
}Player;

Player* CreatePlayer(const char* fileName);
Player* SpawnPlayer(Map* map, Player* player);

Player* MoveRight(Map* map, Player* player);
Player* MoveLeft(Map* map, Player* player);
Player* MoveUp(Map* map, Player* player);
Player* MoveDown(Map* map, Player* player);
Player* MovePlayer(Map* map, Player* player);



#endif// !PLAYERS_H