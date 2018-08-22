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
}

void Dog::draw(){
    ticksCounter++;
    animationCounter += (ticksCounter%6 == 0) ? 1 : 0;

    glColor3f(0.8,0.5,0.2);

    // tail
    glPushMatrix();
    glTranslated(0.25,0.15,0.15);
    glRotatef(45.0f,  tailUpAndDown ? (GLfloat)pow(-1,animationCounter%2) : 0, tailRightAndLeft ? (GLfloat)pow(-1,animationCounter%2) : 0, 0.0);
    glScaled(0.03,0.03,0.08);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslated(0.3,0.065,0.3);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,0.065,0.3);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,0.065,0.45);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3,0.065,0.45);
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
}

void Dog::set_tailUpAndDown(bool val){
    tailUpAndDown = val;
}

void Dog::set_tailRightAndLeft(bool val) {
    tailRightAndLeft = val;
}

void Dog::set_headUpAndDown(bool val){
    headUpAndDown = val;
}

void Dog::set_headRightAndLeft(bool val) {
    headRightAndLeft = val;
}
