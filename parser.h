#include <stdlib.h>
#include <stdio.h>

/*  ESTRUCTURA  */

typedef struct T_Parcer {
  char delimitador, escape;
  FILE * archivo;
  char * campos[]
} T_Parcer;

/*  FUNCIONES  */

int PARS_Crear(TParser * parser, char * archivo, char delimitador, char escape);

int PARS_ObtLinea(TParser * parser);

int PARS_ObtCampo(TParser * parser, int N, char * campo);

int PARS_ObtQCampos(TParser * parser);

void PARS_Destruir(TParser * parser);