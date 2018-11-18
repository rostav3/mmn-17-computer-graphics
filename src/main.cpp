/*----------------------------------------------------------------------------------------------------------------------
 * Main file, run all the program
 * Author: Roman Smirnov, Stav Rockah
 * -------------------------------------------------------------------------------------------------------------------*/



// includes
//#include <windows.h> // lean and mean
#include <iostream>
#include "pch.h"
#include "room.h"
#include "items.h"
#include "lamp.h"
#include "menu.h"
#include "window.h"
#include "floor.h"

// misc
static constexpr GLsizei NUM_COORDINATES = 3;

// window defaults
static constexpr auto WIN_NAME = "Dog Room Scene";
static constexpr GLint WIN_WIDTH = 1280;
static constexpr GLint WIN_HEIGHT = 720;

// perspective
static constexpr GLdouble FOV = 40.0;
static constexpr GLdouble NEAR_PRSP = 1.0;
static constexpr GLdouble FAR_PRSP = 10.0;

// eye
static constexpr GLdouble EYE_POS[NUM_COORDINATES] = {0.0, 2.0, 2.0};
static constexpr GLdouble EYE_CENTER[NUM_COORDINATES] = {0.0, 0.0, 0.0};
static constexpr GLdouble EYE_UP[NUM_COORDINATES] = {0.0, 1.0, 0.0};

// objects
static Room room;
static Dog dog;
static Ball ball;
static Bone bone;
static Bowl bowl;
static Lamp lamp;
static Window window;
static Floor room_floor;
static Menu menu;

// camera as dog eyes.
static double prevCameraRotate = 0;
static bool isDogPosition = false;

/*----------------------------------------------------------------------------------------------------------------------
 * This method load texture.
 * -------------------------------------------------------------------------------------------------------------------*/
GLuint loadBMP(const char * imagepath){
	// Data read from the header of the BMP file

	// Each BMP file begins by a 54-bytes header
	unsigned char header[54];
	// Position in the file where the actual data begins
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;
	unsigned char * data;
	FILE * file = fopen(imagepath,"rb");

	// check if the file is okay.
	if (!file) {
		printf("Image could not be opened\n");
		return 0;
	}

	// If not 54 bytes read : problem
	if ( fread(header, 1, 54, file)!=54 ){
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

	// 3 : one byte for each Red, Green and Blue component
	if (imageSize==0){
		imageSize=width*height*3;
	}

	// The BMP header is done that way
	if (dataPos==0) {
		dataPos=54;
	}

	// Create ְa buffer
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
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GLUT_RGB, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glActiveTexture(GL_TEXTURE0);
	return 0;
}


/*----------------------------------------------------------------------------------------------------------------------
 * This method set the camera position
 * -------------------------------------------------------------------------------------------------------------------*/
void setCameraView() {
	glLoadIdentity();
	if (isDogPosition){
		gluLookAt(dog.getNoseX(), dog.getNoseY(), dog.getNoseZ(), dog.getLookAtX(), dog.getLookAtY(), dog.getLookAtZ(),
				  EYE_UP[0], EYE_UP[1], EYE_UP[2]);
	}else{
		gluLookAt(EYE_POS[0], EYE_POS[1], EYE_POS[2], EYE_CENTER[0], EYE_CENTER[1], EYE_CENTER[2], EYE_UP[0], EYE_UP[1],
				  EYE_UP[2]);
	}
}

/*----------------------------------------------------------------------------------------------------------------------
 * This method handle all the display.
 * -------------------------------------------------------------------------------------------------------------------*/
void displayFun(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	room.draw();
	room_floor.draw();
	dog.draw();
	ball.draw();
	bone.draw();
	bowl.draw();
	lamp.draw();
	window.draw();
	menu.draw(&dog, &window);

	// change camera position if change from regular to dog look or walking in doe look, or make any animation.
	if ((isDogPosition != menu.getShowDogEyes()) || ((isDogPosition) && (dog.getWalk() || dog.getHeadRightAndLeft() || dog.getHeadUpAndDown()))){
		isDogPosition = menu.getShowDogEyes();
		setCameraView();
	}

	// rotate in case of dog look.
	if (isDogPosition){
		glRotated(prevCameraRotate-dog.getRotate(), 0, 1, 0);
		prevCameraRotate = dog.getRotate();
	}

	glutSwapBuffers();
	glutPostRedisplay();
}


/*----------------------------------------------------------------------------------------------------------------------
 * This method handle all the keyboard
 * -------------------------------------------------------------------------------------------------------------------*/
void keyboardFun(unsigned char key, int x, int y) {
	if (dog.getWalk()){
		return;
	}
	menu.keyboard(key, x, y);
	switch (key) {
		case 'w':
			glRotatef(5.0f, 1.0f, 0.0f, 0.0f);
			break;
		case 's':
			glRotatef(-5.0f, 1.0f, 0.0f, 0.0f);
			break;
		case 'a':
			glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
			break;
		case 'd':
			glRotatef(-5.0f, 0.0f, 1.0f, 0.0f);
			break;
		case 'e':
			glRotatef(5.0f, 0.0f, 0.0f, 1.0f);
			break;
		case 'q':
			glRotatef(-5.0f, 0.0f, 0.0f, 1.0f);
			break;
		case '=':
			glScalef(1.1f, 1.1f, 1.1f);
			break;
		case '-':
			glScalef(0.9f, 0.9f, 0.9f);
			break;
		default:
			return;
	}
}

/*----------------------------------------------------------------------------------------------------------------------
 * This method set the perspective projection.
 * -------------------------------------------------------------------------------------------------------------------*/
void setPerspectiveProjection(GLfloat aspect) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FOV, aspect, NEAR_PRSP, FAR_PRSP);
	glMatrixMode(GL_MODELVIEW);
}


/*----------------------------------------------------------------------------------------------------------------------
 * This method all the reshape of the menu and the world.
 * -------------------------------------------------------------------------------------------------------------------*/
void reshapeFun(int w, int h) {
	menu.reshape(w, h);
	glViewport(0, 0, w, h);
	setPerspectiveProjection((GLfloat) w / (GLfloat) h);
	setCameraView();
}

/*----------------------------------------------------------------------------------------------------------------------
 * This method init the setup
 * -------------------------------------------------------------------------------------------------------------------*/
void initialSetup(){
	glEnable(GL_CULL_FACE);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_SMOOTH);
	glEnable(GL_BLEND);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	menu.setup();
	lamp.init();
	room_floor.init();
	window.init();

	setPerspectiveProjection((GLfloat) glutGet(GLUT_WINDOW_WIDTH) / (GLfloat) glutGet(GLUT_WINDOW_HEIGHT));
	setCameraView();
}

/*----------------------------------------------------------------------------------------------------------------------
 * This is the main method
 * -------------------------------------------------------------------------------------------------------------------*/
int main(int argc, char **argv) {
    glewInit();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - WIN_WIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT) / 2 -
																		   WIN_HEIGHT / 2);
	glutCreateWindow(WIN_NAME);
	glutDisplayFunc(displayFun);
	glutReshapeFunc(reshapeFun);
	glutKeyboardFunc(keyboardFun);


	initialSetup();


	glutMainLoop();
	menu.cleanup();
	return 0;
}