void quickSort(int* vetor, int esquerda,int direita){
	int i,j,x,y;
	i=esquerda;
	j=direita;
	x=vetor[(esquerda+direita)/2]; //elemento pivo

	//partição das listas
	do{
		//procura elementos maiores que o pivô na primeira parte
		while(vetor[i]<x && i<direita){
			i++;
		}
		//procura elementos menores que o pivo na segunda parte
		while(x<vetor[j]&& j>esquerda){
			j--;
		}

		//processor de troca (ordenação)
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
