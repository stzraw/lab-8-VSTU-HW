#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

char stroka(int i, int n, char c1, char c2);
int summa(int m, int n);
double stepen(int i);
double tabf(double x);
double ryad(double a, int n);

int main()
{
    int n0, i;
    char c1, c2, ch;
    int m1, n1, s;
    int degn, limitm;
    double res, lastres, resk;
    double a2, b2, h, x, y;
    double a3, res3;
    int n3;

    setlocale(LC_ALL, ".UTF8");

    printf("Задание 0:\n");
    printf("Введите количество символов: ");
    scanf("%d", &n0);
    printf("Введите первый и второй символ: ");
    scanf(" %c %c", &c1, &c2);

    putchar('+');
    for (i = 1; i <= n0; i++)
    {
        ch = stroka(i, n0, c1, c2);
        putchar(ch);
        putchar('!');
    }
    putchar('+');
    putchar('\n');

    printf("\nЗадание 1:\n");
    printf("Введите m и n (m >= n): ");
    scanf("%d %d", &m1, &n1);

    s = summa(m1, n1);
    printf("результат %d\n", s);

    printf("\nЗадание 1А (по показателю степени n):\n");
    printf("Введите степень n: ");
    scanf("%d", &degn);

    res = 1.0;
    for (i = 0; i <= degn; i++)
    {
        res = stepen(i);
        printf("2^%2d = %10.0lf\n", i, res);
    }
    resk = res / 1024.0;
    printf("Результат: %.1lfK\n", resk);

    printf("\nЗадание 1А (до заданного числа m):\n");
    printf("Введите предельное целое число m (m >= 1): ");
    scanf("%d", &limitm);

    lastres = 1.0;
    for (i = 0; stepen(i) <= (double)limitm; i++)
    {
        lastres = stepen(i);
        printf("2^%2d = %10.0lf\n", i, lastres);
    }
    resk = lastres / 1024.0;
    printf("Результат: %.1lfK\n", resk);

    printf("\nЗадание 2:\n");
    a2 = 0.2;
    b2 = 2.2;
    printf("Функция: y = 1.8 * x^2 - sin(10 * x) на интервале [0.2; 2.2]\n");
    printf("Введите шаг табуляции (h > 0): ");
    scanf("%lf", &h);

    if (h <= 0.0)
    {
        printf("Ошибка: шаг табуляции должен быть больше 0\n");
    }
    else
    {
        printf("_____________________\n");
        printf("|   x   |    f(x)   |\n");
        printf("---------------------\n");

        for (x = a2; x <= b2 + 0.0001; x += h)
        {
            y = tabf(x);
            printf("| %5.2lf | %9.4lf |\n", x, y);
        }
        printf("---------------------\n");
    }

    printf("\nЗадание 3 (ДЗ):\n");
    printf("Введите число a (a != 0): ");
    scanf("%lf", &a3);
    printf("Введите целое число n (n >= 0): ");
    scanf("%d", &n3);

    if (a3 == 0.0 || n3 < 0)
    {
        printf("Ошибка: некорректные входные данные\n");
    }
    else
    {
        res3 = ryad(a3, n3);
        printf("Сумма ряда: %.6lf\n", res3);
    }
    return 0;
}

char stroka(int i, int n, char c1, char c2)
{
    if (i <= n / 2)
    {
        return c1;
    }
    else
    {
        return c2;
    }
}

int summa(int m, int n)
{
    int i, s;

    s = 0;
    for (i = m; i >= n; i--)
    {
        s += i;
    }
    return s;
}

double stepen(int i)
{
    return pow(2.0, i);
}

double tabf(double x)
{
    return 1.8 * pow(x, 2) - sin(10.0 * x);
}

double ryad(double a, int n)
{
    int i;
    double sum, p;

    sum = 0.0;
    for (i = 0; i <= n; i++)
    {
        p = pow(2.0, i);
        sum += 1.0 / pow(a, p);
    }
    return sum;
}
