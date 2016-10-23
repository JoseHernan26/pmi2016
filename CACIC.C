/*Jose Perez
German Altamirano
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAInscripto.h"

int main()
{
    FILE *fp1;
    pila p;
    int i,opc;
    inscripcion nuevo;

    system("COLOR 0F");
    for(i=0; i<80; i++)
        printf("%c",42);
    printf("\n\n\t\t\t\t BIENVENIDO\n\t\t\t\t\n");
    for(i=0; i<80; i++)
        printf("%c",42);
    printf("\n");
    system("PAUSE");
    system("CLS");
    system("COLOR 1F");
    init(&p);
    if ((fp1 = fopen("preins.txt","r")) != NULL)
    {
        while (!feof(fp1))
        {
            fscanf(fp1, "%s%s%d%s%d%d", nuevo.apellido, nuevo.nombre, &nuevo.dni, nuevo.universidad, &nuevo.tipo_inscripcion, &nuevo.confirmacion);

            insertar(&p, nuevo);
        }
//        inscripcion x;
//        int i;
//        for(i = 0; i <= p.tope; i++)
//        {
//            x = p.a[i];
//            mostrar(x);
//            printf("\n");
//        }


    }
    else
    {
        printf("Error fatal, no se pudo abrir el archivo\n");
        system("pause");
    }


    do
    {
        system("cls");
        printf("\n<1> AGREGAR UN INSCRIPTO\n"
               "<2> BUSCAR INSCRIPTO POR DNI\n"
               "<3> MOSTRAR DATOS DE PREINSCRIPTO\n"
               "<4> MOSTRAR CANTIDAD DE DINERO \n"
               "<5> IMPRIMIR LOS INSCRIPTOS EN UN ARCHIVO\n"
               "<0> SALIR\n"
               "Elija una opcion: ");
        scanf("%d", &opc);
       switch (opc)
        {
            case 1:
                {
                    if (isfull(p))
                    printf("\nERROR La pila esta llena\n");
                    else
                    {
                        cargar_nuevo(&nuevo);
                        insertar(&p, nuevo);
                    }
                    system("pause");
                    break;
                }

            case 2:{
                printf("\nINGRESE EL DNI QUE DESEA BUSCAR: ");
                do
                {
                    scanf("%d",&nuevo.dni);
                    getchar();
                    if(nuevo.dni<11111111 || nuevo.dni>99999999)
                        printf("\n ERROR NUMERO NO VALIDO REINGRESE NUEVAMENTE: ");
                }
                while(nuevo.dni<11111111 || nuevo.dni>99999999);

                busca_inscripto(&p,nuevo.dni);
                system("pause");

                break;}
            case 3:
                {
                    cantidad_inscriptos(p);
                    break;
                }
            case 4 :
                    {
                    calcula(p);
                    busca_inscripto(&p,nuevo.dni);
                    break;
                    }

            case 5:{
                     imprimir (p);
                     system("pause");
                     break;
                    }

            case 0: break;
        }

    }while(opc != 0);





    return 0;
}


