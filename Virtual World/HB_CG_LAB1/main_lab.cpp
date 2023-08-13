#include <GL/glut.h>

int screenWidth = 800;
int screenHeight = 600;

// Camera parameters
GLfloat cameraPositionX = 0.0f;
GLfloat cameraPositionY = 0.0f;
GLfloat cameraPositionZ = 3.0f;
GLfloat cameraFrontX = 0.0f;
GLfloat cameraFrontY = 0.0f;
GLfloat cameraFrontZ = -1.0f;
GLfloat cameraUpX = 0.0f;
GLfloat cameraUpY = 1.0f;
GLfloat cameraUpZ = 0.0f;

void drawTable()
{
    // Set table color
    glColor3f(0.6f, 0.4f, 0.2f);

    // Draw table top
    glPushMatrix();
    glTranslatef(0.0f, -0.6f, -0.5f);
    glScalef(0.6f, 0.05f, 0.4f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Draw table legs
    glPushMatrix();
    glTranslatef(-0.25f, -0.75f, -0.25f);
    glScalef(0.1f, 0.5f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25f, -0.75f, -0.25f);
    glScalef(0.1f, 0.5f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.25f, -0.75f, 0.25f);
    glScalef(0.1f, 0.5f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25f, -0.75f, 0.25f);
    glScalef(0.1f, 0.5f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawBook()
{
    // Set book color
    glColor3f(0.0f, 0.2f, 0.8f);

    // Draw book
    glPushMatrix();
    glTranslatef(-0.2f, -0.4f, -0.35f);
    glScalef(0.2f, 0.05f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawFan()
{
    // Set fan color
    glColor3f(0.8f, 0.8f, 0.8f);

    // Draw fan base
    glPushMatrix();
    glTranslatef(0.0f, 0.9f, 0.0f);
    glScalef(0.1f, 0.01f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Draw fan blades
    for (int i = 0; i < 3; i++)
    {
        glPushMatrix();
        glRotatef(120.0f * i, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 0.9f, 0.0f);
        glScalef(0.3f, 0.01f, 0.03f);
        glutSolidCube(1.0f);
        glPopMatrix();
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set up the camera
    gluLookAt(cameraPositionX, cameraPositionY, cameraPositionZ,
        cameraPositionX + cameraFrontX, cameraPositionY + cameraFrontY, cameraPositionZ + cameraFrontZ,
        cameraUpX, cameraUpY, cameraUpZ);

    // Draw the table, book, and fan
    drawTable();
    drawBook();
    drawFan();

    glFlush();
}

void reshape(int width, int height)
{
    screenWidth = width;
    screenHeight = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / (float)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("3D Virtual Room");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(reshape);

    // Set the background color to dark gray
    glClearColor(0.2f, 0.2f, 0.2f, 0.0);

    glutMainLoop();
    return 0;
}
