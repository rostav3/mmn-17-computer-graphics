//
// Created by stav on 24/08/18.
//

#ifndef MMN_17_COMPUTER_GRAPHICS_BLOCKEDSQUARE_H
#define MMN_17_COMPUTER_GRAPHICS_BLOCKEDSQUARE_H


class BlockedSquare {
    double startX;
    double startZ;
    double endX;
    double endZ;

public:
    BlockedSquare(double start_x, double start_z, double end_x, double end_z);
    bool isInBlock(double xPosition, double zPosition);
};


#endif //MMN_17_COMPUTER_GRAPHICS_BLOCKEDSQUARE_H
