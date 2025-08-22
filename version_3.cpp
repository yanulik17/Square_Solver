#include <TXLib.h>
#include <stdio.h>

int Solve_Square (double* coeffs, double* answer);
int Solve_Linear (double* coeffs, double* answer);
bool Input (double *coeffs);
int Output (double* answer);
double Discriminant (double* coeffs);

enum roots {
    no_roots, one_root, two_roots, inf_roots
};

// функция расчета дискриминанта ---------------------------------------------

double Discriminant (double* coeffs) {
    double D = 0;
    D = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
    return D;
}

// функция ввода коэффициентов -----------------------------------------------

bool Input (double* coeffs) {

    bool flag = 1;
    printf("Введите коэффициенты квадратного уравнения в порядке a, b, c:\n");

    if (scanf("%lg%lg%lg", &coeffs[0], &coeffs[1], &coeffs[2]) == 3) {
        return flag;
    }

    else {
        printf("Некорректный ввод данных.");
        flag = 0;
        return flag;
    }
}

// функция вывода ответов ----------------------------------------------------

int Output(double* answer) {

    int count = answer[0];
     switch (count) {

        case no_roots:
            printf("Уравнение не имеет действительных корней.");
            break;

        case one_root:
            printf("Уравнение имеет ровно один действительный корень: ");
            printf("%lg", answer[1]);
            break;

        case two_roots:
            printf("Уравнение имеет ровно два действительных корня: ");
            printf("%lg", answer[1]);
            printf(" и ");
            printf("%lg", answer[2]);
            break;

        case inf_roots:
            printf("Уравнение имеет бесконечное число корней.");
            break;

        default:
            break;
     }

     return 0;
}

// функция решения линейного уравнения --------------------------------------

int Solve_Linear (double* coeffs, double* answer) {

    double x = 0;

    int count = 0;
    if (coeffs[1] == 0 && coeffs[2] != 0) {
        count = no_roots;
    }
    else if (coeffs[1] == 0 && coeffs[2] == 0) {
        count = inf_roots;
    }

    else {
        count = one_root;
        x = - (coeffs[2] / coeffs[1]);
    }

    answer[0] = count;
    answer[1] = x;

    return 0;
}

// функция решения квадратного уравнения -----------------------------------

int Solve_Square (double* coeffs, double* answer)
{

    double D = 0, x1 = 0, x2 = 0, delta = 1e-9;
    int count = 0;

    D = Discriminant(coeffs);

    if (D > 0 + delta) { // дискриминант больше нуля

        count = two_roots;
        answer[0] = count;
        x1 = (-coeffs[1] + sqrt(D)) / (2 * coeffs[0]);
        x2 = (-coeffs[1] - sqrt(D)) / (2 * coeffs[0]);
        answer[1] = x1;
        answer[2] = x2;
    }

    else if (D < 0 - delta) {  // дискриминант меньше нуля
        count = no_roots;
        answer[0] = count;

    }

    else {     // дискриминант ноль
        count = one_root;
        answer[0] = count;
        x1 = (-coeffs[1] + sqrt(D)) / (2 * coeffs[0]);
        answer[1] = x1;
    }
    return 0;
}

//----------------------------------------------------------------------

int main (void)
{
    double coefficients[3]; // инициализация массива коэффициентов

    double answer[3];

    if (Input(coefficients)) {;   // если инпут в порядке

        if (coefficients[0] == 0) {
            Solve_Linear(coefficients, answer);
            Output(answer);
        }
        else {
            Solve_Square(coefficients, answer);
            Output(answer);
        }
    }
    return 0;
}
