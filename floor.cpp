//
// Created by stav on 22/08/18.
//

#include "floor.h"
#include <GL/glut.h>
//#include <stb_image.h>
#include <iostream>

static constexpr GLfloat materialAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
static constexpr GLfloat materialDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
static constexpr GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
static constexpr GLfloat materialShininess = 3.0f;
//static GLuint texture = 0;
//unsigned char *data = nullptr;

//GLuint loadTexture(const char *filename) {

//
//	// load and generate the texture
//	int width, height, nrChannels;
//	data = stbi_load(filename, &width, &height, &nrChannels, 3);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	} else {
//		std::cout << "Failed to load texture" << std::endl;
//	}
////	stbi_image_free(data);
//	return texture;
	// Black/white checkerboard
//	float pixels[] = {
//			0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
//			1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
//	};
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
//	glGenerateMipmap(GL_TEXTURE_2D);
//}

 void Floor::init() {
//	GLuint texture = loadTexture("./floor_tiles.jpg");
//
}

void Floor::draw() {

	// set the texture wrapping/filtering options (on the currently bound texture object)
//	glEnable(GL_TEXTURE_2D);
//	glActiveTexture(GL_TEXTURE0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glPushMatrix();
	glColor4f(0.2f, 0.2f, 0.2f, 1.0f);
	glTranslated(0.4, 0, 0.4);
	glScaled(4.0, 0.025, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();

//	glDisable(GL_COLOR_MATERIAL);
//	glDisable(GL_TEXTURE_2D);

}
