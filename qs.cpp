
#include <iostream>
#include "Vetor.cpp"
#include <vector>

using namespace std;

void quickSort(vector<int>&,int,int);

int partition(vector<int>&, int,int);




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


/*
int main()
{
    const int size = 1000;
	vector<int> A;


	for (int i = 0; i < 10; i++) {

		int b = rand() % 9 + 1;

		A.push_back(b);
        //cout << aVector[i] << " ";
        quickSort(A, 0, 10);
	}
	return 0;
}*/

int main()
{
    vector<int> A ;
    int p=0;
    int q=10;

    cout<<"======"<<endl;
    //for(auto e: A)
      //  cout<< e <<" ";
    cout<< endl;
    for (int i = 0; i < 10; i++) {

      int b = rand() % 9 + 1;

      A.push_back(b);
          //cout << aVector[i] << " ";
          quickSort(A, 0, 10);
    }
    ExibeVetor(A);
    quickSort(A,p,q);
      cout<<"======"<<endl;
        cout<<"======"<<endl;
    ExibeVetor(A);
  //cout<<"======"<<endl;
    //for(auto e: A)
    //    cout<< e <<" ";
  //  cout<< endl;
}
