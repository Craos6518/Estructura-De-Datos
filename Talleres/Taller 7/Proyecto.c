/*  Taller de programacion #7 (Proyecto sobre Manejo de Listas)

    UNIVERSIDAD  TECNOLOGICA  DE  PEREIRA

    Programa: Ingeniería en Sistemas y Computación

    Materia: Estructuras de Datos

    Proyecto sobre Manejo de Listas.

Problema: 
La aerolínea “VIAJAR”, desea hacer un manejo adecuado de los vuelos que realiza periódicamente.
De cada vuelo se tienen los siguientes datos: Nro de vuelo, ciudad origen, ciudad destino, 
matrícula del avión, nombre del piloto, hora del vuelo y fecha del vuelo, además se tiene el 
estado del vuelo (programado o realizado). Cada vuelo tiene a su vez asignado una lista de 
pasajeros; de cada pasajero se tiene la cédula, el nombre, el teléfono y el estado (con reserva 
o a bordo siempre que el vuelo no se haya realizado).


La información de los vuelos viene en el archivo de texto “VUELOS.txt” con el siguiente formato: 
!nro de vuelo (6 caracteres), origen (8), destino (8), matricula del avion (6),
!nombre del piloto (20), hora de vuelo (4), fecha de vuelo (6), 
!estado (0: programado, 1: realizado).

!Ejemplo de registro:123445BOGOTA—MEDELLIN222222FELIPE MONTENEGRO---10453101030


Los datos de cada pasajero vienen en el archivo de texto “PASAJERO.txt”, 
!numero  de vuelo (6 caracteres), cédula (9), nombre (20), telefono (10), estado (1: reserva, 2: a bordo). 

!Ejemplo de registro:12345687654321ANA MARIA RAMÍREZ---03632134521


La información de los vuelos se sube a memoria y se almacenan en una lista que contiene  
una estructura con el mismo formato del archivo, con los pasajeros también sucede lo mismo

El programa debe permitir hacer lo siguiente:

Crear una estructura de multilista para el manejo de los datos de la aerolinea, con los vuelos 
como la lista principal y para cada vuelo la sublista de pasajeros.
Se debe poder adicionar vuelos.
Adicionar pasajeros
Obtener listados (pasajeros de un vuelo realizado o programado, lista de vuelos programados, 
lista de vuelos realizados).
Dada la cédula de una persona, obtener un listado de los vuelos que ha realizado y de los vuelos
que tiene programado realizar.
Cuando se hace un vuelo, se debe modificar el estado del vuelo a realizado.
Se debe tener una opción que permita registrar cuando un pasajero pasa a bordo.
*/

//-------------------Librerias---------------------//
#include <stdio.h>//libreria estandar entrada salida
//#include <iostream>//libreria estandar entrada salida
#include <stdlib.h>
#include <string.h>
//using namespace std;
//-------------------Fin de libreria---------------//
//-------------------Estructuras-------------------//
/*
    !nro de vuelo (6 caracteres), origen (8), destino (8), matricula del avion (6),
    !nombre del piloto (20), hora de vuelo (4), fecha de vuelo (6), 
    !estado (0: programado, 1: realizado).

    !Ejemplo de registro:123445BOGOTA—MEDELLIN222222FELIPE MONTENEGRO---10453101030
*/
struct VUELOS{
    char NroDeVuelo [7];
    char Origen[9];
    char Destino[9];
    char MatriculaAvion[7];
    char NombrePiloto[21];
    char Hora [5];
    char Fecha[7];
    char Estado;
}Vuelo;

//!
/*
!nro de vuelo (6 caracteres), cédula (9), nombre (20), telefono (10), estado (1: reserva, 2: a bordo). 

!Ejemplo de registro:12345687654321ANA MARIA RAMÍREZ---03632134521
*/

struct PASAJERO{
    char NroDeVuelo [7];
    char Cedula[11];
    char Nombre[21];
    char Telefono[11];
    char Estado;
}Pasajeros;
//-------------------Fin de Estructuras-------------------//
//-------------------Declaracion de Funciones-------------//
void Menu();
void validar();
void AdicionarVuelos();
void AdicionarPasajero();
void ListaPasajero();
void BuscarPasajero();
void ModificarEstado();
void RegistrarPasajero();
//-------------------Inicio funcion main------------------//
int main(){

    Menu();
    getchar();
    return 0;

}

void Menu(){
    system("cls");
    printf("\t\tMenu Aerolinea Viajar\n\n");
    printf("\t1. Adicionar Vuelos.\n");
    printf("\t2. Adicionar Pasajeros (El vuelo debe de existir)\n");
    printf("\t3. Lista de pasajeros.\n");
    printf("\t4. Buscar pasajero.\n");
    printf("\t5. Modificar estado del vuelo.\n");
    printf("\t6. Registrar pasajero.\n");
    printf("\t0. Salir.\n");
    printf("\t\tIngrese la opci%cn: ",162);
    validar();
}

void validar(){
    int Opcion =0;
    scanf("%d",&Opcion);
    fflush(stdin);
    if(Opcion >= 0 && Opcion <= 6){
        switch(Opcion){
            case 1:
            printf("\nSe van a adicionar vuelos\n");
                AdicionarVuelos();
            break;
            case 2:
            printf("\nSe va adicioanr un pasajero\n");
                AdicionarPasajero();
            break;
            case 3:
            printf("\nSe van a listar los pasajeros\n");
                ListaPasajero();
            break;
            case 4:
            printf("\nBuscando pasajeros\n");
                BuscarPasajero();
            break;
            case 5:
            printf("\nModificando el estado del vuelo\n");
                ModificarEstado();
            break;
            case 6:
            printf("\nRegistro de pasajero\n");
                RegistrarPasajero();
            break;
            default:
                printf("\nSaliendo del aplicativo\n");
            break;
        }
    }
    else{
        printf("La opcion es incorrecta\n");
        getchar();
        Menu();
    }
}

void AdicionarVuelos(){
    system("cls");//TODO control por parte del programador
    printf("\n\nFuncion AdicionarVuelos\n\n");//TODO control por parte del programador
    getchar();//TODO control por parte del programador
    system("cls");
    int i =0;
    char NroDeVuelo [7], Opcion;
    printf("\t\tModulo para adicionar un vuelo\n\n");
    printf("Ingrese el Nro de Vuelo: ");
    gets(NroDeVuelo);
    fflush(stdin);
    FILE * ptr;
    ptr=fopen("VUELOS.txt","r");
    if(ptr == NULL){
        fclose(ptr);
        printf("\n¿Es la primera vez que ingresa?   [Y/N]: ");
        scanf("%c", &Opcion);
        fflush(stdin);
        if(Opcion == 'Y' || Opcion == 'y'){
            system("cls");
            ptr = fopen("VUELOS.txt","w");
            strcpy(Vuelo.NroDeVuelo, NroDeVuelo);
            printf("Ingrese el origen: ");
            gets(Vuelo.Origen);
            printf("\nIngrese el destino: ");
            gets(Vuelo.Destino);
            printf("\nIngrese la matricula del avion: ");
            gets(Vuelo.MatriculaAvion);
            printf("\nIngrese el nombre del piloto: ");
            gets(Vuelo.NombrePiloto);
            printf("\nIngrese la hora del vuelo: ");
            gets(Vuelo.Hora);
            printf("\nIngrese la fecha del vuelo: ");
            gets(Vuelo.Fecha);
            printf("\nIngrese el estado del vuelo (0: programado, 1: realizado): ");
            scanf("%c",&Vuelo.Estado);
            fflush(stdin);
            fwrite(&Vuelo,sizeof(Vuelo),1,ptr);
            fclose(ptr);
        }
        else{
            printf("\nFavor comunicarse con el soporte tecnico error 0x00000109\n");
        }
    }
    else{
        while(!feof(ptr)){
            fread(&Vuelo,sizeof(Vuelo),1,ptr);
            if(strcmp(NroDeVuelo, Vuelo.NroDeVuelo)==0){
                i++;
            }
            else{
                i;
            }
        }
        if(i == 0){
            fclose(ptr);
            ptr = fopen("VUELOS.txt","wb");
            strcpy(Vuelo.NroDeVuelo, NroDeVuelo);
            printf("Ingrese el origen: ");
            gets(Vuelo.Origen);
            printf("\nIngrese el destino: ");
            gets(Vuelo.Destino);
            printf("\nIngrese la matricula del avion: ");
            gets(Vuelo.MatriculaAvion);
            printf("\nIngrese el nombre del piloto: ");
            gets(Vuelo.NombrePiloto);
            printf("\nIngrese la hora del vuelo: ");
            gets(Vuelo.Fecha);
            printf("\nIngrese la fecha del vuelo: ");
            gets(Vuelo.Fecha);
            printf("\nIngrese el estado del vuelo (0: programado, 1: realizado): ");
            scanf("%c",&Vuelo.Estado);
            fflush(stdin);
            fwrite(&Vuelo,sizeof(Vuelo),1,ptr);
            fclose(ptr);
        }
        else{
            printf("\nEl Numero del vuelo ya existe");
            fclose(ptr);
        }
    }
    printf("\nPrecione una tecla para continuar...");
    fflush(stdin);
    getchar();
    Menu();
}

void AdicionarPasajero(){
    system("cls");//TODOcontrol por parte del programador
    printf("\n\nFuncion AdicionarPasajero\n\n");//TODOcontrol por parte del programador
    getchar();//TODOcontrol por parte del programador
    system("cls");
    int i =0;
    char NroDeVuelo [7], Opcion;
    printf("\t\tModulo para adicionar un Pasajero\n\n");
    printf("Ingrese el Numero del vuelo: ");
    gets(NroDeVuelo);
    FILE *BusquedaDeVuelo;
    FILE * ptr;
    BusquedaDeVuelo = fopen("VUELOS.txt","rb");
    ptr = fopen("PASAJERO.txt","rb");
    if(BusquedaDeVuelo !=NULL){
        while(!feof(BusquedaDeVuelo)){
            fread(&Vuelo,sizeof(Vuelo),1,BusquedaDeVuelo);
            printf("%s <==> %s\n",Vuelo.NroDeVuelo,NroDeVuelo);
            if(strcmp(NroDeVuelo, Vuelo.NroDeVuelo)==0){
                i++;
            }
            else{
                i;
            }
        }
        if(i != 0){
            if(ptr == NULL){
                fclose(ptr);
                printf("\n¿Es la primera vez que ingresa?   [Y/N]: ");
                scanf("%c", &Opcion);
                fflush(stdin);
                if(Opcion == 'Y' || Opcion == 'y'){
                    ptr = fopen("PASAJERO.txt", "wb");
                    strcpy(Pasajeros.NroDeVuelo,NroDeVuelo);
                    printf("\nIngrese la cedula: ");
                    gets(Pasajeros.Cedula);
                    printf("\nIngrese el nombre: ");
                    gets(Pasajeros.Nombre);
                    printf("\nIngrese el telefono: ");
                    gets(Pasajeros.Telefono);
                    printf("\nIngrese el estado del vuelo (0: programado, 1: realizado): ");
                    scanf("%c",&Pasajeros.Estado);
                    fwrite(&Pasajeros,sizeof(Pasajeros),1,ptr);
                    fclose (ptr);
                }
                else{
                    printf("\nFavor comunicarse con el soporte tecnico error 0x00000109\n");
                }
            }
            else{
                ptr = fopen("PASAJERO.txt", "w");
                char Cedula[10];
                printf("\nIngrese la cedula: ");
                gets(Cedula);
                while(!feof(ptr)){
                    fread(&Pasajeros,sizeof(Pasajeros),1,ptr);
                    if(strcmp(Cedula,Pasajeros.Cedula)==0){
                        i++;
                    }
                    else{
                        i;
                    }
                }
                if(i==0){
                    fclose(ptr);
                    ptr = fopen("PASAJERO.txt", "w");
                    strcpy(Pasajeros.Cedula,Cedula);
                    printf("\nIngrese el nombre: ");
                    gets(Pasajeros.Nombre);
                    printf("\nIngrese el telefono: ");
                    gets(Pasajeros.Telefono);
                    printf("\nIngrese el estado del vuelo (0: programado, 1: realizado): ");
                    scanf("%c",&Pasajeros.Estado);
                    fwrite(&Pasajeros,sizeof(Pasajeros),1,ptr);
                    fclose (ptr);
                }
                else{
                    printf("\nEl pasajero ya se encuantra en el vuelo\n");
                }
            }
        }
        else{
            printf("\nEl pasajero ya se encuantra en el vuelo\n");
        }
    }
    else{
        printf("\nNo es posible leer el archivo VUELOS.txt\nComunicate con soporte tecnico.\n\tERROR 0x00000109\n");
    }
    printf("\nPrecione una tecla para continuar...");
    fflush(stdin);
    getchar();
    Menu();
}

void ListaPasajero(){
    system("cls");//TODOcontrol por parte del programador
    printf("\n\nFuncion ListaPasajero\n\n");//TODOcontrol por parte del programador
    getchar();//TODOcontrol por parte del programador
    char NroDeVuelo [7];
    char Cedula[11];
    int i=0;
    printf("\nIngrese el Numero del Vuelo: ");
    gets(NroDeVuelo);
    FILE *Buscar;
    Buscar = fopen("PASAJERO.txt", "rb");
    if(Buscar != NULL){
        printf("\n\n\t\tPasajeros en el vuelo %s son: \n",NroDeVuelo);
        printf("\tCEDULA\t\t  NOMBRE\t\tTELEFONO\t\tESTADO\n");
        while(!feof(Buscar)){
            fread(&Pasajeros,sizeof(Pasajeros),1,Buscar);
            //printf("%s <==> %s\n",Pasajeros.NroDeVuelo,NroDeVuelo );
            if(strcmp(Pasajeros.Cedula, Cedula)!=0){
                if(strcmp(NroDeVuelo, Pasajeros.NroDeVuelo)== 0){
                    printf("\n");
                    printf("\t%s", Pasajeros.Cedula);
                    printf("\t%s", Pasajeros.Nombre);
                    printf("\t\t%s", Pasajeros.Telefono);
                    printf("\t\t  %c\n", Pasajeros.Estado);
                    i++;
                    strcpy(Cedula,Pasajeros.Cedula);
                }
            }
            
        }
        if(i == 0){
            printf("\nEl vuelo no existe\n");
        }
        else{
            printf("\nEn el vuelo %s hay %d personas", NroDeVuelo,i);
        }
        
    }
    printf("\nPrecione una tecla para continuar...");
    fflush(stdin);
    getchar();//TODOcontrol por parte del programador
    Menu();
}

void BuscarPasajero(){
    system("cls");
    printf("Funcion BuscarPasajero");//TODOcontrol por parte del programador
    system("cls");
    char Cedula[11], CedulaAnterior[11];
    char NroDeVuelo [7];
    int i=0;
    printf("Ingrese la cedula del pasajero a buscar: ");
    gets(Cedula);
    FILE *Buscar;
    Buscar =fopen("PASAJERO.txt","rb");
    printf("\n");
    printf("\tNmr Vuelo\t     Nombre\t\tTelefono\tEstado\n\n");
    while(!feof(Buscar)){
        fread(&Pasajeros,sizeof(Pasajeros),1,Buscar);
        //printf("%s <==> %s\n", Cedula, Pasajeros.Cedula);
        if(strcmp(Pasajeros.NroDeVuelo, NroDeVuelo)!=0){
            if(strcmp(Pasajeros.Cedula, Cedula)== 0){
                printf("\t%s",Pasajeros.NroDeVuelo);
                printf("\t\t%s",Pasajeros.Nombre);
                printf("\t\t%s",Pasajeros.Telefono);
                printf("\t   %c",Pasajeros.Estado);
                strcpy(NroDeVuelo,Pasajeros.NroDeVuelo);
                i++;
            }
        }
    }
    if(i== 0){
        printf("\nLa cedula ingresa no esta registrada...\n");
    }
    fflush(stdin);
    getchar();
    Menu();
}

void ModificarEstado(){ //? preguntarle a juan
    system("cls");
    printf("Funcion ModificarEstado");//TODOcontrol por parte del programador
    getchar();
    Menu();
}

void RegistrarPasajero(){
    system("cls");
    printf("Funcion RegistrarPasajero");//TODOcontrol por parte del programador
    getchar();
    Menu();
}