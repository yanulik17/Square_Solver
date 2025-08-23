#include <TXLib.h>
#include <stdio.h>

// ���������� ������
enum roots {
    no_roots, one_root, two_roots, inf_roots
};

// ����� ���������
enum comparations {
    _less, _equal, _more
};

struct SquareSolver {
    double a;
    double b;
    double c;
    roots num_roots;
    double x1;   // ������� ������
    double x2;   // ������� ������
};

int Solve_Square (SquareSolver* solver);
int Solve_Equation (SquareSolver* solver);
int Solve_Linear (SquareSolver* solver);
bool Input (SquareSolver* solver);
int Output (SquareSolver* solver);
double Discriminant (SquareSolver* solver);
int Compare (double chto, double s_chem);
void UnitTests();
bool Check(SquareSolver* sollution);

// ������� ������� ���� ��������� --------------------------------------------------------------

int Solve_Equation (SquareSolver* solver) {

    if (Compare(solver->a, 0) == _equal) {
        Solve_Linear(solver);
    }

    else {
        Solve_Square(solver);
    }
    return 0;
}

// ������� �������� ������������ ������ --------------------------------------------------------

bool Check(SquareSolver* sollution) {

     SquareSolver temp_sollution = {sollution->a, sollution->b, sollution->c, no_roots, 0, 0};
     Solve_Equation(&temp_sollution);
     if (temp_sollution.num_roots != sollution->num_roots) {
         return false;
     }
     else if (Compare(temp_sollution.x1, sollution->x1) != _equal || Compare(temp_sollution.x2, sollution->x2) != _equal) {
        return false;
     }
     else {
        return true;
     }
}

// ������� ���� ������������ ------------------------------------------------------------------

void UnitTests() {

     SquareSolver all_sollutions[1] = {{1, -5, 6, two_roots, 2, 3}};

     for (int i = 0; i < 1; i++) {
        if (!Check(&all_sollutions[i])) {
            printf("������ � ����� ����� %d.\n", i+1);
            return;
        }

     }
     printf("OK\n");

}

// ������� ��������� ���������� ���� double � ������������� ��������� -------------------------

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

// ������� ������� ������������� -------------------------------------------------------------

double Discriminant (SquareSolver* solver) {
    double D = 0;
    D = (solver->b) * (solver->b) - 4 * (solver->a) * (solver->c);
    return D;
}

// ������� ����� ������������� ---------------------------------------------------------------

bool Input (SquareSolver* solver) {

    assert(solver != NULL);
    bool flag = 1;
    printf("������� ������������ ����������� ��������� � ������� a, b, c:\n");

    if (scanf("%lg%lg%lg", &solver->a, &solver->b, &solver->c) == 3) {
        return flag;
    }

    else {
        printf("������������ ���� ������.");
        flag = 0;
        return flag;
    }
}

// ������� ������ ������� --------------------------------------------------------------------

int Output(SquareSolver* solver) {

     switch (solver->num_roots) {

        case no_roots:
            printf("��������� �� ����� �������������� ������.");
            break;

        case one_root:
            printf("��������� ����� ����� ���� �������������� ������: ");
            printf("%lg", solver->x1);
            break;

        case two_roots:
            printf("��������� ����� ����� ��� �������������� �����: ");
            printf("%lg", solver->x1);
            printf(" � ");
            printf("%lg", solver->x2);
            break;

        case inf_roots:
            printf("��������� ����� ����������� ����� ������.");
            break;

        default:
            break;
     }

     return 0;
}

// ������� ������� ��������� ��������� -----------------------------------------------------

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

// ������� ������� ����������� ��������� ---------------------------------------------------

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
            break;

        default:

            break;
    }

    return 0;
}

//-------------------------------------------------------------------------------------------

int main (void)
{
    UnitTests();
    SquareSolver solver = {}; // ��������� �������������� ��������� ����������� ���������

    if (Input(&solver)) {;   // ���� ����� � �������

        Solve_Equation(&solver);
        Output(&solver);
    }
    return 0;
}
