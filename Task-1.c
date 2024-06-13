#include <stdio.h>

void mas(int *n, int a[]) {
    do {
        printf("Введіть кільксть елементів: ");
        scanf("%d", n);
        if (*n <= 0) {
            printf("Елементів має бути більше 0\n");
        }
    } while (*n <= 0);

    printf("Введіть елементи масиву: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Масив a:\n");
    for (int i = 0; i < *n; i++) {
        printf("%d\t", a[i]);
    }
}

void sort(int n, int a[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void menu() {
    int n = 0;
    int m = 0;
    int a[n];
    int h;
    do {
        
        printf("\n1. Заповнити масив");
        printf("\n2. Відсортувати");
        printf("\n0. Вихід з програми\n");
        printf("\nВведіть номер (0-2): ");
        scanf("%d", &h);

        if (h == 1) {
            mas(&n, a);
            m = 1;
        } else if (h == 2) {
            if (m == 1) {
                sort(n, a);
                printf("Відсортований масив:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\n");
            } else {
                printf("\nСпочатку задайте елементи масиву\n");
            }
        } else if (h == 0) {
            printf("Вихід з програми\n");
        } else {
            printf("Неправильна цифра\n");
        }

    } while (h != 0);
}

int main(void) {
    menu();
}
