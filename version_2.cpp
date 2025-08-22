#include <TXLib.h>
#include <stdio.h>

int Solve_Square (double a, double b, double c);
int Solve_Linear (double a, double b, double c);
void Input (void);
int Output (void);

// ������� ����� ������������� -------------------------------------------



// ������� ������ ������� ------------------------------------------------



// ������� ������� ��������� ��������� -----------------------------------

int Solve_Linear (double a, double b, double c)
{
    double x;
    x = - (c / b);
    printf("%lg", x);
    return 0;
}

// ������� ������� ����������� ��������� ----------------------------------

int Solve_Square (double a, double b, double c)
{
    double D = 0, x_1 = 0, x_2 = 0, x = 0, delta = 1e-9;
    D = b * b - 4 * a * c;

    if (D > 0 + delta) { // ������������ ������ ����
        printf("��������� ����� ��� ��������� �������������� �����: ");   // switch
                                                                            // case, ��������� ��� enum
        x_1 = (-b - sqrt(D)) / (2 * a);
        printf("%lg", x_1);
        printf(" � ");
        x_2 = (-b + sqrt(D)) / (2 * a);
        printf("%lg", x_2);
        return 0;
    }

    else if (D < 0 - delta) {  // ������������ ������ ����
        printf("��������� �� ����� ������� � �������������� ������.\n");
        return 0;
    }

    else {     // ������������ ����
        printf("��������� ����� ����� ���� �������������� ������: ");
        x = (-b - sqrt(D)) / (2 * a);
        printf("%lg", x);
        return 0;
        }
}

//----------------------------------------------------------------------

int main (void)
{

    double a = 0, b = 0, c = 0;

    printf("������� ������������ ����������� ��������� ������ � ����� ������� � ������� a, b, c:\n");

    if (scanf("%lg", &a) + scanf("%lg", &b) + scanf("%lg", &c) == 3) {

        if (a == 0) {
            Solve_Linear(a, b, c);
        }
        else {
            Solve_Square(a, b, c);
        }
    }

    else {
        printf("������������ ���� ������.");
    }
    return 0;
}
