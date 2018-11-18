/*----------------------------------------------------------------------------------------------------------------------
 * This class represent the dog.
 * Author: Roman Smirnov 312914443, Stav Rockah 307900878
 * -------------------------------------------------------------------------------------------------------------------*/

// includes
#include <cmath>
#include "dog.h"

static constexpr GLfloat materialAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
static constexpr GLfloat materialDiffuse[] = {0.0f, 0.0f, 0.0f, 1.0f};
static constexpr GLfloat materialSpecular[] = {0.0f, 0.0f, 0.0f, 1.0f};
static constexpr GLfloat materialShininess = 128.0f;

static constexpr GLfloat eyeMaterialAmbient[] = {1.0f, 1.0f, 1.0f, 1.0f};
static constexpr GLfloat eyeMaterialDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
static constexpr GLfloat eyeMaterialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
static constexpr GLfloat eyeMaterialShininess = 3.0f;

/*----------------------------------------------------------------------------------------------------------------------
 * The constructor of the class, initalize all the parameters.
 * -------------------------------------------------------------------------------------------------------------------*/
Dog::Dog() {
    animationCounter = 0;
    ticksCounter = 0;
    rotate = 0;
    currentDirectionNum = 0;
    x = 0;
    y = 0;
    z = 0;
    lookAtX = 0;
    lookAtY = 0.4;
    lookAtZ = 0;
    tailUpAndDown = false;
    tailRightAndLeft = false;
    headRightAndLeft = false;
    headUpAndDown = false;
    turnRight = false;
    turnLeft = false;
    walk = false;
}

/*----------------------------------------------------------------------------------------------------------------------
 * This method handle the draw of the dog (contain all the animations)
 * -------------------------------------------------------------------------------------------------------------------*/
void Dog::draw(){
    // ticks for all animations
    ticksCounter++;
    animationCounter += (ticksCounter%6 == 0) ? 1 : 0;

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

    glColor3f(0.8,0.5,0.2);

    // if dog is walk, forword in the current direction
    if (walk){
        x += 0.01*DIRECTIONS[currentDirectionNum][0];
        z +=  0.01*DIRECTIONS[currentDirectionNum][2];

        // remove the forword in case of blocked
        if (isBlocked()) {
            x -= 0.01 * DIRECTIONS[currentDirectionNum][0];
            z -= 0.01 * DIRECTIONS[currentDirectionNum][2];
        } else {
            // add the forword to the look position too.
            lookAtX +=0.01*DIRECTIONS[currentDirectionNum][0];
            lookAtZ +=0.01*DIRECTIONS[currentDirectionNum][2];
        }
    }

    // handle rotate right
    if (turnRight){
        rotate -= 5;
        if (rotate % 90 == 0){
            currentDirectionNum =  currentDirectionNum == 3 ? 0 : currentDirectionNum + 1;
            turnRight = false;
        }
    }

    // handle rotate left
    if (turnLeft) {
        rotate += 5;
        if (rotate % 90 == 0) {
            currentDirectionNum =  currentDirectionNum == 0 ? 3 : currentDirectionNum - 1;
            turnLeft = false;
        }
    }

    glPushMatrix();
    glTranslated(x,y,z);
    glRotated(rotate, 0, 1, 0);

    glPushMatrix();
    glTranslated(-0.35,0,-0.35);

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
    noseX = 0.25 + (headRightAndLeft ? pow(-1,animationCounter%2)/100 : 0);
    noseY =  0.42 +  (headUpAndDown ? pow(-1,animationCounter%2)/100 : 0);
    noseZ = 0.6;
    glTranslated(noseX, noseY, noseZ);
    glScaled(0.02,0.02,0.02);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();


    glColor3f(1,1,1);

    // eyes
    glMaterialfv(GL_FRONT, GL_AMBIENT, eyeMaterialAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, eyeMaterialDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, eyeMaterialSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, eyeMaterialShininess);

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


/*----------------------------------------------------------------------------------------------------------------------
 * This method return if the dog is blocked by any item/wall or not.
 * -------------------------------------------------------------------------------------------------------------------*/
bool Dog::isBlocked(){
    for (int i = 0; i < NUM_OBJECTS; ++i) {
        if (OBJECTS_SQUARES[i].isInBlock(x,z))
            return true;
    }
    return false;
}

/*----------------------------------------------------------------------------------------------------------------------
 * All sets of needed properties
 * -------------------------------------------------------------------------------------------------------------------*/

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

void Dog::setTurnRight(bool val){
    turnRight = val;
}

void Dog::setTurnLeft(bool val){
    turnLeft = val;
}

/*----------------------------------------------------------------------------------------------------------------------
 * All gets of needed properties
 * -------------------------------------------------------------------------------------------------------------------*/

bool Dog::getHeadUpAndDown(){
    return headUpAndDown;
}

bool Dog::getHeadRightAndLeft(){
    return headRightAndLeft;
}

bool Dog::getWalk(){
    return walk;
}

bool Dog::getTurnRight(){
    return turnRight;
}

bool Dog::getTurnLeft(){
    return turnLeft;
}

double Dog::getNoseX(){
    return -noseX+x;
}

double Dog::getNoseY(){
    return noseY+y;
}

double Dog::getNoseZ(){
    return -noseZ+z;
}

double Dog::getRotate() {
    return rotate;
}

double Dog::getLookAtX(){
    return lookAtX;
}
double Dog::getLookAtY(){
    return lookAtY;
}

double Dog::getLookAtZ(){
    return lookAtZ;
}