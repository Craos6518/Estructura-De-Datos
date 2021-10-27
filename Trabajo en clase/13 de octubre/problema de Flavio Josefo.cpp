/* TTRABAJO EN CLASE:
    Problema de Flavio Josefo.
    Asignatura: Estructura de datos.
    Autores: Jhon Sebastian Perez
            Andres Felipe Martinez
    Fecha: 20 Octubre 2021
    compilado en: gcc (MinGW.org GCC-6.3.0-1) 6.3.0 - Visual tudio Code 
*/
/*
    Nombre de la funcion: Insertar(int dato);
    Objetivo: Esta funcion se encarga de insertar los datos en la lista.
    Parametros: dato -> Es el dato a ingresar.
    Ejemplo: dato -> 1.
*/
/*
    Nombre de la funcion: Eliminar(double Random)
    Objetivo: Elimina el numero generado aleatoreamente,además, de creando el nuevo apuntador al sgte dato.
    Parametros: Random -> Es el dato aleatorio generador
    cont -> Contador usado para saber la posicion y poder eliminar el valor
    Ejemplo: Randmon -> 3
    Lista existente: 1 2 3 4 5
    cont == Random => 3
    Lista despues de la eliminacion: 1 2 4 5
*/

/*
    Nombre de la funcion: Mostrar();
    Objetivo: Mostrar la lista
    Parametros: Sin parametros
    Ejemplo: 
    Lista existente: 1 2 3 4 5
    Como veriamos la lista:
    1
    2
    3
    4
    5
*/

/*
    Nombre de la funcion: GenerarAleatoreo(int Tamano);
    Objetivo: Generar los numeros aleatoreos para eliminar a los de la lista.
    Parametros: Tamano -> La cantidad de valores que tendra la lista
    Ejemplo: Tamano -> 8

    se puede obtener un numero aleatorio en tre 0 y 8

*/
//-------------------------LIBRERIAS-------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace::std;

struct nodo{
	int dato;
	nodo* siguiente;
	nodo* atras;
} *primero, *ultimo;

//---------------------------DECLARACION DE FUNCIONES
void Insertar(int);
void Eliminar(double);
void Mostrar();
double GenerarAleatoreo(int);
//---------------------------INICIO DE LA FUNCION main--------------------------------------
int main(){
	int Opcion = 0;
	int Tamano = 0;
	int Random = 0;
	
	do
	{
		system("pause");
        system("cls");
        printf("\t\tMENU\n");
        printf("\t1. Ingresar tama%co\n",165);
        printf("\t2. Llenar lista\n");
        printf("\t3. Mostrar la lista.\n");
        printf("\t4. Generar numero aleatorio(masacre)\n");
        printf("\t5. Eliminar a alguien.\n");
        printf("\t6. Salir.\n");
        printf("\t Ingrese la opcion: "); 
		cout << "\n\n Escoja una Opcion: ";
		scanf("%d",&Opcion);
        switch(Opcion){
		case 1:
			system("cls");
                printf("Ingrese el tama%co: \n",165);
                scanf("%d",&Tamano);
			break;
		case 2:
			system("cls");
                if(Tamano > 2){
                    for(int i=1;Tamano >= i; i++){
                        Insertar(i);
                    }
                    printf("\n\tHecho...!");
                }
                else{
                    printf("El tama%co ingresado no esta permitido",165);
                }
			break;
		case 3:
			Mostrar();
			break;
		case 4:
			Random = (GenerarAleatoreo(Tamano) - 1);
			break;
		case 5: 
			Eliminar(Random);
			break;
		case 6:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (Opcion != 6);
	
	return 0;
}
//---------------------------FIN DE LA FUNCION main--------------------------------------
//---------------------------INICIO DE LA FUNCION INSERTAR-----------------------
void Insertar(int dato){
	nodo* nuevo = new nodo();
    nuevo->dato = dato;
	
	if(primero==NULL){
		primero = nuevo;
		ultimo = nuevo;
		primero->siguiente = primero;
		primero->atras = ultimo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->atras = ultimo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
}
//---------------------------INICIO DE LA FUNCION ELIMINAR
void Eliminar(double Random){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
    int cont = 0;
	bool encontrado = false;
	if(primero!=NULL){
		do{
			if(cont == Random){
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = ultimo;
					ultimo->siguiente = primero;
				}
                else if(actual==ultimo){
					ultimo = anterior;
					ultimo->siguiente = primero;
					primero->atras = ultimo;
				}
                else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				
				cout << "\n Jugador Eliminado\n\n";
				encontrado = true;				
			}
			cont++;
			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		
		if(!encontrado){
			cout << "\n Jugador no Encontrado\n\n";
		}
	}
    else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}
//---------------------------INICIO DE LA FUNCION MOSTRAR
void Mostrar(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->dato; 
			actual = actual->siguiente;
		}while(actual!=primero);
		
	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

double GenerarAleatoreo(int Tamano){
    double valor;
    srand(time(NULL));
    	valor = rand()%Tamano;
    	cout<<"El numero aleatorio creado fue "<<valor<<endl;
    	return valor;
}