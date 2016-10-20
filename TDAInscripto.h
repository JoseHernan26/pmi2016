#include <stdio.h>
#include <stdlib.h>
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
void insertar(pila *p,inscripcion nuevo)
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

int busca_inscripto (pila p, int dni) {
pila aux;
while (!isempty(p) && copiar(p).dni!= dni){    //PREGUNTAR ME DEVUELVE UNA ESTRUCTURA, QUIERO SABER EL DNI//
 aux=p;
 suppress(&aux);
}
if (!isempty(p)){
printf("EL DNI: %d SE ENCUENTRA INSCRIPTO \n", dni);
return 1;}
else{
printf("EL DNI: %d NO ESTA INSCRIPTO\n",dni );
return 0;}
//while(!isempty(aux)){
    //insertar(&aux,p);//ERROR EN EL PASAJE DEL 2� ARGUMENTO//
//}
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


