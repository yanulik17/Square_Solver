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

// ������� ������� ������������� ---------------------------------------------

double Discriminant (double* coeffs) {
    double D = 0;
    D = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
    return D;
}

// ������� ����� ������������� -----------------------------------------------

bool Input (double* coeffs) {

    bool flag = 1;
    printf("������� ������������ ����������� ��������� � ������� a, b, c:\n");

    if (scanf("%lg%lg%lg", &coeffs[0], &coeffs[1], &coeffs[2]) == 3) {
        return flag;
    }

    else {
        printf("������������ ���� ������.");
        flag = 0;
        return flag;
    }
}

// ������� ������ ������� ----------------------------------------------------

int Output(double* answer) {

    int count = answer[0];
     switch (count) {

        case no_roots:
            printf("��������� �� ����� �������������� ������.");
            break;

        case one_root:
            printf("��������� ����� ����� ���� �������������� ������: ");
            printf("%lg", answer[1]);
            break;

        case two_roots:
            printf("��������� ����� ����� ��� �������������� �����: ");
            printf("%lg", answer[1]);
            printf(" � ");
            printf("%lg", answer[2]);
            break;

        case inf_roots:
            printf("��������� ����� ����������� ����� ������.");
            break;

        default:
            break;
     }

     return 0;
}

// ������� ������� ��������� ��������� --------------------------------------

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

// ������� ������� ����������� ��������� -----------------------------------

int Solve_Square (double* coeffs, double* answer)
{

    double D = 0, x1 = 0, x2 = 0, delta = 1e-9;
    int count = 0;

    D = Discriminant(coeffs);

    if (D > 0 + delta) { // ������������ ������ ����

        count = two_roots;
        answer[0] = count;
        x1 = (-coeffs[1] + sqrt(D)) / (2 * coeffs[0]);
        x2 = (-coeffs[1] - sqrt(D)) / (2 * coeffs[0]);
        answer[1] = x1;
        answer[2] = x2;
    }

    else if (D < 0 - delta) {  // ������������ ������ ����
        count = no_roots;
        answer[0] = count;

    }

    else {     // ������������ ����
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
    double coefficients[3]; // ������������� ������� �������������

    double answer[3];

    if (Input(coefficients)) {;   // ���� ����� � �������

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
