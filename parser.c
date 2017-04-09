#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "parser.h" ??

// hay un int main()??

int PARS_Crear(TParser * parser, char * archivo, char delimitador, char escape) {

  // abro el archivo en modo lectura
  parser.archivo = fopen(archivo, "r");
  if (parser.archivo == NULL){
    return 0;
  }
  
  parser.delimitador = delimitador;
  parser.escape = escape;
  
  return 1;
}

int PARS_ObtLinea(TParser * parser) {

  char linea[200];
  fgets (linea, 200, parser.archivo);

  // ahora tengo que parsear esa linea por las ','
  // posiblemente usar una funcion que evaluee el caracter de escape?

  // ObtProxCampo(parser);
}

int PARS_ObtCampo(TParser * parser, int N, char * campo) {

  if( parser.campos[N] == NULL ){ // Algun chequeo de que no pida un campo no disponible
    return 0;
  }
  strcpy(campo, parser.campos[N]);
  return 1;
}

int PARS_ObtQCampos(TParser * parser) {
  int nCampos;
  while ( ++parser.campos != '/0') {
    nCampos++;
  }
  return nCampos;
}

void PARS_Destruir(TParser * parser) {
  // tengo que hacer el free de memoria seguramente
  fclose(parser.archivo);
}

/*
int ObtProxCampo(TParser * parser) {
  // leer hasta la coma a menos que este el escape antes
}
*/
