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
  
}

void 
resizeWindow (int w, int h)
{
  float aspectratio;
  
  if (h == 0) 
    {
      h = 1;
    }

  glViewport (0, 0, w, h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();

  aspectratio = (float) w / (float) h;

  if (w <= h) 
    {
      glOrtho (-10, 10, -10/aspectratio, 10/aspectratio, 1.0, -1.0);
    }
  else 
    {
      glOrtho (-10*aspectratio, 10*aspectratio, -10, 10, 1.0, -1.0);
    }
  return;
}

int 
main (int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitWindowSize (900, 900);
  glutInitWindowPosition (0, 0);
  glutCreateWindow ("Breakout 3D");
  init (); // Limpia colores en ventana
  glutDisplayFunc (display);
  glutReshapeFunc (resizeWindow);
  
  glutMainLoop ();
}
