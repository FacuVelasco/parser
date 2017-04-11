#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int PARS_Crear(T_Parser * parser, char * archivo, char delimitador, char escape) {

  /* abro el archivo en modo lectura */
  parser->archivo = fopen(archivo, "r");
  if (parser->archivo == NULL){
    return 0;
  }

  parser->delimitador = delimitador;
  parser->escape = escape;

  return 1;
}

int PARS_ObtLinea(T_Parser * parser) {

  char linea[200];
  char * campo;

  if (fgets(linea, 200, parser->archivo) != NULL) {

    while(ObtProxCampo(parser, linea, campo)){
      parser->(++campos) = campo;
      /* parser->campos++; */
    }
    return 1;
  }
  return 0;
}

int PARS_ObtCampo(T_Parser * parser, int N, char * campo) {

  /* Compruebo que pida un campo valido */
  if (N > PARS_ObtQCampos(parser)) {
    return 0;
  }
  strcpy(campo, parser->campos[N]);
  return 1;
}

int PARS_ObtQCampos(T_Parser * parser) {
  return sizeof(parser->campos) / sizeof(parser->campos[0]);
}

void PARS_Destruir(T_Parser * parser) {
  parser->archivo = NULL;
  parser->delimitador = NULL;
  parser->escape = NULL;

  fclose(parser->archivo);
}

int ObtProxCampo(T_Parser * parser, char * linea, char * campo) {
  /* Me fijo que la linea haya cortado en delimitador y no en el final de la linea */
  if (*(++linea) == parser->delimitador) {
    /* leer hasta el delimitador a menos que este el escape antes */
    while ((*(++linea) != parser->delimitador || *(++linea) != '\0') || *(linea--) == parser->escape) {
      *(++campo) = *(++linea);
    }
    *campo = '\0';
    return 1;
  }
  return 0;
}
