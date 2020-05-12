#include "Players.h"
#include "Maps.h"

Player* Create(const char* fileName) {
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

	fclose(file);
	return new;
}


