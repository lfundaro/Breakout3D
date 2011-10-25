#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float desplazamiento = 0.0;

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  /* clear the matrix */
  /* viewing transformation */
  //  gluLookAt (0.0,7.0, -18.0, 0.0, -3.0, 0.0, 0.0, 1.0, 0.0);
  //gluLookAt (0.0,10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
  dibujarTablero (desplazamiento);
  

  //  glutSwapBuffers();
  glFlush ();
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


void reshape (int w, int h)
{
  float aspectratio;
  aspectratio = (float) w / (float) h;
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  gluPerspective(60.0f, aspectratio, 2.0f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
  /* Inicialización de ventana */
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB |  GLUT_DEPTH);
  //  glutInitWindowSize (1024, 768);
  glutInitWindowSize (800, 600);
  glutInitWindowPosition (100, 150);
  glutCreateWindow (argv[0]);
  /* Propiedades de openGL */
  glEnable(GL_DEPTH_TEST);
  glClearDepth (1.0f);
  glClearColor(0,0,0,1.0f);
  glShadeModel(GL_SMOOTH); 
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
  /* Directivas para graficar */
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  //glutSpecialFunc(procesarTeclas);
  glutMainLoop();
  return 0;
}
