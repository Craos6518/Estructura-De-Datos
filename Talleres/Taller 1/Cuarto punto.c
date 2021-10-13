#include <stdio.h>
#include <windows.h>
void Llenar_Vector(int);
void Invertir(int *, int);
int main(){
    int Tamano=0;  
    printf("Ingrese el TAMA%cO del Vector: ",165);
    scanf("%d",&Tamano);
    Llenar_Vector(Tamano);
    system("pause");
    return 0;   
}

void Llenar_Vector(int Tamano){
    int Casillero[Tamano], Casillero2[Tamano], Valor =0;
    for(int i=0; i<Tamano; i++){
        printf("\nIngrese el valor en la posicion %d: ", i);
        scanf("%d",&Valor);
        fflush(stdin);
        Casillero[i]= Valor;
        
    }
    Invertir(Casillero, (Tamano));
}
void Invertir(int *Casillero, int Tamano){
    int Casillero2 [Tamano], Tamano2 = Tamano, Valor=0;
    for(int i=0; i <Tamano; i++){
        Valor= Casillero[i];
        for(int j=(Tamano2-(i+1)); j>=0; j=j-1){
            Casillero2[j]=Valor;
            j=0;
        }
    }
    for(int i=0; i <Tamano; i++){
        printf(" %d ",Casillero[i]);
    }
    printf("\n");
    for(int i=0; i <Tamano; i++){
        printf(" %d ",Casillero2[i]);
    }
}
