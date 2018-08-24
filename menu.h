/*----------------------------------------------------------------------------------------------------------------------
 * This class represent the menu.
 * Author: Roman Smirnov 312914443, Stav Rockah 307900878
 * -------------------------------------------------------------------------------------------------------------------*/

 // includes
#include "dog.h"
#include "window.h"

#ifndef MMN_17_COMPUTER_GRAPHICS_MENU_H
#define MMN_17_COMPUTER_GRAPHICS_MENU_H

class Menu {
public:
    void draw(Dog* dog, Window* window);
    void setup();
    void cleanup();
	void reshape(int w, int h);
	void keyboard(int key, int x, int y);
	bool getShowDogEyes();
};

#endif //MMN_17_COMPUTER_GRAPHICS_MENU_H