#include <iostream>
#include <string>
#include <GL/glut.h>

using namespace std;

int screenWidth = 800;
int screenHeight = 600;

void drawTriangle()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.5f, -0.3f);
    glEnd();
}

void drawSquare()
{
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.7f);
    glVertex2f(0.3f, -0.7f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(-0.3f, -0.3f);
    glEnd();
}

void drawCircle()
{
    const float PI = 3.14159265358979323846;
    int numSegments = 100;
    float radius = 0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= numSegments; i++)
    {
        float angle = 2.0f * PI * i / numSegments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawCurve()
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.7f, 0.3f); // Starting point
    glVertex2f(-0.5f, 0.6f); // Control point 1
    glVertex2f(-0.3f, 0.3f); // Control point 2
    glVertex2f(-0.1f, 0.6f); // Ending point
    glEnd();
}

void drawLine()
{
    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.7f); // Line start
    glVertex2f(0.9f, 0.4f); // Line end
    glEnd();
}

void drawText(float x, float y, string text)
{
    glRasterPos2f(x, y);
    for (size_t i = 0; i < text.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f); // Grey background

    // Draw a red triangle
    glColor3f(1.0f, 0.0f, 0.0f);
    drawTriangle();
    drawText(-0.5f, -0.4f, "Triangle");

    // Draw a green square
    glColor3f(0.0f, 1.0f, 0.0f);
    drawSquare();
    drawText(-0.1f, -0.6f, "Square");

    // Draw a blue circle
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCircle();
    drawText(-0.2f, -0.2f, "Circle");

    // Draw a yellow Bézier curve
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCurve();
    drawText(-0.5f, 0.65f, "Curve");

    // Draw a white line segment
    glColor3f(1.0f, 1.0f, 1.0f);
    drawLine();
    drawText(0.7f, 0.7f, "Line");

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Shapes in OpenGL");

    glutDisplayFunc(myDisplay);

    glutMainLoop();

    return 0;
}
