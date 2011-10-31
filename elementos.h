#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Nivel.h"
#define PI 3.14159265
#define NORM_VEL 30

// Función que dibuja el tablero

int
evaluarBloques(ElemBloque *primero, int mover, int salto);
void 
dibujarBloques(LisBloque *bloques, ElemBloque *primero);
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
moverPelota(ElemBloque *primero,GLfloat *dirX, GLfloat *dirY, 
	    GLfloat *despPelotaX, GLfloat *despPelotaY, 
	    GLfloat *despDisparadorX, GLint *movInicial, 
	    GLfloat *xDisparador, GLfloat *yDisparador, 
	    GLint *vidas, LisNivel *juego, GLfloat velocidad, 
	    GLfloat *grado, int *haChocado);

void
cambiarDireccion(GLfloat *dirX, GLfloat *dirY);

void 
cuboMovible (double desp);
