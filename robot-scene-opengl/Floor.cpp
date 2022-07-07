#include "Floor.h"



void Floor::draw() {
	int grid_size_x = 10;
	int grid_size_y = 10;
	int tile_size_x = 1;
	int tile_size_y = 1;
	GLfloat color[4] = { 0,0,1,1 };

	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	glEnable(GL_NORMALIZE);

	glColor3f(0, 0, 1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, red_shiny_plastic.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, red_shiny_plastic.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, red_shiny_plastic.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red_shiny_plastic.Kd);

	for ( int x = -grid_size_x; x < grid_size_x; x++)
		for ( int y = -grid_size_y; y < grid_size_y; y++)
		{
			glVertex3f(x * tile_size_x,0, y * tile_size_y);
			glVertex3f((x + 1) * tile_size_x, 0, y * tile_size_y);
			glVertex3f((x + 1) * tile_size_x, 0, (y + 1) * tile_size_y);
			glVertex3f(x * tile_size_x, 0, (y + 1) * tile_size_y);
		}
	glEnd();
	glPopMatrix();

}
