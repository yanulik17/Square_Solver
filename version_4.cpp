#include <TXLib.h>
#include <stdio.h>

enum roots {
    no_roots, one_root, two_roots, inf_roots
};


struct SquareSolver {
    double a;
    double b;
    double c;
    double x1;   // меньший корень
    double x2;   // больший корень
    roots num_roots;
};


int Solve_Square (SquareSolver* solver);
int Solve_Linear (SquareSolver* solver);
bool Input (SquareSolver* solver);
int Output (SquareSolver* solver);
double Discriminant (SquareSolver* solver);

// функция расчета дискриминанта ---------------------------------------------

double Discriminant (SquareSolver* solver) {
    double D = 0;
    D = (solver->b) * (solver->b) - 4 * (solver->a) * (solver->c);
    return D;
}

// функция ввода коэффициентов -----------------------------------------------

bool Input (SquareSolver* solver) {

    bool flag = 1;
    printf("Введите коэффициенты квадратного уравнения в порядке a, b, c:\n");

    if (scanf("%lg%lg%lg", &solver->a, &solver->b, &solver->c) == 3) {
        return flag;
    }

    else {
        printf("Некорректный ввод данных.");
        flag = 0;
        return flag;
    }
}

// функция вывода ответов ----------------------------------------------------

int Output(SquareSolver* solver) {

     switch (solver->num_roots) {

        case no_roots:
            printf("Уравнение не имеет действительных корней.");
            break;

        case one_root:
            printf("Уравнение имеет ровно один действительный корень: ");
            printf("%lg", solver->x1);
            break;

        case two_roots:
            printf("Уравнение имеет ровно два действительных корня: ");
            printf("%lg", solver->x1);
            printf(" и ");
            printf("%lg", solver->x2);
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

int Solve_Linear (SquareSolver* solver) {

    if (solver->b == 0 && solver->c != 0) {
        solver->num_roots = no_roots;
    }
    else if (solver->b == 0 && solver->c == 0) {
        solver->num_roots = inf_roots;
    }

    else {
        solver->num_roots = one_root;
        solver->x1 = - (solver->c / solver->b);
    }

    return 0;
}

// функция решения квадратного уравнения -----------------------------------

int Solve_Square (SquareSolver* solver)
{

    double D = 0, delta = 1e-9;

    D = Discriminant(solver);

    if (D > 0 + delta) { // дискриминант больше нуля

        solver->num_roots = two_roots;

        solver->x1 = (- solver->b - sqrt(D)) / (2 * (solver->a));
        solver->x2 = (- solver->b + sqrt(D)) / (2 * (solver->a));
    }

    else if (D < 0 - delta) {  // дискриминант меньше нуля
        solver->num_roots = no_roots;
    }

    else {     // дискриминант ноль
        solver->num_roots = one_root;
        solver->x1 = (- solver->b - sqrt(D)) / (2 * (solver->a));
    }
    return 0;
}

//----------------------------------------------------------------------

int main (void)
{
    SquareSolver solver = {};

 // инициализация массива коэффициентов

 // первый элемент - кол-во корней, дальше - корни (если есть)

    if (Input(&solver)) {;   // если инпут в порядке

        if (solver.a == 0) {
            Solve_Linear(&solver);
            Output(&solver);
        }
        else {
            Solve_Square(&solver);
            Output(&solver);
        }
    }
    return 0;
}
