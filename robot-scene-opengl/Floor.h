#pragma once
#include "SceneItem.h"

class Floor : SceneItem
{
	const float WALL_HIGHT = 10;
	int grid_size_x = 4;
	int grid_size_y = 4;
	int tile_size_x = 4;
	int tile_size_y = 4;
	public:
		void draw();
		void buildWalls();
		void createWall(float x1, float y1, float x2, float y2);
};

