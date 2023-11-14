#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void MostrarLista(int lista[], int num);
int busquedaBinaria(int lista[], int num, int elemento);
void OrdenarLista(int lista[], int num);

int main(void)
{
    srand(time(NULL));
    
    int num = 1000;
    int lista[num];
    int i;
    
   
    for (i = 0; i < num; i++)
    {
        lista[i] = rand() % 10 + 1;
    }
    
    
   
    OrdenarLista(lista, num);
    
    printf("Elementos de la lista (ordenados): \n");
    MostrarLista(lista, num);
    
    int elemento;
    printf("Elemento a buscar: ");
    scanf("%d", &elemento);
    
    clock_t inicio = clock();
    
    int posicion = busquedaBinaria(lista, num, elemento);
    
    clock_t fin = clock();
    
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    
    if (posicion != -1)
    {
        printf("Posicion: %d\n", posicion + 1);
    }
    else
    {
        printf("El elemento no se encuentra\n");
    }
    
    printf("Tiempo de ejecucion: %f segundos\n", tiempo);
    
    return 0;
}

void MostrarLista(int lista[], int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int busquedaBinaria(int lista[], int num, int elemento)
{
    int primero = 0;
    int ultimo = num - 1;
    int mitad;
    
    while (primero <= ultimo)
    {
        mitad = (primero + ultimo) / 2;
        
        if (lista[mitad] < elemento)
        {
            primero = mitad + 1;
        }
        else if (lista[mitad] == elemento)
        {
            return mitad;
        }
        else
        {
            ultimo = mitad - 1;
        }
    }
    
    return -1;
}

void OrdenarLista(int lista[], int num)
{
    int i, j;
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (lista[j] > lista[j + 1])
            {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

