/**
@file fan.cpp
*/

#include "fan.h"
//! This angle specifies the angle by which the fan has to be rotated
float _angle2 = -60.0f;
/*!This function draws our fan
*/
void drawFan(){
	//Rod of the fan from ceiling
	//FRONT 
	glBegin(GL_POLYGON);
	glColor3f(0.75,0.75,0.75);
	glVertex3f(0.03f,-0.03f,-0.4f);
	glVertex3f(0.03,-0.03,-0.4);
	glVertex3f(-0.03,0.03,-0.4);
	glVertex3f(-0.03,-0.03,-0.4);

	glEnd();
	//BACK
	glBegin(GL_POLYGON);
	glColor3f(0.75,0.75,0.75);
	glVertex3f(0.03,-0.03,0.4);
	glVertex3f(0.03,0.03,0.4);
	glVertex3f(-0.03,0.03,0.4);
	glVertex3f(-0.03,-0.03,0.4);
	glEnd();

	//RIGHT
	glBegin(GL_POLYGON);
	glColor3f(  0.75,  0.75,  0.75 );
  glVertex3f( 0.03, -0.03, -0.4 );
  glVertex3f( 0.03,  0.03, -0.4 );
  glVertex3f( 0.03,  0.03,  0.4 );
  glVertex3f( 0.03, -0.03,  0.4 );
  glEnd();

  //  LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.75, 0.75,  0.75 );
  glVertex3f( -0.03, -0.03,  0.4 );
  glVertex3f( -0.03,  0.03,  0.4 );
  glVertex3f( -0.03,  0.03, -0.4 );
  glVertex3f( -0.03, -0.03, -0.4 );
  glEnd();

  //  TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.75,  0.75,  0.75 );
  glVertex3f(  0.03,  0.03,  0.4 );
  glVertex3f(  0.03,  0.03, -0.4 );
  glVertex3f( -0.03,  0.03, -0.4 );
  glVertex3f( -0.03,  0.03,  0.4 );
  glEnd();

  //  BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   0.75,  0.75,  0.75 );
  glVertex3f(  0.03, -0.03, -0.4 );
  glVertex3f(  0.03, -0.03,  0.4 );
  glVertex3f( -0.03, -0.03,  0.4 );
  glVertex3f( -0.03, -0.03, -0.4 );
  glEnd();

  glTranslatef(0.0,0.0,-0.4);
  glRotatef(_angle2,0.0f,0.0f,1.0f);
//Drawing the center of the fan
// FRONT
  glBegin(GL_POLYGON);
  glColor3f(   0.25,  0.25, 0.25 );
  glVertex3f(  0.12, -0.12, -0.05 );      
  glVertex3f(  0.12,  0.12, -0.05 );      
  glVertex3f( -0.12,  0.12, -0.05 );      
  glVertex3f( -0.12, -0.12, -0.05 );      
  glEnd();

  //   BACK
  glBegin(GL_POLYGON);
  glColor3f(   0.25,  0.25, 0.25);
  glVertex3f(  0.12, -0.12, 0.05 );
  glVertex3f(  0.12,  0.12, 0.05 );
  glVertex3f( -0.12,  0.12, 0.05 );
  glVertex3f( -0.12, -0.12, 0.05 );
  glEnd();

  //  RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  0.25,  0.25,  0.25 );
  glVertex3f( 0.12, -0.12, -0.05 );
  glVertex3f( 0.12,  0.12, -0.05 );
  glVertex3f( 0.12,  0.12,  0.05 );
  glVertex3f( 0.12, -0.12,  0.05 );
  glEnd();

  //  LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.25,  0.25,  0.25 );
  glVertex3f( -0.12, -0.12,  0.05 );
  glVertex3f( -0.12,  0.12,  0.05 );
  glVertex3f( -0.12,  0.12, -0.05 );
  glVertex3f( -0.12, -0.12, -0.05 );
  glEnd();

  //  TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.25,  0.25,  0.25 );
  glVertex3f(  0.12,  0.12,  0.05 );
  glVertex3f(  0.12,  0.12, -0.05 );
  glVertex3f( -0.12,  0.12, -0.05 );
  glVertex3f( -0.12,  0.12,  0.05 );
  glEnd();

  //  BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   0.25,  0.25,  0.25 );
  glVertex3f(  0.12, -0.12, -0.05 );
  glVertex3f(  0.12, -0.12,  0.05 );
  glVertex3f( -0.12, -0.12,  0.05 );
  glVertex3f( -0.12, -0.12, -0.05 );
  glEnd();
//Fan wings colored in grey
glBegin(GL_TRIANGLES);
  glColor3f( 0.75, 0.75, 0.75 ); 
  glVertex3f( -0.15, 0.9, 0 );
  glVertex3f( 0.15, 0.9, 0 );
  glVertex3f( 0, 0 , 0);
  glEnd();

  glRotatef( 120, 0.0, 0.0, 1.0 );
  glBegin(GL_TRIANGLES);
  glColor3f( 0.75, 0.75, 0.75 ); 
  glVertex3f( -0.15, 0.9, 0 );
  glVertex3f( 0.15, 0.9, 0 );
  glVertex3f( 0, 0 , 0);
  glEnd();

  glRotatef( 120, 0.0, 0.0, 1.0 );
  glBegin(GL_TRIANGLES);
  glColor3f( 0.75, 0.75, 0.75 ); 
  glVertex3f( -0.15, 0.9, 0 );
  glVertex3f( 0.15, 0.9, 0 );
  glVertex3f( 0, 0 , 0);
  glEnd();
  //Specifies the angle by which the fan rotates every second
  _angle2 += 3.0f;
  if (_angle2 > 360) {
      _angle2 -= 360;
  }

}
