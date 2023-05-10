#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivo = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    clock_t start, end;
    FILE *fp;
    //fp = fopen("teste_cinquenta_decrescente.txt", "r");
    //fp = fopen("teste_quinhentos_descrescente.txt", "r");
    //fp = fopen("teste_cinco_mil_descrescente.txt", "r");
    //fp = fopen("teste_dez_mil_descrescente.txt", "r");
    //fp = fopen("teste_vinte_cinco_mil_descrescente.txt", "r");
    fp = fopen("teste_trinta_mil_descrescente.txt", "r");

    //os casos de teste de 35000 em diante retornam erro de memoria
    //fp = fopen("teste_trinta_cinco_mil_descrescente.txt", "r");

    if (fp == NULL) {
        printf("Error falha ao abrir arquivo!");
        return 1;
    }

    int quantidade_numeros = 30000;
    //tamanho do vetor deve ser ajustado de acordo com o arquivo lido
    int index = 0, vetor[quantidade_numeros], num;
    while (fscanf(fp, "%d", &num) == 1) {
        vetor[index] = num;
        index++;
    }

	start = clock();
	quickSort(vetor, 0, quantidade_numeros - 1);
	end = clock();
	/* Get the time taken by program to execute in seconds */
    double duration = ((double)end - start)/CLOCKS_PER_SEC;

	printf("Vetor ordenado:\n");
	for(int i = 0; i < quantidade_numeros; i++){
		printf("%d ", vetor[i]);
	}
	printf("\nTime taken to execute in seconds : %f", duration);
	return 0;
}
