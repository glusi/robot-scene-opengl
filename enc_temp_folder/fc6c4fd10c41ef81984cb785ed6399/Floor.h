#pragma once
#include "SceneItem.h"

class Floor : SceneItem
{
	//height of wall
	const float WALL_HIEGHT = 10;
	//Grid tiles on x
	const int grid_size_x = 5;
	//Grid tiles on y
	const int grid_size_y = 5;
	//Grid tiles on x
	const int tile_size_x = 5;
	const int tile_size_y = 5;
	public:
		void draw();
		void buildWalls();
		void createWall(float x1, float y1, float x2, float y2);
};

