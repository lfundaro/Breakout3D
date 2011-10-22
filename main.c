#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glLoadIdentity ();
  /* clear the matrix */
  /* viewing transformation */
  gluLookAt (0.0,-8.0, 13.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glScalef (20.0, 20.0, 0.8);
  glRotatef (-95.0, 1.0, 0.0, 0.0); 
  /* modeling transformation */
  glutWireCube (1.0);
  glFlush ();
}

void reshape (int w, int h)
{
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
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (700, 700);
  glutInitWindowPosition (100, 150);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}

