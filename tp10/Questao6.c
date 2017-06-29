
#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <time.h>

#define SWAP(x,y) do {\
    __typeof__(x) tmp = x;\
    x = y;\
    y = tmp;\
} while(0)


int partition(int *array, int left, int right, int pivot)
{
    int pivotValue = array[pivot];
    SWAP(array[pivot], array[right]);
    int storeIndex = left;
    for (int i=left ; i<right ; i++)
    {
        if (array[i] <= pivotValue)
        {
            SWAP(array[i], array[storeIndex]);
            storeIndex++;
        }
    }
    SWAP(array[storeIndex], array[right]);
    return storeIndex;
}
void dump(int *array, int size)
{
    for (int i=0 ; i<size ; i++)
    {
        printf("[%d] %d\n", i, array[i]);
    }
}

void quicksort(int *array, int left, int right)
{
     if (right > left)
     {
        int pivotIndex = left + (right - left)/2;
        pivotIndex = partition(array, left, right, pivotIndex);
        quicksort(array, left, pivotIndex-1);
        quicksort(array, pivotIndex+1, right);
     }
}
struct qsort_starter
{
    int *array;
    int left;
    int right;
    int depth;
};

void parallel_quicksort(int *array, int left, int right, int depth);


void* quicksort_thread(void *init)
{
    struct qsort_starter *start = init;
    parallel_quicksort(start->array, start->left, start->right, start->depth);
    return NULL;
}

void parallel_quicksort(int *array, int left, int right, int depth)
{
    if (right > left)
    {
        int pivotIndex = left + (right - left)/2;
        pivotIndex = partition(array, left, right, pivotIndex);
      if (depth-- > 0)
        {
            struct qsort_starter arg = {array, left, pivotIndex-1, depth};
            pthread_t thread;
            int ret = pthread_create(&thread, NULL, quicksort_thread, &arg);
            assert((ret == 0) && "Thread creation failed");
          parallel_quicksort(array, pivotIndex+1, right, depth);
            pthread_join(thread, NULL);
        }
        else
        {
            quicksort(array, left, pivotIndex-1);
            quicksort(array, pivotIndex+1, right);
        }
    }
}


int* geradorDeNumeros(int M, int K){

    unsigned short seed[]={12,1,2};
    int i;
    int *vetor = malloc(sizeof(int)*M);

    for(i=0;i<M;i++)
        vetor[i] = 1 + K * erand48(seed);

    return vetor;
}


int main()
{
    int depth = 0;



    clock_t time1, time2, time_diff;
  int qtdnum, intervalo, *vet;
   struct timeval antes, depois ;
   float delta, delta2 ;

    int K = (2048*1024) ;
    qtdnum = K;
    intervalo = 10000;
    vet = geradorDeNumeros(qtdnum, intervalo);




    gettimeofday (&antes, 0) ;

    parallel_quicksort(vet, 0, K-1, depth);


    gettimeofday (&depois, 0) ;


    delta = (depois.tv_sec + depois.tv_usec/1000000.0) -
                (antes.tv_sec  + antes.tv_usec /1000000.0) ;


    delta2 = ((depois.tv_sec * 1000000 + depois.tv_usec)
           - (antes.tv_sec * 1000000 + antes.tv_usec));

 	printf("Tempo de execução em segundos %f segundos & Diferenca de %f microsegundos\n\n", delta , delta2);


    return 0;
}
