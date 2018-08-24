//
// Created by stav on 22/08/18.
//
#include <GL/glut.h>
#include "lamp.h"

static GLfloat light0Ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
static GLfloat light0Diffuse[] = {0.9f,1.0f,0.8f,1.0f};
static GLfloat light0Specular[] = {0.9f,1.0f,0.8f,1.0f};
static GLfloat light0Position[] = {0.0, 0.0, 0.0, 1.0};



static GLfloat materialAmbient[] = {0.33, 0.33, 0.33, 1.0};
static GLfloat materialDiffuse[] = {0.78, 0.78, 0.78, 1.0};
static GLfloat materialSpecular[] = {0.99, 0.99, 0.99, 1.0};
static GLfloat materialShininess = 27.8;




void Lamp::init() {
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_AMBIENT, light0Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR, light0Specular);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1);
}

void Lamp::draw() {

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

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
    glColor4f(9.0f,1.0f,8.0f, 1.0f);
    glTranslated(1.8,1.3,1.8);
    glScaled(0.5,0.5,0.5);
    glDisable(GL_LIGHTING);
    glutSolidSphere(0.4,50,50);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glPopMatrix();
}