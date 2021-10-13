#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int TamanoVector();
void LlenarVectores(int *, int *, int, int, int);
void CompararVectores(int *, int *, int, int);
int main(){
    int tamano1 =0, tamano2=0; 
    tamano1 = TamanoVector();
    int vec1 [tamano1];
    tamano2 = TamanoVector();
    int vec2 [tamano2];
    LlenarVectores(vec1, vec2, 0,tamano1,tamano2);
    CompararVectores(vec1, vec2, tamano1, tamano2);
    system("pause");
    return 0;
}

int TamanoVector(){
    srand (time(NULL));
    return rand() % 10;
}

void LlenarVectores(int *vec1, int *vec2, int Bandera, int Tamano1, int Tamano2){
    srand (time(NULL));
    int Tamano =0;
    if(Bandera == 0 || Bandera == 1){
        if(Bandera == 0){
            Tamano= Tamano1;
        }
        else{
            Tamano = Tamano2;
        }

        for(int i=0; i< Tamano; i++){
            if(Bandera == 0){
                vec1[i] = rand() %10;
            }
            else if(Bandera == 1){
                vec2[i] = rand() %10;
            }
        }
        Bandera++;
        LlenarVectores(vec1, vec2,Bandera,Tamano1, Tamano2);
    }
    return;
}

void CompararVectores(int *vec1, int *vec2, int Tamano1, int Tamano2){
    int  Bandera=0;
    if(Tamano1 == Tamano2){
        printf("Los vectores cumplen el primer requicito para determinar si son iguales\n");
        getchar();
        fflush(stdin);
        for(int i=0; i<Tamano1; i++){
            if(vec1[i]==vec2[i]){
                Bandera++;
            }
            else{
                i = Tamano1;
            }
        }
        if(Bandera != 0 && Bandera == Tamano1){
            printf("Los vectores son iguales\n");
            getchar();
            fflush(stdin);
        }
        else{
            printf("Los vectores son diferentes\n");
            getchar();
            fflush(stdin);
        } 
    }
    else{
        printf("Los vectores No cumplen el primer requicito para determinar si son iguales\n");
        getchar();
        fflush(stdin);
    }
    return;
}