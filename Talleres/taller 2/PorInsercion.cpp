void MostrarVector(long *,int);
void ordInsercion (long *, int);
int main(){
    long MiVector[]={4,8,2,9,4,6,7,2,1,9,3,10,5,6,1};
    MostrarVector(MiVector,15);
    ordInsercion(MiVector,15);   
    printf("\n");
    MostrarVector(MiVector,15);
    printf("\n");
    system("pause");
    return 0;
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