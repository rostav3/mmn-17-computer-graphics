//
// Created by stav on 22/08/18.
//
#include <GL/glut.h>
#include "lamp.h"

void Lamp::draw() {
    glColor3f(0,0,0);

    glPushMatrix();
    glTranslated(1.8,0.025,1.8);
    glScaled(0.5,0.2,0.5);
    glRotatef(270.0f, 1.0, 0.0, 0.0);
    glutSolidCone(0.5,0.5,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.8,0.025,1.8);
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glRotatef(-90.0f, 1.0, 0.0, 0.0);

    gluCylinder(quadratic,0.03,0.03,1.1,50,50);
    glPopMatrix();


    glColor3f(1,1,1);

    glPushMatrix();
    glTranslated(1.8,1.3,1.8);
    glScaled(0.5,0.5,0.5);
    glRotatef(90.0f, 1.0, 0.0, 0.0);
    glutSolidCone(0.5,0.5,50,50);
    glPopMatrix();


}