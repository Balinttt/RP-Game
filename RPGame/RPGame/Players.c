#include "Players.h"
#include "Maps.h"
#include <stdlib.h>
#include <stdio.h>

Player* CreatePlayer(const char* fileName) {
	Player* new = (Player*)calloc(1, sizeof(Player));
	if (!new) {
		printf("Sikertelen lefoglalas.");
		exit(1);
	}
	FILE* file = fopen(fileName, "r");
	fscanf(file, "%i", &new->level);
	fscanf(file, "%i", &new->hp);
	new->posx = 1;
	new->posy = 1;
	new->standingOn = 'o';

	fclose(file);
	return new;
}

Player* SpawnPlayer(Map* map, Player* player) {
	player->standingOn = map->cord[player->posx][player->posy];
	map->cord[player->posx][player->posy] = 'P';
	return map;
}

Player* MoveRight(Map* map, Player* player) {
	if (map->cord[player->posx][player->posy +1] != '2'){
	player->posy++;
	map -> cord[player->posx][player->posy - 1] = player -> standingOn;
	player->standingOn = map->cord[player->posx][player->posy];
	}
	else {
		map->cord[player->posx][player->posy] = player->standingOn;
	}
	return player;
}

Player* MoveLeft(Map* map, Player* player) {
	if (map->cord[player->posx][player->posy - 1] != '2') {
		player->posy--;
		map->cord[player->posx][player->posy + 1] = player->standingOn;
		player->standingOn = map->cord[player->posx][player->posy];
	}
	else {
		map->cord[player->posx][player->posy] = player->standingOn;
	}	
	return player;
}

Player* MoveUp(Map* map, Player* player) {
	if (map->cord[player->posx - 1][player->posy] != '3'){
		player->posx--;
		map->cord[player->posx + 1][player->posy] = player->standingOn;
		player->standingOn = map->cord[player->posx][player->posy];
	}
	else {
		map->cord[player->posx][player->posy] = player->standingOn;
	}
	return player;
}

Player* MoveDown(Map* map, Player* player) {
	if (map->cord[player->posx + 1][player->posy] != '3') {
		player->posx++;
		map->cord[player->posx - 1][player->posy] = player->standingOn;
		player->standingOn = map->cord[player->posx][player->posy];
	}
	else {
		map->cord[player->posx][player->posy] = player->standingOn;
	}
	return player;
}

Player* MovePlayer(Map* map1, Player* player1) {
	char option = '1';
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

	}
}


