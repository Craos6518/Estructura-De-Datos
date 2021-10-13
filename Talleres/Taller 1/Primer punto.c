#include <stdio.h>
#include <windows.h>
void Llenar_Vector(int);
void Sumar_Datos(int *);
int main(){
    int Tamano=0;
    printf("Ingrese el TAMA%cO del Vector: ",165);
    scanf("%d",&Tamano);
    Llenar_Vector(Tamano);
    system("pause");
    return 0;   
}

void Llenar_Vector(int Tamano){
    int Casillero[Tamano];
    for(int i=0; i<sizeof(Casillero); i++){
        printf("\nIngrese el valor en la posicion %d: ", i);
        scanf("%d",&Casillero[i]);
    }
    Sumar_Datos(Casillero);
}

void Sumar_Datos(int *Casillero){
    int Anterior=0;
    for(int i=0; i<sizeof(Casillero); i++){
        Anterior +=Casillero[i];
    }
    printf("\nLa suma de todos los elementos es %d\n", Anterior);
}