#include "elementos.h"

void 
dibujarTablero (float desplazamiento)
{
  /* Tablero base */
  glColor3f(1.0,1.0,1.0);
  glPushMatrix();
  glTranslatef(0.0,0.0,-0.6);
  glScalef(2.5,0.0,3.2);
  glBegin(GL_QUADS);
  glVertex3f(1.0,0.0,-1.0); // vo
  glVertex3f(-1.0,0.0,-1.0); // v1
  glVertex3f(-1.0,0.0,1.0); // v2
  glVertex3f(1.0,0.0,1.0); // v3
  glEnd();
  glPopMatrix();
  
  /* Banda frontal */
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glTranslatef(0.0,0.0,-2.8);
  glScalef(2.5,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex3f(1.0,0.0,-1.0); // vo
  glVertex3f(1.0,0.2,-1.0); // v4
  glVertex3f(-1.0,0.2,-1.0); // v5
  glVertex3f(-1.0,0.0,-1.0); // v1
  glEnd();
  glPopMatrix();

  /* Contorno Banda superior */
  glPushMatrix();
  glLineWidth(2);
  glColor3f (0.0, 0.0, 0.0);
  glTranslatef(0.0,0.0,-2.77);
  glScalef(2.5,1.1,1.0);
  glBegin (GL_LINE_LOOP);
  glVertex3f(1.0,0.0,-1.0); // vo
  glVertex3f(1.0,0.2,-1.0); // v4
  glVertex3f(-1.0,0.2,-1.0); // v5
  glVertex3f(-1.0,0.0,-1.0); // v1
  glEnd();
  glPopMatrix();

  /* Banda lateral izquierda */
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glTranslatef(-1.5,0.0,-0.6);
  glScalef(1.0,1.0,3.2);
  glBegin(GL_QUADS);
  glVertex3f(-1.0,0.0,-1.0); // v1
  glVertex3f(-1.0,0.2,-1.0); // v7
  glVertex3f(-1.0,0.2,1.0); // v6
  glVertex3f(-1.0,0.0,1.0); // v2
  glEnd();
  glPopMatrix();

  /* Contorno Banda lateral izquierda */
  glPushMatrix();
  glColor3f (0.0, 0.0, 0.0);
  glLineWidth(2);
  glTranslatef(-1.45,0.1,-0.5);
  glScalef(1.0,1.0,3.2);
  glBegin (GL_LINE_LOOP);
  glVertex3f(-1.0,0.0,-1.0); // v1
  glVertex3f(-1.0,0.2,-1.0); // v7
  glVertex3f(-1.0,0.2,1.0); // v6
  glVertex3f(-1.0,0.0,1.0); // v2
  glEnd();
  glPopMatrix();


  /* Banda lateral derecha */
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glTranslatef(1.5,0.0,-0.6);
  glScalef(1.0,1.0,3.2);
  glBegin(GL_QUADS);
  glVertex3f(1.0,0.0,-1.0); // vo
  glVertex3f(1.0,0.2,-1.0); // v8
  glVertex3f(1.0,0.2,1.0); // v9
  glVertex3f(1.0,0.0,1.0); // v3
  glEnd();
  glPopMatrix();

  /* Contorno Banda lateral derecha */
  glPushMatrix();
  glColor3f (0.0, 0.0, 0.0);
  glLineWidth(2);
  glTranslatef(1.45,0.1,-0.5);
  glScalef(1.0,1.0,3.2);
  glBegin (GL_LINE_LOOP);
  glVertex3f(1.0,0.0,-1.0); // vo
  glVertex3f(1.0,0.2,-1.0); // v8
  glVertex3f(1.0,0.2,1.0); // v9
  glVertex3f(1.0,0.0,1.0); // v3
  glEnd();
  glPopMatrix();

  /* Cubo movible */ 
  glPushMatrix();
  glTranslatef(0.0,1.4,2.49);
  glScalef(0.6,0.5,0.2);
  glColor3f(0.0,0.0,1.0);
  glutSolidCube(1);
  glColor3f(0.0,0.0,0.0);
  glLineWidth(2);
  glutWireCube(1);
  glPopMatrix();

}
