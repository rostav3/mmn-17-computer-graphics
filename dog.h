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
//    BlockedSquare OBJECTS_SQUARES[1] = {BlockedSquare(-1.32, 0.6, -1.08, 1.3)};
    BlockedSquare OBJECTS_SQUARES[4] = {BlockedSquare(-1.5, 0.7, -0.9, 1.3),
                                        BlockedSquare(0.7, -1, 1.3, -0.4),
                                        BlockedSquare(-0.8, -0.55, -0.34, -0.05),
                                        BlockedSquare(1.3, 1.3, 2.3, 2.3)};

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

    void setTurnRight();

    void setTurnLeft();

    bool isBlocked();
};

#endif //MMN17COMPUTERGRAPHICS_DOG_H
