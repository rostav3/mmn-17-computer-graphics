//
// Created by stav on 22/08/18.
//

// includes
#include <GL/glut.h>
#include <cmath>
#include "dog.h"


Dog::Dog() {
    animationCounter = 0;
    ticksCounter = 0;
    tailUpAndDown = false;
    tailRightAndLeft = false;
    headRightAndLeft = false;
    headUpAndDown = false;
    x = 0.25;
    y = 0.15;
    z = 0.35;
}

void Dog::draw(){
    ticksCounter++;
    animationCounter += (ticksCounter%6 == 0) ? 1 : 0;

    glColor3f(0.8,0.5,0.2);
    if (walk){
        z += 0.01;
    }

    // tail
    glPushMatrix();
    glTranslated(x,y,z-0.2);
    glRotatef(45.0f,  tailUpAndDown ? (GLfloat)pow(-1,animationCounter%2) : 0, tailRightAndLeft ? (GLfloat)pow(-1,animationCounter%2) : 0, 0.0);
    glScaled(0.03,0.03,0.08);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslated(x+0.05,y-0.085,z-0.05);
    glRotatef(15.0f, moveBackLeftLeg ? (GLfloat)pow(-1,animationCounter%2) : 0,0,0);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x-0.05,y-0.085,z-0.05);
    glRotatef(-15.0f, moveBackRightLeg ? (GLfloat)pow(-1,animationCounter%2) : 0,0,0);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x-0.05,y-0.085,z+0.1);
    glRotatef(-15.0f, moveTopRightLeg ? (GLfloat)pow(-1,animationCounter%2) : 0,0,0);

    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+0.05,y-0.085,z+0.1);
    glRotatef(15.0f, moveTopLeftLeg ? (GLfloat)pow(-1,animationCounter%2) : 0,0,0);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    // body
    glPushMatrix();
    glTranslated(x,y,z);
    glScaled(0.11,0.11,0.2);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x,y+0.1,z+0.05);
    glScaled(0.08,0.18,0.08);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // head
    glPushMatrix();
    glTranslated(x + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),y+0.25 +  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),z+0.1);
    glScaled(0.17,0.155,0.17);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();


    glColor3f(0.6,0.4,0.14);

    // hear
    glPushMatrix();
    glTranslated(x+0.11 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),y + 0.29 + (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),0.13 + z);
    glScaled(0.06,0.09,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // hear
    glPushMatrix();
    glTranslated(x-0.11 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),y + 0.29 + (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0), 0.13 + z);
    glScaled(0.06,0.09,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // nose
    glPushMatrix();
    glTranslated(x + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),y + 0.27 +  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),0.25 + z);
    glScaled(0.02,0.02,0.02);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();


    glColor3f(1,1,1);

    // eyes
    glPushMatrix();
    glTranslated(x+0.035 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0), 0.3 + y +  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0), z + 0.175);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // eyes
    glPushMatrix();
    glTranslated(x - 0.035 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0), 0.3 + y + (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0), z + 0.175);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();
}

void Dog::setTailUpAndDown(bool val){
    tailUpAndDown = val;
}

void Dog::setTailRightAndLeft(bool val) {
    tailRightAndLeft = val;
}

void Dog::setHeadUpAndDown(bool val){
    headUpAndDown = val;
}

void Dog::setHeadRightAndLeft(bool val) {
    headRightAndLeft = val;
}
void Dog::setMoveTopRightLeg(bool val){
    moveTopRightLeg = val;
}

void Dog::setMoveTopLeftLeg(bool val){
    moveTopLeftLeg = val;
}

void Dog::setMoveBackRightLeg(bool val){
    moveBackRightLeg = val;
}

void Dog::setMoveBackLeftLeg(bool val){
    moveBackLeftLeg = val;
}

void Dog::setWalk(bool val){
    walk = val;
    moveTopLeftLeg = val;
    moveTopRightLeg = val;
    moveBackRightLeg = val;
    moveBackLeftLeg = val;

}