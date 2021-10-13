#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menu();
void CapturarYValidar();
void PorInsercion();
void LlenarVector(long *,int);
void MostrarVector(long *,int);
void ordInsercion (long *, int);
void Burbuja();
void MetodoDeLaBurbuja(long *, int);
void Quicksort();
void MetodoQuicksort(long *, int, int);
void Shellsort();
void ordenacionShell(long *, int);

struct Numeros{
    char Num[3];
}Numeros;

int main(){
    Menu();
    system("pause");
}

void Menu(){
    system("cls");
    printf("\t\t    Menu\n\t==============================\n");
    printf("\t| 1.Por Insercion Directa.   |\n\t==============================\n\t| 2. Por Metodo de Burbuja.  |\n\t==============================\n\t| 3.Por Quicksort.           |\n\t==============================\n\t| 4.Por Shellsort.           |\n\t==============================\n\t| 5. Salir.                  |\n\t==============================\n");
    CapturarYValidar();
}

void CapturarYValidar(){
    int Opcion=0;
    printf("\nIngrese la opcion: ");
    scanf("%d",&Opcion);
    fflush(stdin);
    if(Opcion <= 5 && Opcion >=0){
        switch(Opcion){
            case 1:
            PorInsercion();
            break;
            case 2:
            Burbuja();
            break;
            case 3:
            Quicksort();
            break;
            case 4:
            Shellsort();
            break;
            
            default:
            printf("\n Saliendo del aplicativo.\n");
        }
    }
}

void PorInsercion(){
    system("cls");
    printf("\tMetodo de Insercion Directa\n");
    long MiVector[10000];
    LlenarVector(MiVector,10000);
    MostrarVector(MiVector,10000);
    ordInsercion(MiVector,10000);   
    printf("\n");
    MostrarVector(MiVector,10000);
    getchar();
    fflush(stdin);
    Menu();
}

void LlenarVector(long *MiVector,int Tamano){
    char Valor[2];
    char Valor2;
    FILE *Ptr;
    char VectorSecundario[10000];
    Ptr = fopen("datos.txt","rb");
    if(Ptr==NULL){
        printf("Error al abrir el fichero\n");
        getchar();
        fflush(stdin);
        Menu();
    }
    else{
        for(int i=0; i < Tamano; i++){
            fread(&Numeros, sizeof(Numeros), 1,Ptr);
            fflush(stdin);
            if(Numeros.Num[0]==9){
                if(Numeros.Num[2]==9){
                    *(MiVector+i)=atoi((Numeros.Num[2]));
                }
                else{
                    Numeros.Num[0]=Numeros.Num[1];
                    Numeros.Num[1]=Numeros.Num[2];
                    fread(&Valor, sizeof(Valor), 1,Ptr);
                    if(Valor[1]== 9){
                        Numeros.Num[2]=Valor[0];
                        *(MiVector+i)=atoi(Numeros.Num);
                        printf("%d ", *(MiVector+i));
                    }
                    else{
                        Valor2=Valor[1];
                        Valor[0]=Numeros.Num[0];
                        Valor[1]=Numeros.Num[1];
                        *(MiVector+i)=atoi(Valor);
                        printf("%d ", *(MiVector+i));
                    }
                    
                }
            }
            else if(Numeros.Num[1]==9){
                Valor[1]=Numeros.Num[1];
                
            }
            else{
                *(MiVector+i)=atoi(Numeros.Num);
                printf("%d ", *(MiVector+i));
            }
            
        }
    }

}
void MostrarVector(long *MiVector,int Tamano){
    for(int i=0;i<Tamano;i++){
        printf(" %d ",*(MiVector+i));
    }
}

void ordInsercion (long *MiVector, int Tamano){
    int j;
    int aux;
    for (int i = 1; i < Tamano; i++){
        /* índice j explora la sublista a[i-1]..a[0] buscando la
        posición correcta del elemento destino, lo asigna a a[j] */
        j = i;
        aux = *(MiVector+i);
        /* se localiza el punto de inserción explorando hacia abajo */
        while (j > 0 && aux < *(MiVector+(j-1))){
            /* desplazar elementos hacia arriba para hacer espacio */
            *(MiVector+j) = *(MiVector+(j-1));
            j--;
        }
        *(MiVector+j) = aux;
    }
}

void Burbuja(){
    system("cls");
    printf("\tMetodo de Burbuja\n");
    long MiVector[10000];
    LlenarVector(MiVector,10000);
    MostrarVector(MiVector,10000);
    MetodoDeLaBurbuja(MiVector,10000);   
    printf("\n");
    MostrarVector(MiVector,10000);
    getchar();
    fflush(stdin);
    Menu();
    
}

void MetodoDeLaBurbuja(long *MiVector, int n){
    int interruptor = 1;
    int pasada, j;
    for (pasada = 0; pasada < n-1 && interruptor; pasada++){
        // bucle externo controla la cantidad de pasadas //
        interruptor = 0;
        for (j = 0; j < n-pasada-1; j++){
            if (*(MiVector+j) > *(MiVector+(j+1))){
                // elementos desordenados, es necesario intercambio //
                long aux;
                interruptor = 1;
                aux = *(MiVector+j);
                *(MiVector+j) = *(MiVector+(j+1));
                *(MiVector+(j+1)) = aux;
            }
        }
    }
}

void Quicksort(){
    system("cls");
    printf("\tMetodo de Quicksort\n");
    long MiVector[10000];
    LlenarVector(MiVector,10000);
    MostrarVector(MiVector,10000);
    MetodoQuicksort(MiVector,0,9999);   
    printf("\n");
    MostrarVector(MiVector,10000);
    getchar();
    fflush(stdin);
    Menu();
}

void  MetodoQuicksort(long *a, int primero, int ultimo){
    int i, j, central;
    double pivote;
    central = (primero + ultimo)/2;
    pivote = a[central];
    i = primero;
    j = ultimo;
    do {
        while (a[i] < pivote) i++;
            while (a[j] > pivote) j--;
                if (i<=j){
                    double tmp;
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp; /* intercambia a[i] con a[j] */
                    i++;
                    j--;
                }
    }
    while (i <= j);
        if (primero < j){
             MetodoQuicksort(a, primero, j);/* mismo proceso con sublista izqda */
            if (i < ultimo){
                 MetodoQuicksort(a, i, ultimo); /* mismo proceso con sublista drcha */
            }
        }
}

void Shellsort(){
    long MiVector[10000];
    LlenarVector(MiVector,10000);
    MostrarVector(MiVector,10000);
    ordenacionShell(MiVector,10000);   
    printf("\n");
    MostrarVector(MiVector,10000);
    getchar();
    fflush(stdin);
    Menu();
}

void ordenacionShell(long *a, int n){
    int intervalo, i, j, k;
    intervalo = n / 2;
    while (intervalo > 0){
        for (i = intervalo; i < n; i++){
            j=i- intervalo;
            while (j >= 0){
                k=j+ intervalo;
                if (*(a+j) <= *(a+k))
                    j = -1; /* así termina el bucle, par ordenado */
                else{
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