#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "parser.h" ??

// hay un int main()??

int PARS_Crear(TParser * parser, char * archivo, char delimitador, char escape) {

  // abro el archivo en modo lectura
  parser->archivo = fopen(archivo, "r");
  if (parser->archivo == NULL){
    return 0;
  }
  
  parser->delimitador = delimitador;
  parser->escape = escape;
  
  return 1;
}

int PARS_ObtLinea(TParser * parser) {

  char linea[200];
  char * campo;
  
  if (fgets(linea, 200, parser->archivo) != NULL) {
  
    ObtProxCampo(linea, campo);
    while(campo){
      parser->campo = campo; // hace falta un strcpy?
      ObtProxCampo(linea, campo);
    }
    return 1;
  }
  return 0;
}

int PARS_ObtCampo(TParser * parser, int N, char * campo) {

  // Compruebo que pida un campo valido
  if (N > PARS_ObtQCampos(parser)) { 
    return 0;
  }
  strcpy(campo, parser->campos[N]);
  return 1;
}

int PARS_ObtQCampos(TParser * parser) {
  return sizeof(parser->campos) / sizeof(parser->campos[0])
  /*
  int nCampos = 1;
  while ( ++parser.campos != '/0') {
    nCampos++;
  }
  return nCampos;
  */
}

void PARS_Destruir(TParser * parser) {
  parser->File = NULL;
  parser->delimitador = NULL;
  parser->escape = NULL;

  fclose(parser->archivo);
}

int ObtProxCampo(char * linea, char * campo) {
  // leer hasta la coma a menos que este el escape antes

  return 0; // si no consigue campo devuelvo 0
}
