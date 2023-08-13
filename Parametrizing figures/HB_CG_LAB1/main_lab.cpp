#include <windows.h>
#include <GL/glut.h>

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(0.5);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.65f, 0.06f);
    glVertex2f(0.65f, 0.06f);
    glVertex2f(0.0f, 0.70f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.65f, 0.06f);
    glVertex2f(0.65f, 0.06f);
    glVertex2f(0.65f, -0.85f);
    glVertex2f(-0.65f, -0.85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.20f, -0.25f);
    glVertex2f(0.20f, -0.25f);
    glVertex2f(0.20f, -0.85f);
    glVertex2f(-0.20f, -0.85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.60f, -0.55f);
    glVertex2f(-0.30f, -0.55f);
    glVertex2f(-0.30f, -0.35f);
    glVertex2f(-0.60f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.30f, -0.55f);
    glVertex2f(0.60f, -0.55f);
    glVertex2f(0.60f, -0.35f);
    glVertex2f(0.30f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.65f, -0.85f);
    glVertex2f(-0.65f, -0.85f);
    glVertex2f(-0.68f, -0.90f);
    glVertex2f(0.68f, -0.90f);
    glEnd();


    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup");
    glutInitWindowSize(420, 420);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}