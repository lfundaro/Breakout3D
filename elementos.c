#include "elementos.h"
#include "Nivel.h"
#include <stdio.h>
#include <math.h>

void 
dibujarTablero(GLfloat *x, GLfloat *y) 
{
  glColor3f(0.5,0.5,0.5); // Blanco
  /* Base del tablero */
  glBegin(GL_QUADS);
  glVertex3d(0.0,0.0,0.0); // vo
  glVertex3d(0.0,*y,0.0); // v2
  glVertex3d(*x,*y,0.0); // v3
  glVertex3d(*x,0.0,0.0); // v4
  glEnd();

  /* Banda Frontal */
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glTranslatef(0.0,*y,0.0);
  glBegin(GL_QUADS);
  glVertex3d(0.0,0.0,0.0); // vo
  glVertex3d(0.0,0.1,0.1); // v2
  glVertex3d(*x,0.1,0.1); // v3
  glVertex3d(*x,0.0,0.0); // v4
  glEnd();
  glPopMatrix();

  /* Contorno Banda Frontal */
  glPushMatrix();
  glColor3f(0.0,0.0,0.0);
  glLineWidth(3);
  glTranslatef(0.0,*y - 0.002,0.0);
  glBegin(GL_LINE_LOOP);
  glVertex3d(0.0,0.0,0.0); // vo
  glVertex3d(0.0,0.1,0.1); // v2
  glVertex3d(*x,0.1,0.1); // v3
  glVertex3d(*x,0.0,0.0); // v4
  glEnd();
  glPopMatrix();
  
  /* Banda Lateral Izquierda */
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(0.0,0.1,0.1);
  glVertex3f(0.0,*y,0.1);
  glVertex3f(0.0,*y,0.0);
  glEnd();
  glPopMatrix();

  /* Contorno Banda Lateral Izquierda */
  glPushMatrix();
  glColor3f(0.0,0.0,0.0);
  glLineWidth(5);
  glTranslatef(0.008,0.0,0.0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(0.0,0.0,0.1);
  glVertex3f(0.0,*y,0.1);
  glVertex3f(0.0,*y,0.0);
  glEnd();
  glPopMatrix();

  /* Banda Lateral Derecha */
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glTranslated(*x,0.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(0.0,0.1,0.1);
  glVertex3f(0.0,*y,0.1);
  glVertex3f(0.0,*y,0.0);
  glEnd();
  glPopMatrix();

  /* Contorno Banda Lateral Izquierda */
  glPushMatrix();
  glColor3f(0.0,0.0,0.0);
  glLineWidth(5);
  glTranslatef(*x - 0.005,0.0,0.0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(0.0,0.1,0.1);
  glVertex3f(0.0,*y,0.1);
  glVertex3f(0.0,*y,0.0);
  glEnd();
  glPopMatrix();
}

void
dibujarDisparador(GLfloat *x, GLfloat *y, GLfloat *z)
{
  glTranslatef(1.25,0.0,0.0);
  glColor3f(0.3,0.3,1.0);
  glPushMatrix();
  /* Frontal */
  glBegin(GL_QUADS);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(*x,0.0,0.0);
  glVertex3f(*x,0.0,*z);
  glVertex3f(0.0,0.0,*z);
  glEnd();
  /* Techo */
  glColor3f(0.3,0.3,1.0);
  glBegin(GL_QUADS);
  glVertex3f(0.0,0.0,*z);
  glVertex3f(*x,0.0,*z);
  glVertex3f(*x,*y,*z);
  glVertex3f(0.0,*y,*z);
  glEnd();
  glColor3f(0.3,0.3,1.0);

  /* Disparador */
  glPushMatrix();
  glColor3f(0.2,0.2,0.3);
  glTranslatef((*x/2.0)-((*x/2.0)/3),0.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(0.0,0.0,*z + 0.009);
  glVertex3f(*x/3.0,0.0,*z + 0.009);
  glVertex3f(*x/3.0,*z,*z + 0.009);
  glVertex3f(0.0,*z,*z + 0.009);
  glEnd();
  glColor3f(0.2,0.25,0.3);
  glBegin(GL_QUADS);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(*x/3.0,0.0,0.0);
  glVertex3f(*x/3.0,-0.00009,*z);
  glVertex3f(0.0,-0.00009,*z);
  glEnd();
  glPopMatrix();


  /* Cara derecha */
  glBegin(GL_QUADS);
  glVertex3f(*x,0.0,0.0);
  glVertex3f(*x,0.0,*z);
  glVertex3f(*x,*y,*z);
  glVertex3f(*x,*y,0.0);
  glEnd();
  /* Cara izquierda */
  glBegin(GL_QUADS);
  glVertex3f(0.0,0.00,0.0);
  glVertex3f(0.0,0.0,*z);
  glVertex3f(0.0,*y,*z);
  glVertex3f(0.0,*y,0.0);
  glEnd();
  
  /**** Contornos ****/
  /* Frontal */
  glLineWidth(2);
  glColor3f(0.0,0.0,0.0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(*x,0.0,0.0);
  glVertex3f(*x,0.0,*z);
  glVertex3f(0.0,0.0,*z);
  glEnd();

  /* Techo */
  glBegin(GL_LINE_LOOP);
  glVertex3f(0.0,0.0,*z);
  glVertex3f(*x,0.0,*z);
  glVertex3f(*x,*y,*z);
  glVertex3f(0.0,*y,*z);
  glEnd();

  /* Cara derecha */
  glBegin(GL_LINE_LOOP);
  glVertex3f(*x,0.0,0.0);
  glVertex3f(*x,0.0,*z);
  glVertex3f(*x,*y,*z);
  glVertex3f(*x,*y,0.0);
  glEnd();

  /* Cara Izquierda */
  glBegin(GL_LINE_LOOP);
  glVertex3f(0.0,0.00,0.0);
  glVertex3f(0.0,0.0,*z);
  glVertex3f(0.0,*y,*z);
  glVertex3f(0.0,*y,0.0);
  glEnd();
  glPopMatrix();
}

void
dibujarPelota()
{
  glColor3f(0.4,0.4,0.4);
  glutSolidSphere(0.05,10,10);
  return;
}

void
moverPelota(GLfloat *dirX, GLfloat *dirY, GLfloat *despPelotaX,
            GLfloat *despPelotaY, GLfloat *despDisparadorX,
            GLint *movInicial, GLfloat *xDisparador, 
            GLfloat *yDisparador, GLint *vidas,
            GLfloat velocidad)
{
  if (*movInicial)
    *despPelotaX += *despDisparadorX;
  *movInicial = 0;
  if (*dirX >= 0)
    {
      // Límite banda derecha
      if (*despPelotaX < 2.90)
        {
          *despPelotaX += *dirX;
        }
      else
        {
          *dirX = -(*dirX);
        }
    }
  // Límite banda izquierda
  else      
    {
      if (*despPelotaX > 0.09)
        {
          *despPelotaX += *dirX;
        }
      else
        {
          *dirX = -(*dirX);
        }
    }
  if (*dirY >= 0)
    {
      // Límite Banda Superior
      if (*despPelotaY < 5.495) 
        {
          *despPelotaY += *dirY;
        }
      else 
        {
          *dirY = -(*dirY)*velocidad;
        }
    }
  else    // Pelota Baja
    {
      // Límite Banda Inferior
      if (*despPelotaY - 0.05 > 0.18)
        {
          *despPelotaY += *dirY;
        }
      else
        {
          *dirY = -(*dirY);
        }
    }
  // Pelota se mueve lateralmente
  glTranslatef(*despPelotaX,*despPelotaY,0.0);
  // Chequear si pelota choca con base
  int proximidadY = *despPelotaY - 0.05 - 0.20 <= 0.01;
  GLfloat dist = 0.0;
  if (proximidadY)
    {
      if (*despPelotaX <= (*xDisparador + 0.25) && 
          *despPelotaX >= (*xDisparador - 0.25))
        {
          // Cambio de direccion de tiro
          // Si viene desde la izquierda
              if (*despPelotaX < 1.50 && dirY < 0)
                {
                  // Pelota pega en el centro del disparador
                  if (*despPelotaX >= *xDisparador - 0.5/3.0 &&
                      *despPelotaX <= *xDisparador + 0.5/3.0)
                    {
                      *dirX = -(*dirX);
                      printf("izquierda y cambio \n");
                    }
                }
              // Pelota viene desde la derecha
              if (*despPelotaX > 1.50 && dirY < 0)
                {
                  // Pelota pega en el centro del disparador
                  if (*despPelotaX >= *xDisparador - 0.5/3.0 &&
                      *despPelotaX <= *xDisparador + 0.5/3.0)
                    {
                        *dirX = -(*dirX);
                      printf ("derecha y cambio \n");
                    }
                }
              dibujarPelota();
              glutPostRedisplay();
              return;
        }
      else
        {
          --(*vidas);
          printf ("vidas = %d\n",*vidas);
          return;
        }
    }
  else
    {
      dibujarPelota();
    }
  glutPostRedisplay();
  return;
}

void dibujarBloque(ElemBloque *tmpBloque) {
  float tamX = 0.3;
  float tamY = 0.12;
  float tamZ = 0.12;
  float baseX = 0.15;
  float baseY =(40*0.12);
  float baseZ =0.06;
  int tmpColumna= eColumna(tmpBloque);
  float tmpFila = fila(tmpBloque->bloque);
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
  //  glTranslatef(baseX+(tmpColumna*tamX),baseY-(tmpFila*tamY),baseZ);
  glTranslatef(baseX+(tmpColumna*tamX),baseY-(tmpFila*tamY),baseZ);
  glScalef(tamX-0.01,tamY-0.01,tamZ-0.01);
  glColor3f(r,g,b);
  glutSolidCube(1);
  glColor3f(0.2,0.2,0.2);
  glLineWidth(2);
  glutWireCube(1);
}
