//
// Created by stav on 22/08/18.
//
#include <GL/glut.h>
#include "window.h"

static GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
static GLfloat diffuse[] = {0.9f,1.0f,0.8f,1.0f};
static GLfloat specular[] = {0.9f,1.0f,0.8f,1.0f};
static GLfloat position[] = {0.0, 0.0, 0.0, 1.0};
static GLfloat direction[] = {0.0, 0.0, 0.0};


void Window::init() {
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1,GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1,GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1,GL_SPECULAR, specular);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.1);
    x = -1.58;
    y = 1;
    z = 0.4;
}

void Window::draw() {
    glPushMatrix();
    glColor4f(0.8f,1.0f,0.6f, 1.0f);
    glTranslated(x,y,z);
    glScaled(0.025,0.5,0.5);
    glDisable(GL_LIGHTING);
    glutSolidCube(1.0);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glPopMatrix();

    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,  direction);
}

void Window::setY(double val){
    y = val;
}
void Window::setZ(double val){
    z = val;
}

double Window::getY(){
    return y;
}
double Window::getZ(){
    return z;
}
