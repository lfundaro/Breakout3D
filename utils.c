#include "utils.h"
#include <math.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


int cmpCoord2D(double despPelotaX, double despPelotaZ, float cuboX, float cuboZ) {
  /* if (abs(cuboX + 1.0 - despPelotaX) > 0.1 && despPelotaZ >= 0.0 && */
  /*     abs(cuboZ - despPelotaZ + 0.1) < 0.1) { */
  /*   return 0; */
  /* } */
  if (despPelotaZ >= 0.0) {
    double diff = fabs(despPelotaZ + 0.05 - 3.7);
    if (diff >= 0.0 && diff < 0.001) {
      printf ("CuboX = %f\n",cuboX);
      printf ("X = %f\n",despPelotaX);
      double absCubo = fabs(cuboX);
      double absPelotaX = fabs(despPelotaX);
      if (absPelotaX <= absCubo + 0.25 &&
          absPelotaX >= absCubo - 0.25)
        return 0;
      else 
        return -1;
      /* // Caso pelota a la derecha del cubo */
      /* if (absPelotaX - 0.05 > absCubo + 0.25) { */
      /*   return -1; */
      /*   printf ("Pelota a la derecha\n"); */
      /* } */
      /* // Caso pelota la izquierda del cubo */
      /* if (absPelotaX + 0.05 < absCubo - 0.25) { */
      /*   printf("pelota a la izquierda\n"); */
      /*   return -1; */
      /* } */
      /* // Caso pelota entre dos extremos del cubo */
      /* if (absPelotaX >= absCubo - 0.25 &&  */
      /*     absPelotaX <= absCubo + 0.25) { */
      /*   printf("pelota entre extremos\n"); */
      /*   return 0; */
      /* } */
      

    /* double dist = fabs(despPelotaX - cuboX + 0.25); */
    /* printf ("Distancia X = %f \n", dist); */
    /* if (dist >= fabs(cuboX) && dist <= fabs(cuboX) + 0.25) { */
    /*   return -1; */
    /*   //      if ((abs(cuboX) + 1.0) > abs(despPelotaX)) */
    /*   /\* if (despPelotaX < 0.0) { *\/ */
    /*   /\*   if (abs(cuboX - 1.0) - despPelotaX)  *\/ */
    /*   /\* } *\/ */
    /*   /\* else { // despPelotaX >= 0 *\/ */
        
    /*   /\* } *\/ */
    /* } */
    /* else return 0; */
    /* } */
    }
  }
  return 0;
}
