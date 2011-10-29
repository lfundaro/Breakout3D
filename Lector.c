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
  printf("Cargando Archivo\n");
  archivo = fopen("CONFIGURACION","r");
  if (archivo == NULL){
    tmpNiveles = (LisNivel*)malloc(sizeof(LisNivel));
    iniLisNivel(tmpNiveles,0,0,0);
  }else{
    fgets(caracter,100,archivo);
    tmpVida = atoi (caracter);

    fgets(caracter,100,archivo);
    tmpFrio = atoi (caracter);

    fgets(caracter,100,archivo);
    tmpSalto = atoi (caracter);

    fgets(caracter,100,archivo);
    tmpNumNivel = atoi (caracter);
    tmpNiveles = (LisNivel*)malloc(sizeof(LisNivel));
    iniLisNivel(tmpNiveles,tmpVida,tmpFrio,tmpSalto);
    i = 0;
    while (i < tmpNumNivel) {
      fgets(tmpNombre,100,archivo);

      fgets(caracter,100,archivo);
      caracter2 = strtok(caracter,separador);
      tmpImpactos = atoi(caracter2);

      caracter2 = strtok(NULL,separador);
      caracter3 = strtok(caracter2,separador2);
      //      caracter3 = strtok(caracter3,separador3);
      tmpNumBloques = atoi(caracter3);;
      caracter3 = strtok(NULL,separador2);
      tmpVelocidad = ((float)(tmpNumBloques))+((float)(0.1* atoi(caracter3)));
      fgets(caracter,100,archivo);
      tmpNumBloques = atoi(caracter);
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
