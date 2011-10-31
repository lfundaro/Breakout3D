#include "Lector.h"
#include "Nivel.h"
#include "utils.h"
#include "elementos.h"

#include <string.h>
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
GLint vidas = 10;
GLfloat dirX;
GLfloat dirY;
GLfloat grado;
GLfloat velocidad;
GLfloat deltaXdisparador = 1.5;
GLint haChocado = 0;
int impacto;
int contImpactos = 0;
float incVel;


void
direccionInicial(GLfloat *dirX, GLfloat *dirY,GLfloat velocidad,
                 GLfloat *grado)
{
  *grado = (float) (rand() % 11 + 85);
  *dirX = cosf(*grado*PI/180)*velocidad/NORM_VEL;
  *dirY = sinf(*grado*PI/180)*velocidad/NORM_VEL;
  return;
}

void mostra_text(char cadena[], float x, float y) {
    int tmp;
    glColor3f(0,1,0);
    for(tmp=0; tmp < strlen(cadena); tmp++) { 
      glRasterPos2f(x+(tmp*(0.15)), y );
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)cadena[tmp]);
    }
}

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
  alarm(0);
  direccionInicial(&dirX,&dirY,velocidad,&grado);
  haChocado = 0;
  velocidad = 1.0;
  glutPostRedisplay();
}

void display(void) {
  char *stmpPuntuacion = (char*) malloc(sizeof(char)*15);
  char *stmpNivel = (char*) malloc(sizeof(char)*15);
  char *stmpVida = (char*) malloc(sizeof(char)*15);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  /* Coordenad=as del sistema */
  glLoadIdentity();
  gluLookAt (0.0, -3.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  // gluLookAt (1.0, -5.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glTranslatef(-1.5,-2.0,0.0);

  /* Puntuacion */
  sprintf(stmpPuntuacion,"%s%d","Puntuacion: ",puntuacion(juego));
  mostra_text(stmpPuntuacion,1,6);
  sprintf(stmpNivel,"%s%d","Nivel: ",numNivel(tmpNivel->nivel));
  mostra_text(stmpNivel,1,6.5);
  sprintf(stmpVida,"%s%d","Vidas: ",vida(juego));
  mostra_text(stmpVida,1,7);

  /* Dibujo de objetos */
  /* Tablero */
  dibujarTablero(&xTablero,&yTablero);

  if (tmpBloques->numElementos <= 0) {
    tmpNivel = tmpNivel->siguiente;
    if (tmpNivel == NULL){
      printf("ganaste\n");
    } else {
      tmpBloques = bloquesNivel(tmpNivel->nivel);
      incVel = eVelNivel(tmpNivel);
      impacto = eImpactoNivel(tmpNivel);
      reiniciarJuego();
    }
  }
    /* Bloques */
  tmpBloque = cabezaBloque(tmpBloques);
  gameOver = evaluarBloques(tmpBloque,mover,salto(juego));
  if (mover == 1) mover = 0;
  tmpBloque = cabezaBloque(tmpBloques);
  dibujarBloques(tmpBloques,tmpBloque);
  tmpBloque = cabezaBloque(tmpBloques);

  /* Barra Disparadora */
  glPushMatrix();
  glTranslatef(despDisparadorX,0.0,0.0);
  dibujarDisparador(&xDisparador,&yDisparador,&zDisparador);
  glPopMatrix();

  /* Pelota */

  if (pelotaInicial)  // Inicio de juego
    {
      glTranslatef(1.50+despDisparadorX,0.10,0.10);
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
	      tmpBloque=cabezaBloque(tmpBloques);
	      moverPelota(tmpBloque, &dirX,&dirY,&despPelotaX,
                      &despPelotaY, &despDisparadorX,
                      &movInicial, &deltaXdisparador, 
                      &yDisparador,&vidas,juego,&velocidad,&grado,
                      &haChocado,&contImpactos);
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
  glutSwapBuffers();
  return;
}

void 
teclaDisparar() 
{
  pelotaInicial = 0;
  alarm(enfriamiento(juego));
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
  juego = cargarInfo(argv[1]);
  tmpNivel = cabezaNivel(juego);
  tmpBloques = bloquesNivel(tmpNivel->nivel);
  incVel = eVelNivel(tmpNivel);
  impacto = eImpactoNivel(tmpNivel);
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
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  velocidad = 1.0;
  /* Inicializacion de vector direccion */
  direccionInicial(&dirX,&dirY,velocidad,&grado);
  glutMainLoop();
  return 0;
}
