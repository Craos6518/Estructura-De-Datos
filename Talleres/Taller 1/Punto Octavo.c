#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int TamanoVector();
void LlenarVectores(int *, int);
void MostrarDelVector(int *,int);
int main(){
    int tamano1 =0; 
    tamano1 = TamanoVector();
    int vec1 [tamano1];
    
    LlenarVectores(vec1,tamano1);
    MostrarDelVector(vec1,tamano1);
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
        vec1[i] = (rand() %10)+1;
    }
    return;
}

void MostrarDelVector(int *Vector,int Tamano){
    for(int i=0; i< Tamano; i++){
        printf("%d ",Vector[i]); 
    }
    printf("\n");
}