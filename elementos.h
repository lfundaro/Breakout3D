#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define PI 3.14159265
#define NORM_VEL 30

// Función que dibuja el tablero
void 
dibujarTablero (GLfloat *x, GLfloat *y);

void 
dibujarDisparador(GLfloat *x, GLfloat *y, GLfloat *z);

void
dibujarPelota();

void
rotarVector(GLfloat *grado, GLfloat delta, GLfloat *compX, 
            GLfloat *compY, GLfloat velocidad);

void
cambiarDireccion(GLfloat *dirX, GLfloat *dirY);

void
moverPelota(GLfloat *dirX, GLfloat *dirY, GLfloat *despPelotaX,
            GLfloat *despPelotaY, GLfloat *despDisparadorX,
            GLint *movInicial, GLfloat *cuboX, GLfloat *cuboY,
            GLint *vidas, GLfloat velocidad,GLfloat *grado,
            int *haChocado);

void 
cuboMovible (double desp);

