#include "elementos.h"
#include "Nivel.h"
#include <stdio.h>
#include <math.h>

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

int
evaluarBloques(ElemBloque *primero, int mover, int salto)
{
  ElemBloque *tmpBloque = primero;
  ElemBloque *anterior;
  int gameOver = 0;
  if (mover == 1) {
    anterior = NULL;
    while(primero != NULL) {
      eMoverBloque(primero,1,0);
      if (eFila(tmpBloque) == 40) {
        gameOver = 1;
      }
      anterior = tmpBloque;
      primero = (primero->siguiente);
    }
    alarm(salto);
    return gameOver;
  }
  return gameOver;
}

void
dibujarBloques(LisBloque *bloques, ElemBloque *tmpBloque)
{
  ElemBloque *tmp, *tmp2;
  if (tmpBloque != NULL && eImpactos(tmpBloque) == 0) {
    tmp = tmpBloque;
    tmpBloque = tmpBloque->siguiente;
    bloques->primero = tmpBloque;
    liberarBloque(tmp->bloque);
    free(tmp);
    bloques->numElementos -= 1;
  }
  while(tmpBloque != NULL) {
    tmp = tmpBloque->siguiente;
    if (tmp != NULL && eImpactos(tmp) == 0) {
      tmp2 = tmp;
      tmp = tmp->siguiente;
      tmpBloque->siguiente = tmp;
      liberarBloque(tmp2->bloque);
      free(tmp2);
      bloques->numElementos -= 1;
    }
    glPushMatrix();
    dibujarBloque(tmpBloque);
    tmpBloque = (tmpBloque->siguiente);
    glPopMatrix();
  }
}

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
rotarVector(GLfloat *grado, GLfloat delta, GLfloat *compX, 
            GLfloat *compY, GLfloat velocidad)
{
  *grado += delta;
  *compX = fabsf(cosf(*grado*PI/180)*velocidad/NORM_VEL);
  *compY = fabsf(sinf(*grado*PI/180)*velocidad/NORM_VEL);
  return;
}

void
moverPelota(ElemBloque *primero,GLfloat *dirX, GLfloat *dirY, 
	    GLfloat *despPelotaX, GLfloat *despPelotaY, 
	    GLfloat *despDisparadorX, GLint *movInicial, 
	    GLfloat *xDisparador, GLfloat *yDisparador, 
	    GLint *vidas, LisNivel *juego, GLfloat velocidad, 
	    GLfloat *grado, int *haChocado)
{
  float tamX = 0.3;
  float tamY = 0.12;
  float tamZ = 0.12;
  float baseX = 0.15;
  float baseY =(40*0.12);
  float baseZ =0.06;
  GLfloat minX;
  GLfloat maxX;
  GLfloat minY;
  GLfloat maxY;
  GLfloat pelota = 0.05;
  int pego = 0;
  float error = 0.01;
  if (*movInicial)
    *despPelotaX += *despDisparadorX;
  *movInicial = 0;
  while(primero != NULL) {
    if (eImpactos(primero) != 0) {
      minX = baseX+(eColumna(primero)*tamX)-(tamX/2);
      maxX = baseX+(eColumna(primero)*tamX)+(tamX/2);
      maxY = baseY-(eFila(primero)*tamY)+(tamY/2);
      minY = baseY-(eFila(primero)*tamY)-(tamY/2);
      if ((minX <= ((*despPelotaX)+pelota)) && (((*despPelotaX)-pelota) <= maxX)
          && (minY <= ((*despPelotaY)+pelota)) && (((*despPelotaY)-pelota)<= maxY)) {
	if ((minY <= ((*despPelotaY)+pelota)) && (((*despPelotaY)-pelota)<= maxY) && (*despPelotaX <= minX || *despPelotaX >= maxX)) {
	  *dirX = -*dirX; 
	  *despPelotaX += *dirX; 
	}
	if ((minX <= ((*despPelotaX)+pelota)) && (((*despPelotaX)-pelota) <= maxX) && (*despPelotaY <= minY || *despPelotaY >= maxY)) {
	  *dirY = -*dirY;
	  *despPelotaY += *dirY;
	}
        pego = 1;
        modificarImpactos(primero,-1);
        modificarPunt(juego,ePuntuacion(primero));
      }
    }
    primero=primero->siguiente;
  }
  if (pego == 0)
    {
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
          *haChocado = 0;
        }
      else 
        {
          *dirY = -(*dirY)*velocidad;
          *haChocado = 0;
        }
    }
  else    // Pelota Baja
    {
      // Chequear si pelota choca con base
      int proximidadY = *despPelotaY - 0.05 <= 0.12;
      GLfloat dist = 0.0;
      if (proximidadY)
        {
          // Choca la barra
          if (*despPelotaX <= (*xDisparador + 0.25) && 
              *despPelotaX >= (*xDisparador - 0.25))
            {
              if (!(*haChocado)) 
                {
                  float rangoDisp = 0.5/3.0;
                  // Cambio de direccion de tiro
                  // Si viene desde la izquierda
                  if (*dirX > 0)
                    {
                      // Pelota pega en el centro del disparador
                      if (*despPelotaX >= *xDisparador - rangoDisp &&
                          *despPelotaX <= *xDisparador + rangoDisp)
                        {
                          *dirY = -(*dirY);
                        }
                      // Pega en la parte izquierda del disparador
                      if (*despPelotaX >= *xDisparador - 0.25 &&
                          *despPelotaX <= *xDisparador - rangoDisp)
                        {
                          // Se rota el vector +5
                          rotarVector(grado, 5, dirX, dirY, velocidad);
                          *dirX = -(*dirX);
                        }
                      // Pega en la parte derecha del disparador
                      if (*despPelotaX <= *xDisparador + 0.25 &&
                          *despPelotaX >= *xDisparador + rangoDisp)
                        {
                          // Se rota el vector -5
                          rotarVector(grado,-5, dirX, dirY, velocidad);
                          *dirX = -(*dirX);
                        }
                    }
                  // Pelota viene desde la derecha
                  if (*dirX < 0)
                    {
                      // Pelota pega en el centro del disparador
                      if (*despPelotaX >= *xDisparador - rangoDisp &&
                          *despPelotaX <= *xDisparador + rangoDisp)
                        {
                          *dirY = -(*dirY);
                        }
                      // Pega en la parte izquierda del disparador
                      if (*despPelotaX >= *xDisparador - 0.25 &&
                          *despPelotaX <= *xDisparador - rangoDisp)
                        {
                          // Se rota el vector -5
                          rotarVector(grado,-5, dirX, dirY, velocidad);
                          *dirX = -(*dirX);
                        }
                      // Pega en la parte derecha del disparador
                      if (*despPelotaX <= *xDisparador + 0.25 &&
                          *despPelotaX >= *xDisparador + rangoDisp)
                        {
                          // Se rota el vector +5
                          rotarVector(grado,5, dirX, dirY, velocidad);
                          *dirX = -(*dirX);
                        }
                    }
                  *haChocado = 1;
                }
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
          *despPelotaY += *dirY; 
          *haChocado = 0;
        }
    }
    }
  glTranslatef(*despPelotaX,*despPelotaY,0.0);
  dibujarPelota();
  glutPostRedisplay();
  return;
}

