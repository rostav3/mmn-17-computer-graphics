/*----------------------------------------------------------------------------------------------------------------------
 * This class represent the floor.
 * Author: Roman Smirnov 312914443, Stav Rockah 307900878
 * -------------------------------------------------------------------------------------------------------------------*/

 //  includes
#include "floor.h"
#include <GL/glut.h>

static constexpr GLfloat mat_ambient[] = {0.7f,0.7f,0.7f,0.1f};
static constexpr GLfloat mat_diffuse[] = {0.5f,0.5f,0.5f,1.0f};
static constexpr GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
static constexpr GLfloat mat_shininess[] = {10.0f};

/*----------------------------------------------------------------------------------------------------------------------
 * This method draw the floor with shine and texture
 * -------------------------------------------------------------------------------------------------------------------*/
void Floor::draw(){
    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);


    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glColor4f(1.0f,1.0f,1.0f, 1.0f);
    glTranslated(0.4,0,0.4);
    glScaled(4.0,0.025,4.0);
    glutSolidCube(1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
