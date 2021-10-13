#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

typedef struct _nodo {
    int dato;
    struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

int main(){
    TipoLista Lista = NULL; //Inicio de listas en Nulo
    int Opcion =0,Tamano =0, Random=0;
    do{
        system("cls");
        printf("\t\tMENU\n");
        printf("\t1. Ingresar tama%co\n",165);
        printf("\t2. Llenar lista\n");
        printf("\t3. Mostrar la lista.")
        printf("\t4. Generar numero aleatorio(masacre)");
        scanf("%d",&Opcion);
        switch(Opcion){
            case 1:
                system("cls");
                printf("Ingrese el tama%co: %d\n",165);
                scanf("%d",&Tamano);
            break;
            case 2:
                system("cls");
                if(Tamano > 2){
                    for(int i=0; i<Tamano; i++){
                        Insertar(Lista, i);
                    }
                }
                else{
                    printf("El tama%co ingresado no esta permitido",165);
                }
            break;
            case 3:
                if(Lista != NULL){
                    MostrarLista(Lista);
                }
                else{
                    printf("La lista esta vacia");
                }
            break;
            case 4:
                Random=GenerarAleatoreo();
            break;

        }
    }       
}

void Insertar(TipoLista &lista, int valor){
    TipoLista q;
    q = new(struct nodo);
    q->dato = valor;
    q->siguiente = lista;
    lista  = q;
}

void MostrarLista(TipoLista &lista){

	int i = 0;
	system("cls");
	while(lista != NULL)
	{
		cout<<' '<< i+1 <<") "<< lista->nro<<endl;
		lista = lista -> sgte;
		i++;
	}
}

int GenerarAleatoreo(){
    //prueba
    
}