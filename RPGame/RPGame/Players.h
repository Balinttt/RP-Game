#ifndef PLAYERS_H
#define PLAYERS_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"Maps.h"

typedef struct Player {
	int posx;
	int posy;
	int level;
	int hp;
	char standingOn;
}Player;

typedef struct Map {
	char** cord;
	int width;
	int height;
	int nr;
}Map;

//typedef struct Gate {
//	int posx;
//	int posy;
//	bool isopen;
//}Gate;

void DrawMenu(const char* fileName);

Player* CreatePlayer(const char* fileName);
Map* CreateMap(const char* fileName);
//Gate* CreateGate(Map* map, int posx, int posy);
//Gate* GateFunction(Map* map, Gate* gate, char action);

Map* DrawMap(Map* map);
Player* SpawnPlayer(Map* map, Player* player);
bool IsWall(Map* map, int posx, int posy);

Player* MoveRight(Map* map, Player* player);
Player* MoveLeft(Map* map, Player* player);
Player* MoveUp(Map* map, Player* player);
Player* MoveDown(Map* map, Player* player);
Player* MovePlayer(Map* map, Player* player);


#endif// !PLAYERS_H