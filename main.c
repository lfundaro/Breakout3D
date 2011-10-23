#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float desplazamiento = 0.0;

void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);
}

void display(void)
{
  glEnable(GL_DEPTH_TEST);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity ();
  /* clear the matrix */
  /* viewing transformation */
  gluLookAt (0.0,7.0, -18.0, 0.0, -3.0, 0.0, 0.0, 1.0, 0.0);
  //gluLookAt (0.0,1.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
  dibujarTablero (desplazamiento);
  

  /* glPushMatrix(); */
  /* float i; */
  /* glColor3f (0.0, 0.0, 0.0); */
  /* for (i = 1.0; i > 0.7; i = i - 0.1) */
  /*   { */
  /*     glLoadIdentity(); */
  /*     glScalef (11.0, 27.5, 11.0); */
  /*     glRotatef (80.0, 1.0, 0.0, 0.0);  */
  /*     glBegin (GL_LINE_LOOP); */
  /*     glVertex3f(i,i,0.0); */
  /*     glVertex3f(-i,i,0.0); */
  /*     glVertex3f(-i,-i,0.0); */
  /*     glVertex3f(i,-i,0.0); */
  /*     glEnd(); */
  /*   } */
  /* glPopMatrix(); */

  /* Contorno Tablero base */

  glutSwapBuffers();
  glFlush ();
}

void reshape (int w, int h)
{
  glEnable(GL_DEPTH_TEST);
  float aspectratio;
  aspectratio = (float) w / (float) h;
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(100.0f, aspectratio, 1.0, 400.0);
  glMatrixMode (GL_MODELVIEW);
}

void 
teclaIzquierda ()
{
  desplazamiento += 0.05;
  return;
}

void
teclaDerecha ()
{
  desplazamiento -= 0.05;
  return;
}

void
procesarTeclas (int key, int x, int y) 
{
  switch (key)
    {
    case GLUT_KEY_LEFT:
      teclaIzquierda ();
      break;
    case GLUT_KEY_RIGHT:
      teclaDerecha ();
      break;
    default:
      break;
    }
  return;
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB |  GLUT_DEPTH);
  glutInitWindowSize (1024, 768);
  glutInitWindowPosition (100, 150);
  glutCreateWindow (argv[0]);
  init ();
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(display);
  glutSpecialFunc(procesarTeclas);
  glutMainLoop();
  return 0;
}
