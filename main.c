#include "Lector.h"
#include "Nivel.h"
#include "utils.h"

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
double despPelotaZ = 3.7;
double despPelotaX = 0.0;
int pelotaInicial = 1;
int pelotaSube = 1;
int pelotaMovHor = 0; // 0 = izq. 1 = der.
//double barraPosInicialX = -4.45+4.5;0.5f,-29+5+(tmpFila*3)
double speedZ = -0.1;
double speedX = 0.0;
double cuboX = 0.0;
double cuboZ = 0.0;
int gameOver = 0;

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
  cuboX = -4.45+4.5 + despDisparador;
  cuboZ = 4.7; //-29+5+(36.5*.4*3);
  cuboMovible (despDisparador);
  glPopMatrix();

  tmpBloque = cabezaBloque(tmpBloques);
  while (tmpBloque != NULL) {
    glPushMatrix();
    dibujarBloque(tmpBloque);
    glPopMatrix();
    tmpBloque = (tmpBloque->siguiente);
  }

  if (speedZ <= 0.0) pelotaSube = 1;
  else pelotaSube = 0;

  if (speedX <= 0.0) pelotaMovHor = 0;
  else pelotaMovHor = 1;

  glPushMatrix();
  if (pelotaInicial) {   // Comienzo del juego
    glTranslatef(0.0,0.5f,3.7);
    Pelota();
  }
  else { // Pelota en Juego
    if (!gameOver) {
      if (pelotaSube) {
        despPelotaZ += speedZ; //1.0; //0.05;
        if (fabs(despPelotaZ - 0.1 + 5.4) < 0.001)
          pelotaSube = 0;
      }
      else {  // Pelota baja
        despPelotaZ += speedZ; //1.0; //0.05;
        if (despPelotaZ + 0.1 - 3.75 > 0.001)
          pelotaSube = 1;
      }
      if (!pelotaMovHor) { // Movimiento a la Izq.
        despPelotaX += speedX; //1.0;
        if (fabs(despPelotaX + 0.1 + 2.3/*3.2*/) < 0.1) {
          pelotaMovHor = 1;
        }
      }
      else { // Pelota se mueve la derecha
        despPelotaX += speedX; //1.0;
        if (despPelotaX + 0.1 - 2.3 /*2.0*/ > 0.001) {
          pelotaMovHor = 0;
        }
      }
      glTranslatef(despPelotaX, 0.5f, despPelotaZ);
      // Chequear si pelota viene en dirección a la barra
      if (cmpCoord2D(despPelotaX, despPelotaZ, cuboX, cuboZ) == 0)
        Pelota();
      else {
        gameOver = 1;
      }
    }
  }
  glutPostRedisplay();
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
  if (!pelotaInicial)
    if (despDisparador < 1.9)
      despDisparador += 0.5;
  return;
}

void 
teclaReiniciar ()
{
  pelotaInicial = 1;
  gameOver = 0;
  despPelotaZ = 3.7;
  despPelotaX = 0.0;
  pelotaSube = 1;
  pelotaMovHor = 0;
  despDisparador = 0;
}

void
teclaIzquierda ()
{
  if (!pelotaInicial)
    if (despDisparador > -1.9)
      despDisparador -= 0.5;
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
      teclaDisparar();
      glutPostRedisplay();
      break;
    case 'r': case 'R':
      teclaReiniciar();
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


      /* despPelotaZ += speedZ; */
      /* despPelotaX += speedX; */
      /* if (despPelotaZ >= 0 && despPelotaZ + 0.01 - 3.8 < 0.1) { */
      /*   speedZ = -speedZ; */
      /* } */
      /* if (despPelotaZ < 0 && despPelotaZ - 0.01 + 3.75 < 0.1) { */
      /*   speedZ = -speedZ; */
      /* } */
      /* glTranslatef(despPelotaX, 0.5f, despPelotaZ); */
      /* Pelota(); */
