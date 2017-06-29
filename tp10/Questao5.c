#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 32000

void quickSort(int* vetor, int esquerda,int direita){
	int i,j,x,y;
	i=esquerda;
	j=direita;
	x=vetor[(esquerda+direita)/2];

	do{
		while(vetor[i]<x && i<direita){
			i++;
		}
		while(x<vetor[j]&& j>esquerda){
			j--;
		}
		if(i<=j){
			y=vetor[i];
			vetor[i]=vetor[j];
			vetor[j]=y;
			i++;
			j--;
		}
	}while(i<=j);

	//chamada recursiva
	if(esquerda<j){
		quickSort(vetor,esquerda,j);
	}
	if(i<direita){
		quickSort(vetor,i,direita);
	}
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int main(){
clock_t begin, end;
double time_spent;
int v[N];
int i, j;

srand((unsigned)time(NULL));
    for(i=0;i<N;i++){
        v[i] = rand()%(N-1)+1;
        if(i% 10 == 0){
            //printf("\n");
        }
        //printf(" %3d",v[i]);
    }

begin = clock();
quickSort(v,0,N-1);
end = clock();
time_spent =(double)(end - begin) / CLOCKS_PER_SEC;
printf("Tempo da execucao: %.20f\n",time_spent);

/*
for (j=0; j<N; j++){
printf("valores: %d\n",v[j]);
}
*/

}