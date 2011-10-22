#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);
}

void display(void)
{
  glEnable(GL_DEPTH_TEST);
  glClear (GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
  glLoadIdentity ();
  /* clear the matrix */
  /* viewing transformation */
  gluLookAt (0.0,7.0, -18.0, 0.0, -3.0, 0.0, 0.0, 1.0, 0.0);
  //gluLookAt (0.0,1.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
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


  /* Banda lateral derecha */
  glColor3f (0.4, 0.4, 0.4);
  glBegin (GL_QUADS);
  glVertex3f(1.0, -1.0, -0.1);

  glVertex3f(1.0, -1.0, 0.0);

  glVertex3f(1.0, 1.0, 0.0);

  glVertex3f(1.0, 1.0, -0.1);
  glEnd ();

  /* Banda superior */
  glColor3f (0.2, 0.2, 0.2);
  glBegin (GL_QUADS);
  glVertex3f(1.0, 1.0, -0.1);

  glVertex3f(1.0, 1.0, 0.0);

  glVertex3f(-1.0, 1.0, 0.0);

  glVertex3f(-1.0, 1.0, -0.1);
  glEnd ();

  /* Cubo disparador */ 
  glPushMatrix ();
  glTranslatef (0.0, -1.181, -0.2);
  glScalef (0.3, 0.05, 0.01);
  glColor3f (0.0, 0.0, 1.0);
  glutSolidCube(1.0);
  
  glRotatef (90.0, 0.0, 1.0, 0.0);
  glBegin (GL_LINE_LOOP);
  glColor3f (1.0, 0.0, 0.0);
  glVertex3f (-1.0,0.0,0.0);
  glVertex3f (0.0,-1.0,0.0);
  glVertex3f (1.0,0.0,0.0);
  glVertex3f (0.0,1.0,0.0);
  glEnd ();
 
  glPopMatrix ();


  
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
  glutMainLoop();
  return 0;
}
