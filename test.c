/* #include <GL/gl.h> */
/* #include <GL/glu.h> */
/* #include <GL/glut.h> */


/* void reshape (int w, int h) */
/* { */
/*   float aspectratio; */
/*   aspectratio = (float) w / (float) h; */
/*   glViewport (0, 0, (GLsizei) w, (GLsizei) h); */
/*   glMatrixMode (GL_PROJECTION); */
/*   glLoadIdentity(); */
/*   gluPerspective(60.0f, aspectratio, 0.5, 20.0); */
/*   glMatrixMode(GL_MODELVIEW); */
/* } */

/* void  */
/* display(void)  */
/* { */
/*   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); */
/*   glMatrixMode(GL_MODELVIEW); */
/*   glLoadIdentity(); */
/*   gluLookAt (0.0, -3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); */
/*   glTranslatef(-1.5,-2.0,0.0); */

/*   glPointSize(10); */
/*   glColor3d(1.0,0.0,0.0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3d(0.0,0.0,0.0); */
/*   glVertex3d(0.0,7.0,0.0); */
/*   glVertex3d(3.0,7.0,0.0); */
/*   glVertex3d(3.0,0.0,0.0); */
/*   glEnd(); */

/*   glPushMatrix(); */
/*   glColor3d(0.0,1.0,0.0); */
/*   glPushMatrix(); */
/*   glTranslated(0.5,0.1,0.1); */
/*   glScaled(1.0,0.2,0.2); */
/*   glutSolidCube(1); */
/*   glLineWidth(5); */
/*   glColor3f(0.0,0.0,0.0); */
/*   glutWireCube(1); */
/*   glPopMatrix(); */

/*   glutSwapBuffers(); */
/*   glFlush(); */
/*   return; */
/* } */

/* int main(int argc, char** argv) { */
/*   /\* Inicialización de ventana *\/ */
/*   glutInit(&argc, argv); */
/*   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB |  GLUT_DEPTH); */
/*   glutInitWindowSize (1024, 768); */
/*   glutInitWindowPosition (100, 150); */
/*   glutCreateWindow (argv[0]); */
/*   /\* Propiedades de openGL *\/ */
/*   glEnable(GL_DEPTH_TEST); */
/*   glClearDepth (1.0f); */
/*   glClearColor(0,0,0,1.0f); */
/*   glShadeModel(GL_SMOOTH);  */
/*   glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST); */
/*   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  */
/*   /\* Directivas para graficar *\/ */
/*   glutReshapeFunc(reshape); */
/*   glutDisplayFunc(display); */
/*   glutSpecialFunc(procesarTeclas); */
/*   glutKeyboardFunc(keyboard); */
/*   glutMainLoop(); */
/*   return 0; */
/* } */



//Cubo movible
x = 0.5
y = 0.09
z = 0.09

  //disparador
y = 0.09
z = 0.099
x = 0.2

  // Tablero
x = 3.0
y = 5.5


