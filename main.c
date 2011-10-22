#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void
init ()
{
  glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
  glClear (GL_COLOR_BUFFER_BIT);
  return;
}

void
display ()
{
  glColor3f (1.0, 1.0, 1.0);
  glLoadIdentity ();
  glScalef (1.0, 1.0, 1.0);
  glutWireCube (1.0);
  glFlush ();
  
}

void 
reshape (int w, int h)
{
  float aspectratio;
  
  if (h == 0) 
    {
      h = 1;
    }

  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0 );
  aspectratio = (float) w / (float) h;

  if (w <= h) 
    {
      glOrtho (-10, 10, -10/aspectratio, 10/aspectratio, 1.0, -1.0);
    }
  else 
    {
      glOrtho (-10*aspectratio, 10*aspectratio, -10, 10, 1.0, -1.0);
    }
  glMatrixMode (GL_MODELVIEW);
  return;
}

int 
main (int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (900, 900);
  glutInitWindowPosition (200, 200);
  glutCreateWindow (argv[0]);
  init (); // Limpia colores en ventana
  glutDisplayFunc (display);
  glutReshapeFunc (reshape);
  
  glutMainLoop ();
  return 0;
}
