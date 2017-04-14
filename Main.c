#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#define MAX 10 //Mudar para tamanho da instancia desejada

float comparacoesbubble=0;
float trocasbubble=0;
float comparacoesinsertion=0;
float trocasinsertion=0;
float comparacoesselection=0;
float trocasselection=0;
float comparacoesmerge=0;
float trocasmerge=0;
float comparacoesheap=0;
float trocasheap=0;
float comparacoesquick=0;
float trocasquick=0;

int tirarMedia(int vetor[], int tam){
        int media=0;
        int i=0;

        for(i=0; i<tam; i++) {
                media += vetor[i];
        }
        media = media/tam;
        return media;
}

float tirarMediaF(float vetor[], int tam){
        float media=0.0;
        int i=0;

        for(i=0; i < tam; i++) {
                media += vetor[i];
        }
        media = media/tam;
        return media;
}

void ExibirVetor(int vetor[], int tam){
        int i=0;
        while(i < tam) {
                printf("|%d|, ", vetor[i]);
                i++;
        }
}

void GerarNumeros(int vetor[], int tam){
        int i=0;
        srand(time(NULL));
        while(i < tam) {
                vetor[i] = rand();
                i++;
        }
}


void bubbleSort(int vetor[], int tam){
        int i,j;
        int iAux;

        for(i=1; i<tam; i++) {
                for(j=tam-1; j>=i; j--) {
                        if(vetor[j-1] > vetor[j]) {
                                iAux = vetor[j-1];
                                vetor[j-1] = vetor[j];
                                vetor[j] = iAux;
                                trocasbubble++;
                        }
                        comparacoesbubble++;
                }
        }
        return;
}

void selectionSort(int vetor[], int tam){
        int i, j, min, aux;
        for (i = 0; i < (tam-1); i++) {
                min = i;
                for (j = (i+1); j < tam; j++) {
                        if(vetor[j] < vetor[min]) min = j;
                }
                if (i != min) {
                        aux = vetor[i];
                        vetor[i] = vetor[min];
                        vetor[min] = aux;
                        trocasselection++;
                }
                comparacoesselection++;
        }
}

int * insertionSort(int vetor[], int tam){
        int i, j, atual;

        for (i = 1; i < tam; i++) {
                atual = vetor[i];
                j = i - 1;

                while ((j >= 0) && (atual < vetor[j])) {
                        vetor[j + 1] = vetor[j];
                        j = j - 1;
                        trocasinsertion++;
                }
                comparacoesinsertion++;
                vetor[j + 1] = atual;
        }
        return (int *) vetor;
}


void heapSort(int vetor[], int tam) {
        int i = tam/2, pai, filho, t;
        for (;; ) {
                if (i > 0) {
                        i--;
                        t = vetor[i];
                }else {
                        tam--;
                        if (tam == 0) return;
                        t = vetor[tam];
                        vetor[tam] = vetor[0];
                        trocasheap++;
                }
                pai = i;
                filho = i * 2 + 1;
                while(filho < tam) {
                        comparacoesheap++;
                        if ((filho + 1 < tam)  &&  (vetor[filho + 1] > vetor[filho]))
                                filho++;
                        if (vetor[filho] > t) {
                                vetor[pai] = vetor[filho];
                                pai = filho;
                                filho = pai * 2 + 1;
                                trocasheap++;
                        }else break;
                }
                vetor[pai] = t;
        }
}


void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
        int i, j, k, metadeTamanho, *vetorTemp;

        if(posicaoInicio == posicaoFim) return;

        // ordenacao recursiva das duas metades
        metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
        mergeSort(vetor, posicaoInicio, metadeTamanho);
        mergeSort(vetor, metadeTamanho + 1, posicaoFim);

        // intercalacao no vetor temporario t
        i = posicaoInicio;
        j = metadeTamanho + 1;
        k = 0;
        vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

        while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
                if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
                        vetorTemp[k] = vetor[j];
                        j++;
                        k++;
                        trocasmerge++;
                }
                else {
                        if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                                vetorTemp[k] = vetor[i];
                                i++;
                                k++;
                        }
                        else {
                                if (vetor[i] < vetor[j]) {
                                        vetorTemp[k] = vetor[i];
                                        i++;
                                        k++;
                                }
                                else {
                                        vetorTemp[k] = vetor[j];
                                        j++;
                                        k++;
                                }
                        }
                        trocasmerge++;
                }
                comparacoesmerge++;
        }

        // copia vetor intercalado para o vetor original
        for(i = posicaoInicio; i <= posicaoFim; i++) {
                vetor[i] = vetorTemp[i - posicaoInicio];
        }
        free(vetorTemp);
}


int Separa(int *v, int inicio, int fim) {
        int pivo = v[fim], i, j = inicio, valor;
        for(i=inicio; i<fim; i++) {
                if(v[i] < pivo) {
                        valor = v[i];
                        v[i] = v[j];
                        v[j] = valor;
                        j++;
                        trocasquick++;
                }
                comparacoesquick++;
        }
        if(pivo <= v[j]) {
                v[fim] = v[j];
                v[j] = pivo;
        }
        return j;
}

void quickSort(int *vetor, int inicio, int fim) {
        if(inicio >= fim)
                return;
        int pivoIndex = Separa(vetor, inicio, fim);
        quickSort(vetor, inicio, pivoIndex-1);
        quickSort(vetor, pivoIndex+1, fim);
}

void ClonaVetor(int *vetor, int *vetor2){

        for (int i = 0; i < MAX; i++) {
                vetor2[i] = vetor[i];
        }

}

int main(){
        int vetor[MAX];
        int vetorbubble[MAX];
        int vetorinsertion[MAX];
        int vetorselection[MAX];
        int vetorheap[MAX];
        int vetormerge[MAX];
        int vetorquick[MAX];
        float vTempobubble[10], vComparacoesbubble[10], vTrocasbubble[10];
        float vTempoinsertion[10], vComparacoesinsertion[10], vTrocasinsertion[10];
        float vTemposelection[10], vComparacoesselection[10], vTrocasselection[10];
        float vTempomerge[10], vComparacoesmerge[10], vTrocasmerge[10];
        float vTempoheap[10], vComparacoesheap[10], vTrocasheap[10];
        float vTempoquick[10], vComparacoesquick[10], vTrocasquick[10];


        struct timeval antesbubble, depoisbubble;
        struct timeval antesinsertion, depoisinsertion;
        struct timeval antesselection, depoisselection;
        struct timeval antesmerge, depoismerge;
        struct timeval antesheap, depoisheap;
        struct timeval antesquick, depoisquick;

        float deltabubble, tempoMediobubble;
        float deltainsertion, tempoMedioinsertion;
        float deltaselection, tempoMedioselection;
        float deltamerge, tempoMediomerge;
        float deltaheap, tempoMedioheap;
        float deltaquick, tempoMedioquick;


        float comparacoesMediabubble, trocasMediabubble;
        float comparacoesMediainsertion, trocasMediainsertion;
        float comparacoesMediaselection, trocasMediaselection;
        float comparacoesMediamerge, trocasMediamerge;
        float comparacoesMediaheap, trocasMediaheap;
        float comparacoesMediaquick, trocasMediaquick;

        int i=0;

        for(i=0; i < 10; i++) {
                GerarNumeros(vetor, MAX);
                ClonaVetor(vetor, vetorbubble);
                ClonaVetor(vetor, vetorinsertion);
                ClonaVetor(vetor, vetorselection);
                ClonaVetor(vetor, vetormerge);
                ClonaVetor(vetor, vetorheap);
                ClonaVetor(vetor, vetorquick);
                /////////////////////////////bubbleSort
                gettimeofday(&antesbubble, 0);
                bubbleSort(vetor, MAX);
                gettimeofday(&depoisbubble, 0);

                deltabubble = (depoisbubble.tv_sec + depoisbubble.tv_usec/1000000.0) - (antesbubble.tv_sec  + antesbubble.tv_usec /1000000.0);

                vComparacoesbubble[i] = comparacoesbubble;
                vTrocasbubble[i] = trocasbubble;
                vTempobubble[i] = deltabubble;

                comparacoesbubble=0;
                trocasbubble=0;

                /////////////////////////////////////////////////insertionSort
                gettimeofday(&antesinsertion, 0);
                insertionSort(vetorinsertion, MAX);
                gettimeofday(&depoisinsertion, 0);

                deltainsertion = (depoisinsertion.tv_sec + depoisinsertion.tv_usec/1000000.0) - (antesinsertion.tv_sec  + antesinsertion.tv_usec /1000000.0);

                vComparacoesinsertion[i] = comparacoesinsertion;
                vTrocasinsertion[i] = trocasinsertion;
                vTempoinsertion[i] = deltainsertion;

                comparacoesinsertion=0;
                trocasinsertion=0;
                /////////////////////////////////////////////////selectionSort
                gettimeofday(&antesselection, 0);
                selectionSort(vetorselection, MAX);
                gettimeofday(&depoisselection, 0);

                deltaselection = (depoisselection.tv_sec + depoisselection.tv_usec/1000000.0) - (antesselection.tv_sec  + antesselection.tv_usec /1000000.0);

                vComparacoesselection[i] = comparacoesselection;
                vTrocasselection[i] = trocasselection;
                vTemposelection[i] = deltaselection;

                comparacoesselection=0;
                trocasselection=0;
                /////////////////////////////////////////////////mergeSort
                gettimeofday(&antesmerge, 0);
                mergeSort(vetormerge, 0, MAX);
                gettimeofday(&depoismerge, 0);

                deltamerge = (depoismerge.tv_sec + depoismerge.tv_usec/1000000.0) - (antesmerge.tv_sec  + antesmerge.tv_usec /1000000.0);

                vComparacoesmerge[i] = comparacoesmerge;
                vTrocasmerge[i] = trocasmerge;
                vTempomerge[i] = deltamerge;

                comparacoesmerge=0;
                trocasmerge=0;

                /////////////////////////////////////////////////heapSort
                gettimeofday(&antesheap, 0);
                heapSort(vetor, MAX);
                gettimeofday(&depoisheap, 0);

                deltaheap = (depoisheap.tv_sec + depoisheap.tv_usec/1000000.0) - (antesheap.tv_sec  + antesheap.tv_usec /1000000.0);

                vComparacoesheap[i] = comparacoesheap;
                vTrocasheap[i] = trocasheap;
                vTempoheap[i] = deltaheap;

                comparacoesheap=0;
                trocasheap=0;

                /////////////////////////////////////////////////quickSort
                gettimeofday(&antesquick, 0);
                quickSort(vetorquick,0, MAX);
                gettimeofday(&depoisquick, 0);

                deltaquick= (depoisquick.tv_sec + depoisquick.tv_usec/1000000.0) - (antesquick.tv_sec  + antesquick.tv_usec /1000000.0);

                vComparacoesquick[i] = comparacoesquick;
                vTrocasquick[i] = trocasquick;
                vTempoquick[i] = deltaquick;

                comparacoesquick=0;
                trocasquick=0;
                ///////////////////

        }

        comparacoesMediabubble = tirarMediaF(vComparacoesbubble,10);
        trocasMediabubble = tirarMediaF(vTrocasbubble,10);
        tempoMediobubble = tirarMediaF(vTempobubble,10);


        comparacoesMediainsertion = tirarMediaF(vComparacoesinsertion,10);
        trocasMediainsertion = tirarMediaF(vTrocasinsertion,10);
        tempoMedioinsertion = tirarMediaF(vTempoinsertion,10);

        comparacoesMediaselection = tirarMediaF(vComparacoesselection,10);
        trocasMediaselection = tirarMediaF(vTrocasselection,10);
        tempoMedioselection = tirarMediaF(vTemposelection,10);

        comparacoesMediamerge = tirarMediaF(vComparacoesmerge,10);
        trocasMediamerge = tirarMediaF(vTrocasmerge,10);
        tempoMediomerge = tirarMediaF(vTempomerge,10);

        comparacoesMediaheap = tirarMediaF(vComparacoesheap,10);
        trocasMediaheap = tirarMediaF(vTrocasheap,10);
        tempoMedioheap = tirarMediaF(vTempoheap,10);

        comparacoesMediaquick = tirarMediaF(vComparacoesquick,10);
        trocasMediaquick = tirarMediaF(vTrocasquick,10);
        tempoMedioquick = tirarMediaF(vTempoquick,10);
        printf("\n////////////////////////////////////////\n");
        printf("\n\n\nTempo do bubbleSort: %f", tempoMediobubble);
        printf("\nComparacoes do bubbleSort: %f", comparacoesMediabubble);
        printf("\nTrocas do bubbleSort: %f", trocasMediabubble);

        printf("\n////////////////////////////////////////\n");
        printf("\n\n\nTempo do insertionSort: %f", tempoMedioinsertion);
        printf("\nComparacoes do : %f", comparacoesMediainsertion);
        printf("\nTrocas do : %f", trocasMediainsertion);

        printf("\n////////////////////////////////////////\n");
        printf("\n\n\nTempo do selectionSort: %f", tempoMedioselection);
        printf("\nComparacoes do selectionSort: %f", comparacoesMediaselection);
        printf("\nTrocas do selectionSort: %f", trocasMediaselection);

        printf("\n////////////////////////////////////////\n");
        printf("\n\n\nTempo do mergeSort: %f", tempoMediomerge);
        printf("\nComparacoes do mergeSort: %f", comparacoesMediamerge);
        printf("\nTrocas do mergeSort: %f", trocasMediamerge);

        printf("\n////////////////////////////////////////\n");
        printf("\n\n\nTempo do heapSort: %f", tempoMedioheap);
        printf("\nComparacoes do heapSort: %f", comparacoesMediaheap);
        printf("\nTrocas do heapSort: %f", trocasMediaheap);

        printf("\n////////////////////////////////////////\n");
        printf("\n\n\nTempo do quickSort: %f", tempoMedioquick);
        printf("\nComparacoes do quickSort : %f", comparacoesMediaquick);
        printf("\nTrocas do quickSort : %f", trocasMediaquick);

        return 0;
}
