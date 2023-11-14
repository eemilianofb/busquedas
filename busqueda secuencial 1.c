#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int i, num, elemento, bandera = 0;

    srand(time(NULL));

    printf("N�mero de elementos a crear: ");
    scanf("%d", &num);

    int lista[num];

    printf("N�mero a buscar: ");
    scanf("%d", &elemento);

    for (i = 0; i < num; i++)
    {
        lista[i] = rand() % (10 + 1 - 1) + 1;
    }

    printf("Elementos de la lista:\n");

    for (i = 0; i < num; i++)
    {
        printf("%d\n", lista[i]);
    }

    printf("\n");

    for (i = 0; i < num; i++)
    {
        if (lista[i] == elemento)
        {
            printf("Elemento en posici�n: %d\n", i + 1);
            bandera = 1;
            break;
        }
    }

    if (bandera == 0)
    {
        printf("El elemento no se encuentra\n");
    }

    return 0;
}

