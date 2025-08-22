#include <TXLib.h>
#include <stdio.h>

// ������� ������� ����������� ��������� ----------------------------------

int Solve_Square (double a, double b, double c)
{
    double D = 0, x_1 = 0, x_2 = 0, x = 0;
    D = b * b - 4 * a * c;

    if (D > 0) {
        printf("��������� ����� ��� ��������� �������������� �����: ");
        x_1 = (-b - sqrt(D)) / (2 * a);
        printf("%lg", x_1);
        printf(" � ");
        x_2 = (-b + sqrt(D)) / (2 * a);
        printf("%lg", x_2);
        return 0;
    }

    else if (D == 0) {
        printf("��������� ����� ����� ���� �������������� ������.");
        x = (-b - sqrt(D)) / (2 * a);
        printf("%lg", x);
        return 0;
    }

    else {
        printf("��������� �� ����� ������� � �������������� ������.");
        return 0;
        }
}

//----------------------------------------------------------------------

int main (void)
{
    double a, b, c;
    bool flag = 0;

    printf("������� ������������ ����������� ��������� ������ � ����� ������� � ������� a, b, c:\n");

    while (scanf("%lg", &a) == 1) {

        if (a == 0)
        {
            printf("��� �� ���������� ���������.");
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
