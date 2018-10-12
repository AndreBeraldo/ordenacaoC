#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ES.c"
#include "quadraticos.c"

void textoInicial(){
    printf("/*************************************|\n");
    printf("|        Programa de ordena��o        |\n");
    printf("|-------------------------------------|\n");
    printf("|           Instru��es                |\n");
    printf("| 1- Utilize um arquivo de entrada    |\n");
    printf("|  (adicionando .txt ao fim da string |\n");
    printf("| 2- Escolha o m�todo de ordena��o    |\n");
    printf("| 3- O vetor ordenado ser� printado   |\n");
    printf("|       em um arquivo de sa�da.       |\n");
    printf("|*************************************/\n");
}

int main() {
        setlocale(LC_ALL, "Portuguese");
    while(1){
        textoInicial();
        char metOrd[20];
        char nomeArq[20];
        int tamE;
        printf("Insira o nome do arquivo para leitura: ");
        scanf("%s", nomeArq);

        tamE = contarElementos(nomeArq);
        printf("\nN�mero de elementos: %d\n", tamE);
        int vet[tamE];
        lerArquivo(nomeArq,vet);

        while(1){

            printf("Escolha o m�todo a ser utilizado: \n");
            printf("\t 1- Bolha\n");
            printf("\t 2- Bolha inteligente\n");
            printf("\t 3- Sele��o\n");
            printf("\t 4- Inser��o\n");
            printf("\t 5- MergeSort\n");
            printf("\t 6- QuickSort\n");
            int opcao=0;
            printf("\nOp��o: ");
            scanf("%d", &opcao);
            switch(opcao){
            case 1:
                t0 = clock();

                bubbleSort(vet, tamE);
                escreverArquivo(vet, tamE);
                tf = clock();

                tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
                printf("\n\nTempo gasto BOLHA: %lf ms\n\n", tempo_gasto);
                break;

            case 2:
                t0 = clock();

                intBubbleSort(vet, tamE);
                escreverArquivo(vet, tamE);

                tf = clock();
                tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
                printf("\n\nTempo gasto BOLHA INTELIGENTE: %lf ms\n\n", tempo_gasto);
                break;

            case 3:
                t0 = clock();

                selectionSort(vet, tamE);
                escreverArquivo(vet, tamE);

                tf = clock();
                tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
                printf("\n\nTempo gasto SELECTION SORT: %lf ms\n\n", tempo_gasto);
                break;

            case 4:
                t0 = clock();

                inserctionSort(vet, tamE);
                escreverArquivo(vet, tamE);

                tf = clock();
                tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
                printf("\n\nTempo gasto INSERCTION SORT: %lf ms\n\n", tempo_gasto);
                break;

            case 5:
                t0 = clock();

                mergeSort(vet, 0, tamE);
                escreverArquivo(vet, tamE);

                tf = clock();
                tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
                printf("\n\nTempo gasto MERGE SORT: %lf ms\n\n", tempo_gasto);
                break;

            case 6:
                t0 = clock();

                quickSort(vet, 0, tamE-1);
                escreverArquivo(vet, tamE);

                tf = clock();
                tempo_gasto = (( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000));
                printf("\n\nTempo gasto QUICK SORT: %lf ms\n\n", tempo_gasto);
                break;

            default:
                printf("\nM�todo nao encontrado!\n");
            }
            printf("/*****************************************|\n");
            printf("| 1 - Outro m�todo para o mesmo arquivo   |\n");
            printf("|       2 - Avaliar outro arquivo         |\n");
            printf("|                3 - Sair                 |\n");
            printf("|*****************************************/\n");
            printf("\nOp��o: ");
            scanf("%d", &opcao);

            if(opcao == 1){ system("cls");textoInicial(); }
            else if(opcao == 2){ system("cls");break;break;}
            else {exit(1);}
        }
    }
    return (EXIT_SUCCESS);
}



