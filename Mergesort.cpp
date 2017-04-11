#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void merge(vector<int> aVector, int size, int low, int middle, int high){
    int temp[size];
    for(int i = low; i <= high; i++){
        temp[i] = aVector[i];
    }
    int i = low;
    int j = middle+1;
    int k = low;

    while (i <= middle && j <= high){
        if(temp[i] <= temp[j]){
            aVector[k] = temp[i];
            ++i;
        }
        else {
            aVector[k] = temp[j];
            ++j;
        }
        ++k;
    }
    while (i <= middle){
        aVector[k] = temp[i];
        ++k;
        ++i;
    }
}

void mergeSort(vector<int> aVector, int size, int low, int high){
    if (low < high){
        int middle = (low + high) / 2;
        mergeSort(aVector, size, low, middle);
        mergeSort(aVector, size, middle+1, high);
        merge(aVector, size, low, middle, high);
    }
}
int main()
{
    const int size = 5;
	vector<int> aVector;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {

		int b = rand() % 9 + 1;


       aVector.push_back(7);
       aVector.push_back(3);
       aVector.push_back(4);
       aVector.push_back(1);
       aVector.push_back(10);

        cout << aVector[i] << " ";
        mergeSort(aVector, size, 0, 10);
	}
	return 0;
}
