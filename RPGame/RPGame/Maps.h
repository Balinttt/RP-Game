#ifndef MAPS_H
#define MAPS_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>

typedef struct Map {
	char** cord;
	int width;
	int height;
	int nr;
}Map;

Map* Create(const char* fileName);
Map* DrawMap(Map* map);





#endif// !MAPS_H