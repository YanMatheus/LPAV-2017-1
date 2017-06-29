#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 4


struct reg {
        int *inicio;
        int *fim;
        int *vet;
        int n;

};

int somatorio[N];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;



void * function (void *arg) {

        struct reg *valor;
        valor = (struct reg*) arg;
        printf("inicio %d\n",valor->inicio[valor->n]);
        printf("fim %d\n",valor->fim[valor->n]);


        int i;


        for (i = valor->inicio[valor->n]; i < valor->fim[valor->n]; i++) {
                pthread_mutex_lock(&mutex);
                somatorio[valor->n] += valor->vet[i];
                pthread_mutex_unlock(&mutex);
        }


}


int* geradorDeNumeros(int M, int K){

        unsigned short seed[]={12,1,2};
        int i;
        int *vetor = malloc(sizeof(int)*M);

        for(i=0; i<M; i++)
                vetor[i] = 1 + K * erand48(seed);

        return vetor;
}



int main () {

        clock_t time1, time2, time_diff;
        int qtdnum, intervalo, *vet;


        struct timeval antes, depois;
        float delta, delta2;
        int K = (2048*1024);
        qtdnum = K;
        intervalo = 10000;
        vet = geradorDeNumeros(qtdnum, intervalo);



        pthread_t threads[N];
        int vetFim[N];
        int vetIni[N];
        int result  = K / N;

        vetFim[0] = result;
        vetIni[0] = 0;
        int l = 1;
        while(l < N) {
                vetIni[l] = vetFim[l-1];
                vetFim[l] = vetFim[l-1] + result;
                l++;
        }

        struct reg x;
        x.inicio = vetIni;
        x.fim = vetFim;
        x.vet = vet;


        struct  reg aux[N];

        for(int i = 0; i < N; i++) {
                aux[i] = x;
                aux[i].n = i;
        }




        int i = 0;
        gettimeofday (&antes, 0);

        for(i = 0; i < N; i++) {
                pthread_create(&threads[i], NULL, function, (void *)(&aux[i]));
        }

        for(i = 0; i < N; i++) {
                pthread_join(threads[i], NULL);
        }
        gettimeofday (&depois, 0);

        printf("Somatorio %d\n",somatorio[0]);










        delta = (depois.tv_sec + depois.tv_usec/1000000.0) -
                (antes.tv_sec  + antes.tv_usec /1000000.0);


        delta2 = ((depois.tv_sec * 1000000 + depois.tv_usec)
                  - (antes.tv_sec * 1000000 + antes.tv_usec));

        printf("Tempo de execução em segundos %f segundos & Diferenca de %f microsegundos\n\n", delta, delta2);




        exit(0);
}
