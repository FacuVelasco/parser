#include <stdlib.h>
#include <stdio.h>

/*  ESTRUCTURA  */

typedef struct T_Parcer {
  FILE * archivo;
  char delimitador, escape;
  char ** campos;
} T_Parcer;

/*  FUNCIONES  */

/*
PRE: "parser" no creado, "delimitador" es un caracter no nulo,
  "escape" es un caracter no nulo y distinto de delimitador.
POST: Si no hubo error parser creado y devuelve 1, si no devuelve 0.
*/
int PARS_Crear(TParser * parser, char * archivo, char delimitador, char escape);

/*
PRE: "parser" creado.
POST: Si pudo obtener una linea devuelve 1 (no hubo errores),
  si no devuelve 0 (no hay mas lineas para leer en el archivo).
*/
int PARS_ObtLinea(TParser * parser);

/*
PRE: "parser" creado, "linea" obtenida.
POST: Si pudo obtener campo devuelve 1 (no hubo errores) y el campo obtenido,
  si no devuelve 0 (no existe el n-esimo campo pedido).
*/
int PARS_ObtCampo(TParser * parser, int N, char * campo);

/*
PRE: "parser" creado, "linea" obtenida.
POST: Devuelve la cantidad de campos de la ultima linea obtenida.
*/
int PARS_ObtQCampos(TParser * parser);

/*
PRE: "parser" creado.
POST: "parser" destruido.
*/
void PARS_Destruir(TParser * parser);