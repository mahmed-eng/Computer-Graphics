#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

// Function to draw a rectangle
void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set random seed based on current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Draw 5 aligned rectangles with random sizes and positions
    for (int i = 0; i < 5; ++i) {
        float x = static_cast<float>(std::rand() % 400);
        float y = static_cast<float>(std::rand() % 400);
        float width = static_cast<float>(std::rand() % 100 + 50);
        float height = static_cast<float>(std::rand() % 100 + 50);

        glColor3f(static_cast<float>(std::rand()) / RAND_MAX,
            static_cast<float>(std::rand()) / RAND_MAX,
            static_cast<float>(std::rand()) / RAND_MAX);

        drawRectangle(x, y, width, height);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Aligned Rectangles");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white

    // Register the display function
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
