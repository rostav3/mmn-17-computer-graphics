
// includes
#include <GL/gl.h>
#include <math.h>
#include <cmath>
#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>

// misc
static constexpr GLsizei NUM_COORDINATES = 3;

// window
static constexpr GLchar WIN_NAME[] = "Polyhedron Animation";
static constexpr GLint WIN_WIDTH = 800;
static constexpr GLint WIN_HEIGHT = 800;

// perspective
static constexpr GLdouble FOV = 40.0;
static constexpr GLdouble ASPECT = 1.0;
static constexpr GLdouble NEAR = 1.0;
static constexpr GLdouble FAR = 10.0;

// orthographic
static constexpr GLdouble ORTHO_COORDS[] = {-1, 1, -1, 1, 1, 10};

// eye
static constexpr GLdouble EYE_POS[NUM_COORDINATES] = {0.5, 0.5, 5.0};
static constexpr GLdouble EYE_CENTER[NUM_COORDINATES] = {0.5, 0.5, 0.5};
static constexpr GLdouble EYE_UP[NUM_COORDINATES] = {0.0, 1.0, 0.0};

// animation
static  GLfloat camera_move_x = 2.3;
static  GLfloat camera_move_y = 1.38;
static  GLfloat camera_move_z = 2.0;
static  GLfloat zoom_factor = 1;
static GLfloat  c_x = .0;
static GLfloat  c_y = 0.25;
static GLfloat  c_z = .0;
static GLfloat  u_x = .0;
static GLfloat  u_y = 1.0;
static GLfloat  u_z = .0;




GLuint loadBMP_custom(const char * imagepath){
// Data read from the header of the BMP file
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int width, height;
    unsigned int imageSize;   // = width*height*3
    unsigned char * data;
    FILE * file = fopen(imagepath,"rb");
    if (!file){printf("Image could not be opened\n"); return 0;}
    if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
        printf("Not a correct BMP file\n");
        return 0;
    }
    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP file\n");
        return 0;
    }

    // Read ints from the byte array
    dataPos    = *(unsigned int*)&(header[0x0A]);
    imageSize  = *(unsigned int*)&(header[0x22]);
    width      = *(unsigned int*)&(header[0x12]);
    height     = *(unsigned int*)&(header[0x16]);
    if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos==0)      dataPos=54; // The BMP header is done that way
// Create a buffer
    data = new unsigned char [imageSize];

// Read the actual data from the file into the buffer
    fread(data,1,imageSize,file);

//Everything is in memory now, the file can be closed
    fclose(file);

// Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

// "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

// Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glActiveTexture(GL_TEXTURE0);
}

void setPerspectiveProjection(GLfloat aspect) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOV, aspect, NEAR, FAR);
    glMatrixMode(GL_MODELVIEW);
}


void displayFun() {
    GLfloat mat_ambient[]={0.7f,0.7f,0.7f,0.1f};
    GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[]={20.0f};
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    GLfloat light_Intensity[]={0.9f,0.9f,0.9f,1.0f};

    GLfloat light_Position[]={4.0f,6.0f,3.0f,0.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,light_Position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_Intensity);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    setPerspectiveProjection((GLfloat) glutGet(GLUT_WINDOW_WIDTH) / (GLfloat) glutGet(GLUT_WINDOW_HEIGHT));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camera_move_x,camera_move_y,camera_move_z,c_x,c_y,c_z,u_x,u_y,u_z);


    // floor

//    glEnable(GL_TEXTURE_2D);
//    glDisable(GL_TEXTURE_2D);

    glColor3f(1,1,1);

    glPushMatrix();
    glTranslated(0.4,0,0.4);
    glScaled(4.0,0.025,4.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.4,2.0,0.4);
    glScaled(4.0,0.025,4.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //walls
    glPushMatrix();
    glTranslated(0.4,1,-1.59);
    glScaled(4.0,2.0,0.025);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.4,1,2.39);
    glScaled(4.0,2.0,0.025);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.39,1,0.4);
    glScaled(0.025,2.0,4.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.59,1,0.4);
    glScaled(0.025,2.0,4.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.8,0.5,0.2);

    // tail
    glPushMatrix();
    glTranslated(0.25,0.15,0.15);
    glScaled(0.03,0.03,0.08);
    glutSolidSphere(1.0, 50, 50);
    glRotatef(45.0f, 0.0, 1.0, 0.0);

    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslated(0.3,0.065,0.3);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glRotatef(-90, 40.0, 0.0, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,0.065,0.3);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glRotatef(-90, 40.0, 0.0, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.2,0.065,0.45);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glRotatef(-90, 40.0, 0.0, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3,0.065,0.45);
    glScaled(0.03,0.06,0.03);
    glutSolidSphere(1.0, 50, 50);
    glRotatef(-90, 40.0, 0.0, 0.0);
    glPopMatrix();

    // body

    glPushMatrix();
    glTranslated(0.25,0.15,0.35);
    glScaled(0.11,0.11,0.2);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.25,0.25,0.4);
    glScaled(0.08,0.18,0.08);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // head
    glPushMatrix();
    glTranslated(0.25,0.4,0.45);
    glScaled(0.17,0.155,0.17);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();


    glColor3f(0.6,0.4,0.14);

    // hear
    glPushMatrix();
    glTranslated(0.36,0.44,0.48);
    glScaled(0.06,0.09,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // hear
    glPushMatrix();
    glTranslated(0.14,0.44,0.48);
    glScaled(0.06,0.09,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // nose
    glPushMatrix();
    glTranslated(0.25,0.42,0.6);
    glScaled(0.02,0.02,0.02);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();


    glColor3f(1,1,1);

    // eyes
    glPushMatrix();
    glTranslated(0.285,0.45,0.525);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // eyes
    glPushMatrix();
    glTranslated(0.215,0.45,0.525);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();


    // ball
    glColor3f(1,0,0);

    glPushMatrix();
    glTranslated(-0,0.1,0.65);
    glScaled(0.1,0.1,0.1);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    glColor3f(1,0.9,0.8);

    // bone
    glPushMatrix();
    glTranslated(0.6,0.06,0.35);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.54,0.06,0.35);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.57,0.06,0.25);
    glScaled(0.04,0.04,0.15);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6,0.06,0.15);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.54,0.06,0.15);
    glScaled(0.06,0.06,0.06);
    glutSolidSphere(0.8, 50, 50);
    glPopMatrix();

    // bowl
    glColor3f(0.3,0.6,0);
    glPushMatrix();
    glTranslated(0.7,-0.012,0.7);
    glScaled(0.1,0.1,0.1);
    glRotatef(90.0f, 1.0, 0.0, 0.0);
    glutSolidTorus(0.6,0.71,20,50);
    glPopMatrix();


    // light
    glColor3f(0.4,0.4,0.4);
    glPushMatrix();
    glTranslated(0.25,0.07,0.7);
    glScaled(0.15,0.15,0.15);
    glRotatef(45.0f, 1.0, 0.0, 0.0);
    glutSolidCone(0.6,0.71,20,50);
    glPopMatrix();


    glPushMatrix();
    glScaled(0.5,0.5,0.5);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


void idleFun() {
    glutPostRedisplay();
}

void keyboardFun(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            camera_move_y += 0.1;
            break;
        case 's':
            camera_move_y -= 0.1;
            break;
        case 'a':
            camera_move_x -= 0.1;
            break;
        case 'd':
            camera_move_x += 0.1;
            break;
        case 'e':
            camera_move_z -= 0.1;
            break;
        case 'q':
            camera_move_z += 0.1;
            break;
        case 'p':
            zoom_factor -= 0.1;
            break;
        case 'm':
            zoom_factor += 0.1;
            break;
        case 'z':
            c_x+=0.1;
            break;
        case 'x':
            c_x-=0.1;
            break;
        case 'c':
            c_y+=0.1;
            break;
        case 'v':
            c_y-=0.1;
            break;
        case 'b':
            c_z+=0.1;
            break;
        case 'n':
            c_z-=0.1;
            break;
        case 'Z':
            u_x+=0.1;
            break;
        case 'X':
            u_x-=0.1;
            break;
        case 'C':
            u_y+=0.1;
            break;
        case 'V':
            u_y-=0.1;
            break;
        case 'B':
            u_z+=0.1;
            break;
        case 'N':
            u_z-=0.1;
            break;
        default:
            return;    }
//    setCameraView();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(0,0);
    glutCreateWindow(WIN_NAME);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glutDisplayFunc(displayFun);
    GLuint image = loadBMP_custom("/home/stav/CLionProjects/mmn17ComputerGarphics/Grass01.bmp");
//    glutReshapeFunc(reshapeFun);
    glutKeyboardFunc(keyboardFun);
    glutIdleFunc(idleFun);
//    initCubeDisplayList();
    glutMainLoop();
}