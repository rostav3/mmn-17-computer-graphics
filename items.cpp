//
// Created by Roman Smirnov on 22/08/2018.
//

#include <GL/glut.h>
#include "items.h"

void Ball::draw() {
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslated(-1.2,0.1,1);
	glScaled(0.1,0.1,0.1);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();
}

void Bowl::draw() {
	glColor3f(0.3,0.6,0);
	glPushMatrix();
	glTranslated(1,-0.012,-0.7);
	glScaled(0.1,0.1,0.1);
	glRotatef(90.0f, 1.0, 0.0, 0.0);
	glutSolidTorus(0.6,0.71,20,50);
	glPopMatrix();
}

//void Projector::draw() {
//	glColor3f(0.4,0.4,0.4);
//	glPushMatrix();
//	glTranslated(0.25,0.07,0.7);
//	glScaled(0.15,0.15,0.15);
//	glRotatef(45.0f, 1.0, 0.0, 0.0);
//	glutSolidCone(0.6,0.71,20,50);
//	glPopMatrix();
//}

void Bone::draw() {
	glColor3f(1,0.9,0.8);

	glPushMatrix();
	glTranslated(-0.6,0.06,-0.35);
	glScaled(0.06,0.06,0.06);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.54,0.06,-0.35);
	glScaled(0.06,0.06,0.06);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.57,0.06,-0.25);
	glScaled(0.04,0.04,0.15);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6,0.06,-0.15);
	glScaled(0.06,0.06,0.06);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.54,0.06,-0.15);
	glScaled(0.06,0.06,0.06);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();
}


