/*----------------------------------------------------------------------------------------------------------------------
 * This classes represent all the items in the room.
 * Author: Roman Smirnov 312914443, Stav Rockah 307900878
 * -------------------------------------------------------------------------------------------------------------------*/

 // includes
#include <GL/glut.h>
#include "items.h"

/*----------------------------------------------------------------------------------------------------------------------
 * This method handle the draw of the ball
 * -------------------------------------------------------------------------------------------------------------------*/
void Ball::draw() {
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslated(-1.2,0.1,1);
	glutSolidSphere(0.12, 50, 50);
	glPopMatrix();
}

/*----------------------------------------------------------------------------------------------------------------------
 * This method handle the draw of the bowl
 * -------------------------------------------------------------------------------------------------------------------*/
void Bowl::draw() {
	glColor3f(0.3,0.6,0);
	glPushMatrix();
	glTranslated(1,-0.012,-0.7);
	glScaled(0.1,0.1,0.1);
	glRotatef(90.0f, 1.0, 0.0, 0.0);
	glutSolidTorus(0.6,0.71,20,50);
	glPopMatrix();
}

/*----------------------------------------------------------------------------------------------------------------------
 * This method handle the draw of the bone
 * -------------------------------------------------------------------------------------------------------------------*/
void Bone::draw() {
	glColor3f(1,0.9,0.8);

	glPushMatrix();
	glTranslated(-0.6,0.06,-0.35);
	glutSolidSphere(0.048, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.54,0.06,-0.35);
	glutSolidSphere(0.048, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.57,0.06,-0.25);
	glScaled(0.04,0.04,0.15);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.6,0.06,-0.15);
	glutSolidSphere(0.048, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.54,0.06,-0.15);
	glutSolidSphere(0.048, 50, 50);
	glPopMatrix();
}