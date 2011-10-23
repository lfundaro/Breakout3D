#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
  FILE *archivo;
  char caracter[100];
  char *caracter2;
  char *caracter3;
  char separador[] = " ";
  char separador2[] = ".";
  char separador3[] = ",";
  int tmpVida;
  int tmpFrio;
  int tmpSalto;
  int tmpNivel;
  char *tmpNombre;
  int tmpImpactos;
  float tmpVelocidad;
  int tmpBloques;
  int i,j;
  int tmpFila,tmpColumna;
  char tmpColor;

  archivo = fopen("CONFIGURACION","r");
  if (archivo == NULL){
    printf("\nNo se consigue el archivo de confifuracion.\n\n");
  }else{
    fgets(caracter,100,archivo);
    tmpVida = atoi (caracter);
    printf("Vida: %d\n",tmpVida);

    fgets(caracter,100,archivo);
    tmpFrio = atoi (caracter);
    printf("Frio: %d\n",tmpFrio);

    fgets(caracter,100,archivo);
    tmpSalto = atoi (caracter);
    printf("Salto: %d\n",tmpSalto);

    fgets(caracter,100,archivo);
    tmpNivel = atoi (caracter);
    printf("Niveles: %d\n",tmpNivel);
    i = 0;
    while (i < tmpNivel) {
      fgets(caracter,100,archivo);
      printf("\nNombre del Nivel: %s",caracter);
      fgets(caracter,100,archivo);
      caracter2 = strtok(caracter, separador);
      tmpImpactos = atoi(caracter2);
      printf("Impactos: %d\n",tmpImpactos);
      caracter2 = strtok(NULL,separador);
      caracter3 = strtok(caracter2,separador2);
      //      caracter3 = strtok(caracter3,separador3);
      tmpBloques = atoi(caracter3);;
      caracter3 = strtok(NULL,separador2);
      tmpVelocidad = ((float)(tmpBloques))+((float)(0.1* atoi(caracter3)));
      printf("Velocidad: %.2f\n",tmpVelocidad);
      fgets(caracter,100,archivo);
      tmpBloques = atoi(caracter);
      printf("Bloques(%d):\n",tmpBloques);
      j=0;
      while (j < tmpBloques) {
	fgets(caracter,100,archivo);
	tmpFila = atoi(strtok(caracter,separador));
	tmpColumna= atoi(strtok(NULL,separador));
	caracter2 = strtok(NULL,separador);
	tmpColor = caracter2[0];
	printf("(%d,%d,%c)\n",tmpFila,tmpColumna,tmpColor);
	j++;
      }
      i++;
      
    }
  }
  printf("Carga exitosa\n");
  fclose(archivo);
  return 0;
}
