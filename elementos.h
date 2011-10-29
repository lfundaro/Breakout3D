#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Función que dibuja el tablero
void 
dibujarTablero (GLfloat *x, GLfloat *y);

void 
dibujarDisparador(GLfloat *x, GLfloat *y, GLfloat *z);

void
dibujarPelota();


void
moverPelota(GLfloat *speedX, GLfloat *speedY, GLfloat *despPelotaX,
            GLfloat *despPelotaY, GLfloat *despDisparadorX,
            GLint *movInicial);

void 
cuboMovible (double desp);

