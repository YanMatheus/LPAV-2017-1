#include "Vetor.cpp"

void BubbleSort(vetor &v)
{
        for (int i=0; i<v.size()-1; i++)
        {
                for (int j=0; j<v.size()-1; j++)
                {
                        if (v[j]>v[j+1])
                        {
                                swap (v[j],v[j+1]);
                        }

                }
        }
}


/*
int main()

{
        vetor v;

        v.push_back(7);
        v.push_back(3);
        v.push_back(4);
        v.push_back(1);
        v.push_back(10);

        cout<<"vetor desordenado";
        ExibeVetor (v);

        BubbleSort (v);

        cout<<"vetor ordenado";

        ExibeVetor (v);
        return 0;
}*/
