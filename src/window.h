/*----------------------------------------------------------------------------------------------------------------------
 * This class represent the window.
 * Author: Roman Smirnov 312914443, Stav Rockah 307900878
 * -------------------------------------------------------------------------------------------------------------------*/

#ifndef MMN_17_COMPUTER_GRAPHICS_WINDOW_H
#define MMN_17_COMPUTER_GRAPHICS_WINDOW_H

#include "pch.h"

class Window {
	double x;
	double y;
	double z;
public:
	void init();
    void draw();

    // set methods
	void setY(double val);
	void setZ(double val);

	// get methods
	double getY();
	double getZ();
};

#endif //MMN_17_COMPUTER_GRAPHICS_WINDOW_H