/*  Taller de programacion #5 Colas
    Asignatura: Estructura de datos
    Autor: Andres Felipe Martinez Henao
    Fecha: 20 octubre 2021
    compilado en: gcc (MinGW.org GCC-6.3.0-1) 6.3.0 - Visual tudio Code 
*/
/*
    Nombre de la función: Menu();
    Objetivo: Muestra en pantalla el menu del programa
*/
//!
/*
    Nombre de la función: InvertirCola(q);
    Objetivo: Esta funcion se encarga de invertir los datos de una cola
    Parametros: q -> es la cola, lista para ser invertida
    Ejemplo:q -> 3 2 1
            Cola invertida
            q -> 1 2 3
*/
//!
/*
    Nombre de la función: BuscarEnCola(q,Num);
    Objetivo: Busca un elemento en la cola e imprimir en pantalla si se encuentra o no en la cola
    Parametros: q -> Tiene la cola de datos
                Num -> Tiene el valor  ingresado por el usuario
                i -> se encarga de aunmentarse si al recorrer la cola encuentra el valor buscado y retorna ese valor
                se encarga de indicarme si existe o no el dato en la cola
                Num2 -> va ir ieniendo cada dato de la cola mientras es recorrida
    Ejemplo: q -> 3 2 1      Num = 2;
            i ->aumenta en 1 ya que el 2 se encuentra en la cola
            la funcion retorna el 1 y imprime en pantalla que el Elemento 2 se encuentra en el cola
*/
//!
/*
    Nombre de la funcion: Ascendente(q);
    Objetivo: Verifica si la cola se encuentra de manera ascendete
    Parametros: q -> Tiene la cola de datos
                i ->se encarga de indicarme si la cola esta deforma ascendente o no al guardar el valor de true  o false
    Ejemplo: q -> 3 2 1
            i  = false
            retorna el cero y imprimi en pantalla que la cola no esta de forma ascendete
*/
//!
/*
    Nombre de la función: ColasIguales(q,q2);
    Objetivo: Compara las dos colas para determinar si son iguales
    Parametros: q -> Tiene el valor  los datos de la primera cola
                q2 -> Tiene los datos de la segunda cola
                Iguales ->se encarga de guardar un false o un true si la colas son iguales o no
    Ejemplo: p1 -> 3 2 1    y      p2 -> 3 2 1
            i = 1
            retorna a Iguales y imprimi en pantalla de que las dos colas son iguales
*/
//!
/*
    Nombre de la función: AgregarCola(q,q1,Valor);
    Objetivo: Agrega un dato en la ultima posicion de una cola
    Parametros: q -> Tiene la cola de datos
                Valor -> Tiene el dato ingresado por el usuario
    Ejemplo: q -> 3 2 1
            Valor = 4
            p ->4 3 2 1
*/
//!
/*
    Nombre de la función: MayoresX(q,q1,q2,Valor);
    Objetivo: Separarme los datos mayores en una pila y los menores en otra pila de un dato ingresado 
    Parametros: q -> Tiene la cola de datos
                q1-> Tiene los datos mayores a un dato ingresado
                q2-> Tiene los datos menores o iguales a un dato
                Valor -> Tiene el dato ingresado por el usuario
    Ejemplo: p -> 1 2 3 4 5 6 7
            Valor = 4
            q1 -> 5 6 7
            q2 -> 1 2 3 4
*/
//-------------------------LIBRERIAS-------------------------------------
#include <iostream>
#include <stdlib.h>
#include "TadListas.h"
using namespace std;
//---------------------------INICIO DE LA FUNCION main--------------------------------------
int main(){
    struct cola q, q1, q2, q3, q4;
    q.delante = NULL;
    q.atras = NULL;
    q1.delante = NULL;
    q1.atras = NULL;
    q2.delante = NULL;
    q2.atras = NULL;
    q3.delante = NULL;
    q3.atras = NULL;
    q4.delante = NULL;
    q4.atras = NULL;
    encolar(q,3);
    encolar(q,2);
    encolar(q,1);
    encolar(q,0);
    encolar(q3,3);
    encolar(q3,2);
    encolar(q3,1);
    encolar(q3,0);
    int Dato;
    int Opcion;
    int X;
    
    do{
        Menu(); printf("\n\nIngrese una Opcion: "); 
        cin>>Opcion;
        switch(Opcion){
            case 1:
                printf("\n\nMostrando Cola");
                muestracola(q);
            break;
            case 2:
                InvertirCola(q);
                printf("\n\nCola Invertida...");
            break;
            case 3:
                printf("Elemento a buscar: "); 
                cin>>Dato;
                X = BuscarEnCola(q,Dato);
                if(X==-1)
                    printf("\n\nEl elemento %d no se encuentra en la cola",Dato);
                else
                    printf("\n\nEl elemento %d se encuentra en la cola",Dato);
            break;
            case 4:
                X = Ascendente(q);
                if(X==0)
                    printf("\n\nLa Cola no esta de forma ascendente");
                else
                    printf("\n\nLa Cola esta de forma ascendente");
            break;
            case 5:
                X = ColasIguales(q,q3);
                if(X==0)
                    printf("\n\nLas colas no son iguales");
                else
                    printf("\n\nLa colas son iguales");
            break;
            case 6:
                printf("Elemento a guardar en la cola: "); cin>>Dato;
                AgregarCola(q,q4,Dato);
                printf("\n\nDato guardado en la cola: ");
            break;
            case 7:
                printf("Elemento a agregar: "); cin>>Dato;
                MayoresX(q,q1,q2,Dato);
                printf("\n\nCola con datos mayores a %d",Dato);
                muestracola(q1);
                printf("\nPila con datos menores a %d",Dato);
                muestracola(q2);
            break;
        }
        
        system("pause"); system("cls");
    }while(Opcion!=8);
    return 0;
}
//---------------------------FIN DE LA FUNCION main--------------------------------------
//---------------------------INICIO DE LA FUNCION Menu--------------------------------------
void Menu(){
    printf("\n\t TALLER DE PILAS EN C++\n\n");
    printf("1. Mostrar cola");
    printf("2. InvertirCola");
    printf("3. BuscarEnCola");
    printf("4. Ascendente");
    printf("5. comprobar igualdad de las colas ");
    printf("6. Agregar un datos pos a la cola  ");
    printf("7. Mayores a un Dato");
    printf("8. SALIR");
    return;
}
//---------------------------FIN DE LA FUNCION Menu--------------------------------------
//---------------------------INICIO DE LA FUNCION InvertirCola--------------------------------------
void InvertirCola(struct cola &q){
    struct nodo *aux;
    ptrpila p;
    p=NULL;
    while(q.delante != NULL){
        aux = q.delante;
        q.delante = aux->Sgte;
        push(p,aux->Nro);
        delete(aux);
    }
    q.delante = NULL;
    q.atras = NULL;

    while( p !=NULL){
        aux = p;
        p=aux->Sgte;
        encolar(q,aux->Nro);
        delete(aux);
    }   
    return;
}
//---------------------------FIN DE LA FUNCION InvertirCola--------------------------------------
//---------------------------INICIO DE LA FUNCION BuscarEnCola--------------------------------------
int BuscarEnCola(struct cola &q,int Valor){
    struct nodo *aux;
    aux = q.delante;
    int posicion=1;
    while(aux != NULL){
        if(Valor==aux->Nro)
            return posicion;//retornara la posicion de la cola
        posicion++;
        aux = aux->Sgte;
    }
    return -1; //que el elemento no esta en la cola
}
//---------------------------FIN DE LA FUNCION BuscarEnCola--------------------------------------
//---------------------------INICIO DE LA FUNCION Ascendente--------------------------------------
bool Ascendente(struct cola &q){
    struct nodo *aux,*aux2;
    aux = q.delante;
    aux2 = aux->Sgte;
    bool i=true;
    while(aux2 != NULL){
        if(aux->Nro>aux2->Nro){
            i=false;
        }
        aux = aux->Sgte;
        aux2 = aux2->Sgte;
    }
    return i;
}
//---------------------------FIN DE LA FUNCION Ascendente--------------------------------------
//---------------------------INICIO DE LA FUNCION ColasIguales--------------------------------------
bool ColasIguales(struct cola &q, struct cola &q2){
    struct nodo *aux, *aux2;
    aux = q.delante;
    aux2 = q2.delante;
    bool Iguales=true;
        while(aux != NULL && aux2 != NULL){
            if(aux->Nro != aux2->Nro){
                Iguales=false;
            }
            aux = aux->Sgte;
            aux2 = aux2->Sgte;
        }
        if(aux2 != NULL){
            Iguales=false;
        }
    return Iguales;
}
//---------------------------FIN DE LA FUNCION ColasIguales--------------------------------------
//---------------------------INICIO DE LA FUNCION AgregarCola--------------------------------------
void AgregarCola(struct cola &q,struct cola &q1, int Valor){
    struct nodo *aux;
    aux = q.delante;
    q1.delante = NULL;
    q1.atras = NULL;
    while(aux != NULL){
        if(aux != q.delante){
            encolar(q1,desencolar(q));
        }
        else{
            encolar(q1,Valor);
        }
        aux = aux->Sgte;
    }
    q = q1;
    return;
}
//---------------------------FIN DE LA FUNCION AgregarCola--------------------------------------
//---------------------------INICIO DE LA FUNCION MayoresX--------------------------------------
void MayoresX(struct cola &q,struct cola &q1,struct cola &q2, int Valor){
    struct nodo *aux;
    aux = q.delante;
    while(aux != NULL){
        if(aux->Nro > Valor){
            encolar(q1,aux->Nro);
        }
        else{
            encolar(q2,aux->Nro);
        }
        aux = aux->Sgte;
    }
}
//---------------------------FIN DE LA FUNCION MayoresX--------------------------------------
