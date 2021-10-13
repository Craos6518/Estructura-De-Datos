#include <stdio.h>
struct Agenda{
    char Nombre[20];
    char Apellidos[20];
    char Direccion [12];
    char Ciudad[12];
    char TeleParti[10];
    char TeleTrab [10];
    char TelMovil[10];
    char Email[20];
} Agend;
void menu();

int main(){
    Menu();
    system("pause");
    return 0;
}

void Menu(){
    printf("\tMenu principal\n\t 1.Adicionar. \n\t 2.Listar datos. \n\t 3.Buscar un dato por Nombre y Apellido. \n\t 4.Modificar un dato. \n\t 5.Escribir en el archivo.\n\t");
}