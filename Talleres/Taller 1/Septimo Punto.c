#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int TamanoVector();
void LlenarVectores(int *, int);
void EliminarDelVector(int *,int);
int main(){
    int tamano1 =0; 
    tamano1 = TamanoVector();
    int vec1 [tamano1];
    
    LlenarVectores(vec1,tamano1);
    EliminarDelVector(vec1,tamano1);
    system("pause");
    return 0;
}

int TamanoVector(){
    srand (time(NULL));
    return rand() % 10;
}

void LlenarVectores(int *vec1,int Tamano1){
    srand (time(NULL));
    for(int i=0; i< Tamano1; i++){
        vec1[i] = rand() %10;
    }
    return;
}

void EliminarDelVector(int *vec1, int Tamano1){
    int  Bandera=0, Valor=0, Vector[Tamano1];
    printf("Ingrese el valor a eliminar: ");
    scanf("%d",&Valor);
    fflush(stdin);
    for(int i=0; i<Tamano1; i++){
        if(vec1[i] != Valor){
            Vector[i]=vec1[i];
        }
        else{
            Bandera++;
            Vector[i]=11;
        }
    }
    if(Bandera != 0){
        printf("\nSe elimino correctamente.\nEl nuevo vector es: ");
        for(int i=0; i< Tamano1; i++){
            if(Vector[i] != 11){
                printf("%d ", Vector[i]);
            }
            else{
                printf("- ");
            }
        }
    }
    printf("\n");
    printf("El tamano es de: %d \n",Tamano1);
    getchar();
    return;
}