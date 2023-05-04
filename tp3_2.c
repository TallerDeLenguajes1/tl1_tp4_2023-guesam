#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct tarea {
    int tareaID; // numerado en ciclo iterativo
    char * descripcion;
    int duracion; // entre 10 - 100
} typedef tarea;

void cargarTareas(tarea ** tareas, int num);

int main(){
    srand(time(NULL));
    int num;

    printf("Ingrese cuantas tareas desea cargar: ");
    scanf("%d", &num);

    tarea ** tareas = (tarea **) malloc(sizeof(tarea) * num);

    for (int i = 0; i < num; i++){
        tareas[i] = NULL;
    }

    return 0;
}

void cargarTareas(tarea ** tareas, int num){
    char * buff;

    for (int i = 0; i < num; i++){
        tareas[i] = (tarea *)malloc(sizeof(tarea));
        tareas[i]->tareaID = i + 1;
        tareas[i]->duracion = rand() % 91 + 10;
    }
    
}