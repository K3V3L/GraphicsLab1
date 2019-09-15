//Jeff Chastine
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
//#include <GL/glext.h>
#include <iostream>
#define DELTA 0.05
using namespace std;
void changeSize(int w, int h);
void render(void);

void keyboard(unsigned char c, int x, int y);

void mouse(int button, int state, int x, int y);
double vpx=0,vpy=0;
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Graphics Lab1");
  glMatrixMode(GL_PROJECTION);
  glutDisplayFunc(render);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(changeSize);
  glutMainLoop();
}

void render(void) {
  glLoadIdentity();
  glOrtho(-1+vpx, 1+vpx, -1+vpy, 1+vpy, -1, 1);
  glClearColor(1, 1, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(0, 0, 1);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  //glOrtho(-1.1,1.1,-1.1,1.1,-1,1);
  glBegin(GL_QUADS);
  
  glVertex2f(-0.2, 0.5);
  glVertex2f(0, 0.5);
  glVertex2f(0, 0.3); 
  glVertex2f(-0.2, 0.3);

  glVertex2f(0,0.5);
  glVertex2f(0.1, 0.7);
  glVertex2f(0.5,0.7);
  glVertex2f(0.4,0.5);
  
  glEnd();
  glBegin(GL_TRIANGLES);
  glVertex2f(0,0.3);
  glVertex2f(0.5, -0.2);
  glVertex2f(0, -0.2);

  glVertex2f(0.5, -0.2);
  glVertex2f(0, -0.2);
  glVertex2f(0.5, -0.7);
  glVertex2f(0.25,-0.45);

  glVertex2f(0.5, -0.7);
  glVertex2f(0,-0.7);
  glVertex2f(0.25, -0.45);
  glVertex2f(0,-0.7);

  glVertex2f(0, -0.45);
  glVertex2f(0, -0.1);
  glVertex2f(-0.1, -0.2);
  glVertex2f(0, -0.3);

  glEnd();
  glutSwapBuffers();
}

void keyboard(unsigned char c, int x, int y)
{
  std::cout << (int)c << std::endl;
  if((int)c == 43)
  {
    // +
    vpx+=DELTA;
    vpy+=DELTA;
    std::cout << "+" << endl;
  }
  else if((int)c == 45)
  {
    vpx-=DELTA;
    vpy-=DELTA;
    std::cout << "-" << endl;
  }
  cout << -1+vpx << " | " << 1+vpx << " | " << -1+vpy << " | " << 1+vpy << std::endl;
  glutPostRedisplay();
}

void changeSize(int w, int h) {
	float ratio = 1.0* w / h;
 	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,ratio,1,1000);

}
