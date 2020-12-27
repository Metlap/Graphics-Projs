/**
@file bezier.cpp
*/
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <cmath>
#include <ctime>
#include <time.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>

float control_points[100][2] = {

};
int points_count = 0;
//Dimensions of the window
int DIMEN_X = 600;
int DIMEN_Y = 600;

int STATE = -1;

float TOUCH_BUFFER = 4;
int RES = 1000; // Pixel resolution

float drag_x, drag_y;
clock_t beginTime;
clock_t endTime;
float timeDiff;

/*! \brief Removes coordinates from control points array.
*
*
*   \param x: x-coordinate to be removed.
*   \param y: y-coordinate to be removed.
*/
void remove_coordinates(float x, float y)
{
  int temp_count = points_count;
  for (int i = 0; i <= temp_count; i++)
  {
    if (control_points[i][0] - x < TOUCH_BUFFER && control_points[i][0] - x > -1 * TOUCH_BUFFER)
    {
      if (control_points[i][1] - y < TOUCH_BUFFER && control_points[i][1] - y > -1 * TOUCH_BUFFER)
      {
        control_points[i][0] = control_points[i+1][0];
        control_points[i][1] = control_points[i+1][1];
        temp_count--;
      }
    }
  }
  points_count = temp_count;
}

/*! \brief Adds coordinates to the control points array.
*
*
*   \param x: x-coordinate to be added.
*   \param y: y-coordinate to be added.
*/
void add_coordinates(float x, float y)
{
  control_points[points_count][0] = x;
  control_points[points_count][1] = y;
  points_count++;
}

/*! \brief Replaces a control point in the array.
*
*
*   \param x_old: x-coordinate to be replaced.
*   \param y_old: y-coordinate to be replaced.
*   \param x_new: new x-coordinate
*   \param y_new: new y-coordinate
*/
void replace_coordinates(float x_old, float y_old, float x_new, float y_new)
{
  for (int i = 0; i < points_count; i++)
  {

    if (control_points[i][0] - x_old < TOUCH_BUFFER && control_points[i][0] - x_old > -1 * TOUCH_BUFFER)
    {
      if (control_points[i][1] - y_old < TOUCH_BUFFER && control_points[i][1] - y_old > -1 * TOUCH_BUFFER)
      {
        control_points[i][0] = x_new;
        control_points[i][1] = y_new;
        break;
      }
    }
  }
}

/*! \brief Plots point on the window.
*
*
*   \param x: x-coordinate to be plotted.
*   \param y: y-coordinate to be plotted.
*   \param color: r value in the rgb scheme.
*/
void plotPoint (int x, int y, float color)
{
  glBegin(GL_POINTS);
  glColor3f(color, 0.1, 0.5);
  glVertex2i(x, y);
  glEnd();
}

/*! \brief Point on the line segment between 2 points.
*
*
*   \param start: 2 dimensional start vertex.
*   \param end: 2 dimensional end vertex.
*   \param t: float value - increment parameter whose value defines the points on the curve.
*/
float * lerp (float start[2], float end[2], float t)
{
  static float req[2];
  req[0] =  (1-t)*start[0] + t * (end[0]);
  req[1] = (1-t)*start[1] + t * (end[1]);
  return req;
}

/*! \brief Constructs a bezier curve recursively using deCasteljau's algorithm.
*
*
*   \param controls: 2 column matrix of vertices recursively lerped.
*   \param number: number of coordinates
*   \param t: distance on the line segment between two vertices
*/
void bezier (float controls[][2], int number, float t)
{
  float control_outputs[number-1][2];
  for (int i = 0; i < number - 1; i++)
  {
    float *temp = lerp(controls[i], controls[i+1], t);
    control_outputs[i][0] = *(temp);
    control_outputs[i][1] = *(temp+1);
  }

  if (number == 2)
  {
    plotPoint(control_outputs[0][0], control_outputs[0][1], 0.5);
  } else {
    bezier(control_outputs, number - 1, t);
  }
}

/*! \brief OpenGL mouse callback based on the mouse button clicked and click-time.
*   If left mouse button is clicked for a brief amount of time, then we add a new  control point.
*   We can drag the points by holding down the left mouse button over the required point and move to a new position on the screen.
*   If right mouse button is clicked on a point then that point is deleted.
*
*   \param button: Button clicked on the mouse.
*   \param state : State of the button clicked.
*   \param x,y: Inverted coordinates on the window
*/
void mouse(int button, int state, int x, int y)
{
  y = DIMEN_Y - y;
  
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
 
    beginTime = clock();
    drag_x = x;
    drag_y = y;
  }
  if(button==GLUT_LEFT_BUTTON && state == GLUT_UP)
  {
    endTime = clock();
    timeDiff = float(endTime - beginTime)/CLOCKS_PER_SEC;
    if(timeDiff<=0.2)
    {
      add_coordinates(x,y);
      timeDiff=0;
    }
    else if(timeDiff>0.2)
    {
      //remove_coordinates(drag_x,drag_y);
      //add_coordinates(x,y);
      replace_coordinates(drag_x, drag_y, x, y);
      glutPostRedisplay();
    }
  }
  if(button==GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {
      remove_coordinates(x,y);
  }
  glutPostRedisplay();
}


/*! \brief Initializes OpenGL parameters.
*
*
*/
void init()
{
  glClearColor(0.3, 0.2, 1.0, 0.1);
  glColor3f(1.0f, 0.0f, 0.0f);
  gluOrtho2D(0.0, DIMEN_X, 0.0, DIMEN_Y);
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  glPointSize(10.0f);
}

/*! \brief OpenGL display callback. Runs the bezier curve implementation.
*
*/
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  int i = 0;
  if (points_count > 0)
  {
    for (i = 0; i < points_count; i++)
    {
      plotPoint((int)control_points[i][0], (int)control_points[i][1], 1.0);
    }
    if (points_count > 1)
    {
      for (i=0; i<RES; i++)
      {
        bezier(control_points, points_count, (float)i/(float)(RES-1));
      }
    }
  }
  glFlush();
}
/*Glut timer function to update the clock
*/
void update(int data)
{
  glutTimerFunc(30,update,0);
  glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(DIMEN_X, DIMEN_Y);
	glutCreateWindow("Bezier");
  //STATE = ADD_STATE;
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
  //glutKeyboardFunc(keyboard);
  glutTimerFunc(30,update,0);
  init();
	glutMainLoop();
  return 1;
}
