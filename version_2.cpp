#include <TXLib.h>
#include <stdio.h>

int Solve_Square (double a, double b, double c);
int Solve_Linear (double a, double b, double c);
void Input (void);
int Output (void);

// функция ввода коэффициентов -------------------------------------------



// функция вывода ответов ------------------------------------------------



// функция решения линейного уравнения -----------------------------------

int Solve_Linear (double a, double b, double c)
{
    double x;
    x = - (c / b);
    printf("%lg", x);
    return 0;
}

// функция решения квадратного уравнения ----------------------------------

int Solve_Square (double a, double b, double c)
{
    double D = 0, x_1 = 0, x_2 = 0, x = 0, delta = 1e-9;
    D = b * b - 4 * a * c;

    if (D > 0 + delta) { // дискриминант больше нуля
        printf("Уравнение имеет два различных действительных корня: ");   // switch
                                                                            // case, прочитать про enum
        x_1 = (-b - sqrt(D)) / (2 * a);
        printf("%lg", x_1);
        printf(" и ");
        x_2 = (-b + sqrt(D)) / (2 * a);
        printf("%lg", x_2);
        return 0;
    }

    else if (D < 0 - delta) {  // дискриминант меньше нуля
        printf("Уравнение не имеет решений в действительных числах.\n");
        return 0;
    }

    else {     // дискриминант ноль
        printf("Уравнение имеет ровно один действительный корень: ");
        x = (-b - sqrt(D)) / (2 * a);
        printf("%lg", x);
        return 0;
        }
}

//----------------------------------------------------------------------

int main (void)
{

    double a = 0, b = 0, c = 0;

    printf("Введите коэффициенты квадратного уравнения каждый в новой строчке в порядке a, b, c:\n");

    if (scanf("%lg", &a) + scanf("%lg", &b) + scanf("%lg", &c) == 3) {

        if (a == 0) {
            Solve_Linear(a, b, c);
        }
        else {
            Solve_Square(a, b, c);
        }
    }

    else {
        printf("Некорректный ввод данных.");
    }
    return 0;
}
