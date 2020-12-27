/**
@file myWorm.cpp
*/
#include <iostream>
#include <math.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define K 10  //Value of spring constant
#define D 1   //Damping constant set to 1
#define L 1.0   //Relaxed Spring length set to 1
#define TIME_INTERVAL 50   
#define dt 0.5  //the worm moves every 0.5sec

using namespace std; 

float f1 = 0;                    //Force due to spring 1 and damping force 
float f2 = 0;                  //Force due to spring 2 and damping force
float f3 = 0;               
int scene_time = 330;

/*!The class used to set force and velocity acting on the masses and springs system.
Special operator overloading functions are also defined in this class
*/
class Vector3f
{
 public:
        float x, y, z;               //Vectors of position and velocity

        Vector3f(){};                 //Default constructor for class Force3f
        Vector3f(float, float, float);//Overloaded constructor to instialize position and velocity vectors
                       	
        //Operator overloading of +, -, *, =, *(float), /(float)
        //Return type is of Vector3f(3d-vector) for all operators and arguments are either Vector3f or float.
        Vector3f operator + (Vector3f);
        Vector3f operator - (Vector3f);
        Vector3f operator * (Vector3f);
        Vector3f operator * (float);
        Vector3f operator / (float);
};

/*!Define the Particle having position, force and velocity component along with its mass.This also has the add_force method defined for 
 adding a spring force to find new velocity and position values */
struct Mass
{
 Vector3f force;
 Vector3f velocity;
 Vector3f position;
 
 float mass;

 void add_force(Vector3f,float);
};

//Function signatures of all functions implemented
float l(Vector3f , Vector3f );
float force(Mass ,Mass );
void update(int );

void init();
void lighting();
void display();

void house();
void plane(double );
void petal();
void flowerpot(double , double , double , double , double , double , double , double , double , double , double , double , double , double , double );
void path();
void head(float );

void ellipseMass(Mass );
void findmax(double );

/*!main() calls the display function and sets the Timer Function
*/
int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 init();
 lighting();
 glClearColor(0.529412, 0.807843, 0.921569, 0.0f);
  
 glutTimerFunc(TIME_INTERVAL, update, 0);
 glutMainLoop();

 return 0;
}

/*!Overloaded constructor to instialize position and velocity vectors
*/
Vector3f::Vector3f(float xPos, float yPos, float zPos)
{
 x=xPos;
 y=yPos;
 z=zPos;
}

//Overloading operators for vector operations
Vector3f Vector3f::operator + (Vector3f param)
{
 Vector3f position;
 position.x=x+param.x;
 position.y=y+param.y;
 position.z=z+param.z;
 return(position);
}
//Overloading operators for vector operations
Vector3f Vector3f::operator - (Vector3f param)
{
 Vector3f position;
 position.x=x-param.x;
 position.y=y-param.y;
 position.z=z-param.z;
 return(position);
}
//Overloading operators for vector operations
Vector3f Vector3f::operator * (Vector3f param)
{
 Vector3f position;
 position.x=x*param.x;
 position.y=y*param.y;
 position.z=z*param.z;
 return(position);
}
//Overloading operators for vector operations
Vector3f Vector3f::operator / (float param)
{
 Vector3f position;
 position.x=x/param;
 position.y=y/param;
 position.z=z/param;
 return(position);
}
//Overloading operators for vector operations
Vector3f Vector3f::operator * (float param)
{
 Vector3f position;
 position.x=param*x;
 position.y=param*y;
 position.z=param*z;
 return(position);
}

/*! Calculates scalar distance between either velocity or position vectors.Calculated in terms of Euclidean Distance.
* \param a : Vector3f first vector.
* \param b : Vector3f second vector.
*/
float l(Vector3f a, Vector3f b)
{
 Vector3f c;
 float dist=0;
 c=a-b;
 dist=sqrt((c.x*c.x)+(c.y*c.y)+(c.z*c.z));
 return dist;
}

/*! add_force() function is defined to compute new postion and velocity vectors due to the force(spring + damping) acting on the masses.
*   \param force: Force vector acting on the mass.
*   \param t : The time interval.
*/
void Mass::add_force(Vector3f force,float t)
{
 velocity=velocity+(force/mass)*t;
 position=position+velocity*t;
}

/*! This function returns the total force acting between 2 masses(spring + damping)
*   \param a: First mass 
*   \param b : Second mass
*/
float force(Mass a,Mass b)
{
 //force = K*(L-l) + D*(dl/dt)   ->   dl/dt is scalar distance between velocity vectors
 return (-(L-(l(a.position,b.position))*K)+(D*l(a.velocity,b.velocity)));
}

//Define intial values of position and velocity vectors 
Vector3f mass_A(-5.55,0.0,0.0);
Vector3f mass_B(-4.55,0.0,0.0);
Vector3f mass_C(-3.55,0.0,0.0);
//Vector3f masss_tail(-2.55,0.0,0.0);
Vector3f mass_A_velocity(0.0,0.0,0.0);
Vector3f mass_B_velocity(0.0,0.0,0.0);
Vector3f mass_C_velocity(0.0,0.0,0.0);
//Vector3f mass_tail_velocity(0.0,0.0,0.0);


//Implement the spring-mass system
Mass ellipse_A;
Mass ellipse_B;
Mass ellipse_C;
//Mass ellipse_tail;

/*! Function to draw the worm as a combination of masses with springs connecting them.
*   \param ellipse: It is member of the struct Mass .
*/
void ellipseMass(Mass ellipse)
{
 glPushMatrix();
 glColor3f(1, 1, 0.0498039);//Body color of worm
 glTranslated(ellipse.position.x,ellipse.position.y,ellipse.position.z);//Translate to current position of mass
 glScaled(3, 1, 1);//Drawing an ellipse at the current position of the mass      
 glutSolidSphere(1,15,15);
 glRotated(-90,0,1,0);
 glColor3f(1, 0.647059, 0);//Draw an orange torus around the body of the worm (enhances the look of the worm movement)
 glutSolidTorus(0.5, 0.6, 30, 30);
 glPopMatrix();
}

// void TailMass(Mass ellipse)
// {
//   glPushMatrix();
//   glColor3f(0.8,0.3,0.0);
//   glTranslated(ellipse.position.x,ellipse.position.y,ellipse.position.z);
//   glScaled(3,1.5,1.3);
//   glRotated(-90,0,1,0);
//   glutSolidCone(1,0.7,50,8);
//   glPopMatrix();
// }

/*! \Draws the head of the worm based on which sphere (A, B, C,tail) is currently maximum along x direction.
*   \param max : Denotes the x-cordinate value of closest mass to the eye.
*/
void head(float max)
{
 glPushMatrix();

 //Head
glColor3f(1, 0.3647059, 0);//Color of the head
 glTranslated(max+1, 0.0, 0.0);//Relative to the maximum of postions of sphere(A, B, C) move 3 units along x-axis
 //glutSolidSphere(1.5, 15, 15);
 
 //Nose
 glTranslated(2, 0.0, 0.0);
 glColor3f(1, 0.247059, 0);//Color of nose
 glutSolidSphere(0.3, 15, 15);
 
 //Antennas
 glColor3f(0.0, 0.0, 0.0);
 glPushMatrix();
 glTranslated(-0.5,0.9,0.8);
 glRotated(90, 0, 1, 0);
 glRotated(45, 0, 1, 1);
 glScaled(0.10, 0.75, 0.10);
 glutSolidSphere(1, 15, 15);//Antenna 1
 glPopMatrix();
 glTranslated(-0.5,1, -0.8);
 glRotated(90, 0, 1, 0);
 glRotated(-45, 0, 1, 1);
 glScaled(0.10, 0.70, 0.10);
 glutSolidSphere(1, 15, 15);//Antenna 2
     
 glPopMatrix();
}

/*! \Used in flowerpot() function to draw petals of sunflower.
*/
void petal()
{
 glPushMatrix();
 
 glTranslated(-1.3, -4.6, 0);
 glScaled(0.25, 0.75, 0.25);
 glutSolidSphere(4, 15, 15);
 
 glPopMatrix();
}


/*! Function to draw flowerpot with a sunflower
    \param : Position of the center of flower pot in 3d coordinates.
    \param : Position of the center of the flower in 3d space.
    \param : Color of the petals
*/
void flowerpot(double x, double y, double z, double c1, double c2, double c3, double cr1, double cr2, double cr3, double cor1, double cor2, double cor3, double core1, double core2, double core3)
{
 glPushMatrix();
 
 glColor3f(1, 0.498039, 0.313725);//Color of flowerpot
 glTranslated(x, y, z);
 glPushMatrix();
 glRotated(-90, 1, 0, 0);
 GLUquadricObj *quadObj = gluNewQuadric();
 gluCylinder(quadObj, 1.5, 2.3, 3, 30, 30);//Draw the pot
 glutSolidTorus(0.1,1.5,30,30);//Draw a rim at the bottom of the pot
 glPopMatrix();
 glTranslated(0,3,0);
 glPushMatrix();
 glRotated(90, 1, 0, 0);
 glutSolidTorus(0.4,2.3,30,30);//Draw a rim at the top of the pot
 glColor3f(0.647059, 0.164706, 0.164706);//Color of Mud
 glScaled(1 , 1, 0);
 glutSolidTorus(1,1,30,30);//Drawing a circle to represent the Mud
 glPopMatrix();
 glPushMatrix();
 glRotated(-90, 1, 0, 0);
 glColor3f(0.133333, 0.545098, 0.133333);//Stem color
 gluCylinder(quadObj, 0.1, 0.1, 3, 30, 30);//Draw the stem of the sunflower
 glPopMatrix();
 glColor3f(cor1, cor2, cor3);//Color of flower center
 glTranslated(0, 3.4, 0);
 glScaled(0.4,0.5, 0.5);
 glutSolidSphere(1, 15, 15);//Draw the center
 glTranslated(1, 0, 0);
 glColor3f(core1, core2, core3);//Color of inner center 
 glScaled(0.4,0.5, 0.5);
 glutSolidSphere(0.9, 15, 15);//Draw an inner center 
 
 for(int i=0; i<360; i ++)//Drawing petals of sunflower around outer center
 {
  glRotated(i,1,0,0);
  if((i<45)|(i>90)&&(i<135)|(i>180)&&(i<225)|(i>270)&&(i<315))
   glColor3f(c1, c2, c3);//1st shade color
  else
   glColor3f(cr1, cr2, cr3);//2nd shade color
  petal();
 }

 glPopMatrix();
}

/*! Function to draw the green base plane.
*   \param planeWid : Denotes the width of the plane.
*/
void plane(double planeWid)
{
 glPushMatrix();
 glColor3f(0.196078 ,0.803922 ,0.196078);
 glTranslated(-1.4,-3.5,0);
 glScaled(planeWid, 0, planeWid*2); 
 glutSolidCube(45);
 glPopMatrix();

 // glPushMatrix();
	// glTranslated(-4.0,5.0,-0.5);glScalef(4,4,4);
	// glColor3d(1.0,0.8,0.0);
	// glutSolidSphere(0.2,15,15);
	// glPopMatrix();
        
 //        glPushMatrix();        
 //        glRotatef(-90,1,0,0);
 //        glTranslated(-4.0,5.0,-1.0);glScalef(4,4,4);
 //    	glColor3d(1.0,0.5,0.3);
 //    	glutSolidCone(0.2,0.5,10,8);
 //    	glPopMatrix();

//Drawing Trees

glPushMatrix(); //push current matrix onto stack
  glTranslated(-1,0,-4.5); //translate initally to -1,0,-4.5
  GLUquadricObj *qob=gluNewQuadric(); //create a quadric object which is initially parallel to y axis
  glRotated(-90,1,0,0); // rotates cylinder to 90 degrees about x axis.
  glPushMatrix(); //cylinder drawing begins
  glColor3f(0.9,0.5,0.3);  //put the color of cylinder to sand brown
  gluCylinder(qob,0.6,0.27,3,8,8);  // creates trunk like cylinder
  glPopMatrix();  // end of cylinder drawing
  glPushMatrix(); //tree top drawing begins
  glColor3d(0,0.5,0); //set color of tree top to dark green
  glTranslated(0,0,1.5); //lift it to certain height so that it sits on trunk top.
  glutSolidCone(0.9,3.5,10,10); //draw cone
  glPopMatrix(); //end of tree top drawing
  glPushMatrix(); //draw tree neighbours
  for(int i=0;i<4;i++)
  { glTranslated(3,0,0);  //each time translate along x by 3 units.
    glColor3f(0.9,0.5,0.3);  //set color of trunk
  gluCylinder(qob,0.6,0.27,3,8,8); //draw trunk
  } 
////////////////////////////////////
  glTranslated(-6,-15,0);
  for(int i=0;i<5;i++)
  { glTranslated(3,0,0);  //each time translate along x by 3 units.
    glColor3f(0.9,0.5,0.3);  //set color of trunk
  gluCylinder(qob,0.6,0.27,3,8,8); //draw trunk
  } 
  //after drawing you hit the end of green carpet
  glPushMatrix();  //trees at the entrance are drawn by rotating those trees that cross green zone
  glRotated(-180,1,0,0);
  glRotated(90,0,0,1);
  glRotated(180,1,0,0); //rotates trunk
  // for(int i=0;i<5;i++)
  // {
  //  glTranslated(3,0,0);
  //  glColor3f(0.9,0.5,0.3);
  // gluCylinder(qob,0.6,0.27,3,8,8);
  // }
  glPopMatrix();//end of drawing entrance trees' trunk
  glPopMatrix();//end of drawing trunks
  glPushMatrix(); //draw tree tops
  for(int i=0;i<4;i++)
  {
    glTranslated(3,0,0); //move along x direction each time by 3 units
    glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,1.5);//lift the tree top
  glutSolidCone(0.9,3.5,10,10); //draw tree top
  glPopMatrix();
  }
glTranslated(-6,-15,0);
    for(int i=0;i<5;i++)
  {
    glTranslated(3,0,0); //move along x direction each time by 3 units
    glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,1.5);//lift the tree top
  glutSolidCone(0.9,3.5,10,10); //draw tree top
  glPopMatrix();
  }

 
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();

  /////////////////////////////////////////





 //Drawing water can
 	glPushMatrix();
 	glColor3f(0.0,0.0,1.0);
 	glTranslated(6.0,8.0,4.0);
  GLUquadricObj *quadObj = gluNewQuadric();
  glScaled(0.7,0.7,0.7);
  glRotated(-90,1,0,0);
 gluCylinder(quadObj, 2.3, 2.1, 5, 30, 30);//Draw the main part of water can
 glColor3f(1.0,1.0,0.0);
gluCylinder(quadObj, 2.28, 2.08, 3.9, 30, 30);
 glRotated(90,1,0,0);
  glColor3f(0.0,0.0,1.0);
 	glTranslated(6.0,8.0,8.0);
 	  glRotated(130,1,0,0);
 	  glRotated(-45,0,0,1);
  GLUquadricObj *quadObj2 = gluNewQuadric();
  glScaled(0.7,0.7,0.7);
 gluCylinder(quadObj2, 0.5, 0.35, 4, 30, 30);
  glColor3f(0.0,0.0,0.5);
 glTranslated(6.0,8.0,4.0);
 glRotated(-90,1,0,0);
 gluDisk(quadObj,2.7,2.0,30,30);
 glRotated(-90,1,0,0);
  gluDisk(quadObj,2.7,2.6,30,30);
 glPopMatrix();



 glPushMatrix();

 glPopMatrix();

}

/*! Function to draw the worm's house with roof, chimney and entrance.
*/
void house()
{
 //House
 glPushMatrix();
 glColor3f(0.803922, 0.521569, 0.247059);//Color of house
 glTranslated(-14.75, 1, 0);
 glScaled(2,2,2);
 glutSolidCube(2);//Drawing the house

 //Roof
 glColor3f(0.545098, 0, 0);//Color of roof
 glTranslatef(0,1,0);
 glPushMatrix();                   
 glRotatef(-90,1,0,0);
 glutSolidCone(1.5,1,50,8);//Draw the roof
 glPopMatrix();

 //Chimney
 glColor3f(0.545098, 0.270588, 0.0745098);//Color of chimney
 glTranslatef(0.75,0.5,-0.75);        
 glPushMatrix();                   
 glScalef(1,3,1);
 glutSolidCube(.25);//Draw the Chimney
 glPopMatrix();
 glPopMatrix();
  
 //Entrance
 glPushMatrix();
 glColor3f(0, 0, 0);//Color for Entrance
 glTranslated(-11.75,1, 0.43);
 glPushMatrix();
 glRotated(90, 0, 1, 0);
 glScaled(0.75,1,0.005);
 glutSolidTorus(0.7,0.7,30,30);//Draw a circle
 glPopMatrix();
 glTranslated(0, -0.8, 0);
 glScaled(0.05,1.5,2.087);
 glutSolidCube(1);//Draw a rectangle
 glPopMatrix();
}

/*! Function to find the maximum position along x for the masses
*/
float findmax()
{
 float max = ellipse_A.position.x;
 if(ellipse_A.position.x > ellipse_B.position.x)
 max = ellipse_A.position.x;
 else
     max = ellipse_B.position.x;
 if(max < ellipse_C.position.x)
      max = ellipse_C.position.x;

 return max;
}

/*!This funnction draw a path from the house leading outside along the x direction.
*/
void path()
{
 glPushMatrix();
 
 glColor3f(0.545098, 0.270588, 0.0745098);//Color of the path
 glTranslated(-0.5, -2.5, -2.45);
 glRotated(90, 1, 0, 0);
 glScaled(43, 4, 0.04);
 glutSolidCube(1); //Draw the path
 
 glPopMatrix();

 // glPushMatrix();

//Garden Objects  
  glPushMatrix();
    glTranslated(5.0,-2.0,14.0);
    glRotated(90,1,0,0);
    glRotated(-30,0,1,0);
    glScalef(3,3,3);
    glColor3d(0.52,0.44,1.0);

    glutSolidTorus(0.3,0.6, 15, 30);
  glPopMatrix();
    
      glPushMatrix();
    glTranslated(2.0,-3.0,14.0);
    glRotated(90,1,0,0);

    glScalef(3,3,3);
    glColor3d(1.0,0.19,0.19);
    glutSolidTorus(0.3,0.6, 15, 30);
  glPopMatrix();

}  

/*! Updates value of forces acting on particles,velocities and positions every 50msec
	\param value : time after which velocities and positions have to be updated.
*/
void update(int value)
{
 f1=force(ellipse_A,ellipse_B);//Spring+Damping force due to 1st spring
 f2=force(ellipse_B,ellipse_C);//Spring+Damping force due to 2nd spring

 //Update position and velocity vectors for all 3 masses
 mass_A=ellipse_A.position;
 mass_A_velocity=ellipse_A.velocity;
 mass_B=ellipse_B.position;
 mass_B_velocity=ellipse_B.velocity;
 mass_C=ellipse_C.position;
 mass_C_velocity=ellipse_C.velocity;


 glutPostRedisplay();
 //Decreases scene_time each time TimerFunc is run
 if(scene_time>0)
                 glutTimerFunc(TIME_INTERVAL, update, scene_time--);
}

/*! Display Function that creates the scene and the worm
*/
void display(void)
{
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-10.0*64/48.0,10.0*64/48.0,-10.0,10.0,0.1,100.0);//Set up orthographics matrix
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 gluLookAt(4*6.0,2*6.0,3*6.0,0.0,0.0,0.0,0.0,1.0,0.0);//Set up camera
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//Load values set by glClearColor()
 
 house();//Draw the worm's house
 plane(1);//Draw the green plane (that is meant to represent grass)
 glPushMatrix();
  glScaled(0.80, 0.80, 0.80);
  //flowerpot(0, 0, -16, 1, 1, 0, 1, 0.843137, 0, 1, 0.647059, 0, 0.678431, 1, 0.184314);//Draw the 1st flower pot
  flowerpot(0, 0, 14,1, 1, 0, 1, 0.843137, 0, 1, 0.647059, 0, 0.678431, 1, 0.184314);//Draw the 2nd flower pot
 glPopMatrix();
 path();
 
 //Initialize mass, position and velocity of the 3 mass system 
 ellipse_A.mass=100;
 ellipse_A.position=mass_A;
 ellipse_A.velocity=mass_A_velocity;
    
 ellipse_B.mass=100;
 ellipse_B.position=mass_B;
 ellipse_B.velocity=mass_B_velocity;
    
 ellipse_C.mass=100;
 ellipse_C.position=mass_C;
 ellipse_C.velocity=mass_C_velocity;

 //Calculate the direction of motion between for the masses A, B, C
 Vector3f directionVector1=((ellipse_B.position-ellipse_A.position)/l(ellipse_A.position,ellipse_B.position));
 Vector3f directionVector2=((ellipse_C.position-ellipse_B.position)/l(ellipse_B.position,ellipse_C.position));
 //Also know as Spine Vector - gives the direction of motion of the worm
 Vector3f spineV=((ellipse_C.position-ellipse_A.position)/l(ellipse_A.position,ellipse_C.position));

 //Calculate spring force acting on the 3 masses
 Vector3f springForce_A=directionVector1*f1;
 Vector3f springForce_B=directionVector1*f1-directionVector2*f2;
 Vector3f springForce_C=directionVector2*f2;

 //Update position and velocity vectors of the 3 masses
 ellipse_A.add_force(springForce_A,dt);
 ellipse_B.add_force(springForce_B*-1,dt);
 ellipse_C.add_force(springForce_C*-1,dt);
    
 //Implementing the directional friction on the individual masses using Spine Vector
 if(spineV.x < 0.0)
 {//Since motion and velocity are define only along x-axis  ->  V = V - Spine_Vector(Spine_Vector*V) = 0
  if(ellipse_A.velocity.x < 0.0)//Effective condition being checked is if(Spine_Vector*Velocity < 0.0)
   ellipse_A.velocity.x = 0.0;
  if(ellipse_B.velocity.x < 0.0)
   ellipse_B.velocity.x = 0.0;
  if(ellipse_C.velocity.x < 0.0)
   ellipse_C.velocity.x = 0.0;
  }
              
  glPushMatrix();
  glTranslated(ellipse_A.position.x,0,0);//Translate to position of 1st mass
  ellipseMass(ellipse_A);//Draw mass_A
  glPopMatrix();

  glPushMatrix();
  glTranslated(ellipse_B.position.x,0,0);//Translate to position of 2nd mass
  ellipseMass(ellipse_B);//Draw mass_B
  glPopMatrix();

  glPushMatrix();
  glTranslated(ellipse_C.position.x,0,0);//Translate to position of 3rd mass
  ellipseMass(ellipse_C);//Draw mass_C
  glPopMatrix();
  
  //Collision detection has not been implemented. At a particular time any of the 3 particles may be have maximum value of position vector along x-axiz   
  float max = findmax();//Find the position of the mass with maximum value of position vector along x axis
    
  glPushMatrix();
  glTranslated(max, 0.0, 0.0);//Translate to the postion of the mass
  head(max);//Draw the head of the worm
  glPopMatrix();   

 

  glutSwapBuffers();//Exchange contents of Front and Back buffers
  glFlush();
}

/*! Initiate values for display
*/
void init()
{
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
 glutInitWindowSize(1280,720);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Worm Motion");
 glutDisplayFunc(display);
}

/*! Function to Enable Lighting, Material and Depth Matrices  ->  Set to default values since display() function does not change Matrix values
*/
void lighting()
{
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
 glEnable(GL_COLOR_MATERIAL);
 glShadeModel(GL_SMOOTH);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_NORMALIZE);
}
