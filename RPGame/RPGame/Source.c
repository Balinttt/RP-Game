#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include"Windows.h"
#include"Maps.h"
#include "Players.h"

int main() {
	Map* map1;
	map1 = Create("map1.txt");
	DrawMenu("Menu.txt");
	DrawMap(map1);
	Player* player1;
	player1 = Create("player1.txt");
	//SpawnPlayer(map1, player1);
	DrawMap(map1);
	/*int option=0;
	printf("Your option:");
	scanf("%i", option);
	switch(option) {
	case 1:		
		DrawMap(map1);
		break;
	}*/

	return 0;
}