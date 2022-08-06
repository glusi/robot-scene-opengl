#pragma once
#include "SceneItem.h"

class Floor : SceneItem
{
	const float WALL_HIGHT = 10;
	public:
		void draw();
		void createWall(float x1, float y1, float x2, float y2);
};

