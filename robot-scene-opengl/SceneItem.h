#pragma once
#include "tools.h"
#include "Vector3.h"
#include "Materials.h"

/**
 * A base class for all drawable objects in scene.
 */
class SceneItem
{
protected:
	
public:
	/**
	 * A virtual draw function to be overridden.
	 * 
	 */
	virtual void draw() = 0;
};

