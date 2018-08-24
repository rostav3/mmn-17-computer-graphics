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
    turnRight = false;
    turnLeft = false;
    rotate = 0;
    currentPosition = 0;
    walk = false;

    x = 0;
    y = 0;
    z = 0;
}

void Dog::draw(){
    ticksCounter++;
    animationCounter += (ticksCounter%6 == 0) ? 1 : 0;

    glColor3f(0.8,0.5,0.2);
    if (walk){
        x += 0.01*POSITIONS[currentPosition][0];
        z +=  0.01*POSITIONS[currentPosition][2];

        if (isBlocked()){
            x -= 0.01*POSITIONS[currentPosition][0];
            z -=  0.01*POSITIONS[currentPosition][2];
        }
    }
    if (turnRight){
        rotate -= 5;
        if (rotate % 90 == 0){
            currentPosition =  currentPosition == 3 ? 0 : currentPosition + 1;
            turnRight = false;
        }
    }

    if (turnLeft) {
        rotate += 5;
        if (rotate % 90 == 0) {
            currentPosition =  currentPosition == 0 ? 3 : currentPosition - 1;
            turnLeft = false;
        }
    }


    glPushMatrix();
    glTranslated(x,y,z);
    glRotated(rotate, 0, 1, 0);

    glPushMatrix();
    glTranslated(-0.3,0,-0.3);

    // tail
    glPushMatrix();
    glTranslated(0.25,0.15,0.175);
    glRotatef(45.0f,  tailUpAndDown ? (GLfloat)pow(-1,animationCounter%2) : 0, tailRightAndLeft ? (GLfloat)pow(-1,animationCounter%2) : 0, 0.0);
    glScaled(0.03,0.03,0.08);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslated(0.3,0.065,0.3);
    glRotatef(15.0f, moveBackLeftLeg ? (GLfloat)pow(-1,animationCounter%2) : 0,0,0);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,0.065,0.3);
    glRotatef(-15.0f, moveBackRightLeg ? (GLfloat)pow(-1,animationCounter%2) : 0,0,0);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,0.065,0.45);
    glRotatef(-15.0f, moveTopRightLeg ? (GLfloat)pow(-1,animationCounter%2) : 0,0,0);

    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3,0.065,0.45);
    glRotatef(15.0f, moveTopLeftLeg ? (GLfloat)pow(-1,animationCounter%2) : 0,0,0);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    // body
    glPushMatrix();
    glTranslated(0.25,0.15,0.35);
    glScaled(0.11,0.11,0.2);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.25,0.25,0.4);
    glScaled(0.08,0.18,0.08);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // head
    glPushMatrix();
    glTranslated(0.25 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),0.4 +  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),0.45);
    glScaled(0.17,0.155,0.17);

    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();


    glColor3f(0.6,0.4,0.14);

    // hear
    glPushMatrix();
    glTranslated(0.36 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),0.44+  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),0.48);
    glScaled(0.06,0.09,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // hear
    glPushMatrix();
    glTranslated(0.14 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),0.44+  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),0.48);
    glScaled(0.06,0.09,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // nose
    glPushMatrix();
    glTranslated(0.25 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),0.42 +  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),0.6);
    glScaled(0.02,0.02,0.02);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();


    glColor3f(1,1,1);

    // eyes
    glPushMatrix();
    glTranslated(0.285 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),0.45+  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),0.525);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // eyes
    glPushMatrix();
    glTranslated(0.215 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0),0.45 +  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0),0.525);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

// end whole dog rotation
    glPopMatrix();
    glPopMatrix();
}

bool Dog::isBlocked(){
    for (int i = 0; i < NUM_OBJECTS; ++i) {
        if (OBJECTS_SQUARES[i].isInBlock(x,z))
            return true;
    }
    return false;
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


bool Dog::getTailUpAndDown(){
    return tailUpAndDown;
}

bool Dog::getTailRightAndLeft(){
    return tailRightAndLeft;
}

bool Dog::getHeadUpAndDown(){
    return headUpAndDown;
}

bool Dog::getHeadRightAndLeft(){
    return headRightAndLeft;
}

bool Dog::getMoveTopRightLeg(){
    return moveTopRightLeg;
}

bool Dog::getMoveTopLeftLeg(){
    return moveTopLeftLeg;
}

bool Dog::getMoveBackRightLeg(){
    return moveBackRightLeg;
}

bool Dog::getMoveBackLeftLeg(){
    return moveBackLeftLeg;
}

bool Dog::getWalk(){
    return walk;
}

void Dog::setTurnRight(bool val){
    turnRight = val;
}

bool Dog::getTurnRight(){
    return turnRight;
}

void Dog::setTurnLeft(bool val){
    turnLeft = val;
}

bool Dog::getTurnLeft(){
    return turnLeft;
}
