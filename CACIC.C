#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAInscripto.h"

int main ()

{

    int opmenu;
    pila p;
    init(&p);

    inscripcion x;
    strcpy(x.apellido, "perez");
    strcpy(x.nombre, "jose");
    x.dni = 3567990;
    x.costo = 300;
    strcpy(x.universidad, "unsl");
    x.tipo_inscripcion = 1;
    strcpy(x.confirmacion, "si");

    insertar(&p, x);

    printf("\nApellido: %s\n", p.a[p.tope].apellido);


//   do
//       {
 //       printf ("llene la pila gil\n");
//
//        scanf("%d", &opmenu);
//
//       }while (opcmenu!=0)
       return 0;
}
