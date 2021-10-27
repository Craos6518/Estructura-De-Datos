/*  Taller de programacion #4 Pilas
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
    Nombre de la función: InvertirPila(p);
    Objetivo: Se encarga de invertir los datos de una pila
    Parametros: P -> es la pila, la cual invertiremos
    Ejemplo: p -> 1 2 3
            pila invertida
            p -> 3 2 1
*/
//!
/*
    Nombre de la función: BuscarElemento(p,Num);
    Objetivo: Se encarga de buscar un elemento en la pila e imprimir en pantalla si existe o no
    Parametros: p -> contiene la pila de datos
                Num -> contendra ingresado por el usuario
                i -> se encarga de aunmentarse si al recorrer la pila encuentra el valor buscado y retorna ese valor
                se encarga de indicarme si existe o no el dato en la pila
                Num2 -> va ir conteniendo cada dato de la pila mientras es recorrida
    Ejemplo: p -> 1 2 3       Num = 2;
            i ->aumenta en 1 ya que el 2 se encuentra en la pila
            la funcion retorna el 1 y imprime en pantalla que el Elemento 2 se encuentra en el pila
*/
//!
/*
    Nombre de la funcion: Ascendente(p);
    Objetivo: Verifica si la pila se esta de manera ascendete
    Parametros: p -> contiene la pila de datos
                i ->se encarga de indicarme si la pila esta deforma ascendente o no al guardar el valor de 1  o 0
                Bandera -> bandera
    Ejemplo: p -> 1 2 3
            i  = 0
            retorna el cero y imprimi en pantalla que la pila no esta de forma ascendete
*/
//!
/*
    Nombre de la función: PilasIguales(p1,p2);
    Objetivo: verifica si las pilas son iguales
    Parametros: Pila1 -> contendra los datos de la primera pila
                Pila2 -> contendra los datos de la segunda pila
                i ->se encarga de guardar un cero (0) o un uno (1) si la pilas son iguales o no
    Ejemplo: p1 -> 1 2 3    y      p2 -> 1 2 3
            i = 1
            retorna a i y imprimi en pantalla de que las dos pilas son iguales
*/
//!
/*
    Nombre de la función: Eliminar(p,Valor);
    Objetivo: elimina un valor especifico de la pila que ingresa el usuario
    Parametros: p -> contiene la pila de datos
                Valor -> contiene el dato ingresado por el usuario
    Ejemplo:    p -> 1 2 3
                Valor = 2
                p -> 1 3
*/
//!
/*
    Nombre de la función: AgregarPila(p,Valor);
    Objetivo: agrega un datos pos la posicion de una pila
    Parametros: p -> contiene la pila de datos
                Valor -> contiene el dato ingresado por el usuario
    Ejemplo: p -> 1 2 3
            Valor = 4
            p ->1 2 3 4
*/
//!
/*
    Nombre de la función: MayoresX(p,p1,p2,Valor);
    Objetivo: separa los datos de una pila mayores en una pila y los menores en otra pila de un dato ingresado 
    Parametros: p -> contiene la pila de datos
                p1-> contiene los datos mayores a un dato ingresado
                p2-> contiene los datos menores o iguales a un dato
                Valor -> contiene el dato ingresado por el usuario
    Ejemplo: p -> 1 2 3 4 5 6 7
            Valor = 4
            p1 -> 5 6 7
            p2 -> 1 2 3 4
*/
#include <stdio.h>
#include <iostream>
#include "TadListas.h"
using namespace std;
void Menu();
void InvertirPila(ptrpila &p);
int main(){
    ptrpila PilaOriginal=NULL, Mayores=NULL, P2=NULL, P3=NULL;
    int Dato=0;
    int Opcion=0;
    int X=0;
    push(PilaOriginal,1);
    push(PilaOriginal,2);
    push(PilaOriginal,3);
    push(Mayores,6);
    push(Mayores,2);
    push(Mayores,3);
    do{
        Menu(); 
        printf("\n\nIngrese la Opcion: "); 
        cin>>Opcion;
        switch(Opcion){
            case 1:
                printf("\n\nMostrar la Pila");
                MostrarPila(PilaOriginal);
            break;
            case 2:
                InvertirPila(PilaOriginal);
                printf("\n\nPila Invertida");
            break;
            case 3:
                printf("Ingrese el elemento a buscar: ");
                cin>>Dato;
                X = BuscarElemento(PilaOriginal,Dato);
                if(X==0)
                    printf("\n\nEl elemento %d no se encuentra en la pila",Dato);
                else
                    printf("\n\nEl elemento %d se encuentra en la pila",Dato);
            break;
            case 4:
                X = Ascendente(PilaOriginal);
                if(X==0)
                    printf("\n\nLa Pila no esta de forma ascendente");
                else
                    printf("\n\nLa Pila esta de forma ascendente");
            break;
            case 5:
                X = PilasIguales(PilaOriginal,Mayores);
                if(X==0)
                    printf("\n\nLas Pilas no son iguales");
                else
                    printf("\n\nLa Pila son iguales");
            break;
            case 6:
                printf("Elemento a eliminar: "); 
                cin>>Dato;
                Eliminar(PilaOriginal,Dato);
            break;
            case 7:
                printf("Elemento a agregar: ");
                cin>>Dato;
                AgregarPila(PilaOriginal,Dato);
            break;
            case 8:
                printf("Ingrese un Nro: ");
                cin>>Dato;
                P3=Mayores;
                Mayores=NULL;
                MayoresX(PilaOriginal,Mayores,P2,Dato);
                printf("\n\nPila con datos mayores a %d\n",Dato);
                MostrarPila(Mayores);
                printf("\nPila con datos menores a %d\n",Dato);
                MostrarPila(P2);
                Mayores=P3;
            break;
        }
        system("pause"); system("cls");
    }while(Opcion!=9);
    return 0;
}
//---------------------------FIN DE LA FUNCION main--------------------------------------
//---------------------------INICIO DE LA FUNCION Menu--------------------------------------
void Menu(){
    printf("\n\t TALLER DE PILAS EN C++\n\n");
    printf("\t1. Mostrar Pila\n");
    printf("\t2. InvertirPila\n");
    printf("\t3. BuscarElemento\n");
    printf("\t4. Ascendente");
    printf("\t5. comprobar igualdad de las pilas\n");
    printf("\t6. Elimnar un dato de la pila");
    printf("\n\t7. Agregar un datos pos a la pila");
    printf("\n\t8. Mayores a un Dato");
    printf("\n\t9. SALIR");
    return;
}
//---------------------------FIN DE LA FUNCION Menu--------------------------------------
//---------------------------INICIO DE LA FUNCION InvertirPila--------------------------------------
void InvertirPila(ptrpila &p){  //invierte los valores de la pila
    ptrpila p2=NULL;
    while(p!=NULL){
        push(p2,pop(p));
    }
    p=p2;
    return;
}
//---------------------------FIN DE LA FUNCION InvertirPila--------------------------------------
//---------------------------INICIO DE LA FUNCION BuscarElemento--------------------------------------
int BuscarElemento(ptrpila &p, int Num){  //busca un elemento de la pila y devuelve un uno(1) si lo encuentra y un cero(0) si no lo encuentra
    ptrpila Aux=NULL;
    Aux=p;
    int i=0, Num2=0;
    while(Aux!=NULL){
        Num2=Aux->Nro;
        Aux=Aux->Sgte;
        if(Num2==Num){
            i++;
        }
    }
    return i;
}
//---------------------------FIN DE LA FUNCION BUscarElemento--------------------------------------
//---------------------------INICIO DE LA FUNCION Ascendente--------------------------------------
bool Ascendente(ptrpila &p){ //muestra en pantalla si la pila esta o no esta ordenada
    ptrpila Aux1=p, Aux2=Aux1->Sgte;
    int i=0, Bandera=0;
    while(Aux2!=NULL){
        if(Aux1->Nro>=Aux2->Nro && Bandera==0){
            i=1;
        }
        else{
            i=0;
            Bandera++;
        }
        Aux1=Aux1->Sgte;
        Aux2=Aux1->Sgte;
    }
    return i;
}
//---------------------------FIN DE LA FUNCION Ascendete--------------------------------------
//---------------------------INICIO DE LA FUNCION PilasIguales--------------------------------------
bool PilasIguales(ptrpila &Pila1, ptrpila &Pila2){
    ptrpila Aux1=Pila1;
    ptrpila Aux2=Pila2;
    int i=1;
    while(Aux1 != NULL && Aux2 != NULL){
        if(Aux1->Nro!=Aux2->Nro){
            i=0;
        }
        Aux1 = Aux1->Sgte;
        Aux2 = Aux2->Sgte;
    }
    if(Aux2 != NULL){
        i=0;
    }
    return i;
}
//---------------------------FIN DE LA FUNCION PilasIguales--------------------------------------
//---------------------------INICIO DE LA FUNCION Eliminar--------------------------------------
void Eliminar(ptrpila &p,int Valor){
    ptrpila Aux1;
    Aux1 = NULL;
    while(p != NULL){
        if(p->Nro != Valor)
            push(Aux1,pop(p));   
        else
            pop(p);
    }
    InvertirPila(Aux1);
    p = Aux1;
    return;
}
//---------------------------FIN DE LA FUNCION Eliminar--------------------------------------
//---------------------------INICIO DE LA FUNCION AgregarPila--------------------------------------
void AgregarPila(ptrpila &p,int Valor){
    ptrpila Aux, Aux2=p;
    Aux = NULL;
    while(p != NULL){
        if(p != NULL){
            push(Aux,pop(p));
        }
        else{
            p=p->Sgte;
        }
    }
            push(Aux,Valor);
    InvertirPila(Aux);
    p=Aux;
    return;
}
//---------------------------FIN DE LA FUNCION AgregarPila--------------------------------------
//---------------------------INICIO DE LA FUNCION MayoresX--------------------------------------
void MayoresX(ptrpila &p, ptrpila &p1, ptrpila &p2,int Valor){
    ptrpila Aux;
    Aux=p;
    while(Aux!=NULL){
        if(Aux->Nro>Valor){
            push(p1,Aux->Nro);
        }
        else
            push(p2,Aux->Nro);
        Aux = Aux->Sgte;
    }
    InvertirPila(p1);
    InvertirPila(p2);
    return;
}
//---------------------------FIN DE LA FUNCION MayoresX--------------------------------------