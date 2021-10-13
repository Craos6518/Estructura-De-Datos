#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void quicksort(long a[], int primero, int ultimo)
{
int i, j, central;
double pivote;
central = (primero + ultimo)/2;
pivote = a[central];
i = primero;
j = ultimo;
do {
while (a[i] < pivote) i++;
while (a[j] > pivote) j--;
if (i<=j)
{
double tmp;
tmp = a[i];
a[i] = a[j];
a[j] = tmp; /* intercambia a[i] con a[j] */
i++;
j--;
}
}while (i <= j);
if (primero < j)
quicksort(a, primero, j);/* mismo proceso con sublista izqda */
if (i < ultimo)
quicksort(a, i, ultimo); /* mismo proceso con sublista drcha */
}

void MostrarVector(long MiVector[],int tam){
    for(int i=0;i<tam;i++){
        cout<<MiVector[i]<<" ";
    }
}


int main(){
    long MiVector[]={4,8,2,9,4,6,7,2,1,9,3,10,5,6,1};
    MostrarVector(MiVector,15);
    quicksort(MiVector,0,14);   
    cout<<endl;
    MostrarVector(MiVector,15);
    cout<<endl;
    system("pause");
    return 0;
}
