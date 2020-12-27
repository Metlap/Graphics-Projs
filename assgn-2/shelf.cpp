/**
@file shelf.cpp
*/
#include "shelf.h"

/*! This function draws the book shelf*/
void drawShelf() {

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

///Front 
//lowest rack base
glNormal3f(0.0f,0.0f,1.0f);
glVertex3f(-3.8f,-6.4f,2.0f);
glVertex3f(3.8f,-6.4f,2.0f);
glVertex3f(3.8f,-6.2f,2.0f);
glVertex3f(-3.8f,-6.2f,2.0f);

//loewer rack base
glNormal3f(0.0f,0.0f,1.0f);
glVertex3f(-3.8f,-2.2f,2.0f);
glVertex3f(3.8f,-2.2f,2.0f);
glVertex3f(3.8f,-2.0f,2.0f);
glVertex3f(-3.8f,-2.0f,2.0f);

//upper rack base
glNormal3f(0.0f,0.0f,1.0f);
glVertex3f(-3.8f,2.2f,2.0f);
glVertex3f(3.8f,2.2f,2.0f);
glVertex3f(3.8f,2.0f,2.0f);
glVertex3f(-3.8f,2.0f,2.0f);

//top most 
glNormal3f(0.0f,0.0f,1.0f);
glVertex3f(-3.8f,6.4f,2.0f);
glVertex3f(3.8f,6.4f,2.0f);
glVertex3f(3.8f,6.2f,2.0f);
glVertex3f(-3.8f,6.2f,2.0f);

///Back
//lowest rack base
glNormal3f(0.0f,0.0f,-1.0f);
glVertex3f(-3.8f,-6.4f,-2.0f);
glVertex3f(3.8f,-6.4f,-2.0f);
glVertex3f(3.8f,-6.2f,-2.0f);
glVertex3f(-3.8f,-6.2f,-2.0f);

//loewer rack base
glNormal3f(0.0f,0.0f,-1.0f);
glVertex3f(-3.8f,-2.2f,-2.0f);
glVertex3f(3.8f,-2.2f,-2.0f);
glVertex3f(3.8f,-2.0f,-2.0f);
glVertex3f(-3.8f,-2.0f,-2.0f);

//upper rack base
glNormal3f(0.0f,0.0f,-1.0f);
glVertex3f(-3.8f,2.2f,-2.0f);
glVertex3f(3.8f,2.2f,-2.0f);
glVertex3f(3.8f,2.0f,-2.0f);
glVertex3f(-3.8f,2.0f,-2.0f);

//top most 
glNormal3f(0.0f,0.0f,-1.0f);
glVertex3f(-3.8f,6.4f,-2.0f);
glVertex3f(3.8f,6.4f,-2.0f);
glVertex3f(3.8f,6.2f,-2.0f);
glVertex3f(-3.8f,6.2f,-2.0f);


///Bottom
//lowest rack base
glNormal3f(0.0f,-1.0f,0.0f);
glVertex3f(-3.8f,-6.4f,2.0f);
glVertex3f(3.8f,-6.4f,2.0f);
glVertex3f(3.8f,-6.4f,-2.0f);
glVertex3f(-3.8f,-6.4f,-2.0f);

//loewer rack base
glNormal3f(0.0f,-1.0f,0.0f);
glVertex3f(-3.8f,-2.2f,2.0f);
glVertex3f(3.8f,-2.2f,2.0f);
glVertex3f(3.8f,-2.2f,-2.0f);
glVertex3f(-3.8f,-2.2f,-2.0f);

//upper rack base
glNormal3f(0.0f,-1.0f,0.0f);
glVertex3f(-3.8f,2.0f,2.0f);
glVertex3f(3.8f,2.0f,2.0f);
glVertex3f(3.8f,2.0f,-2.0f);
glVertex3f(-3.8f,2.0f,-2.0f);

//top most 
glNormal3f(0.0f,-1.0f,0.0f);
glVertex3f(-3.8f,6.2f,2.0f);
glVertex3f(3.8f,6.2f,2.0f);
glVertex3f(3.8f,6.2f,-2.0f);
glVertex3f(-3.8f,6.2f,-2.0f);

///Top

//lowest rack base
glNormal3f(0.0f,1.0f,0.0f);
glVertex3f(-3.8f,-6.2f,2.0f);
glVertex3f(3.8f,-6.2f,2.0f);
glVertex3f(3.8f,-6.2f,-2.0f);
glVertex3f(-3.8f,-6.2f,-2.0f);

//loewer rack base
glNormal3f(0.0f,1.0f,0.0f);
glVertex3f(-3.8f,-2.f,2.0f);
glVertex3f(3.8f,-2.0f,2.0f);
glVertex3f(3.8f,-2.0f,-2.0f);
glVertex3f(-3.8f,-2.0f,-2.0f);

//upper rack base
glNormal3f(0.0f,1.0f,0.0f);
glVertex3f(-3.8f,2.2f,2.0f);
glVertex3f(3.8f,2.2f,2.0f);
glVertex3f(3.8f,2.2f,-2.0f);
glVertex3f(-3.8f,2.2f,-2.0f);

//top most 
glNormal3f(0.0f,1.0f,0.0f);
glVertex3f(-3.8f,6.4f,2.0f);
glVertex3f(3.8f,6.4f,2.0f);
glVertex3f(3.8f,6.4f,-2.0f);
glVertex3f(-3.8f,6.4f,-2.0f);

///Left view of racks
glNormal3f(-1.0f,0.0f,0.0f);
glVertex3f(-3.8f,-6.4f,-2.0f);
glVertex3f(-3.8f,-6.4f,2.0f);
glVertex3f(-3.8f,-6.2f,2.0f);
glVertex3f(-3.8f,-6.2f,-2.0f);

glNormal3f(-1.0f,0.0f,0.0f);
glVertex3f(-3.8f,-2.2f,-2.0f);
glVertex3f(-3.8f,-2.2f,2.0f);
glVertex3f(-3.8f,-2.0f,2.0f);
glVertex3f(-3.8f,-2.0f,-2.0f);

glNormal3f(-1.0f,0.0f,0.0f);
glVertex3f(-3.8f,2.0f,-2.0f);
glVertex3f(-3.8f,2.0f,2.0f);
glVertex3f(-3.8f,2.2f,2.0f);
glVertex3f(-3.8f,2.2f,-2.0f);

glNormal3f(-1.0f,0.0f,0.0f);
glVertex3f(-3.8f,6.2f,-2.0f);
glVertex3f(-3.8f,6.2f,2.0f);
glVertex3f(-3.8f,6.4f,2.0f);
glVertex3f(-3.8f,6.4f,-2.0f);

//Right view of racks

glNormal3f(1.0f,0.0f,0.0f);
glVertex3f(3.8f,-6.4f,-2.0f);
glVertex3f(3.8f,-6.4f,2.0f);
glVertex3f(3.8f,-6.2f,2.0f);
glVertex3f(3.8f,-6.2f,-2.0f);

glNormal3f(1.0f,0.0f,0.0f);
glVertex3f(3.8f,-2.2f,-2.0f);
glVertex3f(3.8f,-2.2f,2.0f);
glVertex3f(3.8f,-2.0f,2.0f);
glVertex3f(3.8f,-2.0f,-2.0f);

glNormal3f(1.0f,0.0f,0.0f);
glVertex3f(3.8f,2.0f,-2.0f);
glVertex3f(3.8f,2.0f,2.0f);
glVertex3f(3.8f,2.2f,2.0f);
glVertex3f(3.8f,2.2f,-2.0f);

glNormal3f(1.0f,0.0f,0.0f);
glVertex3f(3.8f,6.2f,-2.0f);
glVertex3f(3.8f,6.2f,2.0f);
glVertex3f(3.8f,6.4f,2.0f);
glVertex3f(3.8f,6.4f,-2.0f);

//SIDE SUPPORTS
glColor3f(1.0f,0.0f,0.0f);
//Front view

glNormal3f(0.0f,0.0f,1.0f);
glVertex3f(3.8f,-6.4f,2.0f);
glVertex3f(4.0f,-6.4f,2.0f);
glVertex3f(4.0f,6.4f,2.0f);
glVertex3f(3.8f,6.4f,2.0f);

glNormal3f(1.0f,0.0f,1.0f);
glVertex3f(-4.0f,-6.4f,2.0f);
glVertex3f(-3.8f,-6.4f,2.0f);
glVertex3f(-3.8f,6.4f,-2.0f);
glVertex3f(-4.0f,6.4f,2.0f);

//Back view

glNormal3f(0.0f,0.0f,-1.0f);
glVertex3f(3.8f,-6.4f,-2.0f);
glVertex3f(4.0f,-6.4f,-2.0f);
glVertex3f(4.0f,6.4f,-2.0f);
glVertex3f(3.8f,6.4f,-2.0f);

glNormal3f(0.0f,0.0f,-1.0f);
glVertex3f(-4.0f,-6.4f,-2.0f);
glVertex3f(-3.8f,-6.4f,-2.0f);
glVertex3f(-3.8f,6.4f,-2.0f);
glVertex3f(-4.0f,6.4f,-2.0f);


//Top view

glNormal3f(0.0f,1.0f,0.0f);
glVertex3f(3.8f,6.4f,2.0f);
glVertex3f(4.0f,6.4f,2.0f);
glVertex3f(4.0f,6.4f,-2.0f);
glVertex3f(3.8f,6.4f,-2.0f);

glNormal3f(0.0f,1.0f,0.0f);
glVertex3f(-3.8f,6.4f,2.0f);
glVertex3f(-4.0f,6.4f,2.0f);
glVertex3f(-4.0f,6.4f,-2.0f);
glVertex3f(-3.8f,6.4f,-2.0f);

//Bottom view

glNormal3f(0.0f,-1.0f,0.0f);
glVertex3f(3.8f,-6.4f,2.0f);
glVertex3f(4.0f,-6.4f,2.0f);
glVertex3f(4.0f,-6.4f,-2.0f);
glVertex3f(3.8f,-6.4f,-2.0f);

glNormal3f(0.0f,-1.0f,0.0f);
glVertex3f(-3.8f,-6.4f,2.0f);
glVertex3f(-4.0f,-6.4f,2.0f);
glVertex3f(-4.0f,-6.4f,-2.0f);
glVertex3f(-3.8f,-6.4f,-2.0f);

//Right view

glNormal3f(1.0f,0.0f,0.0f);
glVertex3f(4.0f,-6.4f,2.0f);
glVertex3f(4.0f,-6.4f,-2.0f);
glVertex3f(4.0f,6.4f,-2.0f);
glVertex3f(4.0f,6.4f,2.0f);

glNormal3f(1.0f,0.0f,0.0f);
glVertex3f(-3.8f,-6.4f,2.0f);
glVertex3f(-3.8f,-6.4f,-2.0f);
glVertex3f(-3.8f,6.4f,-2.0f);
glVertex3f(-3.8f,6.4f,2.0f);


//Left

glNormal3f(-1.0f,0.0f,0.0f);
glVertex3f(-4.0f,-6.4f,2.0f);
glVertex3f(-4.0f,-6.4f,-2.0f);
glVertex3f(-4.0f,6.4f,-2.0f);
glVertex3f(-4.0f,6.4f,2.0f);

glNormal3f(-1.0f,0.0f,0.0f);
glVertex3f(3.8f,-6.4f,2.0f);
glVertex3f(3.8f,-6.4f,-2.0f);
glVertex3f(3.8f,6.4f,-2.0f);
glVertex3f(3.8f,6.4f,2.0f);

glEnd();
}
