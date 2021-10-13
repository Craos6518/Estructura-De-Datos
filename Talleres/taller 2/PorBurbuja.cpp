#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void MetodoBurbuja (long *, int );
void MostrarDelVector(long *,int);

int main(){
    long MiVector[]={4,8,2,9,4,6,7,2,1,9,3,10,5,6,1};
    MostrarDelVector(MiVector,15);
    MetodoBurbuja(MiVector,15);   
    cout<<endl;
    MostrarDelVector(MiVector,15);
    cout<<endl;
    system("pause");
    return 0;
}


void MostrarVector(long *MiVector,int Tamano){
    for(int i=0;i<Tamano;i++){
        printf(" %d ",*(MiVector+i));
    }
}


void MetodoBurbuja (long *a, int n){
    int interruptor = 1;
    int pasada, j;
    for (pasada = 0; pasada < n-1 && interruptor; pasada++){
        /* bucle externo controla la cantidad de pasadas */
        interruptor = 0;
        for (j = 0; j < n-pasada-1; j++)
            if (*(a+j) > *(a+j+1)){
                /* elementos desordenados, es necesario intercambio */
                long aux;
                interruptor = 1;
                aux = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = aux;
            }
    }
}


