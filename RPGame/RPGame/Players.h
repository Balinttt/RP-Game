#ifndef PLAYERS_H
#define PLAYERS_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>

typedef struct Player {
	int posx;
	int posy;
	int level;
	int hp;
}Player;

Player* Create(const char* fileName);



#endif// !PLAYERS_H