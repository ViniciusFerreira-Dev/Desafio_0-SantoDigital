#include <stdio.h>
#include <stdlib.h>

// Define a estrutura de lista encadeada
typedef struct no {
  int valor;
  struct no* proximo;
} No;

// Define a estrutura de conjunto para armazenar os subconjuntos
typedef struct conjunto {
  No* inicio;
  No* fim;
} Conjunto;

// Inicializa um novo nó com o valor especificado
No* novo_no(int valor) {
  No* novo = (No*) malloc(sizeof(No));
  novo->valor = valor;
  novo->proximo = NULL;
  return novo;
}

// Inicializa um novo conjunto vazio
Conjunto* novo_conjunto() {
  Conjunto* conjunto = (Conjunto*) malloc(sizeof(Conjunto));
  conjunto->inicio = NULL;
  conjunto->fim = NULL;
  return conjunto;
}

// Insere um valor no final do conjunto
void insere(Conjunto* conjunto, int valor) {
  No* novo = novo_no(valor);
  if (conjunto->inicio == NULL) {
    conjunto->inicio = novo;
  } else {
    conjunto->fim->proximo = novo;
  }
  conjunto->fim = novo;
}

// Imprime um conjunto
void imprime_conjunto(Conjunto* conjunto) {
  printf("[");
  No* no_atual = conjunto->inicio;
  while (no_atual != NULL) {
    printf("%d", no_atual->valor);
    no_atual = no_atual->proximo;
    if (no_atual != NULL) {
      printf(", ");
    }
  }
  printf("]\n");
}

// Imprime todos os subconjuntos de um conjunto de números
void subconjuntos(int* conjunto, int tamanho) {
  // Cria um conjunto vazio para armazenar os subconjuntos
  Conjunto* subconjuntos = novo_conjunto();
  insere(subconjuntos, -1);
  // Itera sobre o conjunto de números
  for (int i = 0; i < tamanho; i++) {
    // Remove todos os subconjuntos atuais que não contêm o elemento atual
    while (subconjuntos->inicio->valor != -1 && subconjuntos->inicio->valor != conjunto[i]) {
      No* no_removido = subconjuntos->inicio;
      subconjuntos->inicio = no_removido->proximo;
      free(no_removido);
    }
    // Adiciona o elemento atual a cada subconjunto atual
    No* no_atual = subconjuntos->inicio;
    while (no_atual != NULL) {
      No* novo_no = (No*) malloc(sizeof (conjunto[i]));
      novo_no->proximo = no_atual->proximo;
      no_atual->proximo = novo_no;
      no_atual = no_atual->proximo;
    }
    // Insere os novos subconjuntos no conjunto de subconjuntos
    insere(subconjuntos, conjunto[i]);
    insere(subconjuntos, -1);
  }
  // Imprime todos os subconjuntos
  No* no_atual = subconjuntos->inicio;
  while (no_atual != NULL) {
    if (no_atual->valor == -1) {
      imprime_conjunto(novo_conjunto()); // Imprime o conjunto vazio
    } else {
      // Cria um novo conjunto com os elementos do subconjunto atual
      Conjunto* subconjunto_atual = novo_conjunto();
      No* no_atual_subconjunto = subconjunto_atual->inicio;
      while (no_atual != NULL && no_atual->valor != -1) {
        insere(subconjunto_atual, no_atual->valor);
        no_atual = no_atual->proximo;
      }
      // Imprime o subconjunto atual
      imprime_conjunto(subconjunto_atual);
    }
    no_atual = no_atual->proximo;
  }
}

int main() {
  // Defineo conjunto de números
  int conjunto[] = {1, 2};
  int tamanho = sizeof(conjunto) / sizeof(int);
  // Chama a função para imprimir todos os subconjuntos
  subconjuntos(conjunto, tamanho);
  return 0;
}
