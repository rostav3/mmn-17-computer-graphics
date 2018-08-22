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

    int animationCounter;
    int ticksCounter;

public:
    Dog();
    void draw();
    void setTailUpAndDown(bool val);
    void setTailRightAndLeft(bool val);
    void setHeadUpAndDown(bool val);
    void setHeadRightAndLeft(bool val);
};


#endif //MMN17COMPUTERGRAPHICS_DOG_H
