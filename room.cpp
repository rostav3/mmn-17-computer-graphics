//
// Created by stav on 22/08/18.
//

#include "room.h"
#include <GL/glut.h>

void Room::draw(){
    glColor3f(0.8,0.8,0.8);
    // floor
//    glEnable(GL_TEXTURE_2D);
//    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslated(0.4,0,0.4);
    glScaled(4.0,0.025,4.0);
    glutSolidCube(1.0);
    glPopMatrix();

//    glPushMatrix();
//    glTranslated(0.4,2.0,0.4);
//    glScaled(4.0,0.025,4.0);
//    glutSolidCube(1.0);
//    glPopMatrix();

//    walls
    glPushMatrix();
    glTranslated(0.4,1,-1.59);
    glScaled(4.0,2.0,0.025);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.4,1,2.39);
    glScaled(4.0,2.0,0.025);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.39,1,0.4);
    glScaled(0.025,2.0,4.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.59,1,0.4);
    glScaled(0.025,2.0,4.0);
    glutSolidCube(1.0);
    glPopMatrix();


    // window
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslated(-1.58,1,0.4);
    glScaled(0.025,0.5,0.5);
    glutSolidCube(1.0);
    glPopMatrix();

}
