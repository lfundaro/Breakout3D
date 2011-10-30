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
cambiarDireccion(GLfloat *dirX, GLfloat *dirY);

void
moverPelota(GLfloat *dirX, GLfloat *dirY, GLfloat *despPelotaX,
            GLfloat *despPelotaY, GLfloat *despDisparadorX,
            GLint *movInicial, GLfloat *cuboX, GLfloat *cuboY,
            GLint *vidas);

void 
cuboMovible (double desp);

