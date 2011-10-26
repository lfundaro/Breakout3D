#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

float desplazamiento = 0.0;

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  /* clear the matrix */
  /* viewing transformation */
  // Vista inclinada
  //  gluLookAt (0.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
  //  gluLookAt (0.0, 5.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    gluLookAt (0.0, 5.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
  // Vista recta
  //gluLookAt (0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
  
  glPushMatrix();
  glTranslatef(desplazamiento,0.0,2.1);
  cuboMovible ();
  glPopMatrix();
  
  dibujarTablero (desplazamiento);
  glutSwapBuffers();
  glFlush ();
}

void 
teclaDerecha ()
{
  if (desplazamiento < 1.9)
    desplazamiento += 0.09;
  return;
}

void
teclaIzquierda ()
{
  if (desplazamiento > -1.9)
    desplazamiento -= 0.09;
  return;
}

void
keyboard (unsigned char key, int x, int y) 
{
  switch (key)
    {
    case 'a':
      teclaIzquierda ();
      glutPostRedisplay();
      break;
    case 'd':
      teclaDerecha ();
      glutPostRedisplay();
      break;
    default:
      printf("Didnt match\n");
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
  gluPerspective(60.0f, aspectratio, 0.5, 100.0);
  //  glFrustum (0.0,0.0,w,h,-20.0,200.0);
  glMatrixMode(GL_MODELVIEW);
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
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
  glutKeyboardFunc(keyboard);
  
  glutMainLoop();
  return 0;
}
