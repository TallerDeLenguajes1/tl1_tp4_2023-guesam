#include <stdio.h>
#include <stdlib.h>

struct tarea
{
    int tareaID;
    char *descripcion;
    int duracion;
};

typedef struct tarea tareas;


int main(){
    int can;
    printf("Ingrese cantidad de tareas: ");
    scanf("%d", &can);
    tareas **tarea=(struct tarea**)malloc(sizeof(struct tarea*)*can);
    for (int i = 0; i < can; i++)
    {
        tarea[i] = NULL;
    }
    

    for (int i = 0; i < can; i++)
    {
        tarea[i] = malloc(sizeof(struct tarea));
        tarea[i]->tareaID = i;
        char buff[100];

        printf("Ingrese la descripción: ");
        tarea[i]->descripcion = malloc(sizeof(char) * strlen(buff + 1));
        strcpy(tarea[i]->descripcion, buff);
    }
    
}