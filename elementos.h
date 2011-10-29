#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Función que dibuja el tablero
void 
dibujarTablero ();

void 
dibujarDisparador();

void
dibujarPelota();


void
moverPelota(GLfloat *speedX, GLfloat *speedY, GLfloat *despPelotaX,
            GLfloat *despPelotaY);

void 
cuboMovible (double desp);

