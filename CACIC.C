#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAInscripto.h"

int main(){
FILE *fp1;
pila p;
int i,opc;
inscripcion nuevo;

system("COLOR 0F");
for(i=0;i<80;i++)
    printf("%c",42);
    printf("\n\n\t\t\t\t BIENVENIDO\n\t\t\t\t\n");
for(i=0;i<80;i++)
    printf("%c",42);
    system("PAUSE");
    system("CLS");
    system("COLOR 1F");
    printf("ACA IRIA EL MENU: ");
    scanf("%d",&P.tope);
    init(&P);

    fp1 = fopen("preins.txt","r");
    while (fp1 != EOF){
    fscanf(fp1, "%s %s %d %s %d %d ", nuevo.apellido, nuevo.nombre, p.a[p.tope].dni, nuevo.universidad, nuevo.tipo_inscripcion, nuevo.confirmacion)
    insertar(&p, nuevo);
    }
    printf("INGRESE UNA OPCION: <1> AGREGAR UN INSCRIPTO\n <2> BUSCAR INSCRIPTO POR DNI\n <3> MOSTRAR DATOS DE INSCRIPTO\n <4> CONFIRMAR INSCRIPCION\n <5> ")
switch (opc) {
    case 1 : if (isfull(p))
                printf("\nERROR La pila esta llena\n");
                else{
                cargar_nuevo(nuevo);
                insertar(&p, nuevo);}
                break;
    case 2: printf("\nINGRESE EL DNI QUE DESEA BUSCAR: ");
            do{scanf("%d",&nuevo.dni);getchar();
                if(nuevo.dni<11111111 || nuevo.dni>99999999)
                    printf("\n ERROR NUMERO NO VALIDO REINGRESE NUEVAMENTE: ");
            }while(nuevo.dni<11111111 || nuevo.dni>99999999);
                busca_inscripto(p,nuevo.dni);




            }
return 0;}


