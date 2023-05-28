#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct par {
  int p;
  int s;
} Par;

Par* menor_diferenca(int a[], int tamanho, int* quant) {
  // Inicializa a matriz de pares com a menor diferen�a e o n�mero de pares encontrados
  Par* pares_menor_diferenca = NULL;
  *quant = 0;
  // Encontra a menor diferen�a e adiciona os pares correspondentes � matriz de pares
  int menor_diferenca = INT_MAX;
  for (int i = 0; i < tamanho-1; i++) {
    for (int j = i+1; j < tamanho; j++) {
      int diferenca = abs(a[i] - a[j]);
      if (diferenca < menor_diferenca) {
        // Se a diferen�a for menor que a menor diferen�a j� encontrada, reinicializa a matriz de pares com um novo par contendo esses elementos.
        menor_diferenca = diferenca;
        *quant= 1;
        // Aloca espa�o para um novo par eadiciona-o � matriz de pares
        pares_menor_diferenca = (Par*) realloc(pares_menor_diferenca, (*quant) * sizeof(Par));
        pares_menor_diferenca[0].p= a[i];
        pares_menor_diferenca[0].s = a[j];
      } else if (diferenca == menor_diferenca) {
        // Se a diferen�a for igual � menor diferen�a j� encontrada, adiciona o novo par � matriz de pares
        (*quant)++;
        pares_menor_diferenca = (Par*) realloc(pares_menor_diferenca, (*quant) * sizeof(Par));
        pares_menor_diferenca[*quant-1].p = a[i];
        pares_menor_diferenca[*quant-1].s = a[j];
      }
    }
  }
  // Retorna a matriz de pares com a menor diferen�a
  return pares_menor_diferenca;
}

int main() {
  // Define o array de n�meros inteiros
  int a[] = {3, 8, 50, 5, 1, 18, 12};
  int tamanho = sizeof(a) / sizeof(int);
  // Chama a fun��o para encontrar o(s) parde n�meros com a menor diferen�a absoluta
  int quant;
  Par* pares = menor_diferenca(a, tamanho, &quant);
  // Imprime o(s) par(es) encontrado(s) na tela
  printf("menor diferen�a absoluta:\n");
  for (int i = 0; i < quant; i++) {
    printf("[(%d,%d)]", pares[i].p, pares[i].s);
  }
  // Libera a mem�ria alocada para a matriz de pares
  free(pares);
  return 0;
}
