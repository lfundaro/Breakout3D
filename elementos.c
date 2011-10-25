#include "elementos.h"

void 
dibujarTablero (float desplazamiento)
{
  /* glScalef (11.0, 27.5, 11.0); */
  /* glRotatef (80.0, 1.0, 0.0, 0.0);  */
  /* Tablero base */
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity();
  //glTranslatef (0.0,0.0,-4.0);

  glPushMatrix();

  glColor3f(1.0,1.0,1.0);
  glTranslatef(0.0,0.60,-4.0);
  glRotatef(-30.0,1.0,0.0,0.0);
  glScalef(2.0,2.49,0.0);

  glBegin(GL_QUADS);
  glVertex3f(1.0,1.0,0.0);
  glVertex3f(-1.0,1.0,0.0);
  glVertex3f(-1.0,-1.0,0.0);
  glVertex3f(1.0,-1.0,0.0);
  glEnd();

  glPopMatrix();
  
  glPushMatrix();

  /* glTranslatef(0.0,0.60,-4.0); */
  /* glRotatef(-30.0,1.0,0.0,0.0); */
  /* glScalef(2.0,2.49,0.0); */

  /* glColor3f(1.0,0.0,0.0); */
  /* glBegin(GL_QUADS); */
  /* glVertex3f(-1.0,1.0,0.0); */
  /* glVertex3f(-1.0,1.0,0.0); */
  /* glVertex3f(-1.0,-1.0,0.0); */
  /* glVertex3f(-1.0,-1.0,0.0); */
  /* glEnd(); */

  /* glColor3f(1.0,0.0,0.0); */
  /* glPointSize(30); */
  /* glBegin(GL_POINT); */
  /* glVertex3f(0.0,0.0,-3.0); */
  /* glEnd(); */


  /* glBegin (GL_QUADS); */
  /* glColor3f(1.4, 0.4, 0.4); */
  /* glVertex3f(1.0,1.0,-3.0); */
  /* glVertex3f(-1.0,1.0,-3.0); */
  /* glVertex3f(-1.0,-1.0,0.0); */
  /* glVertex3f(1.0,-1.0,0.0); */
  /* glEnd(); */

  glPopMatrix();

  /* Banda lateral izquierda */

  /* glColor3f(1.0,0.0,0.0); */
  /* glPointSize(30); */
  /* glBegin(GL_POINT); */
  /* glVertex3f(0.0,0.0,1.0); */
  /* glEnd(); */

  //  glPopMatrix();

  /* glBegin (GL_QUADS); */
  /* glColor3f(1.4, 0.4, 0.4); */
  /* glVertex3f(1.0,1.0,0.0); */
  /* glVertex3f(-1.0,1.0,0.0); */
  /* glVertex3f(-1.0,-1.0,0.0); */
  /* glVertex3f(1.0,-1.0,0.0); */
  /* glEnd(); */


  //  glRotatef(-30.0,1.0,0.0,0.0);




  // PUNTO

  /* glColor3f(1.0,0.0,0.0); */
  /* glPointSize(30); */
  /* glBegin(GL_POINT); */
  /* glVertex3f(0.0,0.0,1.0); */
  /* glEnd(); */
  
  /* glColor3f (1.0, 0.0, 0.0); */
  /* glBegin(GL_QUADS); */
  /* glVertex3f(1.0,1.0,0.0); */
  /* glVertex3f(-1.0,1.0,0.0); */
  /* glVertex3f(-1.0,-1.0,0.0); */
  /* glVertex3f(1.0,-1.0,0.0); */
  /* glEnd(); */

  /* /\* Cubo disparador *\/  */
  /* glPushMatrix (); */
  /* //glLoadIdentity(); */
  /* glTranslatef (desplazamiento, -1.181, -0.1); */
  /* //glScalef (0.3, 0.05, 0.01); */
  /* glScalef (0.2, 0.5, 0.2); */
  /* glColor3f (0.0, 0.0, 1.0); */
  /* glutSolidCube(1.0); */
  /* glColor3f (0.0, 0.0, 0.0); */
  /* glutWireCube(1.0); */
  /* glutWireCube(1.008); */
  /* glPopMatrix (); */


  /* /\* Contorno Banda lateral izquierda *\/ */

  /* glColor3f (0.0, 0.0, 0.0); */
  /* glBegin (GL_LINE_LOOP); */
  /* glVertex3f(-1.0, -1.0, -0.1); */
  /* glVertex3f(-1.0, -1.0, 0.0); */
  /* glVertex3f(-1.0, 1.0, 0.0); */
  /* glVertex3f(-1.0, 1.0, -0.1); */
  /* glEnd(); */

  /* /\* Banda lateral derecha *\/ */
  /* glColor3f (0.4, 0.4, 0.4); */
  /* glBegin (GL_QUADS); */
  /* glVertex3f(1.0, -1.0, -0.1); */
  /* glVertex3f(1.0, -1.0, 0.0); */
  /* glVertex3f(1.0, 1.0, 0.0); */
  /* glVertex3f(1.0, 1.0, -0.1); */
  /* glEnd (); */

  /* /\* Contorno Banda lateral derecha *\/ */
  /* glColor3f (0.0, 0.0, 0.0); */
  /* glBegin (GL_LINE_LOOP); */
  /* glVertex3f(1.0, -1.0, -0.1); */
  /* glVertex3f(1.0, -1.0, 0.0); */
  /* glVertex3f(1.0, 1.0, 0.0); */
  /* glVertex3f(1.0, 1.0, -0.1); */
  /* glEnd(); */

  /* /\* Banda superior *\/ */
  /* glColor3f (0.2, 0.2, 0.2); */
  /* glBegin (GL_QUADS); */
  /* glVertex3f(1.0, 1.0, -0.1); */
  /* glVertex3f(1.0, 1.0, 0.0); */
  /* glVertex3f(-1.0, 1.0, 0.0); */
  /* glVertex3f(-1.0, 1.0, -0.1); */
  /* glEnd (); */
  
  /* /\* Contorno Banda superior *\/ */
  /* glColor3f (0.0, 0.0, 0.0); */
  /* glBegin (GL_LINE_LOOP); */
  /* glVertex3f(1.0, 1.0, -0.1); */
  /* glVertex3f(1.0, 1.0, 0.0); */
  /* glVertex3f(-1.0, 1.0, 0.0); */
  /* glVertex3f(-1.0, 1.0, -0.1); */
  /* glEnd(); */


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
