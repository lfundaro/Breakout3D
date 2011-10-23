#include "elementos.h"

void 
dibujarTablero (float desplazamiento)
{
  glScalef (11.0, 27.5, 11.0);
  glRotatef (80.0, 1.0, 0.0, 0.0); 
  /* Tablero base */
  glColor3f (1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
  glVertex3f(1.0,1.0,0.0);
  glVertex3f(-1.0,1.0,0.0);
  glVertex3f(-1.0,-1.0,0.0);
  glVertex3f(1.0,-1.0,0.0);
  glEnd();

  /* Banda lateral izquierda */
  glColor3f (0.4, 0.4, 0.4);
  glBegin (GL_QUADS);
  glVertex3f(-1.0, -1.0, -0.1);
  glVertex3f(-1.0, -1.0, 0.0);
  glVertex3f(-1.0, 1.0, 0.0);
  glVertex3f(-1.0, 1.0, -0.1);
  glEnd ();

  /* Contorno Banda lateral izquierda */

  glColor3f (0.0, 0.0, 0.0);
  glBegin (GL_LINE_LOOP);
  glVertex3f(-1.0, -1.0, -0.1);
  glVertex3f(-1.0, -1.0, 0.0);
  glVertex3f(-1.0, 1.0, 0.0);
  glVertex3f(-1.0, 1.0, -0.1);
  glEnd();

  /* Banda lateral derecha */
  glColor3f (0.4, 0.4, 0.4);
  glBegin (GL_QUADS);
  glVertex3f(1.0, -1.0, -0.1);
  glVertex3f(1.0, -1.0, 0.0);
  glVertex3f(1.0, 1.0, 0.0);
  glVertex3f(1.0, 1.0, -0.1);
  glEnd ();

  /* Contorno Banda lateral derecha */
  glColor3f (0.0, 0.0, 0.0);
  glBegin (GL_LINE_LOOP);
  glVertex3f(1.0, -1.0, -0.1);
  glVertex3f(1.0, -1.0, 0.0);
  glVertex3f(1.0, 1.0, 0.0);
  glVertex3f(1.0, 1.0, -0.1);
  glEnd();

  /* Banda superior */
  glColor3f (0.2, 0.2, 0.2);
  glBegin (GL_QUADS);
  glVertex3f(1.0, 1.0, -0.1);
  glVertex3f(1.0, 1.0, 0.0);
  glVertex3f(-1.0, 1.0, 0.0);
  glVertex3f(-1.0, 1.0, -0.1);
  glEnd ();
  
  /* Contorno Banda superior */
  glColor3f (0.0, 0.0, 0.0);
  glBegin (GL_LINE_LOOP);
  glVertex3f(1.0, 1.0, -0.1);
  glVertex3f(1.0, 1.0, 0.0);
  glVertex3f(-1.0, 1.0, 0.0);
  glVertex3f(-1.0, 1.0, -0.1);
  glEnd();

  /* Cubo disparador */ 
  glPushMatrix ();
  glTranslatef (desplazamiento, -1.181, -0.2);
  glScalef (0.3, 0.05, 0.01);
  glColor3f (0.0, 0.0, 1.0);
  glutSolidCube(1.0);
  glColor3f (0.0, 0.0, 0.0);
  glutWireCube(1.0);
  glutWireCube(1.008);
  glPopMatrix ();

  /* glPushMatrix (); */
  /* glTranslatef (0.0, -1.178, -0.2); */
  /* //  glScalef (0.5, 0.05, 0.01); */
  /* glScalef (0.08, 0.06, 0.02); */
  /* //  glScalef (0.5, 0.05, 0.002); */
  /* glColor3f (1.0, 0.0, 0.0); */
  /* glutSolidCube (1.0); */
  /* //  glColor3f (0.0, 0.0, 0.0); */
  /* //  glutWireCube (1.0); */
  /* //  glutWireCube (1.008); */
  /* glPopMatrix (); */


  /* /\* Disparador *\/ */
  /* glPushMatrix (); */
  /* glTranslatef (0.0, -1.181, -0.21); */
  /* glScalef (0.07, 0.07, 0.009); */
  /* glColor3f (1.0, 0.0, 0.0); */
  /* glutSolidCube(1.0); */
  /* glPopMatrix (); */
}
