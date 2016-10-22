#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAInscripto.h"

int main(){
pila P;int i;
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



return 0;

}
