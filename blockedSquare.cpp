//
// Created by stav on 24/08/18.
//

#include "blockedSquare.h"
BlockedSquare::BlockedSquare(double start_x, double start_z, double end_x, double end_z) {
    startX = start_x;
    startZ = start_z;
    endX = end_x;
    endZ = end_z;
}

bool BlockedSquare::isInBlock(double xPosition, double zPosition){

    if ((xPosition <= endX) && (xPosition >= startX) && (zPosition <= endZ) && (zPosition >= startZ)){
        return true;
    }
    return false;
}