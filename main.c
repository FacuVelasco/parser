#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TDA_parser.h"

#define clear() printf("\033[H\033[J");

void seleccionarMenu(int option);
void crearParcer(T_Parser * parser);
void leerLinea(T_Parser * parser);
void obtenerCampos(T_Parser * parser);
void obtenerCampo(T_Parser * parser);
void cerrarParcer(T_Parser * parser);

int main(int argc, char * argv[]) {

  int opcion = 1;
  clear();
  while (opcion != 6) {

    printf("PARSER MENU: ingrese un numero\n");
    printf("1. Abrir archivo y parcer\n");
    printf("2. Obtener linea\n");
    printf("3. Obtener la cantidad de campos de la ultima linea\n");
    printf("4. Obtener un campo de la ultima linea\n");
    printf("5. Cerrar archivo\n");
    printf("6. Salir\n\n");

    scanf("%d",opcion);
    while (opcion < 1 || opcion > 6) {
      printf("Numero invalido, ingrese un numero entre 1 y 6.\n");
      scanf("%d",opcion);
    }
    seleccionarMenu(opcion);
    printf("\nPresiona enter para continuar\n");
    getchar();
  }
  return 0;
}

void seleccionarMenu(int option) {

  T_Parser * parser;

  switch(option) {
    case 1:
      crearParcer(parser);
      break;
    case 2:
      leerLinea(parser);
      break;
    case 3:
      obtenerCampos(parser);
      break;
    case 4:
      obtenerCampo(parser);
      break;
    case 5:
      cerrarParcer(parser);
      break;
  }
}

void crearParcer(T_Parser * parser) {

  char * archivo;
  char delimitador,escape;
  printf("Ingrese un archivo con su extension\n");
  scanf("%s",archivo);
  printf("Ingrese el delimitador de su parser\n");
  scanf("%s",delimitador);
  printf("Ingrese el escape de su parser\n");
  scanf("%s",escape);

    if (PARS_Crear(parser, archivo, delimitador, escape)) {
    printf("Parcer creado y arhivo abierto\n");
    return;
  }
  printf("El archivo no pudo ser abierto\n");
}

void leerLinea(T_Parser * parser) {

  if (parser->archivo != NULL) {
    if (PARS_ObtLinea(parser)) {
      printf("Linea obtenida\n");
      return;
    }
    printf("No hay mas lineas\n");
    return;
  }
  printf("Parcer no inicializado\n");
}

void obtenerCampos(T_Parser * parser) {

  int n;
  if (parser->archivo != NULL) {
    if (parser->campos != NULL) {
      n = PARS_ObtQCampos(parser);
      printf("Hay %d campos en la linea\n", n);
    }
    printf("No hay linea seleccionada\n");
    return;
  }
  printf("Parcer no inicializado\n");
}

void obtenerCampo(T_Parser * parser) {

  int n;
  char * campo;
  printf("Ingrese el numero de campo\n");
  scanf("%d",n);
  if (parser->archivo != NULL) {
    if (parser->campos != NULL) {
      if(PARS_ObtCampo(parser, n, campo)) {
        printf("El campo numero %d es %s.\n", n, campo);
        return;
      }
      printf("No exite el campo pedido\n");
      return;
    }
    printf("No hay linea seleccionada\n");
    return;
  }
  printf("Parcer no inicializado\n");
}

void cerrarParcer(T_Parser * parser) {

  if(parser->archivo != NULL) {
    PARS_Destruir(parser);
    return;
  }
  printf("Parcer no inicializado\n");
}
