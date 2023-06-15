#include <GL/glut.h>
#include <cmath>

// Variables para el movimiento de la cámara
float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 0.0f;
float cameraYaw = 0.0f;
float cameraPitch = 0.0f;
float cameraSpeed = 0.1f;
float jumpVelocity = 0.0f;
float gravity = -0.01f;

// Función para dibujar el cuarto
void drawRoom() {
    // Pared frontal (rojo)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glEnd();

    // Pared derecha (verde)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    glEnd();

    // Pared trasera (azul)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glEnd();

    // Pared izquierda (amarillo)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glEnd();

    // Piso (gris)
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glEnd();
}

// Función para manejar las teclas especiales (movimiento de la cámara)
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            // Mover hacia adelante
            cameraX -= cameraSpeed * sin(cameraYaw);
            cameraZ -= cameraSpeed * cos(cameraYaw);
            break;
        case GLUT_KEY_DOWN:
            // Mover hacia atrás
            cameraX += cameraSpeed * sin(cameraYaw);
            cameraZ += cameraSpeed * cos(cameraYaw);
            break;
        case GLUT_KEY_LEFT:
            // Girar a la izquierda
            cameraYaw -= 0.1f;
            break;
        case GLUT_KEY_RIGHT:
            // Girar a la derecha
            cameraYaw += 0.1f;
            break;
    }

    glutPostRedisplay(); // Volver a dibujar la escena
}

// Función para manejar el movimiento de la cámara y la gravedad
void update(int value) {
    // Aplicar gravedad a la cámara
    cameraY += jumpVelocity;
    jumpVelocity += gravity;

    // Evitar que la cámara se hunda en el piso
    if (cameraY < 0.0f) {
        cameraY = 0.0f;
        jumpVelocity = 0.0f;
    }

    glutPostRedisplay(); // Volver a dibujar la escena
    glutTimerFunc(16, update, 0); // Llamar a la función de actualización cada 16 ms (aproximadamente 60 fps)
}

// Función para dibujar la escena
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Configurar la posición y la orientación de la cámara
    gluLookAt(cameraX, cameraY, cameraZ,
              cameraX + sin(cameraYaw), cameraY + cameraPitch, cameraZ + cos(cameraYaw),
              0.0f, 1.0f, 0.0f);

    drawRoom();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cuarto de casa con OpenGL");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, update, 0); // Iniciar la función de actualización

    glutMainLoop();

    return 0;
}
