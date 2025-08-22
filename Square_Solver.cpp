#include <TXLib.h>
#include <stdio.h>

// функция решения квадратного уравнения ----------------------------------

int Solve_Square (double a, double b, double c)
{
    double D = 0, x_1 = 0, x_2 = 0, x = 0;
    D = b * b - 4 * a * c;

    if (D > 0) {
        printf("Уравнение имеет два различных действительных корня: ");
        x_1 = (-b - sqrt(D)) / (2 * a);
        printf("%lg", x_1);
        printf(" и ");
        x_2 = (-b + sqrt(D)) / (2 * a);
        printf("%lg", x_2);
        return 0;
    }

    else if (D == 0) {
        printf("Уравнение имеет ровно один действительный корень.");
        x = (-b - sqrt(D)) / (2 * a);
        printf("%lg", x);
        return 0;
    }

    else {
        printf("Уравнение не имеет решений в действительных числах.");
        return 0;
        }
}

//----------------------------------------------------------------------

int main (void)
{
    double a, b, c;
    bool flag = 0;

    printf("Введите коэффициенты квадратного уравнения каждый в новой строчке в порядке a, b, c:\n");

    while (scanf("%lg", &a) == 1) {

        if (a == 0)
        {
            printf("Это не квадратное уравнение.");
            return 0;
        }

        else
        {
            while (scanf("%lg", &b))
            {
                while (scanf("%lg", &c))
                {
                    Solve_Square(a, b, c);
                    return 0;
                }
            }
        }
    }
}
