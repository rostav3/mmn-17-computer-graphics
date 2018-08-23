//
// Created by stav on 22/08/18.
//
#include <GL/glut.h>
#include "lamp.h"


void Lamp::draw() {

    // lamp base
    glPushMatrix();
    glColor4f(0.5f,0.5f,0.5f, 1.0f);
    glTranslated(1.8,0.025,1.8);
    glScaled(0.5,0.2,0.5);
    glRotatef(-90.0f, 1.0, 0.0, 0.0);
    glutSolidCone(0.5,0.5,50,50);
    glPopMatrix();


    // lamp pole
    glPushMatrix();
    glColor4f(0.5f,0.5f,0.5f, 1.0f);
    glTranslated(1.8,0.025,1.8);
    GLUquadricObj *quadratic= gluNewQuadric();
    glRotatef(-90.0f, 1.0, 0.0, 0.0);
    gluCylinder(quadratic,0.03,0.03,1.1,50,50);
    glPopMatrix();

    // lamp head
    glPushMatrix();
    glColor4f(1.0f,1.0f,1.0f, 0.5f);
    glTranslated(1.8,1.3,1.8);
    glScaled(0.5,0.5,0.5);
    glDisable(GL_LIGHTING);
    glutSolidSphere(0.4,50,50);
    glEnable(GL_LIGHTING);
    glPopMatrix();

}