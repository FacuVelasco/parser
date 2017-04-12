#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int PARS_Crear(T_Parser * parser, char * archivo, char delimitador, char escape) {

  /* Abro el archivo en modo lectura */
  parser->archivo = fopen(archivo, "r");
  if (parser->archivo == NULL){
    return 0;
  }

  parser->delimitador = delimitador;
  parser->escape = escape;

  /* Pido memoria para los campos leidos del archivo */
  parser->campos = malloc(20*sizeof(char *));

  return 1;
}

int PARS_ObtLinea(T_Parser * parser) {
  
  /* 
    Elegi numeros arbitrariamente
    Podria poner como constantes MAX_LEN_LINEA y MAX_LEN_CAMPO
  */
  char linea[200];
  char campo[50];

  if (fgets(linea, 200, parser->archivo) != NULL) {

    int i = 0;

    /* Me fijo que la linea haya cortado en delimitador y no en el final de la linea */
    while(*linea != '\0'){

      i = 0;

      /*
        Pasa un nuevo caracter cuando esta sobre el delimitador
        pero no al final del while para que pueda evaluar bien la primer condicion (!='\0')
      */
      if(*linea == parser->delimitador){
        *(linea++);
      }

      /* Lee hasta el delimitador a menos que este el escape antes */
      while ((*linea != parser->delimitador && *linea != '\0') || *(linea-1) == parser->escape) {
        campo[i] = *(linea++);
        i++;
      }
      campo[i] = '\0';

      parser->campo = malloc(strlen(campo))
      strcpy(parser->(++campo), campo);
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

  int cont = 0;
  /* Cuando parser->campo apunte a null salgo del loop */
  while (parser->campo) {
    parser->(++campo);
    cont++;
  }
  return cont;
}

void PARS_Destruir(T_Parser * parser) {

  /* Cuando parser->campo apunte a null salgo del loop */
  while (parser->campo) {
    free(*parser->(++campo));
  }
  free(parser->campo);

  parser->delimitador = NULL;
  parser->escape = NULL;

  fclose(parser->archivo);
}
