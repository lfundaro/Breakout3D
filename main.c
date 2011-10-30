#include "Lector.h"
#include "Nivel.h"
#include "utils.h"
#include "elementos.h"

#include <signal.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

LisNivel *juego;
LisBloque *tmpBloques;
ElemBloque *tmpBloque;
ElemNivel *tmpNivel;
GLfloat despDisparadorX = 0.0;
GLfloat despPelotaY = 0.10;
GLfloat despPelotaX = 1.50;
GLfloat posActualDisp = 0.0;
int pelotaInicial = 1;
int gameOver = 0;
GLfloat xTablero = 3.0;
GLfloat yTablero = 5.5;
GLfloat xDisparador = 0.5;
GLfloat yDisparador = 0.12;
GLfloat zDisparador = 0.12;
GLfloat xCubo = 0.3;
GLfloat yCubo = 0.12;
GLfloat zCubo = 0.12;
int mover = 0;
GLint movInicial = 1;
GLint vidas = 3;
GLfloat dirX = 0.03;
GLfloat dirY = 0.03;
GLfloat deltaXdisparador = 1.5;

void
reiniciarJuego()
{
  pelotaInicial = 1;
  gameOver = 0;
  despPelotaX = 1.50;
  despPelotaY = 0.10;
  despDisparadorX = 0.0;
  movInicial = 1;
  deltaXdisparador = 1.5;
  glutPostRedisplay();
}

int evaluarBloques(){
  ElemBloque *anterior;
  if (mover == 1) {
    tmpBloque = cabezaBloque(tmpBloques);
    anterior = NULL;
    while(tmpBloque != NULL) {
      modificarImpactos(tmpBloque,-1);
      eMoverBloque(tmpBloque,1,0);
      if (eFila(tmpBloque) == 40) {
        gameOver = 1;
      }
      anterior = tmpBloque;
      tmpBloque = (tmpBloque->siguiente);
    }
    mover = 0;
    alarm(salto(juego));
  }
}

void dibujarBloques(){
  tmpBloque = cabezaBloque(tmpBloques);
  while(tmpBloque != NULL) {
    glPushMatrix();
    if (eImpactos(tmpBloque) > 0) {
      dibujarBloque(tmpBloque);
    }
    tmpBloque = (tmpBloque->siguiente);
    glPopMatrix();
  }
}

void display(void) {
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  /* Coordenadas del sistema */
  glLoadIdentity();
  gluLookAt (0.0, -3.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  // gluLookAt (1.0, -5.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glTranslatef(-1.5,-2.0,0.0);

  /* Dibujo de objetos */

  /* Tablero */
  dibujarTablero(&xTablero,&yTablero);
  /* Bloques */
  /* evaluarBloques(); */
  /* glutPostRedisplay(); */
  /* dibujarBloques(); */

  /* Barra Disparadora */
  glPushMatrix();
  glTranslatef(despDisparadorX,0.0,0.0);
  dibujarDisparador(&xDisparador,&yDisparador,&zDisparador);
  glPopMatrix();

  /* Pelota */
  glPushMatrix();
  if (pelotaInicial)  // Inicio de juego
    {
      glTranslatef(1.50+despDisparadorX,0.10,0.10);
      //      deltaXdisparador += despDisparadorX;
      dibujarPelota();
    }
  else  // Juego comenzado
    {
      if (!gameOver) 
        {
          if (vidas > 0)
            {
              int deltaVidas = vidas;
              GLfloat deltaXdisparador = 1.50 + despDisparadorX;
              moverPelota(&dirX,&dirY,&despPelotaX,
                          &despPelotaY, &despDisparadorX,
                          &movInicial, &deltaXdisparador, 
                          &yDisparador,&vidas);
              if (vidas < deltaVidas)
                {
                  reiniciarJuego();
                }
            }
          else
            {
              gameOver = 1;
            }
        }
    }
  glPopMatrix();  
  glutSwapBuffers();
  glFlush();

  return;
}

void
direccionDisparo(GLfloat *dirX, GLfloat *dirY)
{
  float grado;
  grado = (float) (rand() % 11 + 85);
  printf ("grado = %f\n",grado);
  *dirX = cosf(grado)*(*dirX);
  *dirY = sinf(grado)*(*dirY);
  return;
}

void 
teclaDisparar() 
{
  pelotaInicial = 0;
}

void
teclaDerecha ()
{
  if (despDisparadorX <= 1.20)
    {
      despDisparadorX += 0.08;
      deltaXdisparador += despDisparadorX;
    }
  return;
}

void
teclaIzquierda ()
{
  if (despDisparadorX >= -1.20)
    {
      despDisparadorX -= 0.08;
      deltaXdisparador += despDisparadorX;
    }
  return;
}

void 
teclaReiniciar ()
{
  reiniciarJuego();
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
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f, aspectratio, 0.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

void SIGALRM_mover (){
  if (mover == 0){
    mover = 1;
  }
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
  srand(time(NULL));
  /* Inicialización de ventana */
  signal(SIGALRM, SIGALRM_mover);
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_RGB |  GLUT_DEPTH | GLUT_DOUBLE );
  glutInitWindowSize (1024, 768);
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
  alarm(enfriamiento(juego));
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  /* Inicializacion de vector direccion */
  //  cambiarDireccion(&dirX, &dirY);
  glutMainLoop();
  return 0;
}


/* void display(void) */
/* { */
/*   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); */
/*   glMatrixMode(GL_MODELVIEW); */
/*   glLoadIdentity(); */
/*   /\* clear the matrix *\/ */
/*   /\* viewing transformation *\/ */
/*   // Vista inclinada */
/*   // gluLookAt (0.0, 8.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0); */
/*   //  gluLookAt (0.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0); */
/*   // gluLookAt (0.0, 5.0, 8.0, 0.0, 3.0, 0.0, 0.0, 2.0, -1.0); */
/*   gluLookAt (0.0, 8.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0); */
/*   // Vista recta */
/*   //   gluLookAt (10, 7, -3.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0); */

/*   glPushMatrix(); */
/*   glTranslatef(despDisparador,0,0); */
/*   cuboX = -4.45+4.5 + despDisparador; */
/*   cuboZ = 4.7; //-29+5+(36.5*.4*3); */
/*   cuboMovible (despDisparador); */
/*   glPopMatrix(); */

/*   tmpBloque = cabezaBloque(tmpBloques); */
/*   while (tmpBloque != NULL) { */
/*     glPushMatrix(); */
/*     dibujarBloque(tmpBloque); */
/*     glPopMatrix(); */
/*     tmpBloque = (tmpBloque->siguiente); */
/*   } */


/*   glPushMatrix(); */
/*   if (pelotaInicial) {   // Comienzo del juego */
/*     glTranslatef(0.0,0.5f,3.7); */
/*     Pelota(); */
/*   } */
/*   else { // Pelota en Juego */
/*     if (!gameOver) { */
/*       if (pelotaSube) { */
/*         despPelotaZ += speedZ; //1.0; //0.05; */
/*         if (fabs(despPelotaZ - 0.1 + 5.4) < 0.001) */
/*           pelotaSube = 0; */
/*       } */
/*       else {  // Pelota baja */
/*         despPelotaZ += speedZ; //1.0; //0.05; */
/*         if (despPelotaZ + 0.1 - 3.75 > 0.001) */
/*           pelotaSube = 1; */
/*       } */
/*       if (!pelotaMovHor) { // Movimiento a la Izq. */
/*         despPelotaX += dirX; //1.0; */
/*         if (fabs(despPelotaX + 0.1 + 2.3/\*3.2*\/) < 0.1) { */
/*           pelotaMovHor = 1; */
/*         } */
/*       } */
/*       else { // Pelota se mueve la derecha */
/*         despPelotaX += dirX; //1.0; */
/*         if (despPelotaX + 0.1 - 2.3 /\*2.0*\/ > 0.001) { */
/*           pelotaMovHor = 0; */
/*         } */
/*       } */
/*       glTranslatef(despPelotaX, 0.5f, despPelotaZ); */
/*       // Chequear si pelota viene en direcciÃ³n a la barra */
/*       if (cmpCoord2D(despPelotaX, despPelotaZ, cuboX, cuboZ) == 0) */
/*         Pelota(); */
/*       else { */
/*         gameOver = 1; */
/*       } */
/*     } */
/*   } */
/*   glutPostRedisplay(); */
/*   glPopMatrix(); */
  
/*   dibujarTablero (despDisparador); */
/*   glutSwapBuffers(); */
/*   glFlush (); */
/* } */
