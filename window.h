//
// Created by stav on 22/08/18.
//

#ifndef MMN_17_COMPUTER_GRAPHICS_WINDOW_H
#define MMN_17_COMPUTER_GRAPHICS_WINDOW_H


class Window {
	double x;
	double y;
	double z;
public:
	void init();
    void draw();

	void setY(double val);
	void setZ(double val);
	double getY();
	double getZ();
};

#endif //MMN_17_COMPUTER_GRAPHICS_WINDOW_H
