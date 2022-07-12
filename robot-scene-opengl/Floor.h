#pragma once
#include "SceneItem.h"

class Floor : SceneItem
{
	materialStruct floor_material{
		{0.05f,0.05f,0.05f,1.0f}, // Ka
		{0.5f,0.5f,0.5f,1.0f}, // Kd
		{0.7f,0.7f,0.04f,1.0f}, // Ks
		1000.3 // n
		};
	public:
		void draw();
};

