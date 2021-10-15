#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
typedef struct _nodo {
    int dato;
    struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *TipoLista;

void Insertar(TipoLista &l, int v); 
void MostrarLista(TipoLista &l); 
int GenerarAleatoreo(int );
void eliminarElemento(TipoLista &l, int, int);

int main(){
    TipoLista Lista = NULL; //Inicio de listas en Nulo
    int Opcion =0,Tamano =0, Random=0;
    do{
        system("pause");
        system("cls");
        printf("\t\tMENU\n");
        printf("\t1. Ingresar tama%co\n",165);
        printf("\t2. Llenar lista\n");
        printf("\t3. Mostrar la lista.\n");
        printf("\t4. Generar numero aleatorio(masacre)\n");
        printf("\t5. Eliminar a alguien.\n");
        printf("\t Ingrese la opcion: ");
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
                    int Copia = Tamano;
                    for(int i=Tamano; i >=1; i--){
                        Insertar(Lista, i);
                    }
                    printf("\n\tHecho...!");
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
                    printf("La lista esta vacia\n");
                }
            break;
            case 4:
                Random=GenerarAleatoreo(Tamano);
            break;
            case 5:
                if(Lista!=NULL){
                    if(Tamano > 2){
                        eliminarElemento(Lista, Random, Tamano);
                    }
				}
                else{
                    printf("La lista esta vacia\n");
                }
            break;
        }
    }while(Opcion != 4);
}

void Insertar(TipoLista &lista, int valor){
    TipoLista q;
    q = new(struct _nodo);
    q->dato = valor;
    q->siguiente = lista;
    lista  = q;
}

void MostrarLista(TipoLista &lista){

	TipoLista p;
	p = lista;
	int i = 0;
	system("cls");
	while(p != NULL)
	{
		cout<<' '<< i+1 <<") "<< p->dato<<endl;
		p = p -> siguiente;
		i++;
	}
}

int GenerarAleatoreo(int Maximo){
    int ale=0;
    srand (time(NULL));       //[Instrucción que inicializa el generador de números aleatorios]
    ale= rand() %Maximo;
    ale =ale +1;
    return ale;
}

void eliminarElemento(TipoLista &Lista, int valor, int Tamano){
	TipoLista p, ant;
	p = Lista;
    int i=0;
	while(p!=NULL){
		if(p->dato==valor){
			if(p==Lista){
                Lista = Lista->siguiente;
            }
			else{
                ant->siguiente;
            }
                
			delete(p);
			Tamano--;
			return;
		}
		ant = p;
		p = p->siguiente;
		i++;
	}	
}