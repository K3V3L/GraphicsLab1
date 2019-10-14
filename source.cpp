#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//#include <GL/glext.h>
#include <iostream>

#define DELTA 0.05

void changeSize(int w, int h);
void render(void);
void keyboard(unsigned char c, int x, int y);

double vpx = 0, vpy = 0;

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Graphics Lab1");
  glMatrixMode(GL_PROJECTION);
  glutDisplayFunc(render);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(changeSize);
  glutMainLoop();
}

void drawShape() {
  glBegin(GL_TRIANGLES);
  glVertex2f(-0.82, -0.08);
  glVertex2f(-0.26, 0.48);
  glVertex2f(-0.26, -0.08);

  glVertex2f(-0.26, 0.33);
  glVertex2f(-0.26, -0.08);
  glVertex2f(0.2, -0.08);

  glVertex2f(-0.26, -0.08);
  glVertex2f(0.04, -0.08);
  glVertex2f(-0.26, -0.37);

  glVertex2f(-0.26, 0.33);
  glVertex2f(0.2, -0.08);
  glVertex2f(0.61, 0.33);

  glVertex2f(0.2, -0.08);
  glVertex2f(0.42, 0.14);
  glVertex2f(0.61, -0.08);

  glEnd();

  glBegin(GL_QUADS);

  glVertex2f(0.42, 0.14);
  glVertex2f(0.61, -0.08);
  glVertex2f(0.85, 0.14);
  glVertex2f(0.61, 0.33);

  glVertex2f(0.85, 0.14);
  glVertex2f(0.61, 0.33);
  glVertex2f(0.61, -0.5);
  glVertex2f(0.85, -0.33);
  glEnd();
}

void drawOutline() {
  glLineWidth(3.0);

  glBegin(GL_LINE_STRIP);
  glVertex2f(-0.82, -0.08);
  glVertex2f(-0.26, 0.48);
  glVertex2f(-0.26, -0.08);
  glVertex2f(-0.82, -0.08);

  glEnd();
  glBegin(GL_LINE_STRIP);

  glVertex2f(-0.26, 0.33);
  glVertex2f(-0.26, -0.08);
  glVertex2f(0.2, -0.08);
  glVertex2f(-0.26, 0.33);

  glEnd();
  glBegin(GL_LINE_STRIP);

  glVertex2f(-0.26, -0.08);
  glVertex2f(0.04, -0.08);
  glVertex2f(-0.26, -0.37);
  glVertex2f(-0.26, -0.08);

  glEnd();
  glBegin(GL_LINE_STRIP);

  glVertex2f(-0.26, 0.33);
  glVertex2f(0.2, -0.08);
  glVertex2f(0.61, 0.33);

  glEnd();
  glBegin(GL_LINE_STRIP);

  glVertex2f(0.2, -0.08);
  glVertex2f(0.42, 0.14);
  glVertex2f(0.61, -0.08);

  glEnd();
  glBegin(GL_LINE_STRIP);

  glVertex2f(0.42, 0.14);
  glVertex2f(0.61, -0.08);
  glVertex2f(0.85, 0.14);
  glVertex2f(0.61, 0.33);

  glEnd();
  glBegin(GL_LINE_STRIP);

  glVertex2f(0.85, 0.14);
  glVertex2f(0.61, 0.33);
  glVertex2f(0.61, -0.5);
  glVertex2f(0.85, -0.33);
  glEnd();
}

void render(void) {
  glLoadIdentity();
  glOrtho(-1 + vpx, 1 + vpx, -1 + vpy, 1 + vpy, -1, 1);
  glClearColor((float)15 / 255, (float)252 / 255, (float)9 / 255, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f((float)147 / 255, (float)128 / 255, (float)4 / 255);
  drawShape();
  glColor3f((float)74 / 255, (float)31 / 255, (float)0 / 255);
  drawOutline();
  glutSwapBuffers();
}

void keyboard(unsigned char c, int x, int y) {
  switch ((int)c) {
  case 43: //+
    vpx += DELTA;
    vpy += DELTA;
    std::cout << "+" << std::endl;
    break;

  case 45: //-
    vpx -= DELTA;
    vpy -= DELTA;
    std::cout << "-" << std::endl;
    break;

  case 113: // Q
    std::cout << "Q pressed, exiting...";
    exit(0);
    break;
  }
  std::cout << -1 + vpx << " | " << 1 + vpx << " | " << -1 + vpy << " | "
            << 1 + vpy << std::endl;
  glutPostRedisplay();
}

void changeSize(int w, int h) {
  float ratio = 1.0 * w / h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, ratio, 1, 1000);
}
