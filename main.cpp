
// includes

#include "imgui/imgui.h"
#include "imgui/imgui_impl_freeglut.h"
#include "imgui/imgui_impl_opengl2.h"
#include <GL/glut.h>
#include <iostream>
#include "dog.h"
#include "room.h"
#include "items.h"
#include "lamp.h"

//using namespace std
//cout<<"HELLO WORLD"<<endl;

// misc
static constexpr GLsizei NUM_COORDINATES = 3;

// window
static constexpr GLchar WIN_NAME[] = "Dog Room Scene";
static constexpr GLint WIN_WIDTH = 1280;
static constexpr GLint WIN_HEIGHT = 720;

// perspective
static constexpr GLdouble FOV = 40.0;
static constexpr GLdouble NEAR = 1.0;
static constexpr GLdouble FAR = 10.0;


// eye
static constexpr GLdouble EYE_POS[NUM_COORDINATES] = {0.0, 2.0, 2.0};
static constexpr GLdouble EYE_CENTER[NUM_COORDINATES] = {0.0, 1.0, 0.0};
static constexpr GLdouble EYE_UP[NUM_COORDINATES] = {0.0, 1.0, 0.0};



static bool show_demo_window = true;
static bool show_another_window = false;

Dog dog;
Room room;
Ball ball;
Bone bone;
Bowl bowl;
Lamp lamp;

void display_menu() {
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplFreeGLUT_NewFrame();

    static float f = 0.0f;
    ImGui::Begin("Scene Control Panel", &show_another_window);

    ImGui::Spacing();
    ImGui::Text("Camera Options");
    ImGui::Checkbox("Keyboard Control Camera", &show_demo_window);

    ImGui::Spacing();
    ImGui::Text("Ambient Light Options");
    ImGui::SliderFloat("Intensity", &f, 0.0f, 1.0f);

    ImGui::Spacing();
    ImGui::Text("Point Light Options");
    ImGui::Checkbox("Keyboard Control Light", &show_demo_window);
    ImGui::SliderFloat("Intensity", &f, 0.0f, 1.0f);

    ImGui::Spacing();
    ImGui::Text("Dog Options");
    ImGui::Checkbox("Dog View Point", &show_demo_window);
    ImGui::Checkbox("Keyboard Control Dog", &show_demo_window);
    ImGui::Checkbox("Tail Animation", &show_demo_window);      // Edit bools storing our windows open/close state
    ImGui::Checkbox("Head Animation", &show_another_window);
    ImGui::Checkbox("Legs Animation", &show_another_window);

    ImGui::Spacing();
    ImGui::Button("Help");

    ImGui::Spacing();
    ImGui::Button("Quit");

    ImGui::Spacing();
    ImGui::End();
    ImGui::Render();

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}


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


void displayFun(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    room.draw();
    dog.draw();
    ball.draw();
    bone.draw();
    bowl.draw();
    lamp.draw();
    display_menu();

    glutSwapBuffers();
    glutPostRedisplay();
}



void keyboardFun(unsigned char key, int x, int y) {
    ImGui_ImplFreeGLUT_KeyboardFunc(key, x, y);
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
        case 'o':
            dog.setTailUpAndDown(true);
            break;
        case 'p':
            dog.setTailUpAndDown(false);
            break;
        case 'u':
            dog.setTailRightAndLeft(true);
            break;
        case 'i':
            dog.setTailRightAndLeft(false);
            break;
        case 'O':
            dog.setHeadUpAndDown(true);
            break;
        case 'P':
            dog.setHeadUpAndDown(false);
            break;
        case 'U':
            dog.setHeadRightAndLeft(true);
            break;
        case 'I':
            dog.setHeadRightAndLeft(false);
            break;
        case '1':
            dog.setMoveTopRightLeg(true);
            break;
        default:
            return;    }
}

void setPerspectiveProjection(GLfloat aspect) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOV, aspect, NEAR, FAR);
    glMatrixMode(GL_MODELVIEW);
}

void setCameraView() {
    glLoadIdentity();
    gluLookAt(EYE_POS[0], EYE_POS[1], EYE_POS[2], EYE_CENTER[0], EYE_CENTER[1], EYE_CENTER[2], EYE_UP[0], EYE_UP[1], EYE_UP[2]);
}

void reshapeFun(int w, int h) {
    ImGui_ImplFreeGLUT_ReshapeFunc(w, h);
    glViewport(0, 0, w, h);
    setPerspectiveProjection((GLfloat) w / (GLfloat) h);
    setCameraView();
}

void initialSetup(){
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);


    GLfloat mat_ambient[]={0.7f,0.7f,0.7f,0.1f};
    GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[]={20.0f};

    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    GLfloat light_Intensity[]={0.9f,0.9f,0.9f,1.0f};

    GLfloat light_Position[]={4.0f,6.0f,3.0f,0.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,light_Position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_Intensity);

    setPerspectiveProjection((GLfloat) glutGet(GLUT_WINDOW_WIDTH) / (GLfloat) glutGet(GLUT_WINDOW_HEIGHT));
    setCameraView();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - WIN_WIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT) / 2 - WIN_HEIGHT / 2);
    glutCreateWindow(WIN_NAME);
    glutDisplayFunc(displayFun);
    glutReshapeFunc(reshapeFun);
    glutKeyboardFunc(keyboardFun);


    GLuint image = loadBMP_custom("/home/stav/CLionProjects/mmn-17-computer-graphics/resources/Grass01.bmp");


    initialSetup();

    // Setup ImGui binding
    ImGui::CreateContext();
    ImGui_ImplFreeGLUT_Init();
    ImGui_ImplFreeGLUT_InstallFuncs();
    ImGui_ImplOpenGL2_Init();
    ImGui::StyleColorsDark(); // Setup style

    glutMainLoop();

    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplFreeGLUT_Shutdown();
    ImGui::DestroyContext();

    return 0;

}