#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Nivel.h"

LisNivel *cargarInfo(){
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
  int tmpNumNivel;
  char tmpNombre[100];
  int tmpImpactos;
  float tmpVelocidad;
  int tmpNumBloques;
  int i,j;
  int tmpFila,tmpColumna;
  char tmpColor;
  LisBloque *tmpBloques;
  Bloque *tmpBloque;
  ElemBloque *tmpeBloque;
  LisNivel *tmpNiveles;
  Nivel *tmpNivel;
  ElemNivel *tmpeNivel;
  archivo = fopen("CONFIGURACION","r");
  if (archivo == NULL){
    tmpNiveles = (LisNivel*)malloc(sizeof(LisNivel));
    iniLisNivel(tmpNiveles,0,0,0);
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
    tmpNumNivel = atoi (caracter);
    printf("Niveles: %d\n",tmpNumNivel);
    tmpNiveles = (LisNivel*)malloc(sizeof(LisNivel));
    iniLisNivel(tmpNiveles,tmpVida,tmpFrio,tmpSalto);
    i = 0;
    while (i < tmpNumNivel) {
      fgets(tmpNombre,100,archivo);
      printf("\nNombre del Nivel: %s",tmpNombre);
      fgets(caracter,100,archivo);
      caracter2 = strtok(caracter, separador);
      tmpImpactos = atoi(caracter2);
      printf("Impactos: %d\n",tmpImpactos);
      caracter2 = strtok(NULL,separador);
      caracter3 = strtok(caracter2,separador2);
      //      caracter3 = strtok(caracter3,separador3);
      tmpNumBloques = atoi(caracter3);;
      caracter3 = strtok(NULL,separador2);
      tmpVelocidad = ((float)(tmpNumBloques))+((float)(0.1* atoi(caracter3)));
      printf("Velocidad: %.2f\n",tmpVelocidad);
      fgets(caracter,100,archivo);
      tmpNumBloques = atoi(caracter);
      printf("Bloques(%d):\n",tmpNumBloques);
      j=0;
      tmpBloques = (LisBloque*)malloc(sizeof(LisBloque));
      iniLisBloque(tmpBloques);
      while (j < tmpNumBloques) {
        fgets(caracter,100,archivo);
	caracter2 = strtok(caracter,separador);
        tmpFila = atoi(caracter2);
        caracter2 = strtok(NULL,separador);
	tmpColumna= atoi(caracter2);
        caracter2 = strtok(NULL,separador);
        tmpColor = caracter2[0];
        printf("(%d,%d,%c)\n",tmpFila,tmpColumna,tmpColor);

        tmpBloque = (Bloque*)malloc(sizeof(Bloque));
        iniBloque(tmpBloque,tmpFila,tmpColumna,tmpColor);
        tmpeBloque = (ElemBloque*)malloc(sizeof(ElemBloque));
        agregarBloque(tmpBloques,tmpBloque,tmpeBloque);
        j++;
      }
      tmpNivel = (Nivel*)malloc(sizeof(Nivel));
      iniNivel(tmpNivel,i,tmpNombre,tmpImpactos,tmpVelocidad,tmpBloques);
      tmpeNivel = (ElemNivel*)malloc(sizeof(ElemNivel));
      agregarNivel(tmpNiveles,tmpNivel,tmpeNivel);
      i++;
    }
    printf("Carga exitosa\n");
    fclose(archivo);
  }
  return tmpNiveles;
}
