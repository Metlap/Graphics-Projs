/**
@file table.cpp
*/
#include "table.h"
void drawTable()
{
	//Add ambient light
 GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

 //Add positioned light
 GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
 GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
 glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
 glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

 //Add directed light
 GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
 //Coming from the direction (-1, 0.5, 0.5)
 GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
 glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
 glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

 glColor3f(0.58f, 0.47f, 0.14f);
 glBegin(GL_QUADS);

//Front
 glNormal3f(0.0f,0.0f,1.0f);
 glVertex3f(-2.0f,-0.2f,2.0f);
 glVertex3f(2.0f,-0.2f,2.0f);
 glVertex3f(2.0f,0.2f,2.0f);
 glVertex3f(-2.0f,0.2f,2.0f);

 //Right
 glNormal3f(1.0f,0.0f,0.0f);
 glVertex3f(2.0f, -0.2f, -2.0f);
 glVertex3f(2.0f, 0.2f, -2.0f);
 glVertex3f(2.0f, 0.2f, 2.0f);
 glVertex3f(2.0f, -0.2f, 2.0f);

 //Back
 glNormal3f(0.0f, 0.0f, -1.0f);
 glVertex3f(-2.0f, -0.2f, -2.0f);
 glVertex3f(-2.0f, 0.2f, -2.0f);
 glVertex3f(2.0f, 0.2f, -2.0f);
 glVertex3f(2.0f, -0.2f, -2.0f);

 //Left
 glNormal3f(-1.0f, 0.0f, 0.0f);
 glVertex3f(-2.0f, -0.2f, -2.0f);
 glVertex3f(-2.0f, -0.2f, 2.0f);
 glVertex3f(-2.0f, 0.2f, 2.0f);
 glVertex3f(-2.0f, 0.2f, -2.0f);

 //Top
 glNormal3f(0.0f,1.0f,0.0f);
 glVertex3f(2.0f, 0.2f, 2.0f);
 glVertex3f(-2.0f, 0.2f, 2.0f);
 glVertex3f(-2.0f, 0.2f, -2.0f);
 glVertex3f(2.0f, 0.2f, -2.0f);

 //Bottom
 glNormal3f(0.0f,-1.0f,0.0f);
 glVertex3f(2.0f, -0.2f, 2.0f);
 glVertex3f(-2.0f, -0.2f, 2.0f);
 glVertex3f(-2.0f, -0.2f, -2.0f);
 glVertex3f(2.0f, -0.2f, -2.0f);

 //Table front leg
 //front
   glNormal3f(0.0f, 0.0f, 1.0f);

 glVertex3f(1.8f,-0.2f,1.8f);
 glVertex3f(1.4f, -0.2f, 1.8f);
 glVertex3f(1.4f, -3.0f, 1.8f);
 glVertex3f(1.8f, -3.0f, 1.8f);

    //back
    glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(1.8f,-0.2f,1.4f);
 glVertex3f(1.4f, -0.2f, 1.4f);
 glVertex3f(1.4f, -3.0f, 1.4f);
 glVertex3f(1.8f, -3.0f, 1.4f);

 //right
 glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(1.8f,-0.2f,1.8f);
 glVertex3f(1.8f, -0.2f, 1.4f);
 glVertex3f(1.8f, -3.0f, 1.4f);
 glVertex3f(1.8f, -3.0f, 1.8f);

    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

 glVertex3f(1.4f,-0.2f,1.8f);
 glVertex3f(1.4f, -0.2f, 1.4f);
 glVertex3f(1.4f, -3.0f, 1.4f);
 glVertex3f(1.4f, -3.0f, 1.8f);

//back leg back
 //front
 glNormal3f(0.0f, 0.0f, -1.0f);
 glVertex3f(1.8f, -0.2f, -1.4f);
 glVertex3f(1.4f, -0.2f, -1.4f);
 glVertex3f(1.4f, -3.0f, -1.4f);
 glVertex3f(1.8f, -3.0f, -1.4f);

 //back
 glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(1.8f,-0.2f,-1.8f);
 glVertex3f(1.4f, -0.2f, -1.8f);
 glVertex3f(1.4f, -3.0f, -1.8f);
 glVertex3f(1.8f, -3.0f, -1.8f);

    //right
    glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(1.8f,-0.2f,-1.8f);
 glVertex3f(1.8f, -0.2f, -1.4f);
 glVertex3f(1.8f, -3.0f, -1.4f);
 glVertex3f(1.8f, -3.0f, -1.8f);

 //left
    glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(1.4f,-0.2f,-1.8f);
 glVertex3f(1.4f, -0.2f, -1.4f);
 glVertex3f(1.4f, -3.0f, -1.4f);
 glVertex3f(1.4f, -3.0f, -1.8f);

   //leg left
   // front
    glNormal3f(0.0f, 0.0f, 1.0f);

 glVertex3f(-1.8f,-0.2f,1.8f);
 glVertex3f(-1.4f, -0.2f, 1.8f);
 glVertex3f(-1.4f, -3.0f, 1.8f);
 glVertex3f(-1.8f, -3.0f, 1.8f);

    //back
    glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(-1.8f,-0.2f,1.4f);
 glVertex3f(-1.4f, -0.2f, 1.4f);
 glVertex3f(-1.4f, -3.0f, 1.4f);
 glVertex3f(-1.8f, -3.0f, 1.4f);

 //right
 glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(-1.8f,-0.2f,1.8f);
 glVertex3f(-1.8f, -0.2f, 1.4f);
 glVertex3f(-1.8f, -3.0f, 1.4f);
 glVertex3f(-1.8f, -3.0f, 1.8f);

    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

 glVertex3f(-1.4f,-0.2f,1.8f);
 glVertex3f(-1.4f, -0.2f, 1.4f);
 glVertex3f(-1.4f, -3.0f, 1.4f);
 glVertex3f(-1.4f, -3.0f, 1.8f);

 //left leg back front

 //front
 glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(-1.8f,-0.2f,-1.4f);
 glVertex3f(-1.4f, -0.2f, -1.4f);
 glVertex3f(-1.4f, -3.0f, -1.4f);
 glVertex3f(-1.8f, -3.0f, -1.4f);

 //back
 glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(-1.8f,-0.2f,-1.8f);
 glVertex3f(-1.4f, -0.2f, -1.8f);
 glVertex3f(-1.4f, -3.0f, -1.8f);
 glVertex3f(-1.8f, -3.0f, -1.8f);

    //right
    glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(-1.8f,-0.2f,-1.8f);
 glVertex3f(-1.8f, -0.2f, -1.4f);
 glVertex3f(-1.8f, -3.0f, -1.4f);
 glVertex3f(-1.8f, -3.0f, -1.8f);

 //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

 glVertex3f(-1.4f,-0.2f,-1.8f);
 glVertex3f(-1.4f, -0.2f, -1.4f);
 glVertex3f(-1.4f, -3.0f, -1.4f);
 glVertex3f(-1.4f, -3.0f, -1.8f);

glEnd();
}