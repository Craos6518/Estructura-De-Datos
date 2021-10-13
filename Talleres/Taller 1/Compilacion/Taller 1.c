/* Taller de programación #1
Asignatura: Estructura de datos 
Autor: Andres Felipe Martinez Henao
Fecha: 2 Septiembre 2021 
Compilado en gcc (MinGW.org GCC-6.3.0-1) 6.3.0
*/
//Librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
//Prototipos de Funciones
void Menu();
void Validar(int);
void PrimerPunto();
int TamanoVector();
int TamanoVectorAuto();
void LlenarVector(int, int *);
void LlenarVectorAuto(int, int *);
void SumarDatos(int *, int);
void SegundoPunto();
void BuscarDatos(int *, int);
void TercerPunto();
void Invertir(int *, int);
void CuartoPunto();
void QuintoPunto();
void SextoPunto();
void CompararVectores(int *, int *, int, int);
void SeptimoPunto();
void EliminarDelVector(int *,int);
void OctavoPunto();
void MostrarDelVector(int *,int, int);
void NovenoPunto();
void OrdenaeVector(int *,int);
/* 
-Fucnion Principal:
Llama la funcion menu que desencadena el programa.
*/
int main(){
    Menu();
    return 0;
}
/* 
-Funcion Menu:
Crea una variable entera de nombre Opcion, la variable Opcion almacena el numero
ingresado por el usuario.
"fflush(stdin)" su funcion principal es limpial el buffer tambien conocida 
!Memoria del teclado.
*/
void Menu(){
    int Opcion=0;
    printf("\tMENU TALLER 1\n");
    printf("\t--------------------\n");
    printf("\t|  1.Primer Punto. |\n\t--------------------\n\t|  2.Segundo Punto.|\n\t--------------------\n\t|  3.Tercer Punto. |\n\t--------------------\n\t|  4.Cuarto Punto. |\n\t--------------------\n\t|  5.Quinto Punto. |\n");
    printf("\t--------------------\n\t|  6.Sexto Punto.  |\n\t--------------------\n\t|  7.Septimo Punto.|\n\t--------------------\n\t|  8.Octavo Punto. |\n\t--------------------\n\t|  9.Noveno Punto. |\n\t--------------------\n\n");
    printf("Ingrese la Opcion: ");
    scanf("%d",&Opcion);
    fflush(stdin);
    Validar(Opcion);
}
/* 
-Funcion Validar 
Recibe un valor entero proveniente de la funcion Menu
Valida que el valor ingresado por el usuario este dentro del rango.
por medio del switch se validan las diferentes opciones.
*/
void Validar(int Opcion){
    if((Opcion > 0) && (Opcion < 10)){
        switch(Opcion){
            case 1:
            PrimerPunto();
            break;
            case 2:
            SegundoPunto();
            break;
            case 3:
            //TercerPunto();
            //break;
            case 4:
            CuartoPunto();
            break;
            case 5:
            QuintoPunto();
            break;
            case 6:
            SextoPunto();
            break;
            case 7:
            SeptimoPunto();
            break;
            case 8:
            OctavoPunto();
            break;
            case 9:
            //NovenoPunto();
            //break;
            default:
            printf("\n\tAun estamos trabajando en ello.\n\tLamentamos el inconveniente.");
            break;
        }
    }
    else{
        printf("\nEl valor ingresado no esta registrado en la base de datos\n");
    }
}
/* 
-Funcion PrimerPunto:
"system("cls") Limpia la ventana
se crea una variable de tipo char que almacenara la respuesta en caracteres
se crea una variable de tipo entero que almacenara el tamaño del vector ya sea ingresado por el usuario o calculado automaticamente.
Se pregunta si se ¿desea ingresar el tamaño? si se elije el caracter "N" se llamara la funcion TamanoVectorAuto.
Como ultima parte se pregunta ¿desea llenar el vector?  si se elige el caracter "N" se llenara el vector con numeros aleatores.
Lo ultimo que se hara es llamar la funcion SumarDatos con el VECTOR Y SU TAMAÑO.
*/
void PrimerPunto(){
    int Tamano=0;
    char Opcion=0;
    system("cls");
    printf("%cDesea ingresar el tama%c? [Y/N]: ",168,164);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        Tamano=TamanoVector();
    }
    else{
        Tamano=TamanoVectorAuto();
    }
    int Vector[Tamano];
    printf("\n%cDesea llenar el Vector? [Y/N]: ",168);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        LlenarVector(Tamano, Vector);
    }
    else{
        LlenarVectorAuto(Tamano, Vector);
    }
    SumarDatos(Vector, Tamano);
}
/*
-TamanoVector:
Se crea una variable de tipo entero de nombre Tamano, y se captura el valor ingresado por el usuario.
Se retorna el valor de la variable de Tamano.
*/
int TamanoVector(){
    int Tamano=0;
    printf("Ingrese el TAMA%cO del Vector: ",165);
    scanf("%d",&Tamano);
    fflush(stdin);
    return Tamano;
}
/*
Funcion TamanoVectorAuto
Se crea una variable de tipo entero llamado Random.
Se usa la funcion "srand(time(NULL))" para inicializa el generador de números aleatorios
se almacena en la variable Random el numero aleatorio entre 1 y 11. si el valor almacenado es menor que 1 se volvera a llamar la funcion para obtener un tamaño mayor para poder ser usado en los diferentes puntos.
*/
int TamanoVectorAuto(){
    int Random=0;
    srand (time(NULL));
    Random =  (rand() % 10+1);
    if(Random > 1){
        return Random;
    }
    else{
        TamanoVectorAuto();
    }
}
/*
    Funcion LlenarVector
    se usa un bucle para recorrer el vector e ir almacenando en una posicion especifica
*/
void LlenarVector(int Tamano, int *Casillero){
    for(int i=0; i<Tamano; i++){
        printf("\nIngrese el valor en la posicion %d: ", i);
        scanf("%d",&Casillero[i]);
    }
    return;
}
/*
Funcion LlenarVectorAuto
Recibe un tamaño y el vector previamente declarados
Se usa la funcion "srand(time(NULL))" para inicializa el generador de números aleatorios
Se almacena el numero aleatori en el vector en la posicion especifica.
*/
void LlenarVectorAuto(int Tamano1, int *vec1){
    srand (time(NULL));
    for(int i=0; i< Tamano1; i++){
        vec1[i] = rand() %10;
    }
    return;
}
/*Funcion SumarDatos
Recibe el vector y el tamaño previamente declarados
Se crea una variable de tipo entero que almacena la suma de los datos del vector para luego ser impresos.
*/
void SumarDatos(int *Casillero, int Tamano){
    int  Nuevo=0;
    for(int i=0; i<Tamano; i++){
        Nuevo=Nuevo+ *(Casillero+i);
        //printf("%d", Casillero[i]);
    }
    printf("\nLa suma de todos los elementos es %d\n", Nuevo);
    fflush(stdin);
    getchar();
}
/*
Funcion SegundoPunto
Se crea una variable entera llamada Tamano
Se crea una variable de tipo caracter que almacenara la respuesta del usuario
Se valida que la respuesta ingresada por el usuario coincida con "y" o "Y" para llamar la funcion TamanoVector
en caso contrario se llamara la funcion TamanoVectorAuto 
Se vuelve a capturar la respuesta del usuario
Se valida que la respuesta ingresada por el usuario coincida con "y" o "Y" para llamar la funcion LlenarVector
en caso contrario se llamara la funcion LlenarVectorAuto.
Por ultimo llama la funcion BuscarDato
*/
void SegundoPunto(){
    int Tamano=0;
    char Opcion=0;
    system("cls");
    printf("%cDesea ingresar el tama%co? [Y/N]: ", 168,164);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        Tamano=TamanoVector();
    }
    else{
        Tamano=TamanoVectorAuto();
    }
    int Vector[Tamano];
    printf("\n%cDesea llenar el Vector? [Y/N]: ", 168);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        LlenarVector(Tamano, Vector);
    }
    else{
        LlenarVectorAuto(Tamano, Vector);
    }
    BuscarDatos(Vector, Tamano);
}
/*
Funcion BuscarDatos 
Se crean dos variables de tipo enteras que son Buscado y Bandera
Buscado: almacena el numero a buscar ingresado por el usuario.
Bandera: Es la encargada de contar las recurrencias del numero.
Si la bandera es "0" es porque el numero "NO" esta en el vector
y se preguntara si desea volver a realizar la busqueda con otro numeros.
En el caso de que la Bandera sea diferente a "0" es porque el valor existe en el vector.
*/
void BuscarDatos(int *Casillero, int Tamano){
    int Buscado=0, Bandera=0;
    printf("\nIngrese el valor a buscar: ");
    scanf("%d",&Buscado);
    for(int i=0; i<Tamano; i++){
        if(*(Casillero+i) == Buscado){
            Bandera =1;
        }
    }
    if(Bandera == 0){
        fflush(stdin);
        char Opcion=0;
        printf("\nNo se encontro el Valor a buscar\n%cDesea Buscar otro numero? [Y/N]: ",168);
        scanf("%c", &Opcion);
        fflush(stdin);
        if(Opcion == 'Y' || Opcion == 'y'){
            BuscarDatos(Casillero, Tamano);
            system("cls");
        }
    }
    else{
        printf("\nEl Valor Existe en el VECTOR\n");
        fflush(stdin);
        getchar();
    }
}
/*
Se esta trabajando este punto
*/
void TercerPunto(){
    int Tamano=0;
}
/*
Funcion CuartoPunto
Se crea una variable entera llamada Tamano
Se crea una variable de tipo caracter que almacenara la respuesta del usuario
Se valida que la respuesta ingresada por el usuario coincida con "y" o "Y" para llamar la funcion TamanoVector
en caso contrario se llamara la funcion TamanoVectorAuto 
Se vuelve a capturar la respuesta del usuario
Se llama la funcion Invertir
*/
void CuartoPunto(){
    int Tamano=0;
    char Opcion=0;
    system("cls");
    printf("%cDesea ingresar el tama%co? [Y/N]: ",168,164);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        Tamano=TamanoVector();
    }
    else{
        Tamano=TamanoVectorAuto();
    }
    int Vector[Tamano];
    printf("\n%cDesea llenar el Vector? [Y/N]: ",168);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        LlenarVector(Tamano, Vector);
    }
    else{
        LlenarVectorAuto(Tamano, Vector);
    }
    Invertir(Vector, (Tamano));
}
/*
Funcion Invertir
Se recibe el vector y su tamaño respectivo
Se crea un vector del mismo tamaño que contendra el vector invertido y una variable de tipo entero que contendra el valor en una posicion xor
Se recorre el vector y se almacena en la variable "Valor" y es almacena en la posicion "Tamano-(i+1)"
Se imprime el vector original y se imprime el invertido.
*/
void Invertir(int *Casillero, int Tamano){
    int Casillero2 [Tamano], Tamano2 = Tamano, Valor=0;
    for(int i=0; i <Tamano; i++){
        Valor= *(Casillero+i);
        for(int j=(Tamano2-(i+1)); j>=0; j=j-1){
            Casillero2[j]=Valor;
            j=0;
        }
    }
    printf("\nOriginal: ");
    for(int i=0; i <Tamano; i++){
        printf(" %d ",*(Casillero+i));
    }
    printf("\nInvertida: ");
    for(int i=0; i <Tamano; i++){
        printf(" %d ",*(Casillero+i));
    }
    fflush(stdin);
    getchar();
}
/*
Funcion Quintopunto
Se crea una variable entera llamada Tamano
Se crea una variable de tipo caracter que almacenara la respuesta del usuario
Se valida que la respuesta ingresada por el usuario coincida con "y" o "Y" para llamar la funcion TamanoVector
en caso contrario se llamara la funcion TamanoVectorAuto 
Se vuelve a capturar la respuesta del usuario
Se llama la funcion BuscarDatos
*/
void QuintoPunto(){
    int Tamano=0;
    char Opcion=0;
    system("cls");
    printf("%cDesea ingresar el tama%co? [Y/N]: ",168,164);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        Tamano=TamanoVector();
    }
    else{
        Tamano=TamanoVectorAuto();
    }
    int Vector[Tamano];
    printf("\n%cDesea llenar el Vector? [Y/N]: ",168);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        LlenarVector(Tamano, Vector);
    }
    else{
        LlenarVectorAuto(Tamano, Vector);
    }
    BuscarDatos(Vector, Tamano);
}
/*
Funcion SextoPunto
Se crea una variable entera llamada Tamano1 y Tamano2
Se crea una variable de tipo caracter llamada Opcion que almacenara la respuesta del usuario
Se valida que la respuesta ingresada por el usuario coincida con "y" o "Y" para llamar la funcion TamanoVector
en caso contrario se llamara la funcion TamanoVectorAuto 
Se vuelve a capturar la respuesta del usuario
Se crean ambos vectores con los tamaños ingresados.
Se llama la funcion CompararVectores.
*/
void SextoPunto(){
    int Tamano1=0, Tamano2=0;
    char Opcion=0;
    system("cls");
    for(int i=1; i<=2; i++){
        printf("%cDesea ingresar el tama%co del vector %d? [Y/N]: ",168,164, i);
        scanf("%c", &Opcion);
        fflush(stdin);
        if(i == 1){
            if(Opcion == 'Y' || Opcion == 'y'){
                Tamano1=TamanoVector();
            }
            else{
                Tamano1=TamanoVectorAuto();
            }
        }
        else{
            if(Opcion == 'Y' || Opcion == 'y'){
                Tamano2=TamanoVector();
            }
            else{
                Tamano2=TamanoVectorAuto();
            }
        }
    }
    int Vector1[Tamano1], Vector2[Tamano2];
    for(int i=1; i<=2; i++){
        printf("\n%cDesea llenar el Vector %d? [Y/N]: ",168, i);
        scanf("%c", &Opcion);
        fflush(stdin);
        if(i == 1){
            if(Opcion == 'Y' || Opcion == 'y'){
            LlenarVector(Tamano1, Vector1);
            }
            else{
                LlenarVectorAuto(Tamano1, Vector1);
            }
        }
        else{
            if(Opcion == 'Y' || Opcion == 'y'){
                LlenarVector(Tamano2, Vector2);
            }
            else{
                LlenarVectorAuto(Tamano2, Vector2);
            }
        }
    }
    CompararVectores(Vector1, Vector2, Tamano1, Tamano2);

}
/*
Funcion ComparaVectores
Recibe dos vectores creados previamente con sus tamaños.
Se crea una variable de tipo entero llamada Bandera.
Se comparan los tamaños como primera forma para ser si son iguales, si los tamaños coinciden se incrementa la bandera.
en caso contrario los dos vectores ingresados son diferentes.
Cuando los tamaños coinciden: se entra a recorrer el vector y comparar su contenido,
si su contenido coincide se incrementa la bandera en caso en el que algun dato no coincida el contador ise incrementara
hasta obtener el maximo valor permitido y arrojara que los vectores son diferentes.
*/
void CompararVectores(int *Vec1, int *Vec2, int Tamano1, int Tamano2){
    int  Bandera=0;
    if(Tamano1 == Tamano2){
        printf("\nLos vectores cumplen el primer requicito para determinar si son iguales\n");
        getchar();
        fflush(stdin);
        for(int i=0; i<Tamano1; i++){
            if(*(Vec1+i)==*(Vec2+i)){
                Bandera++;
            }
            else{
                i = Tamano1;
            }
        }
        if(Bandera != 0 && Bandera == Tamano1){
            printf("Los vectores son iguales\n");
            getchar();
            fflush(stdin);
        }
        else{
            printf("Los vectores son diferentes\n");
            getchar();
            fflush(stdin);
        } 
    }
    else{
        printf("Los vectores No cumplen el primer requicito para determinar si son iguales\n");
        getchar();
        fflush(stdin);
    }
    return;
}
/*
Funcion SeptimoPunto
Se crea una variable entera llamada Tamano
Se crea una variable de tipo caracter que almacenara la respuesta del usuario
Se valida que la respuesta ingresada por el usuario coincida con "y" o "Y" para llamar la funcion TamanoVector
en caso contrario se llamara la funcion TamanoVectorAuto 
Se vuelve a capturar la respuesta del usuario
Se llama la funcion EliminarDelVector
*/
void SeptimoPunto(){
    int Tamano=0;
    char Opcion=0;
    system("cls");
    printf("%cDesea ingresar el tama%co? [Y/N]: ",168,164);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        Tamano=TamanoVector();
    }
    else{
        Tamano=TamanoVectorAuto();
    }
    int Vector[Tamano];
    printf("\n%cDesea llenar el Vector? [Y/N]: ",168);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        LlenarVector(Tamano, Vector);
    }
    else{
        LlenarVectorAuto(Tamano, Vector);
    }
    EliminarDelVector(Vector,Tamano);
}
/*
Funcion EliminarDelVector
Recibe el vector previamente declarados juntos con su tamaño.
Se crean tres variables de tipo entero llamadas Bandera, Valor, Vector
Se captura el Valor ingresado por el usuario.
Se recorre el Vector buscando una coincidencia con el el valor ingresado por el usuario.
En caso en que no coincida el valor sera ingresado en el segundo vector, si coincide se incrementa la bandera
y se ingresa en la posicion el valor "0".
Si la bandera es diferente a "0" significa que encontro una coincidencia y se imprime el que se elimino correctamenete.
y se imprime el nuevo vector.
Para ser impreso se tiene en cuenta el valor de bandera que es "0" cuando coincida con la bandera "0" se imprimira un "-"
*/
void EliminarDelVector(int *Vec1, int Tamano1){
    int  Bandera=0, Valor=0, Vector[Tamano1];
    printf("Ingrese el valor a eliminar: ");
    scanf("%d",&Valor);
    fflush(stdin);
    for(int i=0; i<Tamano1; i++){
        if(*(Vec1 +i) != Valor){
            *(Vector +i)=*(Vec1 +i);
        }
        else{
            Bandera++;
            *(Vector +i)=0;
        }
    }
    if(Bandera != 0){
        printf("\nSe elimino correctamente.\nEl nuevo vector es: ");
        for(int i=0; i< Tamano1; i++){
            if(*(Vector +i) != 0){
                printf("%d ", *(Vector +i));
            }
            else{
                printf("- ");
            }
        }
        printf("\n");
        printf("El tamano es de: %d \n",Tamano1);
        getchar();
        fflush(stdin);
    }
    else{
        printf("\nNo se pudoeliminar del vector; porque no se econtro coincidencias.");
    }
    return;
}
/*
Funcion OctavoPunto
Se crea una variable entera llamada Tamano
Se crea una variable de tipo caracter que almacenara la respuesta del usuario
Se valida que la respuesta ingresada por el usuario coincida con "y" o "Y" para llamar la funcion TamanoVector
en caso contrario se llamara la funcion TamanoVectorAuto 
Se vuelve a capturar la respuesta del usuario.
Se llama la funcion MostrarDelVector.
*/
void OctavoPunto(){
    int Tamano=0;
    char Opcion=0;
    system("cls");
    printf("%cDesea ingresar el tama%co? [Y/N]: ",168,164);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        Tamano=TamanoVector();
    }
    else{
        Tamano=TamanoVectorAuto();
    }
    int Vector[Tamano];
    printf("\n%cDesea llenar el Vector? [Y/N]: ", 168);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        LlenarVector(Tamano, Vector);
    }
    else{
        LlenarVectorAuto(Tamano, Vector);
    }
    MostrarDelVector(Vector,Tamano, 0);
}
/*
Funcion MostrarDelVector
Recibe el vector, su tamaño y un contador.
Se valida el vector que la Bandera sea MENOR IGUAL al tamaño, Si esto es verdad se imprime el contendio en la posicion especifica.
Se incrementa el valor de la Bandera y se llama la fucnion MostrarDelVector.
En caso contrario se imprime un salto de linea
*/
void MostrarDelVector(int *Vector,int Tamano, int Bandera){
    if (Bandera  <= Tamano){
        printf("%d ",*(Vector+Bandera));
        Bandera++;
        MostrarDelVector(Vector,Tamano, Bandera);
    }
    else
        printf("\n");
}
/*
Se sigue trabajando.
*/
void NovenoPunto(){
    int Tamano=0;
    char Opcion=0;
    system("cls");
    printf("%cDesea ingresar el tama%co? [Y/N]: ",168,164);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        Tamano=TamanoVector();
    }
    else{
        Tamano=TamanoVectorAuto();
    }
    int Vector[Tamano];
    printf("\n%cDesea llenar el Vector? [Y/N]: ",168);
    scanf("%c", &Opcion);
    fflush(stdin);
    if(Opcion == 'Y' || Opcion == 'y'){
        LlenarVector(Tamano, Vector);
    }
    else{
        LlenarVectorAuto(Tamano, Vector);
    }
    OrdenaeVector(Vector, Tamano);
}

void OrdenaeVector(int *Vector,int Tamano1){
    MostrarDelVector(Vector,Tamano1, 0);
    int Vector2[Tamano1], Actual=0, Bandera=0,Nuevo=0, j=0;
    for(int i=0;i<Tamano1; i++){
        Actual=*(Vector+i);
        if(Actual != 12){
            for(j=i+1;j<Tamano1;j++){
            Nuevo = *(Vector+j);
            if(Actual <= Nuevo){
                Bandera++;
            }
        }
            if(Bandera == (Tamano1-i)){
                *(Vector2+i)=Actual;
                Bandera = 0;
                *(Vector+i)=12;
            }
        }
        
    }
}
