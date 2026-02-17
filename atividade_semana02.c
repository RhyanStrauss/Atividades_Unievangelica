#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetorDecrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void bubbleSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
    int temp;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            (*comparacoes)++;

            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*movimentacoes) += 3;
            }
        }
    }
}

void selectionSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
    int minIdx, temp;

    for (int i = 0; i < tamanho - 1; i++) {
        minIdx = i;

        for (int j = i + 1; j < tamanho; j++) {
            (*comparacoes)++;
            if (vetor[j] < vetor[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            temp = vetor[minIdx];
            vetor[minIdx] = vetor[i];
            vetor[i] = temp;
            (*movimentacoes) += 3;
        }
    }
}

void executarTeste(const char *algoritmo,
                   void (*sortFunction)(int *, int, int *, int *),
                   int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    int comparacoes = 0, movimentacoes = 0;
    clock_t inicio, fim;
    double tempoMs;

    if (vetor == NULL) {
        printf("| %-13s | %-7d | %-10s | %-12s | %-12s |\n",
               algoritmo, tamanho, "ERRO", "ERRO", "ERRO");
        return;
    }

    preencherVetorDecrescente(vetor, tamanho);

    inicio = clock();
    sortFunction(vetor, tamanho, &comparacoes, &movimentacoes);
    fim = clock();

    tempoMs = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    printf("| %-13s | %-7d | %-10.3f | %-12d | %-12d |\n",
           algoritmo, tamanho, tempoMs, comparacoes, movimentacoes);

    free(vetor);
}

int main(void) {
    printf("| %-13s | %-7s | %-10s | %-12s | %-12s |\n",
           "Algoritmo", "Tamanho", "Tempo (ms)", "Comparacoes", "Movimentacoes");
    printf("|---------------|---------|------------|--------------|--------------|\n");

    executarTeste("Bubble Sort", bubbleSort, 100);
    executarTeste("Bubble Sort", bubbleSort, 1000);
    executarTeste("Bubble Sort", bubbleSort, 10000);

    executarTeste("Selection Sort", selectionSort, 100);
    executarTeste("Selection Sort", selectionSort, 1000);
    executarTeste("Selection Sort", selectionSort, 10000);

    return 0;
}