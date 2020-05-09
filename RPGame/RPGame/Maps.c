#include "Maps.h"

Map* Create(const char* fileName) {
	Map* new = (Map*)calloc(1, sizeof(Map));
	if (!new) {
		printf("Sikertelen lefoglalas.");
		exit(1);
	}
	FILE* file = fopen(fileName, "r");
	fscanf(file, "%i", &new->nr);
	fscanf(file, "%i", &new->width);
	fscanf(file, "%i", &new->height);

	new->cord = (char**)(calloc(&new->height, sizeof(char*)));
	//ellenorzes
	for (int i = 0; i < new->width; ++i) {
		new->cord[i] = (char*)(calloc(&new->width, sizeof(char)));
	}
	//ellenorzes

	for (int i = 0; i < new->height; ++i) {
		for (int j = 0; j < new->width; ++j) {
			fscanf(file, "%c", &new->cord[i][j]);
		}
	}

	fclose(file);
	return new;
}

Map* DrawMap(Map* map) {
	map->cord[0][0] = "x";
	for (int i = 0; i < map->height; ++i) {
		for (int j = 0; j < map->width; ++j) {
			printf("%c",&map->cord[i][j]);
		}
		printf("\n");
	}
}