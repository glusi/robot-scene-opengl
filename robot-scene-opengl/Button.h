#pragma once
#include "Vector3.h"
#include <string>

class Button
{
public:
	Vector3 position;
	float length;
	float width;
	std::string name;
	Button(Vector3 position, float length, float width, std::string name);

};

