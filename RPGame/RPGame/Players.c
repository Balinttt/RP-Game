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

Map* CreateMap(const char* fileName) {
	Map* new = (Map*)calloc(1, sizeof(Map));
	if (!new) {
		printf("Sikertelen lefoglalas.");
		exit(1);
	}
	FILE* file = fopen(fileName, "r");
	fscanf(file, "%i", &new->nr);
	fscanf(file, "%i", &new->width);
	fscanf(file, "%i", &new->height);

	new->cord = (char**)(calloc(new->height, sizeof(char*)));
	if (!new->cord) {
		printf("Sikertelen lefoglalas.");
		exit(1);
	}
	for (int i = 0; i < new->width; ++i) {
		new->cord[i] = (char*)(calloc(new->width, sizeof(char)));
		if (!new->cord[i]) {
			printf("Sikertelen lefoglalas.");
			exit(1);
		}
	}
	char character;
	fscanf(file, "%c", &character);
	for (int i = 0; i < new->height; ++i) {
		for (int j = 0; j < new->width; ++j) {
			fscanf(file, "%c\n", &character);
			new->cord[i][j] = character;
		}
	}

	fclose(file);
	return new;
}

//Gate* CreateGate(Map* map, int posx, int posy){
//	Gate* new = (Gate*)calloc(1, sizeof(Gate));
//	if (!new) {
//		printf("Sikertelen lefoglalas.");
//		exit(1);
//	}
//	new->posx = posx;
//	new->posy = posy;
//	new->isopen = false;
//	map->cord[posx][posy] = ']';
//}
//
//Gate* GateFunction(Map* map, Gate* gate, char action) {
//	if (action == 'O') {
//		gate->isopen = true;
//		map->cord[gate->posx][gate->posy] = '/';
//	}
//	if (action == 'C') {
//		gate->isopen = false;
//		map->cord[gate->posx][gate->posy] = ']';
//	}
//	return gate;
//}

Player* SpawnPlayer(Map* map, Player* player) {
	player->standingOn = map->cord[player->posx][player->posy];
	map->cord[player->posx][player->posy] = 'P';
	return map;
}

Player* MoveRight(Map* map, Player* player) {
	if (IsWall(map, player->posx, player->posy+1) == false) {
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
	if (IsWall(map, player->posx, player->posy - 1) == false) {
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
	if (IsWall(map, player->posx-1, player->posy) == false) {
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
	if (IsWall(map, player->posx + 1, player->posy) == false) {
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
		//case 'f':
		//	system("cls");
		//	GateFunction(map1, gate, 'O');
		//	//MoveDown(map1, player1);
		//	//SpawnPlayer(map1, player1);
		//	DrawMap(map1);
		//	break;
		}

	}
}

Map* DrawMap(Map* map) {
	for (int i = 0; i < map->height; ++i) {
		for (int j = 0; j < map->width; ++j) {
			if (map->cord[i][j] == '3') {
				printf("-");
			}
			else if (map->cord[i][j] == '2') {
				printf("|");
			}
			else if (map->cord[i][j] == 'o') {
				printf(" ");
			}
			else if (map->cord[i][j] == 'P') {
				printf("X");
			}
			else { printf("%c", map->cord[i][j]); }
		}
		printf("\n");
	}
}

void DrawMenu(const char* fileName) {
	FILE* file = fopen(fileName, "r");
	char c[128];
	while (fgets(c, sizeof(c), file) != NULL) {
		fputs(c, stdout);
	}
	fclose(file);
}

bool IsWall(Map* map, int posx, int posy) {
	if (map->cord[posx][posy] == '2') {
		return true;
	}
	else if (map->cord[posx][posy] == '3') {
		return true;
	}
	else if (map->cord[posx][posy] == '_') {
		return true;
	}
	else if (map->cord[posx][posy] == ']') {
		return true;
	}
	return false;
}


