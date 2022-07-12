#pragma once
#include "SceneItem.h"
#include "Texture.h"

class Floor : SceneItem
{
	materialStruct red_shiny_plastic{
		{0.0, 0.0, 0.3, 1.0}, // Ka
		{0.0, 0.0, 0.6, 1.0}, // Kd
		{0.8, 0.6, 0.6, 1.0}, // Ks
		100.0 // n
		};
	Texture texture;
	public:
		Floor();
		void draw();
};

