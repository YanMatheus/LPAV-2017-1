#include "Vetor.cpp"
void insertionSort (vector<int> data, int n)
{
int i, j, tmp;

 for (i=1; i<n; i++)
 {
     j=i;
     tmp=data[i];
     while (j>0 && tmp<data[j-1])
     {
           data[j]=data[j-1];
           j--;
     }
     data[j]=tmp;
 }

        cout << "insertion sort" << endl;
        system("pause");
        insertionSort(5, i);
      }
