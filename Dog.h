//
// Created by stav on 22/08/18.
//

#ifndef MMN17COMPUTERGRAPHICS_DOG_H
#define MMN17COMPUTERGRAPHICS_DOG_H


class Dog {
    bool tailUpAndDown;
    bool tailRightAndLeft;
    int animationCounter;
    int ticksCounter;

public:
    Dog();
    void draw();
    void set_tailUpAndDown(bool val);
    void set_tailRightAndLeft(bool val);
};


#endif //MMN17COMPUTERGRAPHICS_DOG_H
