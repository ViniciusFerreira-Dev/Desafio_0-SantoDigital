#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** ast(int n) {
  char** lista = (char**) malloc(n * sizeof(char*));// Aloca espa�o para a lista de n strings
 
  for (int i = 0; i < n; i++) { // For para criar cada string
    lista[i] = (char*) malloc((i+2) * sizeof(char)); // Aloca espa�o para a string i, com tamanho i+2 para caber os i asteriscos mais o caractere nulo de termina�ao
    memset(lista[i], '*', i+1);// Preenche a string i com i asteriscos
    lista[i][i+1] = '\0';
  }
 
  return lista; // Retorna a lista de strings
}

int main() {
  int n = 6;  // Define o tamanho da lista de strings
  
  char** lista = ast(n);// Chama a fun��o asteriscos para criar a lista
  
for (int i = 0; i < n; i++) {// For para imprimir cada string da lista
  
    printf("[%s]", lista[i]);  // Imprime a string i da lista
   
    free(lista[i]); // Libera a mem�ria alocada para a string i
}
 
  free(lista); // Libera a memoria alocada para a lista de strings
  return 0;
}
