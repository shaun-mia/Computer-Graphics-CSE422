#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void init()
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-50, 50, -50, 50);
}
void draw()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_TRIANGLES);
glVertex2f(0.0, 0.0);
glVertex2f(10.0, 0.0);
glVertex2f(0.0, 10.0);
glEnd();
glPushMatrix();
glTranslatef(20.0, 20.0, 0.0);
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_TRIANGLES);
glVertex2f(0.0, 0.0);
glVertex2f(10.0, 0.0);
glVertex2f(0.0, 10.0);
glEnd();
glPopMatrix();
glFlush();
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(400, 400);
glutCreateWindow(" get ");
init();
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
