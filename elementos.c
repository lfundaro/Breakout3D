#include "elementos.h"
#include "Nivel.h"

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
moverPelota(GLfloat *speedX, GLfloat *speedY, GLfloat *despPelotaX,
            GLfloat *despPelotaY, GLfloat *despDisparadorX,
            GLint *movInicial)
{
  if (*movInicial)
    *despPelotaX += *despDisparadorX;
  *movInicial = 0;
  if (*speedY >= 0)
    {
      // Límite Banda Superior
      if (*despPelotaY < 5.495) 
        {
          *despPelotaY += *speedY;
        }
      else 
        {
          *speedY = -*speedY;
        }
    }
  else    // Pelota Baja
    {
      // Límite Banda Inferior
      if (*despPelotaY > 0.22)
        {
          *despPelotaY += *speedY;
        }
      else 
        {
          *speedY = -*speedY;
        }
    }
  // Pelota se mueve lateralmente
  if (*speedX >= 0)
    {
      // Límite banda derecha
      if (*despPelotaX < 2.90)
        {
          *despPelotaX += *speedX;
        }
      else
        {
          *speedX = -*speedX;
        }
    }
  // Límite banda izquierda
  else      
    {
      if (*despPelotaX > 0.09)
        {
          *despPelotaX += *speedX;
        }
      else
        {
          *speedX = -*speedX;
        }
    }
  glTranslatef(*despPelotaX,*despPelotaY,0.0);
  dibujarPelota();
  glutPostRedisplay();
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
  float baseY =40*0.12;
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
  glScalef(tamX,tamY,tamZ);
  glColor3f(r,g,b);
  glutSolidCube(1);
  glColor3f(0.2,0.2,0.2);
  glLineWidth(1);
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

