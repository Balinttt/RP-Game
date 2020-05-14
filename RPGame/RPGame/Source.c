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
	map1 = CreateMap("map1.txt");

	Map* menumap;
	menumap = CreateMap("menumap.txt");

	Player* player1;
	player1 = CreatePlayer("player1.txt");

	DrawMenu("Menu.txt");
	getch();

	system("cls");
	SpawnPlayer(menumap, player1);
	DrawMap(menumap);
	MovePlayer(menumap, player1);
	
	
	
	/*SpawnPlayer(map1, player1);
	DrawMap(map1);
	MovePlayer(map1, player1);*/





	/*char option = '1';	
		while (option != '0') {
			option = getch();

			switch ((char)option) {
			case 'a':
				system("cls");
				MoveLeft(map1, player1);
				SpawnPlayer(map1, player1);
				DrawMap(map1);
				break;
			case 'd':
				system("cls");
				MoveRight(map1, player1);
				SpawnPlayer(map1, player1);
				DrawMap(map1);
				break;
			case 'w':
				system("cls");
				MoveUp(map1, player1);
				SpawnPlayer(map1, player1);
				DrawMap(map1);
				break;
			case 's':
				system("cls");
				MoveDown(map1, player1);
				SpawnPlayer(map1, player1);
				DrawMap(map1);
				break;
			}
			
		}*/
	return 0;
}