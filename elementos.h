#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Nivel.h"
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
moverPelota(ElemBloque *primero, GLfloat *speedX, GLfloat *speedY, GLfloat *despPelotaX,
            GLfloat *despPelotaY, GLfloat *despDisparadorX,
            GLint *movInicial, GLfloat *cuboX, GLfloat *cuboY,
            GLint *vidas, LisNivel *juego);

void 
cuboMovible (double desp);
