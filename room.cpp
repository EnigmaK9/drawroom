#include <GL/glut.h>

void drawRoom() {
    // Techo
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);  // Color azul
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glEnd();

    // Piso
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);  // Color gris medio
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glEnd();

    // Paredes
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);  // Color gris claro
    // Pared frontal
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);
    // Pared derecha
    glVertex3f(5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    // Pared trasera
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    // Pared izquierda
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glEnd();
}
    /*
    // Mueble
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.0f);  // Color marrón oscuro
    // Parte superior
    glVertex3f(-2.5f, -5.0f, -1.0f);
    glVertex3f(2.5f, -5.0f, -1.0f);
    glVertex3f(2.5f, -3.0f, -1.0f);
    glVertex3f(-2.5f, -3.0f, -1.0f);
    // Parte frontal
    glVertex3f(-2.5f, -5.0f, -1.0f);
    glVertex3f(2.5f, -5.0f, -1.0f);
    glVertex3f(2.5f, -5.0f, 1.0f);
    glVertex3f(-2.5f, -5.0f, 1.0f);
    // Parte trasera
    glVertex3f(2.5f, -5.0f, -1.0f);
    glVertex3f(-2.5f, -5.0f, -1.0f);
    glVertex3f(-2.5f, -5.0f, 1.0f);
    glVertex3f(2.5f, -5.0f, 1.0f);
    // Parte derecha
    glVertex3f(2.5f, -5.0f, -1.0f);
    glVertex3f(2.5f, -5.0f, 1.0f);
    glVertex3f(2.5f, -3.0f, 1.0f);
    glVertex3f(2.5f, -3.0f, -1.0f);
    // Parte izquierda
    glVertex3f(-2.5f, -5.0f, 1.0f);
    glVertex3f(-2.5f, -5.0f, -1.0f);
    glVertex3f(-2.5f, -3.0f, -1.0f);
    glVertex3f(-2.5f, -3.0f, 1.0f);
    glEnd();
}
*/
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    drawRoom();

    glFlush();
    glutSwapBuffers();
}

void keyboard(int key, int x, int y) {
    const float cameraSpeed = 0.1f; // Velocidad de movimiento de la cámara

    switch (key) {
        case GLUT_KEY_UP: // Tecla de flecha arriba
            glTranslatef(0.0f, 0.0f, -cameraSpeed); // Mover hacia adelante en el eje Z
            break;
        case GLUT_KEY_DOWN: // Tecla de flecha abajo
            glTranslatef(0.0f, 0.0f, cameraSpeed); // Mover hacia atrás en el eje Z
            break;
        case GLUT_KEY_LEFT: // Tecla de flecha izquierda
            glTranslatef(-cameraSpeed, 0.0f, 0.0f); // Mover hacia la izquierda en el eje X
            break;
        case GLUT_KEY_RIGHT: // Tecla de flecha derecha
            glTranslatef(cameraSpeed, 0.0f, 0.0f); // Mover hacia la derecha en el eje X
            break;
    }

    glutPostRedisplay(); // Volver a dibujar la escena
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cuarto de casa con OpenGL");
    glutSpecialFunc(keyboard); // Registrar la función keyboard() como función de manejo del teclado especial
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
