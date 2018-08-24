//
// Created by stav on 22/08/18.
//
#include "blockedSquare.h"


#ifndef MMN17COMPUTERGRAPHICS_DOG_H
#define MMN17COMPUTERGRAPHICS_DOG_H


class Dog {
    bool tailUpAndDown;
    bool tailRightAndLeft;
    bool headUpAndDown;
    bool headRightAndLeft;
    bool moveTopRightLeg;
    bool moveTopLeftLeg;
    bool moveBackRightLeg;
    bool moveBackLeftLeg;
    bool walk;
    int animationCounter;
    int ticksCounter;
    double x;
    double y;
    double z;
    double noseX;
    double noseY;
    double noseZ;

    double lookAtX;
    double lookAtY;
    double lookAtZ;
    bool turnRight;
    bool turnLeft;
    int rotate;
    int currentPosition;


    // misc
    static constexpr int NUM_POSITIONS = 4;
    static constexpr int NUM_COORDINATES = 3;

    static constexpr double POSITIONS[NUM_POSITIONS][NUM_COORDINATES] = {{0,  0, 1},
                                                                         {-1, 0, 0},
                                                                         {0,  0, -1},
                                                                         {1,  0, 0}};
    static constexpr int NUM_OBJECTS = 8;
    BlockedSquare OBJECTS_SQUARES[NUM_OBJECTS] = {BlockedSquare(-1.5, 0.7, -0.9, 1.3),
                                                  BlockedSquare(0.7, -1, 1.3, -0.4),
                                                  BlockedSquare(-0.8, -0.55, -0.34, -0.05),
                                                  BlockedSquare(1.3, 1.3, 2.3, 2.3),
                                                  BlockedSquare(-1.6, 2, 2.4, 2.3),
                                                  BlockedSquare(-1.6, -1.59, 2.4, -1.2),
                                                  BlockedSquare(-1.6, -1.6, -1.3, 2.4),
                                                  BlockedSquare(2, -1.6, 2.4, 2.4)};

public:
    Dog();

    void draw();

    void setTailUpAndDown(bool val);

    void setTailRightAndLeft(bool val);

    void setHeadUpAndDown(bool val);

    void setHeadRightAndLeft(bool val);

    void setMoveTopRightLeg(bool val);

    void setMoveTopLeftLeg(bool val);

    void setMoveBackRightLeg(bool val);

    void setMoveBackLeftLeg(bool val);

    void setWalk(bool val);

    bool getTailUpAndDown();

    bool getTailRightAndLeft();

    bool getHeadUpAndDown();

    bool getHeadRightAndLeft();

    bool getMoveTopRightLeg();

    bool getMoveTopLeftLeg();

    bool getMoveBackRightLeg();

    bool getMoveBackLeftLeg();

    bool getWalk();

    void setTurnRight(bool val);

    bool getTurnRight();

    void setTurnLeft(bool val);

    bool getTurnLeft();

    bool isBlocked();

    double getNoseX();
    double getNoseY();
    double getNoseZ();

    double getLookAtX();
    double getLookAtY();
    double getLookAtZ();

    double getRotate();
};
#endif //MMN17COMPUTERGRAPHICS_DOG_H
