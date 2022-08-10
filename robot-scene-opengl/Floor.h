#pragma once
#include "SceneItem.h"

class Floor : SceneItem
{
	//height of wall
	const float WALL_HIEGHT = 10;
	//Grid tiles on x
	const int grid_size_x = 4;
	//Grid tiles on y
	const int grid_size_y = 4;
	//Tile size X
	const int tile_size_x = 4;
	//Tile size Y
	const int tile_size_y = 4;
	public:
		/* 	Draws the floor	*/
		void draw();
		/*	Draws the walls around the floor */
		void buildWalls();
		/*
		Creates a wall between two points with WALL_HIEGHT height
		@x1 - x of first point
		@y1 - y of first point
		@x2 - x of second point
		@y2 - y of second point
		*/
		void createWall(float x1, float y1, float x2, float y2);
};

