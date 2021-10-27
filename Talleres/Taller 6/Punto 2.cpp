#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
struct nodo{
    int valor;// Valor que va tener la estructura en cada uno en este caso es un numero entero
   struct nodo *siguiente; //Apuntador hacia el siguiente nodo o enlace
};

typedef struct nodo *TipoLista; //Definicion del nombre de la lista
//declaracion de funciones que posee la listas
void Insertar(TipoLista &l, int v); 
void Invertir(TipoLista &l);
void Mostrar(TipoLista &l);

int main(){
    TipoLista lista = NULL;//nicio de listas en Nulo
    int op,x;
    do{
        system("cls");
        printf("***MENU***\n\n");
        printf("\t1. Llenar la lista.");
        printf("\n\t2. Invertir lista");
        printf("\n\t3. Salir.");
        printf("\n\tIngrese la opcion: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                do {  //SE CREAUNA LISTA HASTA QUE EL USUARIO PRECIONE 0
                system("cls");
                printf("Digite  Cero (0) para salir\n");
                printf("Digite el dato que desea agregar:");
                scanf("%d",&x);
                if (x!=0)
                    Insertar(lista,x);//ENVIO DE VALOR AL PROCESO DE INSERTAR DATOS A LISTA
                }while (x!=0);
                getch();
            break;
            case 2:
                Mostrar(lista);
                Invertir(lista);
                Mostrar(lista);
                getch();
            break;
            case 3:
                printf("Saliendo del aplicativo");
                getch();
            break;
        }
    } while(op!=3);
    getchar();
    return 0;
}

//***********

//Insertar registro
void Insertar(TipoLista &lista, int valor){
    TipoLista nuevo;
    nuevo = new(struct nodo);
    nuevo->valor = valor;
    nuevo->siguiente = lista;
    lista  = nuevo;
}
//**************************

void Mostrar(TipoLista &lista){

	TipoLista p;
	p = lista;
	int i = 0;
	system("cls");
	while(p != NULL)
	{
		cout<<' '<< i+1 <<") "<< p->valor<<endl;
		p = p -> siguiente;
		i++;
	}
}

//********************************
void Invertir(TipoLista &lista){
    TipoLista nuevo;
    TipoLista q=lista;
    nuevo = new(struct nodo);
    nuevo->valor =q->valor; ;
    nuevo->siguiente = lista;
    lista  = nuevo;
}