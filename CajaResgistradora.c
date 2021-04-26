#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char nombre_producto[100];
    int Precio;
    char Numero_Producto;
}Producto;

typedef struct
{
    Producto Producto;
    struct nodo* ptrNext;
}Nodo;

Nodo *header=NULL;
Nodo *footer=NULL;
int n;

Nodo* NewNode(){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    return(nodo);
}

void InsertNode(){
    Nodo* nodo= NewNode();
    printf("Nombre del producto: ");
    gets(nodo->Producto.nombre_producto);
    fflush(stdin);
    printf("Precio: ");
    scanf("%d",&nodo->Producto.Precio);
    fflush(stdin);
    if (header==NULL){
        n=1;
        nodo->Producto.Numero_Producto=n;
        header=nodo;
        footer=nodo;
        return;
    }
    n++;
    nodo->Producto.Numero_Producto=n;
    footer->ptrNext=nodo;
    nodo->ptrNext=NULL;
    footer=nodo;
}

void WalkList(){
    if(header==NULL){
        printf("Lista Vacia\n");
        return;
    }
    Nodo* i=header;
    while(i!=NULL){
        printf("Nombre del producto: %s\nPrecio: %d\nNumero del producto: %d\n",i->Producto.nombre_producto,i->Producto.Precio,i->Producto.Numero_Producto);
        i=i->ptrNext;
    }
}
void FreeList(){
    if(header==NULL){
        printf("Lista Vacia\n");
        return;
    }
    Nodo* i=header;
    while (i!=NULL)
    { 

    }
    header=NULL;
    footer=NULL;

}

void DeleteLast(){
    if(header==NULL){
        printf("Lista Vacia\n");
        return;
    }
    Nodo* i=header;
    while(i->ptrNext!=footer){
        i=i->ptrNext;
    }
    footer=i;
    i=i->ptrNext;
    free(i);
    footer->ptrNext=NULL;
}

void Delete_Element(int Numero_Producto){
    if(header==NULL){
        printf("Lista Vacia\n");
        return;
    }
    Nodo* i = header;
    Nodo* j;
    while (i->Producto.Numero_Producto!=(Numero_Producto-1))
    {
        i=i->ptrNext;
    }
    j=i->ptrNext;
    i->ptrNext=j->ptrNext;
    free(j);
}
int Menu_View(){
    int o;
    printf("1. A%cadir producto ",164);
    if(n>1){
        printf("2. Eliminar ultimo producto 3. Terminar cuenta\n\n");
        printf("Digite una opcion: ");
        scanf("%d",&o);
        while (1)
        {
            if(o<1||o>3){
                printf("Digite una opcion valida: ");
                scanf("%d",&o);
            }else{
                break;
            }
        }
        
    }else{
        printf("2. Cancelar cuenta\n\n");
        printf("Digite una opcion: ");
        scanf("%d",&o);
        while (1)
        {
            if(o<1||o>2){
                printf("Digite una opcion valida: ");
                scanf("%d",&o);
            }else{
                break;
            }
        }
    }
    return(o);
}
int Menu_Logic(int o){
    if (n>1){
        switch (o)
        {
        case 1:
            InsertNode();
            return(0);
            break;
        case 2:
            DeleteLast();
            printf("Se ha eliminado el ultimo producto\n");
            return(0);
            break;
        default:
            return(1);
            break;
        }
    }else{
        switch (o)
        {
        case 1:
            InsertNode();
            return(0);
            break;
        default:
            return(1);
            break;
        }
    }
}
int main (){
    printf("\t\t%x%c%c%c%c%c%c%c%c%c%c%c%c%c\n",0xc9,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t\t%c    CAJA    %c\n",186,186);
    printf("\t\t%cREGISTRADORA%c\n",186,186);
    printf("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,188);
    while(1)
    {
        int o=Menu_View();
        getchar();
        int x=Menu_Logic(o);
        if(x==1)break;
    }
    WalkList();
}