//
// Created by stav on 22/08/18.
//

#include "dog.h"

#ifndef MMN_17_COMPUTER_GRAPHICS_MENU_H
#define MMN_17_COMPUTER_GRAPHICS_MENU_H

class Menu {
public:
    void draw(Dog* dog);
    void setup();
    void cleanup();
	void reshape(int w, int h);
	void keyboard(int key, int x, int y);
};


#endif //MMN_17_COMPUTER_GRAPHICS_MENU_H
