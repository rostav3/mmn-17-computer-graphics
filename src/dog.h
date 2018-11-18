/*----------------------------------------------------------------------------------------------------------------------
 * This class represent the dog.
 * Author: Roman Smirnov, Stav Rockah
 * -------------------------------------------------------------------------------------------------------------------*/

 // includes
#include "pch.h"
#include "blockedSquare.h"


#ifndef MMN17COMPUTERGRAPHICS_DOG_H
#define MMN17COMPUTERGRAPHICS_DOG_H

class Dog {
    // directions (for rotate) and block items.
    static constexpr int NUM_OBJECTS = 8;
    static constexpr int NUM_DIRECTIONS = 4;
    static constexpr int NUM_COORDINATES = 3;

    BlockedSquare OBJECTS_SQUARES[NUM_OBJECTS] = {BlockedSquare(-1.5, 0.7, -0.9, 1.3),
                                                  BlockedSquare(0.7, -1, 1.3, -0.4),
                                                  BlockedSquare(-0.8, -0.55, -0.34, -0.05),
                                                  BlockedSquare(1.3, 1.3, 2.3, 2.3),
                                                  BlockedSquare(-1.6, 2, 2.4, 2.3),
                                                  BlockedSquare(-1.6, -1.59, 2.4, -1.2),
                                                  BlockedSquare(-1.6, -1.6, -1.3, 2.4),
                                                  BlockedSquare(2, -1.6, 2.4, 2.4)};

    static constexpr double DIRECTIONS[NUM_DIRECTIONS][NUM_COORDINATES] = {{0,  0, 1},
                                                                         {-1, 0, 0},
                                                                         {0,  0, -1},
                                                                         {1,  0, 0}};
    int currentDirectionNum;

    // tail animations.
    bool tailUpAndDown;
    bool tailRightAndLeft;

    // head animations.
    bool headUpAndDown;
    bool headRightAndLeft;

    // legs animations
    bool moveTopRightLeg;
    bool moveTopLeftLeg;
    bool moveBackRightLeg;
    bool moveBackLeftLeg;

    // walks
    bool walk;
    bool turnRight;
    bool turnLeft;

    // position of all the dog
    double x;
    double y;
    double z;

    // nose position (for set camera position)
    double noseX;
    double noseY;
    double noseZ;

    // where to look at (for set camera look at)
    double lookAtX;
    double lookAtY;
    double lookAtZ;

    // animation and rotate general
    int rotate;
    int animationCounter;
    int ticksCounter;

public:
    Dog();

    void draw();
    bool isBlocked();


    // set methods
    void setTailUpAndDown(bool val);
    void setTailRightAndLeft(bool val);
    void setHeadUpAndDown(bool val);
    void setHeadRightAndLeft(bool val);
    void setMoveTopRightLeg(bool val);
    void setMoveTopLeftLeg(bool val);
    void setMoveBackRightLeg(bool val);
    void setMoveBackLeftLeg(bool val);
    void setWalk(bool val);
    void setTurnRight(bool val);
    void setTurnLeft(bool val);

    // get methods
    bool getHeadUpAndDown();
    bool getHeadRightAndLeft();
    bool getWalk();
    bool getTurnRight();
    double getNoseX();
    double getNoseY();
    double getNoseZ();
    double getLookAtX();
    double getLookAtY();
    double getLookAtZ();
    double getRotate();
    bool getTurnLeft();
};
#endif //MMN17COMPUTERGRAPHICS_DOG_H