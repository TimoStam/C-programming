

#include <GL/glut.h>  // GLUT, include glu.h and gl.h

float rect2X = 0;
float rect2Y = 0;
float rotation = 0.0;

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        rect2Y += 0.01f;
        break;
    case 's':
        rect2Y -= 0.01f;
        break;
    case 'a':
        rect2X -= 0.01f;
        break;
    case 'd':
        rect2X += 0.01f;
        break;
    case 'q':
        rotation -= 5.0;
        break;
    case 'e':
        rotation += 5.0;
        break;
    }
    glutPostRedisplay(); // Redraw the window
}
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.1f, 0.0f); // Red
    glVertex2f(-0.5f, -0.5f);    // x, y
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    //glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    //glColor3f(0.0f, 0.1f, 1.0f); // Red
    //glVertex2f(-0.1f, -0.2f);    // x, y
    //glVertex2f(0.0f, -0.0f);
    //glVertex2f(0.2f, 0.2f);
    //glVertex2f(-0.2f, 0.2f);
    //glEnd();

    glColor3f(0.0f, 0.1f, 1.0f);
    //glutSolidCube(0.4f);
    glPushMatrix(); // Save current transformation state

    glTranslatef(rect2X, rect2Y, 0.0f); // Move
    glRotatef(rotation, 0, 0, 1);       // Then rotate
    glColor3f(0.0f, 0.1f, 1.0f);        // Blue
    glRectf(-0.1f, -0.1f, 0.1f, 0.1f);  // Draw centered at origin
    
    glPopMatrix();  // Restore previous transformation state
    

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutKeyboardFunc(keyboard);

    glutMainLoop();           // Enter the event-processing loop
    return 0;
}