#include <stdio.h>
#include <string.h>

int contarCaracter(char *array, char ch);
int obtenerIndice(char *array, char ch);
char *obtenerSubcadena(char *array, int index);

int main(int argc, char const *argv[]) {
  char a = 'a';
  char b = 'A';
  char c = a - 32;

  printf("%d", (int)c);
  // printf("%d", b);

}


/**
 *   @brief  Cuenta las veces que aparece un caracter determinado dentro de una cadena.
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a averiguar
 *   @return el numero de veces que aparece ch en array o -1 si no aparece.
 */
int contarCaracter(char *array, char ch) {
  int counter = 0;
  char *ptr = array;

  while (*ptr) {
    if (*ptr == ch) {
      counter++;
    }
    *ptr++;
  }

  return counter == 0 ? -1 : counter;
}

/**
 *   @brief  Obtiene el indice de la primera aparicion de un caracter en un array
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a ingresa
 *   @return el indice del primer ch en la cadena array
 */
int obtenerIndice(char *array, char ch) {
  int exists = contarCaracter(array, ch);

  if (exists == -1) {
    return -1;
  }

  int index = 0;
  char *ptr = array;

  while (*ptr) {
    if (*ptr == ch) {
      return index;
    }
    index++;
    *ptr++;
  }
  
}

/**
 *   @brief  Obtiene una subcadena a tomada a partir de un subindice asociado a una subcadena
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  index indice
 *   @return un apuntador a la posicion inicial de la subcadena o NULL si el tamaño de index supera a la longitud de la cadena
 */
char *obtenerSubcadena(char *array, int index) {
  int length = strlen(array);

  if (index >= length) {
    return NULL;
  }

  int counter = 0;
  char *ptr = array;

  while (counter < index) {
    *ptr++;
    counter++;
  }

  return ptr;
}