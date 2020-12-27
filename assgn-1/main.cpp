#include <iostream>
#include "primitives.h"
#include "tree.h"

#include <math.h>
#include <GL/glew.h>
#include <GL/GL.h>
#include <vector>
#include <GL/glut.h>

using namespace std;


void init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1366, 768);
	glutCreateWindow("Tree Drawing");
	glClearColor(0.0, 0.0, 0.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(0, 1366,0, 768);

}
tree *t;

void draw_tree_tidier_wrapper(void)
{
	t->Tidier();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	init();
	int menu_decision, n, type;
	vector <int> arr(10000000);
start:
	system("cls");
	cout << "Welcome to the tree-maker program!!!" << endl << endl;
	cout << "Tree Algo Menu" << endl;
	cout << " 1. Use Tidier" << endl;
	cout << "Please enter which algorithm to use: ";
	cin >> type;
	if (type != 1 ) goto start;
	cout << endl << endl;
	cout << "Tree Maker Menu" << endl;
	cout << " 1. Make a user input tree (array to BST)" << endl;
	cout << " 2. Make a random tree with number of vertices n" << endl;
	cout << " 3. Make a balanced tree with number of vertices n" << endl;
	cout << "Please enter your decision: ";
	cin >> menu_decision;
	cout << endl << endl << "Please enter number of vertices: ";
	cin >> n;
	if (menu_decision == 1)
	{
		cout << "Please enter the array: ";
		for (int i = 0; i < n; ++i) cin >> arr[i];
		t = new tree(arr, n);
	}
	else if (menu_decision == 2)
		t = new tree(n, false);
	else if (menu_decision == 3)
		t = new tree(n, true);
	else goto start;

	if(type == 1 ) {
		glutDisplayFunc(draw_tree_tidier_wrapper);
		glutMainLoop();
	}
	int x;
	cin >> x;
	return 0;
}