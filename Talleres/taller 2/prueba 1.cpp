#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

struct Numeros{
    char Num[5];
}Numeros;

void NumeroAleatorio(int *);
void Extraer(int *,int);


int main() {
    int Tama=0;
    NumeroAleatorio(&Tama);
    int MiVector[Tama]={};
    Extraer(MiVector,Tama);
    cout<<Tama;
    getchar();
    return 0;
}

void NumeroAleatorio(int *Aleatorio){
    srand(time(NULL));
    *Aleatorio=rand()%1000;
    return;
}

void Extraer(int *MiVector,int Tama){
    char Vector[1000]="";
    ifstream Numero;
    Numero.open("datos.txt");
    if(Numero.good()){
        cout<<"El archivo fue abierto correctamente..."<<endl;
        for(int i=0;i<Tama;i++){
            Numero>>Vector;
            *(MiVector+i)=atoi(Vector);
        }
    }
    Numero.close();
    for (int i=0;i<Tama;i++){
        cout<<*(MiVector+i)<<" ";
    }
    getchar();
    return;
}



