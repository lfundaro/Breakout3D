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
#include "Lector.h"
#include "Nivel.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

LisNivel *juego;
LisBloque *tmpBloques;
ElemBloque *tmpBloque;
ElemNivel *tmpNivel;

void dibujarBloque() {
  float tmpFila = (fila(tmpBloque->bloque));
  float tmpColumna = columna(tmpBloque->bloque)*.4;
  char tmpColor = color(tmpBloque->bloque);
  float r,g,b;
  switch (tmpColor) {
  case 'n': case 'N':
    r = 1; g = 0.3; b = 0;
    break;
  case 'r': case 'R':
    r = 0.8; g = 0; b = 0;
    break;
  case 'v': case 'V':
    r = 0; g = 0.7;b = 0.2;
    break;
  case 'g': case 'G':
    r = 0.6; g = 0.6; b = 0.6;
    break;
  case 'a': case 'A':default:
    r = 0.9; g = 0.9; b = 0;
    break;
  }
  glLoadIdentity();
  glTranslatef(1+tmpFila,0+tmpColumna,-4.0f);
  glScalef(1,0.4,0.4);
  glColor3f(r,g,b);
  glutSolidCube(1);
  glColor3f(0.8,0.8,0.8);
  glLineWidth(3);
  glutWireCube(1);
}

void display() {
  glClearColor(0.0f, 0.0f, 0.0f ,1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);

  tmpNivel = cabezaNivel(juego);
  tmpBloques = bloquesNivel(tmpNivel->nivel);
  tmpBloque = cabezaBloque(tmpBloques);

  gluPerspective(10.0f,1.0f, 1.0f, 50.0f);
  glMatrixMode(GL_MODELVIEW);
  dibujarBloque();
  tmpBloque = (tmpBloque->siguiente);
  dibujarBloque();
  tmpBloque = (tmpBloque->siguiente);
  dibujarBloque();
  tmpBloque = (tmpBloque->siguiente);
  dibujarBloque();
  tmpBloque = (tmpBloque->siguiente);
  dibujarBloque();

  glFlush();
}

void reshape(int w, int h) {
  float aspectratio;
  if (h==0)
    h=1;
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  aspectratio = (float) w / (float) h;
  if (w<=h) {
    glOrtho(-10, 10, -10/aspectratio, 10/aspectratio, 1.0, -1.0);
  }else{
    glOrtho(-10*aspectratio, 10*aspectratio, -10, 10, 1.0, -1.0);
  }
}

int main(int argc, char **argv) {
  juego = (LisNivel*)malloc(sizeof(LisNivel));
  juego = cargarInfo();
  tmpBloques =(LisBloque*)malloc(sizeof(LisBloque));
  tmpBloque = (ElemBloque*)malloc(sizeof(ElemBloque));
  tmpNivel = (ElemNivel*)malloc(sizeof(ElemNivel));
  glutInit(&argc,argv);
  glutInitWindowSize (800,800);
  glutInitWindowPosition (10,10);
  glutCreateWindow ("Mi primera ventana");
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB |  GLUT_DEPTH);
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  liberarLisNivel(juego);
  return 0;
}
