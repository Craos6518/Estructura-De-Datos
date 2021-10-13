#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


void ordenacionShell(long *a, int n)
{
int intervalo, i, j, k;
intervalo = n / 2;
while (intervalo > 0)
{
for (i = intervalo; i < n; i++)
{
j=i- intervalo;
while (j >= 0)
{
k=j+ intervalo;
if (*(a+j) <= *(a+k))
j = -1; /* así termina el bucle, par ordenado */
else
{
double temp;
temp = *(a+j);
*(a+j) = *(a+k);
*(a+k) = temp;
j -= intervalo;
}
}
}
intervalo = intervalo / 2;
}
}



void MostrarVector(long *MiVector,int tam){
    for(int i=0;i<tam;i++){
        cout<<*(MiVector+i)<<" ";
    }
}


int main(){
    long MiVector[]={4,8,2,9,4,6,7,2,1,9,3,10,5,6,1};
    MostrarVector(MiVector,15);
    ordenacionShell(MiVector,15);   
    cout<<endl;
    MostrarVector(MiVector,15);
    cout<<endl;
    system("pause");
    return 0;
}
