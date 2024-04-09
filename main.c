#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"
#include <time.h>

void inicializaVectorRand(vectorD *v, short tamano)
{
    srand(time(NULL));
    for (unsigned long int i = 0; i < tamano; i++)
    {
        AsignaVector(v, i, (TELEMENTO)(rand()));
    }
}

void swap (vectorD *pvector, unsigned long m, unsigned long n){
    TELEMENTO aux, aux2;
    aux = Componentei(*pvector,m);
    aux2 = Componentei(*pvector,n);
    AsignaVector(pvector,m,aux2);
    AsignaVector(pvector,n,aux);
}

void quicksort(vectorD *pvector, unsigned long beg, unsigned long end)
{

    if (end > beg + 1)
    {

        TELEMENTO piv = Componentei(*pvector, beg);
        unsigned long l = beg + 1, r = end;
        while (l < r)
        {
            if (Componentei(*pvector, l) <= piv)
            {
                l++;
            }
            else
            {
                r--;
                swap(pvector, l, r);
            }
        }
        l--;
        swap(pvector, l, beg);

        quicksort(pvector, beg, l);

        quicksort(pvector, r, end);
    }
}
void bubblesort(vectorD *v, unsigned long int TAM)
{
    unsigned long int e, i;
    TELEMENTO aux;
    for (e = 0; e < (TAM - 1); e++)
        for (i = 0; i < (TAM - e - 1); i++)
            if (Componentei(*v, i) > Componentei(*v, i + 1))
            {
                aux = Componentei(*v, i);
                AsignaVector(v, i, Componentei(*v, i + 1));
                AsignaVector(v, i + 1, aux);
            }
}

void Selec(vectorD *v, unsigned long int TAM)
{
    unsigned long int e, i, PosMenor;
    TELEMENTO aux;
    for (e = 0; e < (TAM - 1); e++)
    {
        PosMenor = e;
        for (i = e + 1; i < TAM; i++)
            if (Componentei(*v, i) < Componentei(*v, PosMenor))
                PosMenor = i;
        aux = Componentei(*v, e);
        AsignaVector(v, e, Componentei(*v, PosMenor));
        AsignaVector(v, PosMenor, aux);
    }
}

int main(int argc, char **argv)
{
    unsigned long int tamano = 10;
    vectorD v;
    NuevoVector(&v);
    CreaVector(&v, tamano);
    inicializaVectorRand(&v, tamano);
    for (unsigned long int i = 0; i < tamano; i++)
    {
        printf("Elemento %lu: %d\n", i + 1, Componentei(v, i));
    }
    quicksort(&v, 0, tamano);
    printf("\n\nORDENADO CON SELEC:\n\n");
    for (unsigned long int i = 0; i < tamano; i++)
    {
        printf("Elemento %lu: %d\n", i + 1, Componentei(v, i));
    }
    LiberaVector(&v);
    return EXIT_SUCCESS;
}