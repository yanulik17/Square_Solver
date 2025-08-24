#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>

// number of roots
enum roots {
    no_roots, one_root, two_roots, inf_roots
};

// signs of comparation
enum comparations {
    _less, _equal, _more
};

struct SquareSolver {
    double a;
    double b;
    double c;
    roots num_roots;
    double x1;   // minor root
    double x2;   // larger root
};

int Solve_Square (SquareSolver* solver); //
int Solve_Equation (SquareSolver* solver);
int Solve_Linear (SquareSolver* solver);
bool Input (SquareSolver* solver);
int Output (SquareSolver* solver);
double Discriminant (SquareSolver* solver);
int Compare (double chto, double s_chem);
void UnitTests();
bool Check(SquareSolver* sollution);

// general function of solving  --------------------------------------------------------------

int Solve_Equation (SquareSolver* solver) {

    if (Compare(solver->a, 0) == _equal) {
        Solve_Linear(solver);
    }

    else {
        Solve_Square(solver);
    }
    return 0;
}

// checking correctness of roots ------------------------------------------------------------

bool Check(SquareSolver* sollution) {

     SquareSolver temp_sollution = {sollution->a, sollution->b, sollution->c, no_roots, 0, 0};
     Solve_Equation(&temp_sollution);

     if (temp_sollution.num_roots != sollution->num_roots) {
         return false;
     }

     if (temp_sollution.num_roots == one_root || sollution->num_roots == two_roots) {
        if (Compare(temp_sollution.x1, sollution->x1) == _equal && Compare(temp_sollution.x2, sollution->x2) == _equal) {
            return true;
        }
        return false;
    }
    return true;
}

// function for unit testing ------------------------------------------------------------------

void UnitTests() {

     SquareSolver all_sollutions[2] = {{1, -5, 6, two_roots, 2, 3}, {567, 678790, 543546789, no_roots, 0, 0}};

     for (int i = 0; i < 2; i++) {
        if (!Check(&all_sollutions[i])) {
            printf("Ошибка в тесте номер %d.\n", i+1);
            return;
        }

        printf("OK\n");
     }
}

// function of comparation double and int  -----------------------------------------------------

int Compare (double chto, double s_chem) {

     double delta = 1e-9;
     int result = 0;

     if (chto > s_chem + delta) {
        result = _more;
     }

     else if (chto < s_chem - delta) {
        result = _less;
     }

     else {
        result = _equal;
     }
     return result;
}

// the function to count discriminant -------------------------------------------------------------

double Discriminant (SquareSolver* solver) {
    double D = 0;
    D = (solver->b) * (solver->b) - 4 * (solver->a) * (solver->c);
    return D;
}

// the function for correct input -----------------------------------------------------------------

bool Input (SquareSolver* solver) {

    assert(solver != NULL);
    bool flag = 1;
    printf("Enter coefficients of square equation: a, b, c:\n");

    if (scanf("%lg%lg%lg", &solver->a, &solver->b, &solver->c) == 3) {
        return flag;
    }

    else {
        printf("Incorrect data entry.");
        flag = 0;
        return flag;
    }
}

// function for output ---------------------------------------------------------------------------

int Output(SquareSolver* solver) {

     switch (solver->num_roots) {

        case no_roots:
            printf("This equation has no rational roots.");
            break;

        case one_root:
            printf("This equation has one rational root: ");
            printf("%lg", solver->x1);
            break;

        case two_roots:
            printf("This equation has two rational roots: ");
            printf("%lg", solver->x1);
            printf(" and ");
            printf("%lg", solver->x2);
            break;

        case inf_roots:
            printf("This equation has infinite root.");
            break;

        default:
            break;
     }

     return 0;
}

// function for solving linear equations --------------------------------------------------------

int Solve_Linear (SquareSolver* solver) {

    if (Compare(solver->b, 0) == _equal && Compare(solver->c, 0) != _equal) {
        solver->num_roots = no_roots;
    }

    else if (Compare(solver->b, 0) == _equal && Compare(solver->c, 0) == _equal) {
        solver->num_roots = inf_roots;
    }

    else {
        solver->num_roots = one_root;
        solver->x1 = - (solver->c / solver->b);
    }

    return 0;
}

// function for solving square equations -------------------------------------------------------

int Solve_Square (SquareSolver* solver)
{

    double D = 0;
    D = Discriminant(solver);

    switch (Compare(D, 0)) {

        case _more:
            solver->num_roots = two_roots;
            solver->x1 = (- solver->b - sqrt(D)) / (2 * (solver->a));
            solver->x2 = (- solver->b + sqrt(D)) / (2 * (solver->a));
            break;

        case _less:
            solver->num_roots = no_roots;
            break;

        case _equal:
            solver->num_roots = one_root;
            solver->x1 = (- solver->b - sqrt(D)) / (2 * (solver->a));
            solver->x2 = (- solver->b - sqrt(D)) / (2 * (solver->a));
            break;

        default:
            break;
    }

    return 0;
}

//-------------------------------------------------------------------------------------------

int main (int argc, char* argv[])
{
    if (argc == 2) {
        if (strcmp(argv[1], "--test") == 0) {
            UnitTests();

            return 0;
        }

        if (strcmp(argv[1], "--solve") == 0) {
            SquareSolver solver = {}; // struct with characteristics of square equation

            if (Input(&solver)) {;   // if input is okay
                Solve_Equation(&solver);
                Output(&solver);
            }

            return 0;
        }

        if (strcmp(argv[1], "--help") == 0) {
             printf("lol ne razobralsya, use --solve or --test"); 
             return 0;          
        }
    }
    printf("usage: *.exe --help");
    return 0;
}
