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

#include <iostream>

#include <vector>

using namespace std;

void quickSort(vector<int>&,int,int);

int partition(vector<int>&, int,int);

int main()
{
    vector<int> A = {6,10,13,5,8,3,2,25,4,11};
    int p=0;
    int q=10;

    cout<<"======Original======="<<endl;
    for(auto e: A)
        cout<< e <<" ";
    cout<< endl;    

    quickSort(A,p,q);

    cout<<"======Sorted======="<<endl;
    for(auto e: A)
        cout<< e <<" ";
    cout<< endl;   
}


void quickSort(vector<int>& A, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(A, p,q);
        quickSort(A,p,r);  
        quickSort(A,r+1,q);
    }
}


int partition(vector<int>& A, int p,int q)
{
    int x= A[p];
    int i=p;
    int j;

    for(j=p+1; j<q; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(A[i],A[j]);
        }

    }

    swap(A[i],A[p]);
    return i;
}
}

#include <iostream>
#include <vector>
using namespace std;

/**
 * Partition the elements of A, such that you first have elements smaller than
 * "who", followed by eleemnts larger than "who". Return the last poistion of an
 * element smaller or equal to "who".
 */
int partition(vector<int>& A, int left, int right, int who) {
  for (int i=left; i<right; ++i) {
    if (A[i] <= who) {
      swap(A[i], A[left]);
      left ++;
    }
  }
  return left - 1;
}

/**
 * Quick sort vector A, between index "left" and index "right".
 */
void qsort(vector<int>& A, int left, int right) {
  if (left >= right) return;
  
  int middle = left + (right - left) / 2;
  swap(A[middle], A[left]);
  int midpoint = partition(A, left + 1, right, A[left]);
  swap(A[left], A[midpoint]);
  qsort(A, left, midpoint);
  qsort(A, midpoint + 1, right);
}

void printVector(vector<int>& A) {
  for (int i=0; i<A.size(); ++i) {
    cout << A[i] << " ";
  }
  cout << endl;
}

void testPartition() {
  int elements[] = {1, 3, 1, 1, 3};
  vector<int> A(elements, elements + 5);
  int n = partition(A, 0, 5, 1);
  cout << n << endl;
  printVector(A);
}

void testSort() {
  int elements[] = {1, 12, 2, 2, 2, 6, 20, 22};
  vector<int> A(elements, elements + 8);
  qsort(A, 0, A.size());
  printVector(A);
}

int main ()
{
  testPartition();
  cout << "---------------" << endl;
  testSort();
  return 0;
}
