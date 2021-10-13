#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct nodo{
   int valor;// Valor que va tener la estructura en cada uno en este caso es un numero entero
   struct nodo *siguiente; //Apuntador hacia el siguiente nodo o enlace
};

typedef struct nodo *TipoLista; //Definicion del nombre de la lista
//declaracion de funciones que posee la listas
void Insertar(TipoLista &l, int v); 
void Valor(TipoLista &l, int v);

//*****************************

int main(){
   TipoLista lista = NULL;//nicio de listas en Nulo
   int op,x;
   do{
    printf("***MENU***\n\n");
    system("cls");
    printf("\t1. Llenar la lista.");
    printf("\n\t2. Buscar valor en la lista.");
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
            printf("Digite el valor a buscar: ");
            scanf("%d",&x);
            Valor(lista,x);
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


//Buscar valor
void Valor(TipoLista &lista, int Valor1){
	TipoLista q =lista;
	int i = 0;
	while(lista){
		if(q->valor ==Valor1){
			i++;
		}
		q=q->siguiente;
	}
	if(i != 0){
		printf("\n\nSe encontro %d veces en la lista.",i);
	}
	else{
		printf("\n\nNumero no encontrado");
	}
}

//***********

//Insertar registro
void Insertar(TipoLista &lista, int valor)
{
   TipoLista nuevo;
   nuevo = new(struct nodo);
   nuevo->valor = valor;
   nuevo->siguiente = lista;
   lista  = nuevo;
}
 //**************************
