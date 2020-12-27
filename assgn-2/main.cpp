/**
@file main.cpp
*/
#include <iostream>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <string> 
#include <ctime>

#include<bits/stdc++.h>
#include<windows.h>

#include "table.h"
#include "chair.h"
#include "fan.h"
#include "bed.h"
#include "clock.h"
//#include "dumbells.h"
#include "shelf.h"
#include "vase.h"
#include "ObjectLoader2.8.h"

using namespace std;

double rotate_x = 0.0f;
double rotate_y = 0.0f;
//! The angle specifies the magnitude to which we are looking up or down. Calculated w.r.t x-axis 
double pitch=0.0f;
//! The angle specifies the magnitude to which we are looking left or right. Calculated w.r.t y-axis 
double yaw=-90.0f;
//! This angle defines how much we can see of the scene.
double fov=45.0f;
//! 3D vector that contains the position of camera i.e the PRP
glm::dvec3 cameraPos=glm::dvec3(0.0f,0.0f,4.0f);
//! 3D vector that contains the direction of PRP w.r.t VRP
glm::dvec3 directionSight=glm::dvec3(0.0f,0.0f,-1.0f);
//! 3D vector that contains the direction that defines what direction is UP
glm::dvec3 upVec=glm::dvec3(0.0f,1.0f,0.0f);

float zoomf = 1;
double fraction=0.1f;
string filename1 = "./table.obj";
string filename2 = "./house.obj";
ObjModelLoader *tableModel = NULL;
ObjModelLoader *bookModel = NULL;

/*! This function draws the empty cubic frame that forms the prototype for our 3D scenes.
*/
void drawOutline()
{
	glBegin(GL_QUADS);
	// glColor3f(0.5f,0.35f,0.05f);//TOP
	// glVertex3f(1.0f,1.0f,-1.0f);
	// glVertex3f(-1.0f,1.0f,-1.0f);
	// glVertex3f(-1.0f,1.0f,0.0f);
	// glVertex3f(1.0f,1.0f,0.0f);
	glColor3f(0.196, 0.6, 0.8);//BOTTOM
	
	glVertex3f(1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
	// glColor3f(0.5f,0.35f,0.05f);//BACK
	// glVertex3f(1.0f,1.0f,-1.0f);
	// glVertex3f(-1.0f,1.0f,-1.0f);
	// glVertex3f(-1.0f,-1.0f,-1.0f);
	// glVertex3f(1.0f,-1.0f,-1.0f);
	// glColor3f(0.5f,0.35f,0.05f);//FRONT
	// glVertex3f(1.0f,1.0f,0.0f);
	// glVertex3f(-1.0f,1.0f,0.0f);
	// glVertex3f(-1.0f,-1.0f,0.0f);
	// glVertex3f(1.0f,-1.0f,0.0f);
	// glColor3f(0.5f,0.35f,0.05f);//LEFT
	// glVertex3f(-1.0f,1.0f,-1.0f);
	// glVertex3f(-1.0f,1.0f,0.0f);
	// glVertex3f(-1.0f,-1.0f,0.0f);
	// glVertex3f(-1.0f,-1.0f,-1.0f);
	// glColor3f(0.5f,0.35f,0.05f);//RIGHT
	// glVertex3f(1.0f,1.0f,0.0f);
	// glVertex3f(1.0f,1.0f,-1.0f);
	// glVertex3f(1.0f,-1.0f,-1.0f);
	// glVertex3f(1.0f,-1.0f,0.0f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0f,0.0f,0.0f);//BACK TOP
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//BACK BOTTOM
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//BACK LEFT
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//BACK RIGHT
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//FRONT TOP
	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//FRONT BOTTOM
	glVertex3f(-1.0f,-1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//FRONT LEFT
	glVertex3f(-1.0f,1.0f,0.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//FRONT RIGHT
	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//TOP LEFT
	glVertex3f(-1.0f,1.0f,0.0f); 
	glVertex3f(-1.0f,1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//BOTTOM LEFT
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//TOP RIGHT
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//BOTTOM RIGHT
	glVertex3f(1.0f,-1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glEnd();


}
/*! This function is the reshape function that is called everytime an OpenGL window is generated
\param w The width of the window.
\param h The height of the window.
*/
void changeSize(int w,int h){
	if(h == 0)
		h=1;
	float ratio = w*1.0/h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0 , 0 ,w, h);
	gluPerspective(fov,ratio, 1,100);
	glMatrixMode(GL_MODELVIEW);
}

//glm::vec3 > temp_normals;
    //glm::vec3 tempFaceNormal;


/*! This function is the display function that is registered with our OpenGL instance.This routine is redrawn everytime the OpenGL window is refreshed
*/
void myDraw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(cameraPos[0],cameraPos[1],cameraPos[2],cameraPos[0]+directionSight[0],cameraPos[1]+directionSight[1],cameraPos[2]+directionSight[2],upVec[0],upVec[1],upVec[2]);

	//Drawing empty room
	clock_t begin = clock();
	glRotatef(rotate_x,0.0f,1.0f,0.0f);
	glRotatef(rotate_y,1.0f,0.0f,0.0f);
	glScalef(1.0,1.0,2.0);
	drawOutline();
	//Drawing Chair

	glTranslatef(0.72,-0.83f,-0.25);
	glScalef(0.05,0.05,0.025);
	glRotatef(180,0.0,1.0,0.0);
	drawChair();
	glRotatef(-180,0.0,1.0,0.0);
	glScalef(20,20,40);
	glTranslatef(-0.72,0.83f,0.25);

	//Using .obj file imported from Blender to draw table
	glTranslatef(0.75,-0.97,-0.35);
	glColor3f(0.36, 0.26, 0.26);
	glScalef(0.04,0.04,0.016);
	 tableModel->Draw(zoomf);
	 glScalef(25,25,62.5);
    glColor3f(0.049348, 0.060411, 0.800000);
    glTranslatef(-0.75,0.97,0.35);



	//Drawing Table
	/*glTranslatef(0.75,-0.70f,-0.35);
	glScalef(0.1,0.1,0.04);
	drawTable();
	glScalef(10,10,25);
	glTranslatef(-0.75,0.70f,0.35);*/

		//Drawing Bed
	glTranslatef(-0.5f,-0.70f,-0.70f);
	glScalef(0.1,0.1,0.05);
	//glRotatef(180,0.0,1.0,0.0);
	drawBed();
	//glRotatef(-180,0.0,1.0,0.0);
	glScalef(10,10,20);
	glTranslatef(0.5f,0.70f,0.70f);

	//Drawing Bookshelf
	glTranslatef(0.5f,-0.345f,-0.90f);
	glScalef(0.1,0.1,0.05);
	drawShelf();
	glScalef(10,10,20);
	glTranslatef(-0.5f,0.345f,0.90f);


	//Books
	/*glTranslatef(0.5f,-0.27f,-0.90f);
	glColor3f(1.0, 0.0, 0.0);
	glScalef(0.4,0.4,0.16);
	 bookModel->Draw(zoomf);
	 glScalef(2.5,2.5,6.25);
    //glColor3f(0.049348, 0.060411, 0.800000);
    glTranslatef(-0.5f,0.27f,0.90f);
*/

	
//Drawing clock 

	glTranslatef(-0.3,0.5,-0.9);
	glScalef(0.25,0.25,0.5);
	drawClock();
	glScalef(4,4,2);
	glTranslatef(0.3,-0.5,0.9);


//Vase
	glTranslatef(0.15,-0.98,-1.5);
	glScalef(0.5,0.5,0.2);
	drawVase();
	glScalef(2,2,5);
	glTranslatef(-0.15,0.98,1.5);



	//Drawing Fan
	glTranslatef(-0.5,0.78,-1.3);
	glRotatef(-90,1.0,0.0,0.0);
	glScalef(0.5,0.5,0.75);
	drawFan();
	glScalef(2.0,2.0,1.33);
	glRotatef(90,1.0,0.0,0.0);
	glTranslatef(0.5,-0.78,1.3);


glScalef(1.0,1.0,0.5);

	glRotatef(-1*rotate_x,1.0f,0.0f,0.0f);
	glRotatef(-1*rotate_y,0.0f,1.0f,0.0f);

	clock_t end =  clock();
	cout << double(end - begin)/CLOCKS_PER_SEC<<endl;

	glutSwapBuffers();
}

/*! This function provides the initial settings for our OpenGL window
*/
void myinit()
{
	glClearColor(0.72f,0.7f,0.56f,1.0);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

/*! This function details the time intervals at which to redraw the scene in OpenGL
*/
void update(int data)
{
	glutTimerFunc(30,update,0);
	glutPostRedisplay();
}
/*! This function details how to process all the keys for which ASCII values exist
\param key The key that has been pressed.
\param x Integer parameter
\param y Integer parameter
*/

void processNormalKeys(unsigned char key,int x,int y)
{
	double sensitivityX = 1.5f;
	double sensitivityY = 1.5f;
	double sensitivityFOV =  1.0f;
	// If escape key is pressed
	if(key  == 27)
	{
		exit(0);
	}
	if (key== 'W' || key == 'w')
	{
		pitch+=sensitivityY;
	}
	if(key == 'A' || key == 'a')
	{
		yaw-=sensitivityX;
	}
	if(key == 'D' || key == 'd')
	{
		yaw+=sensitivityX;
	}
	if(key == 'S' || key == 's')
	{
		pitch-=sensitivityY;
	}
	if(key=='I'||key=='i')
	{
		rotate_y+=sensitivityY;
	}
	if(key=='J'||key=='j')
	{
		rotate_x-=sensitivityX;
	}
	if(key=='K'||key=='k')
	{
		rotate_y-=sensitivityY;
	}
	if(key=='L'||key=='l')
	{
		rotate_x+=sensitivityX;
	}
	if(pitch > 179.0f)
        pitch = 179.0f;
    if(pitch < -179.0f)
        pitch = -179.0f;
    if(yaw > 179.9f)
        yaw = 179.0f;
    if(yaw < -179.0f)
        yaw = -179.0f;
	glm::dvec3 tempDir;
	tempDir[0]=cos(glm::radians(yaw))*cos(glm::radians(pitch));
	tempDir[1]=sin(glm::radians(pitch));
	tempDir[2]=sin(glm::radians(yaw))*cos(glm::radians(pitch));
	directionSight=glm::normalize(tempDir);
}

/*! This function details how to process all the keys for which ASCII values do not exist
\param key The key that has been pressed.
\param x Integer parameter
\param y Integer parameter
*/
void processSpecialKeys(int key, int x,int y)
{
	
	if(key==GLUT_KEY_LEFT)
	{
		cameraPos-=fraction*glm::normalize(glm::cross(directionSight,upVec));
	}
	if(key==GLUT_KEY_RIGHT)
	{
		cameraPos+=fraction*glm::normalize(glm::cross(directionSight,upVec));	
	}
	if(key==GLUT_KEY_UP)
	{
		cameraPos+=fraction*directionSight;
	}
	if(key==GLUT_KEY_DOWN)
	{
		cameraPos-=fraction*directionSight;
	}
}
/*void handle_mouse(int x, int y)
{
	XNEW = x;
	YNEW = y;
}
// !Handles what happens in an event of mouse click
void handle_click(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		//zoom in
		FOV = FOV - 5;
		cout << "Zoom In\n";
	}
	else if (button = GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//zoom out
		FOV = FOV + 5;
		cout << "Zoom In\n";
	}
}


//yoffset value tells us the amount we scrolled vertically.
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
  if(fov > 1.0f && fov < 45.0f)
  	fov -= yoffset;
  else if(fov <= 1.0f)
  	fov = 1.0f;
  else if(fov >= 45.0f)
  	fov = 45.0f;
 // projection = glm::perspective(glm::radians(fov),ratio, 1.0f, 100.0f); 
}
*/


int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Drawing");
	glutDisplayFunc(myDraw);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	tableModel = new ObjModelLoader(filename1);
	bookModel = new ObjModelLoader(filename2);
	//glfwSetScrollCallback(window, scroll_callback);
	glutTimerFunc(30,update,0);
	myinit();
	glutMainLoop();
	return 1;
}

