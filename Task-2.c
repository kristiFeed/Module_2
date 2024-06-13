#include <stdio.h>
#include <math.h>

void printmas(int *n, int *m, float C[*n][*m])
{
    printf("Матриця C:\n");
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            printf("%.2f\t", C[i][j]);
        }
        printf("\n");
    }
}

void mas(int *n, int *m, float C[*n][*m])
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            if (i < j)
            {
               
                C[i][j] = pow(i, 2) + pow(j, 2) + 2;
            }
            else if (i == j)
            {
                 if (i == 0 && j  == 0)
                {
                    C[i][j] = 0;
                } else 
                C[i][j] = 1.0 / (i + j);
            }
            else
            {
                C[i][j] = sin(i) + sin(j);
            }
        }
    }
}

void menu()
{
    int n, m;
    int h;
    float C[100][100];
    int f = 0;
    do
    {
        printf("\n1. Задати розмір масиву");
        printf("\n2. Вивести матрицю");
        printf("\n0. Вихід з програми\n");
        printf("\nВведіть номер (0-2): ");
        scanf("%d", &h);

        if (h == 1)
        {
            printf("Введіть кількість рядків матриці: ");
            scanf("%d", &n);
            printf("Введіть кількість стовпців матриці: ");
            scanf("%d", &m);
            mas(&n, &m, C);
            f = 1;
        }
        else if (h == 2)
        {
            if (f == 1)
            {
                printmas(&n, &m, C);
            }
            else
            {
                printf("\nСпочатку задайте розмірність матриці\n");
            }
        }
        else if (h == 0)
        {
            printf("Вихід з програми\n");
        }
        else
        {
            printf("Неправильний номер\n");
        }

    } while (h != 0);
}

int main(void)
{
    menu();
}
