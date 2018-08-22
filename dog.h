//
// Created by stav on 22/08/18.
//

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
};


#endif //MMN17COMPUTERGRAPHICS_DOG_H
