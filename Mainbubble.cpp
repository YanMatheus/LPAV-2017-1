#include <iostream>
#include "Bubble.cpp"
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

int main (int argc, char * argv[])
{
        float tempvar = 0;
        float tempvar2 = 0;
        float res = 0;


        float delta, delta2;

        for (int k = 0; k < 8; k++) {

                struct timeval antes, depois;


                gettimeofday (&antes, 0);
                sleep (2);
                vetor v;
                srand((unsigned)time(NULL));

                for (int i = 0; i < 1000; i++) {

                        int b = rand() % 9 + i;


                        v.push_back(b);

                }

                cout<<"\nvetor desordenado";

                ExibeVetor(v);
                BubbleSort (v);

                cout<<"\nvetor ordenado";

                ExibeVetor(v);




                gettimeofday (&depois, 0);

                delta = (depois.tv_sec + depois.tv_usec/1000000.0) -
                        (antes.tv_sec  + antes.tv_usec /1000000.0);
                printf ("\n\nDiferenca de %f segundos\n", delta);

                delta2 = ((depois.tv_sec * 1000000 + depois.tv_usec)
                          - (antes.tv_sec * 1000000 + antes.tv_usec));
                printf ("\n\nDiferenca de %f microsegundos\n", delta2);

                tempvar += delta;
                tempvar2 += delta2;

        }
        tempvar += tempvar/8;
        tempvar2 += tempvar2/8;
printf ("\n\nMedia %f segundos\n", tempvar);
printf ("\n\nMedia de %f microsegundos\n", tempvar2);


}
