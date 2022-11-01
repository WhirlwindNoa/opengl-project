#pragma once
#ifndef MAPS_H
#define MAPS_H

#include <vector>
#include <iostream>

#include "config.h"
#include "graphics.h"

const char* map1[] = {
	"############",
	"#..........#",
	"#..........#",
	"#..........#",
	"#..........#",
	"#..........#",
	"#..........#",
	"#..........#",
	"#..........#",
	"#..........#",
	"#..#....#..#",
	"####....####",
	"xxxxxxxxxxxx"
};

// map is read from down to up, expect it to be reversed.

int mapsize[2] = { *(&map1 + 1) - map1, *(&map1[0] + 1) - map1[0] };

class Maps {
public:
	std::vector<std::vector<int>> world;

	Maps() {
		for (int j = 0; j < mapsize[0]; j++) {
			for (int i = 0; i < mapsize[1]; i++) {
				if (map1[j][i] == '#') {
					int ypx = ((j)*TILE) - 550;
					int xpx = ((i)*TILE) - 550;

					int c1 = 255;
					int c2 = 255;
					int c3 = 255;

					world.push_back({ xpx, ypx, c1, c2, c3});
				}
				else if (map1[j][i] == 'x') {
					int ypx = ((j)*TILE) - 550;
					int xpx = ((i)*TILE) - 550;

					int c1 = 255;
					int c2 = 0;
					int c3 = 0;

					world.push_back({ xpx, ypx, c1, c2, c3 });
				}
			}
		}
	}
};


#endif