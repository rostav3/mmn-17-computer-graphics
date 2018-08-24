//
// Created by stav on 22/08/18.
//

#include "room.h"
#include <GL/glut.h>

static GLfloat mat_ambient[] = {0.5f,0.5f,0.5f,0.1f};
static GLfloat mat_diffuse[] = {0.5f,0.5f,0.5f,1.0f};
static GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
static GLfloat mat_shininess[] = {50.0f};

void Room::draw(){
//    glEnable(GL_TEXTURE_2D);
//    glDisable(GL_TEXTURE_2D);


    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

//    walls
    glPushMatrix();
    glColor4f(0.5f,0.5f,0.5f, 1.0f);
    glTranslated(0.4,1,-1.59);
    glScaled(4.0,2.0,0.025);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.5f,0.5f,0.5f, 1.0f);
    glTranslated(0.4,1,2.39);
    glScaled(4.0,2.0,0.025);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.5f,0.5f,0.5f, 1.0f);
    glTranslated(2.39,1,0.4);
    glScaled(0.025,2.0,4.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.5f,0.5f,0.5f, 1.0f);
    glTranslated(-1.59,1,0.4);
    glScaled(0.025,2.0,4.0);
    glutSolidCube(1.0);
    glPopMatrix();
}
