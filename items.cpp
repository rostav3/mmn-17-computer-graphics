//
// Created by Roman Smirnov on 22/08/2018.
//

#include <GL/glut.h>
#include "items.h"

void Walls::draw() {
	//    walls
	glPushMatrix();
	glTranslated(0.4, 1, -1.59);
	glScaled(4.0, 2.0, 0.025);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4, 1, 2.39);
	glScaled(4.0, 2.0, 0.025);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.39, 1, 0.4);
	glScaled(0.025, 2.0, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.59, 1, 0.4);
	glScaled(0.025, 2.0, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();
}