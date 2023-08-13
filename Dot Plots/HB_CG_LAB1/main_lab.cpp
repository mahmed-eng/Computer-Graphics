#include <windows.h>
#include <math.h>
#include <GL/glut.h>

const int screenWidth = 640;
const int screenHeight = 480;
GLdouble A, B, C, D;

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set white background color
    glColor3f(0.0f, 0.0f, 0.0f);    // Set drawing color
    glPointSize(4.0);                // The dot is 4 by 4 pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
    A = screenWidth / 4.0;
    B = 0.0;
    C = D = screenHeight / 2.0;
}

void dotPlotFunction(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (GLdouble x = 0.0; x < 4.0; x += 0.005)
    {
        GLdouble func = exp(-x) * cos(2 * 3.14159265 * x);
        glVertex2d(A * x + B, C * func + D);
    }
    glEnd();

    // Draw a thicker black horizontal line passing through the curve
    glLineWidth(2.0);            // Set line width to 2
    glColor3f(0.0f, 0.0f, 0.0f); // Set color to black
    glBegin(GL_LINES);
    glVertex2d(0, C);
    glVertex2d(screenWidth, C);
    glEnd();
    glLineWidth(1.0); // Reset line width

    glFlush();
}

int main(int argc, char** argv)
{
    // Initialize the GLUT toolkit
    glutInit(&argc, argv);
    // Set the display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set window size
    glutInitWindowSize(screenWidth, screenHeight);
    // Set window position
    glutInitWindowPosition(100, 150);
    // Open the screen window
    glutCreateWindow("Dot Plot of Function");
    // Register callback functions
    glutDisplayFunc(dotPlotFunction);
    myInit(); // Additional initializations as necessary
    glutMainLoop();
    return 0;
}
