/**
@file bed.cpp
*/
#include "bed.h"
//Function to draw our king sized bed.
void drawBed() {

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

 
 glRotatef( 0, 1.0, 0.0, 0.0 );
 glRotatef( 0, 0.0, 1.0, 0.0 );

 glColor3f(0.36f,0.25f,0.20f);
 glBegin(GL_QUADS);
 //Front
 glNormal3f(0.0f,0.0f,1.0f);
 glVertex3f(-4.0f,-0.5f,6.0f);
 glVertex3f(4.0f,-0.5f,6.0f);
 glVertex3f(4.0f,0.5f,6.0f);
 glVertex3f(-4.0f,0.5f,6.0f);

//Right
 glNormal3f(1.0f,0.0f,0.0f);
 glVertex3f(4.0f,-0.5f,6.0f);
 glVertex3f(4.0f,-0.5f,-6.0f);
 glVertex3f(4.0f,0.5f,6.0f);
 glVertex3f(4.0f,0.5f,-6.0f);

 //Back
  glNormal3f(0.0f,0.0f,-1.0f);
 glVertex3f(-4.0f,-0.5f,-6.0f);
 glVertex3f(4.0f,-0.5f,-6.0f);
 glVertex3f(4.0f,0.5f,-6.0f);
 glVertex3f(-4.0f,0.5f,-6.0f);

 //Left 

 glNormal3f(-1.0f,0.0f,0.0f);
 glVertex3f(-4.0f,-0.5f,6.0f);
 glVertex3f(-4.0f,0.5f,6.0f);
 glVertex3f(-4.0f,0.5f,-6.0f);
 glVertex3f(-4.0f,-0.5f,-6.0f);

 //top
 glNormal3f(0.0f,1.0f,0.0f);
 glVertex3f(-4.0f,0.5f,6.0f);
 glVertex3f(4.0f,0.5f,6.0f);
 glVertex3f(4.0f,0.5f,-6.0f);
 glVertex3f(-4.0f,0.5f,-6.0f);

 //Bottom
 glNormal3f(0.0f,-1.0f,0.0f);
 glVertex3f(-4.0f,-0.5f,6.0f);
 glVertex3f(4.0f,-0.5f,6.0f);
 glVertex3f(4.0f,-0.5f,-6.0f);
 glVertex3f(-4.0f,-0.5f,-6.0f);

 //Bed front leg
//front

glNormal3f(0.0f, 0.0f, 1.0f);

 glVertex3f(3.8f,-0.5f,5.8f);
 glVertex3f(3.2f, -0.5f, 5.8f);
 glVertex3f(3.2f, -3.0f, 5.8f);
 glVertex3f(3.8f, -3.0f, 5.8f);

    //back
    glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(3.8f,-0.5f,5.2f);
 glVertex3f(3.2f, -0.5f, 5.2f);
 glVertex3f(3.2f, -3.0f, 5.2f);
 glVertex3f(3.8f, -3.0f, 5.2f);

 //right
 glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(3.8f,-0.5f,5.8f);
 glVertex3f(3.8f, -0.5f, 5.2f);
 glVertex3f(3.8f, -3.0f, 5.2f);
 glVertex3f(3.8f, -3.0f, 5.8f);

    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

 glVertex3f(3.2f,-0.5f,5.8f);
 glVertex3f(3.2f, -0.5f, 5.2f);
 glVertex3f(3.2f, -3.0f, 5.2f);
 glVertex3f(3.2f, -3.0f, 5.8f);

 //back leg back
 //front
 glNormal3f(0.0f, 0.0f, -1.0f);
 glVertex3f(3.8f, -0.5f, -5.2f);
 glVertex3f(3.2f, -0.5f, -5.2f);
 glVertex3f(3.2f, -3.0f, -5.2f);
 glVertex3f(3.8f, -3.0f, -5.2f);

 //back
 glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(3.8f,-0.5f,-5.8f);
 glVertex3f(3.2f, -0.5f, -5.8f);
 glVertex3f(3.2f, -3.0f, -5.8f);
 glVertex3f(3.8f, -3.0f, -5.8f);

    //right
    glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(3.8f,-0.5f,-5.8f);
 glVertex3f(3.8f, -0.5f, -5.2f);
 glVertex3f(3.8f, -3.0f, -5.2f);
 glVertex3f(3.8f, -3.0f, -5.8f);

 //left
    glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(3.2f,-0.5f,-5.8f);
 glVertex3f(3.2f, -0.5f, -5.2f);
 glVertex3f(3.2f, -3.0f, -5.2f);
 glVertex3f(3.2f, -3.0f, -5.8f);

    //leg left front
    glNormal3f(0.0f, 0.0f, 1.0f);

 glVertex3f(-3.8f,-0.5f,5.8f);
 glVertex3f(-3.2f, -0.5f, 5.8f);
 glVertex3f(-3.2f, -3.0f, 5.8f);
 glVertex3f(-3.8f, -3.0f, 5.8f);

    //back
    glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(-3.8f,-0.5f,5.2f);
 glVertex3f(-3.2f, -0.5f, 5.2f);
 glVertex3f(-3.2f, -3.0f, 5.2f);
 glVertex3f(-3.8f, -3.0f, 5.2f);

 //right
 glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(-3.8f,-0.5f,5.8f);
 glVertex3f(-3.8f, -0.5f, 5.2f);
 glVertex3f(-3.8f, -3.0f, 5.2f);
 glVertex3f(-3.8f, -3.0f, 5.8f);

    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

 glVertex3f(-3.2f,-0.5f,5.8f);
 glVertex3f(-3.2f, -0.5f, 5.2f);
 glVertex3f(-3.2f, -3.0f, 5.2f);
 glVertex3f(-3.2f, -3.0f, 5.8f);

 //left leg back front

 //front
 glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(-3.8f,-0.5f,-5.2f);
 glVertex3f(-3.2f, -0.5f, -5.2f);
 glVertex3f(-3.2f, -3.0f, -5.2f);
 glVertex3f(-3.8f, -3.0f, -5.2f);

 //back
 glNormal3f(0.0f, 0.0f, -1.0f);

 glVertex3f(-3.8f,-0.5f,-5.8f);
 glVertex3f(-3.2f, -0.5f, -5.8f);
 glVertex3f(-3.2f, -3.0f, -5.8f);
 glVertex3f(-3.8f, -3.0f, -5.8f);

    //right
    glNormal3f(1.0f, 0.0f, 0.0f);

 glVertex3f(-3.8f,-0.5f,-5.8f);
 glVertex3f(-3.8f, -0.5f, -5.2f);
 glVertex3f(-3.8f, -3.0f, -5.2f);
 glVertex3f(-3.8f, -3.0f, -5.8f);

 //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

 glVertex3f(-3.2f,-0.5f,-5.8f);
 glVertex3f(-3.2f, -0.5f, -5.2f);
 glVertex3f(-3.2f, -3.0f, -5.2f);
 glVertex3f(-3.2f, -3.0f, -5.8f);


//bed hood
 //front
 glColor3f(0.64,0.16,0.16);
 //glNormal3f(-1.0f, 0.0f, 0.0f);
 glVertex3f(-4.0f, 0.5f, -5.4f);
 glVertex3f(4.0f, 0.5f, -5.4f);
 glVertex3f(4.0f, 3.5f, -5.4f);
 glVertex3f(-4.0f, 3.5f, -5.4f);

    //back
 //glNormal3f(-1.0f, 0.0f, 0.0f);
 glVertex3f(-4.0f, 0.5f, -6.0f);
 glVertex3f(4.0f, 0.5f, -6.0f);
 glVertex3f(4.0f, 3.5f, -6.0f);
 glVertex3f(-4.0f, 3.5f, -6.0f);


  //  glNormal3f(-1.0f, 0.0f, 0.0f);
 glVertex3f(-4.0f, 0.5f, -6.0f);
 glVertex3f(-4.0f, 3.5f, -6.0f);
 glVertex3f(-4.0f, 3.5f, -5.4f);
 glVertex3f(-4.0f, 0.5f, -5.4f);

 glVertex3f(4.0f, 0.5f, -6.0f);
 glVertex3f(4.0f, 3.5f, -6.0f);
 glVertex3f(4.0f, 3.5f, -5.4f);
 glVertex3f(4.0f, 0.5f, -5.4f);

 glVertex3f(4.0f, 3.5f, -6.0f);
 glVertex3f(4.0f, 3.5f, -5.4f);
 glVertex3f(4.0f, 3.5f, -5.4f);
 glVertex3f(4.0f, 3.5f, -6.0f);

 
 glColor3f(1.0f,1.0f,1.0f);
 //Front
 glNormal3f(0.0f,0.0f,1.0f);
 glVertex3f(-3.8f,0.5f,6.0f);
 glVertex3f(3.8f,0.5f,6.0f);
 glVertex3f(3.8f,1.0f,6.0f);
 glVertex3f(-3.8f,1.0f,6.0f);

//Right
 glNormal3f(1.0f,0.0f,0.0f);
 glVertex3f(3.8f,0.5f,6.0f);
 glVertex3f(3.8f,0.5f,-6.0f);
 glVertex3f(3.8f,1.0f,6.0f);
 glVertex3f(3.8f,1.0f,-6.0f);

 //Back
  glNormal3f(0.0f,0.0f,-1.0f);
 glVertex3f(-3.8f,0.5f,-5.4f);
 glVertex3f(3.8f,0.5f,-5.4f);
 glVertex3f(3.8f,1.0f,-5.4f);
 glVertex3f(-3.8f,1.0f,-5.4f);

 //Left 

 glNormal3f(-1.0f,0.0f,0.0f);
 glVertex3f(-3.8f,0.5f,6.0f);
 glVertex3f(-3.8f,1.0f,6.0f);
 glVertex3f(-3.8f,1.0f,-5.4f);
 glVertex3f(-3.8f,0.5f,-5.4f);

 //top
 glNormal3f(0.0f,1.0f,0.0f);
 glVertex3f(-3.8f,1.0f,6.0f);
 glVertex3f(3.8f,1.0f,6.0f);
 glVertex3f(3.8f,1.0f,-5.4f);
 glVertex3f(-3.8f,1.0f,-5.4f);

 //Bottom
 glNormal3f(0.0f,-1.0f,0.0f);
 glVertex3f(-3.8f,0.5f,6.0f);
 glVertex3f(3.8f,0.5f,6.0f);
 glVertex3f(3.8f,0.5f,-5.4f);
 glVertex3f(-3.8f,0.5f,-5.4f);

  glEnd();
}