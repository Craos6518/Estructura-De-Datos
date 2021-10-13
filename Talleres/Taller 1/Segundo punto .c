#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void Llenar_Vector(int);
void Buscar_Datos(int *);
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
    for(int i=0; i<Tamano; i++){
        printf("\nIngrese el valor en la posicion %d: ", i);
        scanf("%d",&Casillero[i]);
    }
    Buscar_Datos(Casillero);
}

void Buscar_Datos(int *Casillero){
    int Buscado=0, Bandera=0;
    printf("\nIngrese el valor a buscar: ");
    scanf("%d",&Buscado);
    for(int i=0; i<sizeof(Casillero); i++){
        if(Casillero[i] == Buscado){
            Bandera =1;
        }
    }
    if(Bandera == 0){
        fflush(stdin);
        char Opcion[1];
        printf("\nNo se encontro el Valor a buscar\nDesea Buscar otro numero: [Y/N]: ");
        gets(Opcion);
        fflush(stdin);
        if((strcmp(Opcion, "y")== 0) || (strcmp(Opcion, "Y"))){
            Buscar_Datos(Casillero);
            system("cls");
        }
    }
    else{
        printf("\nEl Valor Existe en el VECTOR\n");
    }
}