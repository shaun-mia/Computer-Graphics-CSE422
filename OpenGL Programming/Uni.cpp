////////////// uni

#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // set color to red
    glLineWidth(2.0); // set line width
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();

    glPushMatrix(); // save the current matrix
    glScalef(2.0, 2.0, 0.0); // set the scale factor for uniform scaling
    glColor3f(0.0, 1.0, 0.0); // set color to green
    glLineWidth(2.0); // set line width
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
    glPopMatrix(); // restore the saved matrix
    glFlush();
}
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // set the background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // set the viewing window
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // set the window size
    glutInitWindowPosition(100, 100); // set the window position
    glutCreateWindow("Triangle with Uniform Scaling"); // create the window
    init();
    glutDisplayFunc(display); // set the display callback function
    glutMainLoop(); // enter the event-processing loop
    return 0;
}


//////////////Non- Un uni

#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

GLfloat triangle[3][2] = { {100.0, 100.0}, {150.0, 250.0}, {200.0, 100.0} };
GLfloat sx = 1.5, sy = 0.5;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set the background color to white
    glMatrixMode(GL_PROJECTION); // Set the projection mode
    gluOrtho2D(0.0, 400.0, 0.0, 400.0); // Set the projection window
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glColor3f(1.0, 0.0, 0.0); // Set the drawing color to red
    glBegin(GL_TRIANGLES); // Begin drawing the triangle
    glVertex2fv(triangle[0]); // Specify the first vertex
    glVertex2fv(triangle[1]); // Specify the second vertex
    glVertex2fv(triangle[2]); // Specify the third vertex
    glEnd(); // End drawing the triangle
// Apply scaling transformation to the triangle
    for (int i = 0; i < 3; i++)
    {
        triangle[i][0] *= sx;
        triangle[i][1] *= sy;
    }
    glColor3f(0.0, 0.0, 1.0); // Set the drawing color to blue
    glBegin(GL_TRIANGLES); // Begin drawing the scaled triangle
    glVertex2fv(triangle[0]); // Specify the first vertex
    glVertex2fv(triangle[1]); // Specify the second vertex
    glVertex2fv(triangle[2]); // Specify the third vertex
    glEnd(); // End drawing the scaled triangle
    glFlush(); // Render the drawings
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(400, 400); // Set the window size
    glutInitWindowPosition(100, 100); // Set the window position
    glutCreateWindow("Scaling Triangle"); // Create the window
    init(); // Call the initialization function
    glutDisplayFunc(display); // Set the display callback function
    glutMainLoop(); // Enter the event processing loop
    return 0;
}
