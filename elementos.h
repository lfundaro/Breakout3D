/***********************************************************
 *
 * Asunto: Codigo fuente de Break Out. Proyecto 1
 * Materia: Laboratorio de Computacion Grafica I - CI4321
 * Trimestre: Sep-Dic 2011
 * Seccion: 1
 * Profesor: X
 * Integrantes:                  Carnet:
 * * Lorenzo Fundaro            06-39559
 * * Jose    Lezama             07-41104
 *
 *************************************************************/
#ifndef ELEMENTOS_H
#define ELEMENTOS_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Nivel.h"
#define PI 3.14159265
#define NORM_VEL 30

void
rotarVector(GLfloat *grado, GLfloat delta, GLfloat *compX, 
            GLfloat *compY, GLfloat velocidad);

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
moverPelota(ElemBloque *primero,GLfloat *dirX, GLfloat *dirY, 
	    GLfloat *despPelotaX, GLfloat *despPelotaY, 
	    GLfloat *despDisparadorX, GLint *movInicial, 
	    GLfloat *xDisparador, GLfloat *yDisparador, 
	    GLint *vidas, LisNivel *juego, GLfloat *velocidad, 
            GLfloat *grado, int *haChocado, int *impactos);

void
cambiarDireccion(GLfloat *dirX, GLfloat *dirY);

void 
cuboMovible (double desp);

#endif
