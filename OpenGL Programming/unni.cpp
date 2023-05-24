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