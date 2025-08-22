#include <TXLib.h>
#include <stdio.h>

int Solve_Square (double a, double b, double c);
int Solve_Linear (double a, double b, double c);
int Input (void);
int Output (void);

// ������� ����� ������������� -------------------------------------------

int Input (void) {

    struct

    double a = 0, b = 0, c = 0;
    bool flag = 1;  // ���� ��� ������ ����������� ������

    printf("������� ������������ ����������� ��������� ������ � ����� ������� � ������� a, b, c:\n");

    while (scanf("%lg", &a) + scanf("%lg", &b) + scanf("%lg", &c) == 3) {
        flag = 1;
    }

    if (flag == 0) {
        printf("������������ ���� ������.");
    }
    return ;
}

// ������� ������ ������� ------------------------------------------------

int Output (void) {

}

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
    printf(Input());

    return 0;
}
