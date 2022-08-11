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

void Tools::assignMaterial(materialStruct  material, float emmision) {
	//Assign Ka, n, Ks and Kd values of material
	glMaterialfv(GL_FRONT, GL_AMBIENT, material.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, material.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.Kd);
	glMaterialf(GL_FRONT, GL_EMISSION, emmision);
}

void Tools::copyColor(float ** dst_color, float* new_color)
{
	for (int i = 0; i < 4; i++) {
		(*dst_color)[i] = new_color[i];
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

void Tools::drawBox()
{
    int i, n = sizeof(cube) / (sizeof(cube[0]));
    glBegin(GL_QUADS);
    for (i = 0; i < n; i += 5)
    {
        glTexCoord2dv(cube + i + 3);
        glVertex3dv(cube + i + 0);
    }
    glEnd();
}

void APIENTRY Tools::glutSolidCube(GLdouble size)
{
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    drawBox();
    glPopMatrix();
}