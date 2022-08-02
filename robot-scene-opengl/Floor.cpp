#include "Floor.h"



void Floor::draw() {
	int grid_size_x = 4;
	int grid_size_y = 4;
	int tile_size_x = 4;
	int tile_size_y = 4;
	GLfloat color[4] = { 0,0,1,1 };

	glPushMatrix();
	//glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	//glEnable(GL_NORMALIZE);

	glColor3f(0, 0, 1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, floor_material.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, floor_material.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, floor_material.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_material.Kd);

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
