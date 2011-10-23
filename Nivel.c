/***********************************************************
 *
 * Asunto: Codigo fuente de Break Out. Proyecto 1
 * Materia: Laboratorio de Computacion Grafica I - CI4321
 * Trimestre: Sep-Dic 2011
 * Seccion: 1
 * Profesor: X
 * Integrantes:                  Carnet:
 * * Lorenzo Fundaro            06-39559
 * * Jose    Lezama             07-41104
 *
 *************************************************************/
#include "Nivel.h"
#include <stdio.h>
#include <stdlib.h>

void iniNivel(Nivel *nivel, int num,char *identificador, int impacto, float velocidad, LisBloque *bloques) {
  nivel->num = num;
  nivel->id = identificador;
  nivel->impacto = impacto;
  nivel->velocidad = velocidad;
  nivel->bloques = bloques;
}

void liberarNivel(Nivel *nivel) {
  liberarLisBloque(nivel->bloques);
  free(nivel);
}

void iniLisNivel(LisNivel *lista,int vida, int frio, int salto){
  lista->vida = vida;
  lista->enfriamiento = frio;
  lista->salto;
  lista->numElementos = 0;
  lista->primero = NULL;
  lista->ultimo = NULL;

}

int esVaciaNivel(LisNivel *lista){
  return lista->numElementos == 0;
}

void agregarNivel(LisNivel *lista, Nivel *nivel, ElemNivel *elemento){
  lista->numElementos++;
  elemento->nivel = nivel;
  elemento->siguiente = NULL;
  if (lista->primero == NULL) {
    lista->primero = elemento;
  } else {
    lista->ultimo->siguiente = elemento;
  }
  lista->ultimo = elemento;
}

ElemNivel *cabezaNivel(LisNivel *lista) {
  return lista->primero;
}

void liberarLisNivel(LisNivel *lista) {
  ElemNivel *apuntador = lista->primero;
  ElemNivel *tmp;
  while (apuntador != NULL){
    tmp = apuntador;
    liberarNivel(tmp->nivel);
    apuntador = apuntador->siguiente;
    free(tmp);
  }
  free(lista);
}

void iniBloque(Bloque *bloque, int fila, int columna, char color) {
  bloque->fila = fila;
  bloque->columna = columna;
  bloque->color = color;
}

void liberarBloque(Bloque *bloque) {
  free(bloque);
}

int esVaciaBloque(LisBloque *lista){
  return lista->numElementos == 0;
}

void iniLisBloque(LisBloque *lista){
  lista->numElementos = 0;
  lista->primero = NULL;
  lista->ultimo = NULL;
}

void agregarBloque(LisBloque *lista, Bloque *bloque, ElemBloque *elemento){
  lista->numElementos++;
  elemento->bloque = bloque;
  elemento->siguiente = NULL;
  if (lista->primero == NULL) {
    lista->primero = elemento;
  } else {
    lista->ultimo->siguiente = elemento;
  }
  lista->ultimo = elemento;
}

ElemBloque *cabezaBloque(LisBloque *lista) {
  return lista->primero;
}

void liberarLisBloque(LisBloque *lista) {
  ElemBloque *apuntador = lista->primero;
  ElemBloque *tmp;
  while (apuntador != NULL) {
    tmp = apuntador;
    liberarBloque(tmp->bloque);
    apuntador = apuntador->siguiente;
    free(tmp);
  }
  free(lista);
}
