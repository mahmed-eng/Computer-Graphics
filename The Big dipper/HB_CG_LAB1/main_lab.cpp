#include <windows.h>
#include <gl/Gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

void SalmanAslamDisplay(void); // define function to display output
void SalmanAslamDrawDot();     // define function to draw dots

void SalmanAslamDrawDot() {
    glColor3f(0.0f, 0.0f, 0.0f); // Set color to black (R, G, B)
    glPointSize(5.0); // Increase point size to make dots bolder
    glBegin(GL_POINTS);
    glVertex2f(50, 100);
    glVertex2f(65, 50);
    glVertex2f(125, 50);
    glVertex2f(135, 95);
    glVertex2f(185, 115);
    glVertex2f(235, 130);
    glVertex2f(285, 140);
    glEnd();
}

void Init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white (R, G, B, A)
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 500, 0, 500, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void SalmanAslamDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Code to draw
    SalmanAslamDrawDot(); // function to draw dots
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInitWindowSize(500, 500);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("Salman Aslam Assignment No#2");
    Init();
    glutDisplayFunc(SalmanAslamDisplay); // call function to display output
    glutMainLoop();
    return 0;
}
