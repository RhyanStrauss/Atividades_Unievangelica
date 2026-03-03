#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  FUNÇÃO PARA IMPRIMIR ARRAY  */
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*  BUBBLE SORT  */
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

/*  SELECTION SORT  */
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[min])
                min = j;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

/*  INSERTION SORT  */
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*  QUICK SORT  */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*  MERGE SORT  */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/*  SHELL SORT  */
void shellSort(int arr[], int n) {
    for(int gap = n / 2; gap > 0; gap /= 2)
        for(int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
}

/*  TESTE AUTOMÁTICO  */
void testarTodos(int base[], int n) {
    int copia[n];
    clock_t inicio, fim;

    void (*algoritmos[])(int[], int) = {
        bubbleSort, selectionSort, insertionSort, shellSort
    };

    char *nomes[] = {
        "Bubble Sort", "Selection Sort", "Insertion Sort", "Shell Sort"
    };

    for(int a = 0; a < 4; a++) {
        for(int i = 0; i < n; i++)
            copia[i] = base[i];

        inicio = clock();
        algoritmos[a](copia, n);
        fim = clock();

        printf("%s: %f segundos\n",
               nomes[a],
               (double)(fim - inicio) / CLOCKS_PER_SEC);
    }

    // Quick
    for(int i = 0; i < n; i++) copia[i] = base[i];
    inicio = clock();
    quickSort(copia, 0, n - 1);
    fim = clock();
    printf("Quick Sort: %f segundos\n",
           (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Merge
    for(int i = 0; i < n; i++) copia[i] = base[i];
    inicio = clock();
    mergeSort(copia, 0, n - 1);
    fim = clock();
    printf("Merge Sort: %f segundos\n",
           (double)(fim - inicio) / CLOCKS_PER_SEC);
}

/*  MAIN  */
int main() {

    int n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int base[n];
    srand(time(NULL));

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Executar um algoritmo especifico\n");
        printf("2 - Executar comparacao automatica\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {

            for(int i = 0; i < n; i++)
                base[i] = rand() % 10000;

            printf("\nArray original:\n");
            printArray(base, n);

            printf("\nEscolha o algoritmo:\n");
            printf("1 - Bubble\n2 - Selection\n3 - Insertion\n4 - Quick\n5 - Merge\n6 - Shell\n");
            int alg;
            scanf("%d", &alg);

            clock_t inicio = clock();

            switch(alg) {
                case 1: bubbleSort(base, n); break;
                case 2: selectionSort(base, n); break;
                case 3: insertionSort(base, n); break;
                case 4: quickSort(base, 0, n - 1); break;
                case 5: mergeSort(base, 0, n - 1); break;
                case 6: shellSort(base, n); break;
                default: printf("Opcao invalida!\n"); continue;
            }

            clock_t fim = clock();

            printf("\nArray ordenado:\n");
            printArray(base, n);

            printf("Tempo: %f segundos\n",
                   (double)(fim - inicio) / CLOCKS_PER_SEC);
        }

        else if(opcao == 2) {

            printf("\n===== ARRAY ALEATORIO =====\n");
            for(int i = 0; i < n; i++)
                base[i] = rand() % 10000;
            testarTodos(base, n);

            printf("\n===== ARRAY ORDENADO =====\n");
            for(int i = 0; i < n; i++)
                base[i] = i;
            testarTodos(base, n);

            printf("\n===== ARRAY REVERSO =====\n");
            for(int i = 0; i < n; i++)
                base[i] = n - i;
            testarTodos(base, n);
        }

    } while(opcao != 0);

    return 0;
}
