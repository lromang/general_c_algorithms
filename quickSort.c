#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int length, int i, int j){
  int aux;

  // Intercambiar elementos.
  if((i < length) && (j < length)){
    aux  = a[i];
    a[i] = a[j];
    a[j] = aux;
  }
}

void randomize(int* a, int length){
  // Declaración de variables.
  int random, i;

  // Permutar arreglo.
  for(i = 0; i < length; i++){
    if(rand() % 2 == 0){
      random = rand() % length;
      swap(a, length, random, i);
    }
  }
}

int partition(int* a, int lo, int hi, int length){
  // Declaración de variables.
  int i, j, comp;

  // Inicialización de variables.
  i = lo;
  j = ++hi;
  comp = a[lo];

  while(1){

    /*
     * Recorremos desde la izquierda hasta
     * encontrar un número mayor.
     */
    while(a[++i] < comp){
      if(i == hi){
        break;
      }
    }

    /*
     * Recorremos desde la derecha hasta
     * encontrar un número menor.
     */
    while(a[--j] > comp){
      if(j == lo){
        break;
      }
    }

    /*
     * Si i >= j ya está ordenada cada partición.
     */
    if( i >= j){
      break;
    }
    /*
     * Intercambiar elementos de cada partición.
     */
    swap(a, length, i, j);
  }
  swap(a, length, lo, j);

  /*
   * Regresar índice a partir del cual hacer
   * llamada recursiva.
   */
  return j;
}

void qs(int* a, int lo, int hi, int length){
  int j;
  // Verificar condición de paro.
  if(hi > lo){
    // Llamadas recursivas con nuevo índice.
    j = partition(a, lo, hi, length);
    qs(a, lo, j - 1, length);
    qs(a, j + 1, hi, length);
  }
}

void init_qs(int* a, int length){
  randomize(a, length);
  qs(a, 0, length -1 , length);
}

int main(){
  // Declaración de variables.
  int length, i;
  int* array;
  time_t t;

  printf("Ingrese longitud del arreglo.\n");
  scanf("%d", &length);
  printf("-------------------\n");
  // Inicialización de variables.
  array = (int*)malloc(length*sizeof(int));
  srand((unsigned) time(&t));

  // Construcción del arreglo.
  printf("Arreglo ordenado\n");
  for(i=0; i < length; i++){
    array[i] = rand() % length;
    printf("%d\n", array[i]);
  }
  printf("------------------\n");
  printf("Arreglo ordenado con qs\n");
  // Ordenamiento del arreglo con qs.
  init_qs(array, length);
  for(i=0; i < length; i++){
    printf("%d\n", array[i]);
  }

  return 0;
}
