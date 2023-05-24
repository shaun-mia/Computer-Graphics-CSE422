#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200, 200, -200, 200);
}
void drawTriangle()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 100);
    glVertex2i(-100, -100);
    glVertex2i(100, -100);
    glEnd();
}
void mirrorTriangle()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(-1, 1, 1); // Mirror along y-axis
    drawTriangle();
    glFlush();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 200, 400);
    drawTriangle();
    glViewport(200, 0, 200, 400);
    mirrorTriangle();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle and its mirror");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
