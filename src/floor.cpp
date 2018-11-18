//
// Created by stav on 22/08/18.
//


#include "floor.h"
#include "stb_image.h"
#include <iostream>



static constexpr GLfloat materialAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
static constexpr GLfloat materialDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
static constexpr GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
static constexpr GLfloat materialShininess = 3.0f;

void loadTexture(const char *filename) {
	//	load and generate the texture
	int width, height, nrChannels;
	unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
	if (data) {
		GLuint texture;
		glGenTextures(1, &texture);
        glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,  GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}


void Floor::init() {
//	loadTexture("../resources/floor.bmp");
}

void Floor::draw() {
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	GLfloat plane[] = {0.0, 0.0, 1.0, 0.0};
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_LINEAR, plane);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane);

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslated(0.4, 0.0, 0.4);
	glScaled(4.0, 0.025, 4.0);

	glutSolidCube(1.0);

	glPopMatrix();


	glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

//	glDisable(GL_COLOR_MATERIAL);

}
