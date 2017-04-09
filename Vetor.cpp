#include <iostream>
#include <vector>
//#include "gettimeofday.cpp"
using namespace std;

typedef vector<int>vetor;



void ExibeVetor(vetor &v)
{

        for (int i=0; i<v.size(); i++)

        {
                cout << v[i]<<endl;
        }

}
