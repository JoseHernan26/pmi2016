#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100

typedef struct{
    char apellido[15];
    char nombre[15];
    int dni, costo;
    char universidad[10];
    int tipo_inscripcion;
    int confirmacion; //si es  igual a 0 no esta confirmado, 1 esta confirmado//
}inscripcion;

typedef struct{
    int tope;
    inscripcion a[max];
}pila;

void init (pila *p){
    p->tope=-1;
}
void insertar(pila *p,inscripcion nuevo) //inscribir campo a campo
{
     ((*p).tope)++;
    (*p).a[(*p).tope]=nuevo;
}

inscripcion copiar(pila p){
  return p.a[p.tope];
}

int isempty(pila p){
if(p.tope==-1)
	return 1;
else
	return 0;}

int isfull (pila p){
if(p.tope==max-1)
	return 1;
else
	return 0;}

void suppress(pila *p){
    (*p).tope--;
}

void cargar_nuevo(inscripcion n){
printf("\n INGRESE EL APELLIDO: ");
scanf("%s",n.apellido);
printf("\n INGRESE EL NOMBRE: ");
scanf("%s",n.nombre);
printf("\n INGRESE EL DNI: ");
scanf("%d",&n.dni);getchar();
printf("\n INGRESE LA UNIVERSIDAD: ");
scanf("%s",n.universidad);
printf("\n INGRESE EL TIPO DE INSCRIPCION: \t<1> ASISTENTE\n\t<2> EXPOSITOR\n\t<3> ESTUDIANTE\n ");
do{scanf("%d",&n.tipo_inscripcion);
    if(n.tipo_inscripcion<0 || n.tipo_inscripcion>3)
        printf("\nERROR REINGRESE NUEVAMENTE: ");
}while(n.tipo_inscripcion<0 || n.tipo_inscripcion>3);
n.confirmacion=0;
}

int busca_inscripto (pila p, int dni) {  // consultar estado
    inscripcion n;
while (!isempty(p)&& p.a[p.tope].dni!= dni)
        suppress(p);
    if (isempty(p)){
        printf("EL DNI: %d NO SE ENCUENTRA INSCRIPTO \n", dni);
        return 0;}
    else
        return 1; // falta controlar esto en el main
}

void mostrar(inscripcion n){
printf("\n EL NOMBRE Y APELLIDO ES: &s &s ",n.nombre,n.apellido);
printf("\n EL DNI ES: %d",n.dni);
printf("\n LA UNIVERSIDAD A LA QUE ASISTE ES: %s",n.universidad);
switch(n.tipo_inscripcion){
case 1: printf("\n EL INSCRIPTO ES ASISTENTE.");break;
case 2: printf("\n EL INSCRIPTO ES EXPOSITOR.");break;
case 3: printf("\n EL INSCRIPTO ES ESTUDIANTE.");break;
}
 if(n.confirmacion==1){
    printf("\n EL INSCRIPTO ESTA CONFIRMADO");
    switch(n.tipo_inscripcion){
        case 1: printf("\n EL COSTO ES DE $150.");break;
        case 2: printf("\n EL COSTO ES DE $150.");break;
        case 3: printf("\n EL COSTO ES DE $50.");break;}}
 else
    printf("\n EL INSCRIPTO NO ESTA CONFIRMADO");}

int confirma(inscripcion n){
n.confirmacion=1;
printf("\n\t\t\n\a INSCRIPCION CONFIRMADA CORRECTAMENTE.");
switch(n.tipo_inscripcion){
case 1: n.costo=150;break;
case 2: n.costo=150;break;
case 3: n.costo=50;
}
}
int cantidad_inscriptos (pila p){
   int cont;
   inscripcion n;
while (!isempty(p)){
if (p.a[p.tope].confirmacion==1){
        n=p.a[p.tope];
        cont++;
       mostrar(n)
}
 suppress(&p);

}
    if (cont==0){
        printf("No hay ningun confirmado \n");

}
}

void calcula(pila P,inscripcion n){
    int i; float resul=0.0;
    for(i=0;i<P.tope;i++)
        resul=resul+(n.costo);
printf("\n EL DINERO TOTAL INGRESADO ES: %.2f",resul);
void imprimir (pila p){
    FILE *fp2
    fp2= fopen("inscriptos.txt", "r+");
    if (fp2= fopen("inscriptos.txt", "r+")==NULL){
        printf("Error: el archivo no se puede abrir\n");
        exit(1);
    }

    while (!isempty(p)){
    if (p.a[p.tope].confirmacion=1)
    {
        fprintf(fp2, "|%s|\n |%s|\n |%d|\n |%s|\n ", p.a[p.tope].apellido, p.a[p.tope].nombre, p.a[p.tope].dni, p.a[p.tope].universidad );
        switch(p.a[p.tope].tipo_inscripcion){
case 1: fprintf(fp2,"\n EL INSCRIPTO ES ASISTENTE.");break;
case 2: fprintf(fp2,"\n EL INSCRIPTO ES EXPOSITOR.");break;
case 3: fprintf(fp2,"\n EL INSCRIPTO ES ESTUDIANTE.");break;
    }
    suppress(&p);
    }

}
fclose(fp2);
}
