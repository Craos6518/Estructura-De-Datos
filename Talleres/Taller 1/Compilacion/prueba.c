#include <string.h>
#include <stdio.h>
#include <conio.h>
int main(){
    char Opcion=0;
    scanf("%c", &Opcion);
    //if((strcmp(Opcion, "y")== 0) || (strcmp(Opcion, "Y"))){
    if(Opcion == 'Y' || Opcion == 'y'){
        printf("Verdadero");
    }
    else{
        printf("Falso");
    }
    system("pause");
    return 0;
}