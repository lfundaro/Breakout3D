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

typedef struct Bloque Bloque;
typedef struct ElemBloque ElemBloque;
typedef struct LisBloque LisBloque;

typedef struct Nivel Nivel;
typedef struct ElemNivel ElemNivel;
typedef struct LisNivel LisNivel;


struct Bloque {
  int fila;
  int columna;
  char color;
};

struct ElemBloque {
  Bloque *bloque;
  ElemBloque *siguiente;
};

struct LisBloque {
  int numElementos;
  ElemBloque *primero;
  ElemBloque *ultimo;
};

struct Nivel {
  int num;
  char *id;
  int impacto;
  float velocidad;
  LisBloque *bloques;
};

struct ElemNivel {
  Nivel *nivel;
  ElemNivel *siguiente;
};

struct LisNivel {
  int numElementos;
  ElemNivel *primero;
  ElemNivel *ultimo;
};


extern void iniNivel(Nivel *nivel, int num,char *identificador, int impacto, float velocidad, LisBloque *bloques);
extern void liberarNivel(Nivel *nivel);

extern int esVaciaNivel(LisNivel *lista);
extern void iniLisNivel(LisNivel *lista);
extern void agregarNivel(LisNivel *lista, Nivel *nivel, ElemNivel *elemento);
extern ElemNivel *cabezaNivel (LisNivel *lista);
extern void liberarLisNivel(LisNivel *lista);

extern void iniBloque(Bloque *bloque, int fila, int columna, char color);
extern void liberarBloque(Bloque *bloque);

extern int esVaciaBloque(LisBloque *lista);
extern void iniLisBloque(LisBloque *lista);
extern void agregarBloque(LisBloque *lista, Bloque *bloque, ElemBloque *elemento);
extern ElemBloque *cabezaBloque (LisBloque *lista);
extern void liberarLisBloque(LisBloque *lista);
