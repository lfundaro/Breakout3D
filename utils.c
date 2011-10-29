#include "utils.h"


int choqueConBase(GLfloat despPelotaX, GLfloat despPelotaY, GLfloat xDisparador, GLfloat yDisparador) {
  //Pelota a nivel de cubo
  if (fabsf(despPelotaY - (float) 0.21) == 0.0)
    {
      printf("Cubo a nivel\n");
      GLfloat dist = fabsf(despPelotaX + 0.05 - xDisparador);
      if (dist > 0.15)
        {
          return -1;
        }
    }
  else
    {
      return 0;
    }
}
