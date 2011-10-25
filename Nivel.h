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
#ifndef NIVEL_H
#define NIVEL_H
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
  int vida;
  int enfriamiento;
  int salto;
  int numElementos;
  ElemNivel *primero;
  ElemNivel *ultimo;
};


extern void iniNivel(Nivel *nivel, int num,char *identificador, int impacto, float velocidad, LisBloque *bloques);
extern void liberarNivel(Nivel *nivel);

extern int esVaciaNivel(LisNivel *lista);
extern void iniLisNivel(LisNivel *lista,int vida, int frio, int salto);
extern void agregarNivel(LisNivel *lista, Nivel *nivel, ElemNivel *elemento);
extern ElemNivel *cabezaNivel (LisNivel *lista);
extern void liberarLisNivel(LisNivel *lista);

extern int numNivel(Nivel *nivel);
extern char *nomNivel(Nivel *nivel);
extern int impNivel(Nivel *nivel);
extern LisBloque *bloquesNivel(Nivel *nivel);
extern int vida(LisNivel *niveles);
extern int enfriamiento(LisNivel *niveles);
extern int salto(LisNivel *niveles);

extern void iniBloque(Bloque *bloque, int fila, int columna, char color);
extern void liberarBloque(Bloque *bloque);

extern int esVaciaBloque(LisBloque *lista);
extern void iniLisBloque(LisBloque *lista);
extern void agregarBloque(LisBloque *lista, Bloque *bloque, ElemBloque *elemento);
extern ElemBloque *cabezaBloque (LisBloque *lista);
extern void liberarLisBloque(LisBloque *lista);

extern int fila(Bloque *bloque);
extern int columna(Bloque *bloque);
extern char color(Bloque *bloque);

#endif
