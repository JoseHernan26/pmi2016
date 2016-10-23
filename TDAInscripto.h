#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100

typedef struct
{
    char apellido[15];
    char nombre[15];
    int dni, costo;
    char universidad[10];
    int tipo_inscripcion;
    int confirmacion; //si es  igual a 0 no esta confirmado, 1 esta confirmado//
} inscripcion;

typedef struct
{
    int tope;
    inscripcion a[max];
} pila;

void init (pila *p)
{
    p->tope=-1;
}
void insertar(pila *p,inscripcion nuevo) //inscribir campo a campo
{
    ((*p).tope)++;
    (*p).a[(*p).tope]=nuevo;
}

inscripcion copiar(pila p)
{
    return p.a[p.tope];
}

int isempty(pila p)
{
    if(p.tope==-1)
        return 1;
    else
        return 0;
}

int isfull (pila p)
{
    if(p.tope==max-1)
        return 1;
    else
        return 0;
}

void suppress(pila *p)
{
    (*p).tope--;
}

void cargar_nuevo(inscripcion *n)
{
    printf("\n INGRESE EL APELLIDO: ");
    scanf("%s",n->apellido);
    printf("\n INGRESE EL NOMBRE: ");
    scanf("%s",n->nombre);
    printf("\n INGRESE EL DNI: ");
    scanf("%d",&n->dni);
    getchar();
    printf("\n INGRESE LA UNIVERSIDAD: ");
    scanf("%s",n->universidad);
    printf("\n INGRESE EL TIPO DE INSCRIPCION: \n\t<1> ASISTENTE\n\t<2> EXPOSITOR\n\t<3> ESTUDIANTE\n ");
    do
    {
        scanf("%d",&n->tipo_inscripcion);
        if(n->tipo_inscripcion<0 || n->tipo_inscripcion>3)
            printf("\nERROR REINGRESE NUEVAMENTE: ");
    }
    while(n->tipo_inscripcion<0 || n->tipo_inscripcion>3);
    do
    {
        printf("¿Desea confirmar su inscripcion ahora?\n\t <1>SI\n\t <0>NO\n ");
        scanf("%d", &n->confirmacion);
    }
    while(n->confirmacion<0 || n->confirmacion>1);

}

void mostrar(inscripcion n)
{
    printf("\n EL NOMBRE Y APELLIDO ES: %s %s ",n.nombre,n.apellido);
    printf("\n EL DNI ES: %d",n.dni);
    printf("\n LA UNIVERSIDAD A LA QUE ASISTE ES: %s",n.universidad);
    switch(n.tipo_inscripcion)
    {
    case 1:
        printf("\n EL INSCRIPTO ES ASISTENTE.");
        break;
    case 2:
        printf("\n EL INSCRIPTO ES EXPOSITOR.");
        break;
    case 3:
        printf("\n EL INSCRIPTO ES ESTUDIANTE.");
        break;
    }
    if(n.confirmacion==1)
    {
        printf("\n EL INSCRIPTO ESTA CONFIRMADO");
        switch(n.tipo_inscripcion)
        {
        case 1:
            printf("\n EL COSTO ES DE $150.");
            break;
        case 2:
            printf("\n EL COSTO ES DE $150.");
            break;
        case 3:
            printf("\n EL COSTO ES DE $50.");
            break;
        }
    }
    else
        printf("\n EL INSCRIPTO NO ESTA CONFIRMADO");
}

int confirma(inscripcion n)
{
    n.confirmacion=1;
    printf("\n\t\t\n\a INSCRIPCION CONFIRMADA CORRECTAMENTE.");
    switch(n.tipo_inscripcion)
    {
    case 1:
        n.costo=150;
        break;
    case 2:
        n.costo=150;
        break;
    case 3:
        n.costo=50;
    }
}

void busca_inscripto (pila *p, int dni)    // consultar estado
{
    inscripcion n;
    int opcion;
    pila aux;

    while (!isempty(*p)&& (*p).a[(*p).tope].dni!= dni)

    {
        insertar(&aux,copiar(*p));
        suppress(p);
    }

    if (isempty(*p))
    {
        printf("EL DNI: %d NO SE ENCUENTRA INSCRIPTO \n", dni);
        //exit(1);
    }
    else
    {
        n=copiar(*p);
        mostrar(n);
        printf("\nDESEA CONFIRMAR LA INSCRIPCION?\n Presione 1 para confirmar, 0 para volver al menu\n");//controlar switch para volver al menu//
        do
        {
            scanf("%d",&opcion);

            if(opcion<0||opcion>1)
                printf("\n LA OPCION QUE INGRESO ES INVALIDA VUELVA A INGRESAR : ");
        }
        while(opcion<0||opcion>1);

        if (opcion ==1)
        {
            (*p).a[(*p).tope].confirmacion=1;
            printf("Se confirmo un inscripto\n");
        }

    }
    while (!isempty(aux)&& (aux).a[aux.tope].dni!= dni)

    {
        insertar(p,copiar(aux));
        suppress(&aux);
    }



    // falta controlar esto en el main
}



int cantidad_inscriptos (pila p)
{
    int cont;
    inscripcion n;
    while (!isempty(p))
    {
        if (p.a[p.tope].confirmacion!=1)
        {
            n=p.a[p.tope];
            cont++;
            mostrar(n);
        }
        suppress(&p);

    }
    if (cont==0)
    {
        printf("No hay ningun confirmado \n");

    }
}


void calcula(pila P)
{
    int i;
    float resul=0.0;
    for(i=0; i<P.tope; i++)
        resul=resul+(P.a[P.tope].costo);

    printf("\n EL DINERO TOTAL INGRESADO ES: %.2f",resul);
}

void imprimir (pila p)

{
    int cont=0;
    FILE *fp2;
    fp2= fopen("inscriptos.txt", "a+");
    if (fp2==NULL)
    {
        printf("Error: el archivo no se puede abrir\n");
        exit(1);
    }

    else
    {
        while (!isempty(p))
        {
            if (p.a[p.tope].confirmacion==1)
            {
                fprintf(fp2, "%s\n%s\n%d\n%s\n", p.a[p.tope].apellido, p.a[p.tope].nombre, p.a[p.tope].dni, p.a[p.tope].universidad );
                switch(p.a[p.tope].tipo_inscripcion)
                {
                case 1:
                {
                    fprintf(fp2,"EL INSCRIPTO ES ASISTENTE.\n");
                    break;
                }
                case 2:
                {
                    fprintf(fp2,"EL INSCRIPTO ES EXPOSITOR.\n");
                    break;
                }
                case 3:
                {
                    fprintf(fp2,"EL INSCRIPTO ES ESTUDIANTE.\n");
                    break;
                }
                }
                cont++;
            }
            suppress(&p);

        }
    }
    if (cont>0)
        printf("Se agregaron %d nuevos inscriptos\n", cont);
    else
        printf("No se agregaron inscriptos\n");
    fclose(fp2);
}
