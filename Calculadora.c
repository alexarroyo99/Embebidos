#include<stdio.h>
#include<stdlib.h>

void suma2(){
    int a,b;
    printf("\nDigite el primer numero: ");
    scanf("%d",&a);
    printf("\nDigite el segundo numero: ");
    scanf("%d",&b);
    printf("\n%d + %d = %d\n",a,b,a+b);
}
void resta2(){
    int a,b;
    printf("\nDigite el primer numero: ");
    scanf("%d",&a);
    printf("\nDigite el segundo numero: ");
    scanf("%d",&b);
    if (b>a){
        printf("\n%d - %d = %d\n",b,a,b-a);
    }else{
        printf("\n%d - %d = %d\n",a,b,a-b);
    }
}

int main(){
    while(1){
        int option,option2;
        printf("calculadora XD\n\n");
        printf("1. Sumar 2 numeros.\n");
        printf("2. Restar 2 numeros.\n");
        printf("3. Multiplicar 2 numeros.\n");
        printf("4. Raiz Cuadrada.\n");
        printf("5. Factorial de un numero.\n");
        printf("\n\nDigite una opcion: ");
        scanf("%d",&option);
        while (1){
            if(option<1 || option>2){
                printf("\nOpcion Invalida, digite nuevamente: ");
                scanf("%d",&option);
            }else{
                break;
            }
        }
        switch (option)
        {
        case 1:
            suma2();
            break;
        case 2: 
            resta2();
            break;
        
        default:
            break;
        }
        printf("\n¿Desea hacer otra operacion?\n1. Si\n2. Salir");
        printf("\n\nDigite una opcion: ");
        scanf("%d",&option2);
        while (1){
            if(option<1 || option>2){
                printf("\nOpcion Invalida, digite nuevamente: ");
                scanf("%d",&option2);
            }else{
                break;
            }
        }
        if(option2==2) break;
    }  
}