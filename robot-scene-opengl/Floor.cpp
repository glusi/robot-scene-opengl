#include "Floor.h"



void Floor::draw() {
	glPushMatrix();
	//Normal
	glNormal3d(0, 1, 0);
	//Material
	Tools::assignMaterial(floor_material, 1);
	glMaterialf(GL_FRONT, GL_EMISSION, 1);
	for ( int x = -grid_size_x; x < grid_size_x; x++)
		for ( int y = -grid_size_y; y < grid_size_y; y++)
		{
			//Map texture tile
			glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(x * tile_size_x,0, y * tile_size_y);
			glTexCoord2f(0.0, 1.0); glVertex3f((x + 1) * tile_size_x, 0, y * tile_size_y);
			glTexCoord2f(1.0, 1.0); glVertex3f((x + 1) * tile_size_x, 0, (y + 1) * tile_size_y);
			glTexCoord2f(1.0, 0.0); glVertex3f(x * tile_size_x, 0, (y + 1) * tile_size_y);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	glPopMatrix();

	
}

void Floor::buildWalls() {
	glPushMatrix();
	//Wall material
	Tools::assignMaterial(material_wall, 0);
	//Create walls at borders of floor
	createWall(-grid_size_x * tile_size_x, -grid_size_y * tile_size_y, grid_size_x * tile_size_x, -grid_size_y * tile_size_y);
	createWall(-grid_size_x * tile_size_x, -grid_size_y * tile_size_y, -grid_size_x * tile_size_x, grid_size_y * tile_size_y);
	createWall(grid_size_x * tile_size_x, grid_size_y * tile_size_y, -grid_size_x * tile_size_x, grid_size_y * tile_size_y);
	createWall(grid_size_x * tile_size_x, grid_size_y * tile_size_y, grid_size_x * tile_size_x, -grid_size_y * tile_size_y);
	glPopMatrix();
}

void Floor::createWall(float x1, float y1, float x2, float y2)
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	//Map texture to wall quad
	glTexCoord2f(0.0, 0.0); glVertex3f(x1, 0, y1);
	glTexCoord2f(0.0, 1.0); glVertex3f(x2, 0, y2);
	glTexCoord2f(1.0, 1.0); glVertex3f(x2, WALL_HIEGHT, y2);
	glTexCoord2f(1.0, 0.0); glVertex3f(x1, WALL_HIEGHT, y1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
