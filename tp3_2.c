#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct tarea {
    int tareaID; // numerado en ciclo iterativo
    char * descripcion;
    int duracion; // entre 10 - 100
} typedef tarea;

struct nodo
{
    tarea T;
    nodo * sig;
} typedef nodo;

nodo * pendientes;
nodo * realizadas;

void cargarTareas(tarea ** tareas, int num);
void controlTareas(tarea ** tareas, tarea ** tareasT, int num);
void mostrarTareas(tarea ** tareas, int num);
void buscarTareaPorId(tarea ** tareas, int num);
void buscarTareaPorPalabra(tarea ** tareas, int num);

int main(){
    srand(time(NULL));
    int num;

    printf("Ingrese cuantas tareas desea cargar: ");
    scanf("%d", &num);

    tarea ** tareas = (tarea **) malloc(sizeof(tarea *) * num);
    tarea ** tareasRealizadas = (tarea **) malloc(sizeof(tarea *) * num);

    for (int i = 0; i < num; i++){
        tareas[i] = NULL;
        tareasRealizadas[i] = NULL;
    }

    cargarTareas(tareas, num);
    controlTareas(tareas, tareasRealizadas, num);
    printf("\nTareas realizadas\n");
    mostrarTareas(tareasRealizadas, num);
    printf("\nTareas pendientes\n");
    mostrarTareas(tareas, num);
    buscarTarea(tareas, num);

    return 0;
}

void cargarTareas(tarea ** tareas, int num){
    char * buffer;

    for (int i = 0; i < num; i++){
        tareas[i] = (tarea *)malloc(sizeof(tarea));
        tareas[i]->tareaID = i + 1;

        printf("Ingrese la descripcion: ");
        buffer = (char *) malloc(sizeof(char) * 100);
        fflush(stdin);
        gets(buffer);
        tareas[i]->descripcion = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(tareas[i]->descripcion, buffer);

        tareas[i]->duracion = rand() % 91 + 10;

        free(buffer);
    }
}

void controlTareas(tarea ** tareas, tarea ** tareasT, int num){
    int estado;
    for (int i = 0; i < num; i++){
        if(tareas[i] != NULL){
            printf("ID: %d \n", tareas[i]->tareaID);
            printf("Descripcion: %s \n", tareas[i]->descripcion);
            printf("Duracion: %d \n", tareas[i]->duracion);
            printf("Ya realizo esta tarea? (1: Si 2: No) ");
            scanf("%d", &estado);
            
            if(estado == 1){
                tareasT[i] = tareas[i];
                tareas[i] = NULL;
            }
        }
    }
}

void mostrarTareas(tarea ** tareas, int num){
    for (int i = 0; i < num; i++){
        if(tareas[i] != NULL){
            printf("ID: %d \n", tareas[i]->tareaID);
            printf("Descripcion: %s \n", tareas[i]->descripcion);
            printf("Duracion: %d \n", tareas[i]->duracion);
        }
    }
}

void buscarTareaPorId(tarea ** tareas, int num){
    int id, aux;
    printf("Ingrese el ID de la tarea que desea buscar: ");
    scanf("%d", &id);
    fflush(stdin);
    for (int i = 0; i < num; i++){
        if(tareas[i] != NULL){
            aux = tareas[i]->tareaID;
            if((aux) == id){
                printf("\n");
                printf("ID: %d \n", tareas[i]->tareaID);
                printf("Descripcion: %s \n", tareas[i]->descripcion);
                printf("Duracion: %d \n", tareas[i]->duracion);
            }
        }
    }
}

void buscarTareaPorPalabra(tarea ** tareas, int num){
    char *aux, *clave;
    printf("Ingrese la palabra clave: ");
    fflush(stdin);
    gets(clave);
    for (int i = 0; i < num; i++){
        if(tareas[i] != NULL){
            aux = tareas[i]->descripcion;
            if(strstr(aux, clave) != NULL){
                printf("ID: %d \n", tareas[i]->tareaID);
                printf("Descripcion: %s \n", tareas[i]->descripcion);
                printf("Duracion: %d \n", tareas[i]->duracion);
            }
        }
    }
}