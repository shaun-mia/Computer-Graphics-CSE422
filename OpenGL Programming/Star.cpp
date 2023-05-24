#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void myDisplay();
void myInit();
void star(int x,int y);


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("my first attempt");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
void star(int x, int y){

glBegin(GL_QUADS);
        glVertex2i(-30+x,-30+y);
        glVertex2i(30+x, -30+y);
        glVertex2i(30+x, 30+y);
        glVertex2i(-30+x, 30+y);
    glEnd();


    glPointSize(4.0);

    glBegin(GL_TRIANGLES);
        glVertex2i(-30+x,30+y);
        glVertex2i(30+x, 30+y);
        glVertex2i(0+x, 80+y);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2i(30+x,30+y);
        glVertex2i(30+x, -30+y);
        glVertex2i(80+x, 0+y);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2i(-30+x,-30+y);
        glVertex2i(30+x, -30+y);
        glVertex2i(0+x, -80+y);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2i(-30+x,30+y);
        glVertex2i(-30+x, -30+y);
        glVertex2i(-80+x, 0+y);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2i(-30+x,30+y);
        glVertex2i(30+x, 30+y);
        glVertex2i(0+x, 80+y);
    glEnd();}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f,5.0f);
    star(80,0);
    glColor3f(1.0f, 0.0f, 0.0f);
    star(-80,0);
    glColor3f(0.0f, 0.0f, 20.0f);
    star(0,80);
    glColor3f(0.0f, 23.0f, 50.0f);
    star(0,-80);
    glFlush();

}

void myInit(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, +240.0);
}
