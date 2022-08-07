#include "Floor.h"



void Floor::draw() {
	
	GLfloat color[4] = { 0,0,1,1 };
	

	glPushMatrix();
	//glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	//glEnable(GL_NORMALIZE);

	glColor3f(0, 0, 1);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, floor_material.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, floor_material.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, floor_material.Ks);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_material.Kd);

	for ( int x = -grid_size_x; x < grid_size_x; x++)
		for ( int y = -grid_size_y; y < grid_size_y; y++)
		{
			//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glEnable(GL_TEXTURE_2D);
			//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(x * tile_size_x,0, y * tile_size_y);
			glTexCoord2f(0.0, 1.0); glVertex3f((x + 1) * tile_size_x, 0, y * tile_size_y);
			glTexCoord2f(1.0, 1.0); glVertex3f((x + 1) * tile_size_x, 0, (y + 1) * tile_size_y);
			glTexCoord2f(1.0, 0.0); glVertex3f(x * tile_size_x, 0, (y + 1) * tile_size_y);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	//glEnd();
	glPopMatrix();

	
}

void Floor::buildWalls() {
	glPushMatrix();
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
	glTexCoord2f(0.0, 0.0); glVertex3f(x1, 0, y1);
	glTexCoord2f(0.0, 1.0); glVertex3f(x2, 0, y2);
	glTexCoord2f(1.0, 1.0); glVertex3f(x2, WALL_HIGHT, y2);
	glTexCoord2f(1.0, 0.0); glVertex3f(x1, WALL_HIGHT, y1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
