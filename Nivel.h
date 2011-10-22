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
#include <stdio.h>
#include <stdlib.h>

typedef struct Nivel Nivel;
typedef struct Bloque Bloque;
typedef struct ElemNiv ElemNiv;
typedef struct ElemBlo ElemBlo;
typedef struct ListaNiv ListaNiv;
typedef struct ListaBlo ListaBlo;

struct Nivel {
  int num;
  String id;
  int impacto;
  float velocidad;
  ListaBlo bloques;
};

struct Bloque {
  int fila;
  int columna;
  int color;
}

struct ListaNiv {
  int numElementos;
  ElemNiv *primero;
  Elem *ultimo;
};

struct ListaBlo {
  int numElementos;
  Elem *primero;
  Elem *ultimo;
};
