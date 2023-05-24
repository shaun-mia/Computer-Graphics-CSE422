#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void drawTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    glFlush();
}
void rotateTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    const float PI = 3.14159265358979323846f;
    float angle = 45.0f; // Rotation angle in degrees
    float radians = angle * PI / 180.0f; // Convert to radians
    float cosTheta = cosf(radians);
    float sinTheta = sinf(radians);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex2f(-0.5f * cosTheta - (-0.5f) * sinTheta, -0.5f * sinTheta + (-0.5f) * cosTheta);
    glVertex2f(0.5f * cosTheta - (-0.5f) * sinTheta, 0.5f * sinTheta + (-0.5f) * cosTheta);
    glVertex2f(0.0f * cosTheta - 0.5f * sinTheta, 0.0f * sinTheta + 0.5f * cosTheta);
    glEnd();
    glFlush();
}
// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Rotated Triangle");
    glutDisplayFunc(drawTriangle); // Display the initial triangle
    glutIdleFunc(rotateTriangle); // Rotate the triangle continuously
    glutMainLoop();
    return 0;
}
