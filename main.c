#include "Lector.h"
#include "Nivel.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

LisNivel *juego;
LisBloque *tmpBloques;
ElemBloque *tmpBloque;
ElemNivel *tmpNivel;
float despDisparador = 0.0;
float despPelotaZ = 3.7;
float despPelotaX = 0.0;
int pelotaInicial = 1;
int pelotaSube = 1;

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  /* clear the matrix */
  /* viewing transformation */
  // Vista inclinada
  // gluLookAt (0.0, 8.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
  //  gluLookAt (0.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
  // gluLookAt (0.0, 5.0, 8.0, 0.0, 3.0, 0.0, 0.0, 2.0, -1.0);
   gluLookAt (0.0, 8.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
  // Vista recta
  //   gluLookAt (10, 7, -3.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);

  glPushMatrix();
  glTranslatef(despDisparador,0,0);
  cuboMovible (despDisparador);
  glPopMatrix();

  /* tmpBloque = cabezaBloque(tmpBloques); */
  /* while (tmpBloque != NULL) { */
  /*   glPushMatrix(); */
  /*   dibujarBloque(tmpBloque); */
  /*   glPopMatrix(); */
  /*   tmpBloque = (tmpBloque->siguiente); */
  /* } */

   glPushMatrix();
  if (pelotaInicial) {
    glTranslatef(0.0,0.5f,3.7);
    Pelota();
  }
  else {
    despPelotaX = 0.0;
    if (pelotaSube) {
      despPelotaZ -= 0.05;
      if (abs(despPelotaZ + 6.3) < 0.001)
        pelotaSube = 0;
    } 
    else {  // Pelota baja
      despPelotaZ += 0.05;
      if (despPelotaZ - 3.7 > 0.001)
        pelotaSube = 1;
    }
    glTranslatef(despPelotaX, 0.5f, despPelotaZ);
    Pelota();
    glutPostRedisplay();
  }
  glPopMatrix();
  
  dibujarTablero (despDisparador);
  glutSwapBuffers();
  glFlush ();
}

void 
teclaDisparar() 
{
  pelotaInicial = 0;
}

void
teclaDerecha ()
{
  if (despDisparador < 1.9)
    despDisparador += 0.09;
  return;
}

void
teclaIzquierda ()
{
  if (despDisparador > -1.9)
    despDisparador -= 0.09;
  return;
}

void
keyboard (unsigned char key, int x, int y) 
{
  switch (key)
    {
    case 'a':case 'A':
      teclaIzquierda ();
      glutPostRedisplay();
      break;
    case 'd':case 'D':
      teclaDerecha ();
      glutPostRedisplay();
      break;
    case 32:
      printf("teclearon espacio \n");
      teclaDisparar();
      glutPostRedisplay();
      break;
    default:
      printf("Didnt match\n");
      break;
    }
  return;
}

void reshape (int w, int h)
{
  float aspectratio;
  aspectratio = (float) w / (float) h;
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f, aspectratio, 0.5, 100.0);
  //  glFrustum (0.0,0.0,w,h,-20.0,200.0);
  glMatrixMode(GL_MODELVIEW);
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}

int main(int argc, char** argv)
{
  juego = (LisNivel*)malloc(sizeof(LisNivel));
  juego = cargarInfo();
  tmpBloques =(LisBloque*)malloc(sizeof(LisBloque));
  tmpBloque = (ElemBloque*)malloc(sizeof(ElemBloque));
  tmpNivel = (ElemNivel*)malloc(sizeof(ElemNivel));
  tmpNivel = cabezaNivel(juego);
  tmpBloques = bloquesNivel(tmpNivel->nivel);

  /* Inicialización de ventana */
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB |  GLUT_DEPTH);
  //  glutInitWindowSize (1024, 768);
  glutInitWindowSize (800, 600);
  glutInitWindowPosition (100, 150);
  glutCreateWindow (argv[0]);
  /* Propiedades de openGL */
  glEnable(GL_DEPTH_TEST);
  glClearDepth (1.0f);
  glClearColor(0,0,0,1.0f);
  glShadeModel(GL_SMOOTH); 
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  /* Directivas para graficar */
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  //glutSpecialFunc(procesarTeclas);
  glutKeyboardFunc(keyboard);
  
  glutMainLoop();
  return 0;
}
