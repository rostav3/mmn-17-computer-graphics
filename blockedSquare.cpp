/*----------------------------------------------------------------------------------------------------------------------
 * This class represent any item/wall that block the dog.
 * Author: Roman Smirnov 312914443, Stav Rockah 307900878
 * -------------------------------------------------------------------------------------------------------------------*/

#include "blockedSquare.h"

/*----------------------------------------------------------------------------------------------------------------------
 * The constructor of the class, define the limits of the block
 * -------------------------------------------------------------------------------------------------------------------*/
BlockedSquare::BlockedSquare(double start_x, double start_z, double end_x, double end_z) {
    startX = start_x;
    startZ = start_z;
    endX = end_x;
    endZ = end_z;
}

/*----------------------------------------------------------------------------------------------------------------------
 * This method check if the position is in the block square.
 * -------------------------------------------------------------------------------------------------------------------*/
bool BlockedSquare::isInBlock(double xPosition, double zPosition){
    return ((xPosition <= endX) && (xPosition >= startX) && (zPosition <= endZ) && (zPosition >= startZ));
}