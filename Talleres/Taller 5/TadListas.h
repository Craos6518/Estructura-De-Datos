//-------------------------LIBRERIAS-------------------------------------
#include <iostream>
#include <stdlib.h>
using namespace std;
/*****************************FUNCIONES PARA PILAS**********************************************************/
//-------------------------estructuras-------------------------------------
struct nodo{
    int Nro;
    struct nodo *Sgte;
};
typedef nodo *ptrpila;
//-------------------------INICIO DE LA FUNCION push-------------------------------------
void push(ptrpila &p, int valor){ //va guardan los valores ingresado por el usuario en una pila
    ptrpila aux;
    aux = new(struct nodo);
    aux->Nro=valor;
    aux->Sgte=p;
    p=aux;
}
//-------------------------FIN DE LA FUNCION push-------------------------------------
//-------------------------INICIO DE LA FUNCION pop-------------------------------------
int pop(ptrpila &p){  //Elimina el ultimo Nro entrado en la pila
    int num;
    ptrpila aux;

    aux = p;
    num = aux->Nro;

    p= aux->Sgte;
    delete(aux);

    return num;
}
//-------------------------FIN DE LA FUNCION pop-------------------------------------
//-------------------------INICIO DE LA FUNCION MostrarPila-------------------------------------
void MostrarPila(ptrpila p){ //muestra en pantalla toda la pila
    ptrpila aux;
    aux = p;
    while(aux!=NULL){
        cout<<"\t "<<aux->Nro<<endl;
        aux = aux->Sgte;
    }
    return;
}
//-------------------------FIN DE LA FUNCION mostar_pila-------------------------------------
//-------------------------INICIO DE LA FUNCION destrui_pila-------------------------------------
void destruir_pila(ptrpila &p){  //borra toda la pila
    ptrpila aux;
    
    while( p !=NULL){
        aux = p;
        p=aux->Sgte;
        delete(aux);
    }   
    return;
}
//-------------------------FIN DE LA FUNCION destruir_pila-------------------------------------
/*****************************FUNCIONES PARA COLAS**********************************************************/
//-------------------------ESTRUCTURAS-------------------------------------
struct cola{
    nodo *delante;
    nodo *atras;
};
//-------------------------INICIO DE LA FUNCION encolar-------------------------------------
void encolar(struct cola &q, int valor){
    struct nodo *aux = new(struct nodo);
    aux->Nro = valor;
    aux->Sgte = NULL;
    if(q.delante == NULL)
        q.delante = aux;
    else
        (q.atras)->Sgte =aux;
    q.atras = aux;
    return;
}
//-------------------------FIN DE LA FUNCION encolar-------------------------------------
//-------------------------INICIO DE LA FUNCION desencolar-------------------------------------
int desencolar(struct cola &q){
    int num;
    struct nodo *aux;

    aux = q.delante;
    num = aux->Nro;
    q.delante = (q.delante)->Sgte;
    delete(aux);

    return num;
}
//-------------------------FIN DE LA FUNCION desencolar-------------------------------------
//-------------------------INICIO DE LA FUNCION muestracola-------------------------------------
void muestracola(struct cola q){
    struct nodo *aux;
    aux = q.delante;
    while( aux != NULL){
        cout<<"     "<<aux->Nro;
        aux = aux->Sgte;
    }
    return;
}
//-------------------------FIN DE LA FUNCION muestracola-------------------------------------
//-------------------------INICIO DE LA FUNCION vaciocola-------------------------------------
void vaciacola(struct cola &q){
    struct nodo *aux;
    while(q.delante != NULL){
        aux = q.delante;
        q.delante = aux->Sgte;
        delete(aux);
    }
    q.delante = NULL;
    q.atras = NULL;
}
//-------------------------FIN DE LA FUNCION vaciocola-------------------------------------