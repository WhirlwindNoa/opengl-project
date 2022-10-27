#pragma once
#ifndef MAPS_H
#define MAPS_H

#include <vector>

#include "utilities.h"

const char* map1[6] = {
	"######",
	"#    #",
	"##  ##",
	"##  ##",
	"#    #",
	"######"
};



class Maps {
public:
	std::vector< std::vector<float> > world_map;

	Maps() {
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 6; i++) {
				if (map1[j][i] == '#') {
					int ypx = (j+1) * TILE;
					int xpx = (i+1) * TILE;

					world_map.push_back({ u_norm(xpx), u_norm(ypx) });
				}
			}
		}
	}
};


#endif