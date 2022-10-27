#pragma once
#ifndef MAPS_H
#define MAPS_H

#include <vector>
#include <iostream>

#include "utilities.h"

const char* map1[12] = {
	"############",
	"############",
	"############",
	"############",
	"############",
	"############",
	"###### #####",
	"############",
	"############",
	"############",
	"############",
	"### ########"
};



class Maps {
public:
	std::vector< std::vector<float> > world_map;

	Maps() {
		for (int j = 0; j < 12; j++) {
			for (int i = 0; i < 12; i++) {
				if (map1[j][i] == '#') {
					int ypx = ((j) * TILE) - 550;
					int xpx = ((i)*TILE) - 550;

					world_map.push_back({ u_norm(xpx), u_norm(ypx) });
					std::cout << xpx << " " << ypx << std::endl;
				}
			}
		}
	}
};


#endif