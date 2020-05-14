#include "Maps.h"
#include "Players.h"
#include <stdlib.h>
#include <stdio.h>

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
