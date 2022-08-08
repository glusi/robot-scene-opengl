#include "Tools.h"
#include <string>
#include <iostream>

void Tools::drawCylinder(float radius, float height, int slices) {
	GLUquadricObj* IDquadric = gluNewQuadric();
	gluQuadricNormals(IDquadric, GLU_SMOOTH);  // Create Smooth Normals ( NEW )
	gluCylinder(IDquadric, radius, radius, height, slices, slices);
}

void Tools::rotate(float angle, ROTATION_TYPE rotation_type)
{
	switch (rotation_type) {
	case ROTATED_AROUND_X: glRotatef(angle, 1, 0, 0);
	case ROTATED_AROUND_Y: glRotatef(angle, 0, 1, 0);
	case ROTATED_AROUND_Z: glRotatef(angle, 0, 0, 1);
	}
}

void Tools::assignMaterial(materialStruct  material) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, material.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, material.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.Kd);
}

void Tools::copyColor(float **ambient_color, float* new_color)
{
	for (int i = 0; i < 4; i++) {
		(*ambient_color)[i] = new_color[i];
	}
}

std::string Tools::concatStrings(const char* one, const char* two)
{
	std::string buf(one);
	buf.append(two);
	return buf;
}

void Tools::AlignForWidth(float width, float alignment)
{
	ImGuiStyle& style = ImGui::GetStyle();
	float avail = ImGui::GetContentRegionAvail().x;
	float off = (avail - width) * alignment;
	if (off > 0.0f)
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
}

void Tools::drawBox(GLfloat size, GLenum type)
{
    static GLfloat n[6][3] =
    {
      {-1.0, 0.0, 0.0},
      {0.0, 1.0, 0.0},
      {1.0, 0.0, 0.0},
      {0.0, -1.0, 0.0},
      {0.0, 0.0, 1.0},
      {0.0, 0.0, -1.0}
    };
    static GLint faces[6][4] =
    {
      {0, 1, 2, 3},
      {3, 2, 6, 7},
      {7, 6, 5, 4},
      {4, 5, 1, 0},
      {5, 6, 2, 1},
      {7, 4, 0, 3}
    };
    GLfloat v[8][3];
    GLint i;

    v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

    for (i = 5; i >= 0; i--) {
        glBegin(type);
        glNormal3fv(&n[i][0]);
        glVertex3fv(&v[faces[i][0]][0]);
        glVertex3fv(&v[faces[i][1]][0]);
        glVertex3fv(&v[faces[i][2]][0]);
        glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
    }
}

void APIENTRY Tools::glutSolidCube(GLdouble size)
{
    drawBox(size, GL_QUADS);
}