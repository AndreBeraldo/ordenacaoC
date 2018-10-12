#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t t0, tf;
double tempo_gasto;

void bubbleSort(int vet[], int tam){
    t0 = clock();
    int i, j, aux;
    for(i = 1; i < tam; i++){
        for(j = 0; j < tam-1; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;

            }
        }
    }
}

void intBubbleSort(int vet[], int tam){
    t0 = clock();
    int i, j, aux;
    int troca = 0, quant = 0;
    for(i=0; i<tam; i++){
        j=0;
        troca = 0;
        while(j<(tam-i)){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                troca = 1;
            }
            j++;
        }
        if(troca == 0){
            printf("\nExecutou %d vezes", quant);
            return;
        }
        quant++;
    }
    printf("\nExecutou %d vezes\n", quant);
    return;
}

void selectionSort(int vet[], int tam){

    int i, j;
    int min, aux;
    for(i=0; i<tam-1; i++) {
        min = i;
        for(j=i+1; j<tam; j++) {
            if (vet[j] < vet[min])
                min = j;
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
    return;
}

void inserctionSort(int vet[], int tam){

    int i, j, atual;
	for (i = 1; i < tam; i++) {
        atual = vet[i];
		for (j = i - 1; (j >= 0) && (atual < vet[j]); j--) {
			vet[j + 1] = vet[j];
        }
		vet[j+1] = atual;
	}

    return;
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
    return;
}

void quickSort(int a[], int left, int right) {

    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quickSort(a, left, j);
    }
    if(i < right) {
        quickSort(a, i, right);
    }
    return;
}

