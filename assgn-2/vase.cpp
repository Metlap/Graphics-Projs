/**
@file vase.cpp
*/
#include "vase.h"
//Function to draw a lamp.
void drawVase() {

 //Add ambient light
 GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

 //Add positioned light
 GLfloat lightColor0[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Color (0.5, 0.5, 0.5)
 GLfloat lightPos0[] = {0.0f, -0.95f, 0.0f, 1.0f}; //Positioned at (4, 0, 8)
 glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
 glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

 //Add directed light
 GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
 //Coming from the direction (-1, 0.5, 0.5)
 GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
 glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
 glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);


glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 glRotatef( 0, 1.0, 0.0, 0.0 );
 glRotatef( 0, 0.0, 1.0, 0.0 );


  
   //create a quadric object which is initially parallel to y axis
  //glPushMatrix(); //cylinder drawing begins
  glTranslatef(0.0,0.0,0.0);
  glRotated(-90,1,0,0); // rotates cylinder to 90 degrees about x axis.
 GLUquadricObj *qob=gluNewQuadric();
 	
  glColor3f(0.9,0.5,0.3);  //put the color of cylinder and disc to sand brown
  gluDisk(qob,0.0,0.40,8,8);//Draws a Disk of specified radius
  glRotated(90,1,0,0);
 // glTranslatef(0.0,0.10,0.0);
  glRotated(-90,1,0,0);
  gluCylinder(qob,0.07,0.07,0.75,8,8);  // creates post like cylinder
  //glPopMatrix();  // end of cylinder drawing
 // glPushMatrix(); //lamp top drawing begins
   
  glRotated(90,1,0,0);
  glColor3f(1.0,1.0,1.0);

  glTranslatef(0,0.85,0.0); //lift it to certain height so that it sits on post top.
   gluSphere(qob,0.10,8,8); // White sphere looks(acts) like the bulb in the lamp.
   glTranslatef(0.0,-0.8,0.0);
   glTranslatef(0.0,0.75,0.0);
 glColor4f(1.0,1.0,0,0.35);//Make the top of lamp translucent.
  glRotated(-90,1,0,0);
  gluCylinder(qob,0.35,0.15,0.35,10,10); //draw top part of lamp.
 // glPopMatrix();
  glRotated(90,1,0,0);
glTranslatef(0.0,-0.75,0.0);
glTranslatef(0.0,0.0,0.0);


}