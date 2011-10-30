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
cambiarDireccion(GLfloat *dirX, GLfloat *dirY)
{
  float grado = (float) (rand() % 11 + 85);
  *dirX = fabsf(cosf(grado));
  *dirY = fabsf(sinf(grado));
  // Regular velocidad
  *dirX = *dirX/(10);
  *dirY = *dirY/(10);
  printf ("dirY = %f\n",*dirY);
  printf ("dirX = %f\n",*dirX);
  return;
}

void
moverPelota(GLfloat *dirX, GLfloat *dirY, GLfloat *despPelotaX,
            GLfloat *despPelotaY, GLfloat *despDisparadorX,
            GLint *movInicial, GLfloat *xDisparador, 
            GLfloat *yDisparador, GLint *vidas)
{
  if (*movInicial)
    *despPelotaX += *despDisparadorX;
  *movInicial = 0;
  if (*dirY >= 0)
    {
      // Límite Banda Superior
      if (*despPelotaY < 5.495) 
        {
          *despPelotaY += *dirY;
        }
      else 
        {
          *dirY = -*dirY;
        }
    }
  else    // Pelota Baja
    {
      // Límite Banda Inferior
      if (*despPelotaY > 0.22)
        {
          *despPelotaY += *dirY;
        }
      else 
        {
          *dirY = -*dirY;
        }
    }
  // Pelota se mueve lateralmente
  if (*dirX >= 0)
    {
      // Límite banda derecha
      if (*despPelotaX < 2.90)
        {
          *despPelotaX += *dirX;
        }
      else
        {
          *dirX = -*dirX;
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
          *dirX = -*dirX;
        }
    }
  glTranslatef(*despPelotaX,*despPelotaY,0.0);
  // Chequear si pelota choca con base
  int proximidadY = fabs(*despPelotaY - 0.20) <= 0.01;
  //  printf ("proximidad %d\n",proximidad);
  GLfloat dist = 0.0;
  if (proximidadY)
    {
      //      printf("PelotaY = %f \n",*despPelotaY);
      // printf ("Xdisparador = %f\n",*xDisparador);
      //      dist = fabsf(*despPelotaX + 0.05 - (*xDisparador - 0.25);
      printf ("coordX Pelota = %f\n",*despPelotaX);
      printf ("coordX Disparador = %f\n",*xDisparador);
      if (*despPelotaX <= (*xDisparador + 0.25) && 
          *despPelotaX >= (*xDisparador - 0.25))
        {
          // Cambio de direccion de tiro
           /* float grado; */
           /* grado = (float) (rand() % 11 + 85); */
           /* printf ("grado = %f\n",grado); */
           /* *dirX = cosf(grado)*(*dirX); */
           /* *dirY = sinf(grado)*(*dirY); */
           /* printf ("dirY = %f\n",*dirY); */
           /* printf ("dirX = %f \n", *dirX); */
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



/* void */
/* Pelota (double despPelota)  */
/* { */
/*   glColor3f(0.4,0.4,0.4); */
/*   glPushMatrix(); */
/*   glutSolidSphere(0.1,50,50); */
/*   glPopMatrix(); */
/*   return; */
/* } */



/*   glPushMatrix(); */
/*   glColor3d(0.0,1.0,0.0); */
/*   glPushMatrix(); */
/*   glTranslated(0.5,0.1,0.1); */
/*   glScaled(1.0,0.2,0.2); */
/*   glutSolidCube(1); */
/*   glLineWidth(5); */
/*   glColor3f(0.0,0.0,0.0); */
/*   glutWireCube(1); */
/*   glPopMatrix(); */


/* void */
/* cuboMovible (double desp) */
/* { */
/*   float tmpColumna= 4.5; */
/*   float tmpFila = 36.5*.4; */
/*   glScalef(0.49,0.2,0.2); */
/*   glTranslatef(-4.45+tmpColumna,0.5f,-29+5+(tmpFila*3)); */
/*   glColor3f(.3,.3,1); */
/*   glutSolidCube(1); */
/*   // Contorno */
/*   glColor3f(0.8,0.8,0.8); */
/*   glLineWidth(3); */
/*   glutWireCube(1); */
/*   // Disparador */
/*   glTranslatef(0.0,0.1,-0.05); */
/*   glScalef(0.5,1.0,0.9); */
/*   glColor3f(1.0,0.0,0.0); */
/*   glutSolidCube(1.0); */


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



 
/*
  // Cubo movible //
  // Cara trasera
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_QUADS);
  glVertex3f(0.5,0.0,0.5); // v3
  glVertex3f(0.5,0.2,0.5);
  glVertex3f(-0.5,0.2,0.5);
  glVertex3f(-0.5,0.0,0.5); // v2
  glEnd();

  // Techo
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_QUADS);
  glVertex3f(0.5,0.2,0.5);
  glVertex3f(0.5,0.2,0.3);
  glVertex3f(-0.5,0.2,0.3);
  glVertex3f(-0.5,0.2,0.5);
  glEnd();

  //Pared Derecha
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_QUADS);
  glVertex3f(0.5,0.2,0.5);
  glVertex3f(0.5,0.2,0.3);
  glVertex3f(0.5,0.0,0.3);
  glVertex3f(0.5,0.0,0.5);
  glEnd();

  // Pared Izquierda
  glColor3f(1.0,0.5,1.0);
  glBegin(GL_QUADS);
  glVertex3f(-0.5,0.2,0.5);
  glVertex3f(-0.5,0.2,0.3);
  glVertex3f(-0.5,0.2,0.3);
  glVertex3f(-0.5,0.0,0.5);
  glEnd();

  // Pared Frontal
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_QUADS);
  glVertex3f(0.5,0.2,0.3);
  glVertex3f(-0.5,0.2,0.3);
  glVertex3f(-0.5,0.0,0.3);
  glVertex3f(0.5,0.0,0.3);
  glEnd();

  // FIN Cubo movible //

  // Bordes Cubo movible //
  // Cara trasera
  glLineWidth(2);
  glColor3f (0.0, 0.0, 0.0);
  glBegin (GL_LINE_LOOP);
  glVertex3f(0.5,0.0,0.5); // v3
  glVertex3f(0.5,0.2,0.5);
  glVertex3f(-0.5,0.2,0.5);
  glVertex3f(-0.5,0.0,0.5); // v2
  glEnd();

  // Techo 
  glLineWidth(2);
  glTranslatef(0.0,0.0,2.1);
  glColor3f (0.0, 0.0, 0.0);
  glBegin (GL_LINE_LOOP);
  glVertex3f(0.5,0.2,0.5);
  glVertex3f(0.5,0.2,0.3);
  glVertex3f(-0.5,0.2,0.3);
  glVertex3f(-0.5,0.2,0.5);
  glEnd();

  // Banda Izquierda
  glLineWidth(2);
  glTranslatef(0.0,0.0,2.1);
  glColor3f (0.0, 0.0, 0.0);
  glBegin (GL_LINE_LOOP);
  glVertex3f(-0.5,0.2,0.5);
  glVertex3f(-0.5,0.2,0.3);
  glVertex3f(-0.5,0.2,0.3);
  glVertex3f(-0.5,0.0,0.5);
  glEnd();

  // Banda Derecha
  glLineWidth(2);
  glTranslatef(0.0,0.0,2.1);
  glColor3f (0.0, 0.0, 0.0);
  glBegin (GL_LINE_LOOP);
  glVertex3f(0.5,0.2,0.5);
  glVertex3f(0.5,0.2,0.3);
  glVertex3f(0.5,0.0,0.3);
  glVertex3f(0.5,0.0,0.5);
  glEnd();
*/
  



/* void dibujarTablero () */
/* { */
/*   /\* Tablero base *\/ */
/*   glColor3f(1.0,1.0,1.0); */
/*   glPushMatrix(); */
/*   glTranslatef(0.0,0.0,-1); */
/*   glScalef(2.5,0.0,5.1); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(1.0,0.0,-1.0); // vo */
/*   glVertex3f(-1.0,0.0,-1.0); // v1 */
/*   glVertex3f(-1.0,0.0,1.0); // v2 */
/*   glVertex3f(1.0,0.0,1.0); // v3 */
/*   glEnd(); */
/*   glPopMatrix(); */
  
/*   /\* Banda frontal *\/ */
/*   glPushMatrix(); */
/*   glColor3f(1.0,0.0,0.0); */
/*   glTranslatef(0.0,0.0,-5); */
/*   glScalef(2.5,1.0,1.0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(1.0,0.0,-1.0); // vo */
/*   glVertex3f(1.0,0.2,-1.0); // v4 */
/*   glVertex3f(-1.0,0.2,-1.0); // v5 */
/*   glVertex3f(-1.0,0.0,-1.0); // v1 */
/*   glEnd(); */
/*   glPopMatrix(); */

/*   /\* Contorno Banda superior *\/ */
/*   glPushMatrix(); */
/*   glLineWidth(2); */
/*   glColor3f (0.0, 0.0, 0.0); */
/*   glTranslatef(0.0,0.0,-4.98); */
/*   glScalef(2.5,1.1,1.0); */
/*   glBegin (GL_LINE_LOOP); */
/*   glVertex3f(1.0,0.0,-1.0); // vo */
/*   glVertex3f(1.0,0.2,-1.0); // v4 */
/*   glVertex3f(-1.0,0.2,-1.0); // v5 */
/*   glVertex3f(-1.0,0.0,-1.0); // v1 */
/*   glEnd(); */
/*   glPopMatrix(); */

/*   /\* Banda lateral izquierda *\/ */
/*   glPushMatrix(); */
/*   glColor3f(1.0,0.0,0.0); */
/*   glTranslatef(-1.5,0.0,-0.9); */
/*   glScalef(1.0,1.0,5.0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(-1.0,0.0,-1.0); // v1 */
/*   glVertex3f(-1.0,0.2,-1.0); // v7 */
/*   glVertex3f(-1.0,0.2,1.0); // v6 */
/*   glVertex3f(-1.0,0.0,1.0); // v2 */
/*   glEnd(); */
/*   glPopMatrix(); */

/*   /\* Contorno Banda lateral izquierda *\/ */
/*   glPushMatrix(); */
/*   glColor3f (0.0, 0.0, 0.0); */
/*   glLineWidth(2); */
/*   glTranslatef(-1.48,0.1,-0.9); */
/*   glScalef(1.0,1.0,5.0); */
/*   glBegin (GL_LINE_LOOP); */
/*   glVertex3f(-1.0,0.0,-1.0); // v1 */
/*   glVertex3f(-1.0,0.2,-1.0); // v7 */
/*   glVertex3f(-1.0,0.2,1.0); // v6 */
/*   glVertex3f(-1.0,0.0,1.0); // v2 */
/*   glEnd(); */
/*   glPopMatrix(); */


/*   /\* Banda lateral derecha *\/ */
/*   glPushMatrix(); */
/*   glColor3f(1.0,0.0,0.0); */
/*   glTranslatef(1.5,0.0,-0.9); */
/*   glScalef(1.0,1.0,5.0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(1.0,0.0,-1.0); // vo */
/*   glVertex3f(1.0,0.2,-1.0); // v8 */
/*   glVertex3f(1.0,0.2,1.0); // v9 */
/*   glVertex3f(1.0,0.0,1.0); // v3 */
/*   glEnd(); */
/*   glPopMatrix(); */

/*   /\* Contorno Banda lateral derecha *\/ */
/*   glPushMatrix(); */
/*   glColor3f (0.0, 0.0, 0.0); */
/*   glLineWidth(2); */
/*   glTranslatef(1.45,0.1,-0.9); */
/*   glScalef(1.0,1.0,5.0); */
/*   glBegin (GL_LINE_LOOP); */
/*   glVertex3f(1.0,0.0,-1.0); // vo */
/*   glVertex3f(1.0,0.2,-1.0); // v8 */
/*   glVertex3f(1.0,0.2,1.0); // v9 */
/*   glVertex3f(1.0,0.0,1.0); // v3 */
/*   glEnd(); */
/*   glPopMatrix(); */
/* } */

