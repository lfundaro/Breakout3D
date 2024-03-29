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
  lista->salto = salto;
  lista->puntuacion = 0;
  lista->numElementos = 0;
  lista->primero = NULL;
  lista->ultimo = NULL;
  lista->impactoActual = 0;
  lista->velActual = 0;
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

extern void modificarVida(LisNivel *lista, int factor) {
  lista->vida += factor;
}

extern void modificarPunt(LisNivel *lista, int factor) {
  lista->puntuacion += factor;
}

int impactoNivel(Nivel *nivel) {
  return (nivel->impacto);
}

float velNivel(Nivel *nivel) {
  return (nivel->velocidad);
}

int numNivel(Nivel *nivel){
  return (nivel->num);
}

int eImpactoNivel(ElemNivel *elemento) {
  return impactoNivel(elemento->nivel);
}

float eVelNivel(ElemNivel *elemento) {
  return velNivel(elemento->nivel);
}

char *nomNivel(Nivel *nivel){
  return (nivel->id);
}

int impNivel(Nivel *nivel){
  return (nivel->impacto);
}

LisBloque *bloquesNivel(Nivel *nivel){
  return (nivel->bloques);
}

int vida(LisNivel *niveles) {
  return (niveles->vida);
}

extern int enfriamiento(LisNivel *niveles){
  return (niveles->enfriamiento);
}

extern int salto(LisNivel *niveles){
  return (niveles->salto);
}

extern int puntuacion(LisNivel *niveles){
  return (niveles->puntuacion);
}


void iniBloque(Bloque *bloque, int fila, int columna, char color) {
  int valor, impactos;
  switch (color) {
  case 'n': case 'N':
    valor = 30; impactos = 1;
    break;
  case 'r': case 'R':
    valor = 50; impactos = 1;
    break;
  case 'v': case 'V':
    valor = 25; impactos = 1;
    break;
  case 'g': case 'G':
    valor = 0; impactos = -1;
    break;
  case 'a': case 'A':default:
    valor = 10; impactos = 1;
    break;
  }
  bloque->fila = fila;
  bloque->columna = columna;
  bloque->valor = valor;
  bloque->impactos = impactos;
  bloque->color = color;
}

void modificarImpactos(ElemBloque *eBloque, int factor){
  (eBloque->bloque)->impactos += factor;
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
  switch(bloque->color) {
  case 'g': case 'G':
    
    break;
  default:
    lista->numElementos++;
  }
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

int fila(Bloque *bloque){
  return (bloque->fila);
}
int columna(Bloque *bloque){
  return (bloque->columna);
}

int impactos(Bloque *bloque){
  return (bloque->impactos);
}

char color(Bloque *bloque){
  return (bloque->color);
}

int eFila(ElemBloque *eBloque){
  return fila(eBloque->bloque);
}
int eColumna(ElemBloque *eBloque){
  return columna(eBloque->bloque);
}

int eImpactos(ElemBloque *eBloque){
  return impactos(eBloque->bloque);
}

char eColor(ElemBloque *eBloque){
  return color(eBloque->bloque);
}

void cambiarSiguiente(LisBloque *lista, ElemBloque *anterior, ElemBloque *actual) {
  lista->numElementos--;
  ElemBloque *tmp;
  if (anterior == NULL) {
    tmp = actual;
    actual = (actual->siguiente);
    liberarBloque(tmp->bloque);
    lista->primero = actual;
    free(tmp);
  } else {
    tmp = cabezaBloque(lista);
    while ((tmp->siguiente) != anterior) tmp=tmp->siguiente;
    anterior->siguiente = actual->siguiente;
    liberarBloque(actual->bloque);
    free(actual);
    actual = anterior;
  }
}

void eMoverBloque(ElemBloque *eBloque, int fila, int columna) {
  moverBloque(eBloque->bloque,fila,columna);
}

void moverBloque(Bloque *bloque, int fila, int columna){
  bloque->fila += fila;
  bloque->columna += columna;
}

int ePuntuacion(ElemBloque *eBloque){
  return punt(eBloque->bloque);
}

int punt(Bloque *bloque){
  return bloque->valor;
}

int impAct(LisNivel *lista){
  return (lista->impactoActual);
}

float velAct(LisNivel *lista){
  return (lista->velActual);
}

int impCtdd(LisNivel *lista){
  return (lista->impactoCtdd);
}

void modCtdd(LisNivel *lista, int factor) {
  lista->impactoCtdd = factor;
}
