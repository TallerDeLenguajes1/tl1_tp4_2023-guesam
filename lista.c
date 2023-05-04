#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eliminarNodo(nodo * nodos);

//crear nodo
typedef struct nodo
{
    int num;
    nodo * sig;
} nodo;


int main(){
    nodo * aux;
    nodo * cabecera2;
    nodo * cabecera;
    nodo * nuevo;
    int a;

    //inicializo
    cabecera = NULL;
    cabecera2 = NULL;

    //llenando una lista
    for (int i = 0; i < 3; i++){
        nuevo = (nodo *) malloc(sizeof(nodo));
        nuevo->num = i + 1;
        nuevo->sig = cabecera;
        cabecera = nuevo;
    }

    //mostrar una lista
    aux = cabecera;
    while (aux != NULL){
        printf("%d", aux->num);
        aux = aux->sig;
    }


    //aislar nodo y moverlo a otra lista
    aux = cabecera;
    nodo * solito;
    while (aux != NULL){
        printf("%d", aux->num);
        printf("desea moverlo? 1: si 2: no ");
        scanf("%d", a);
        fflush(stdin);
        if(a == 1){
            if(aux == cabecera){
                solito = aux;
                aux = aux->sig;
                cabecera = aux;
                solito->sig = cabecera2;
                cabecera2 = solito;
            } else {

            }
        }

    }
    


    return 0;
}



void eliminarNodo(nodo * nodos){
    if((!nodos)) free(nodos);
}