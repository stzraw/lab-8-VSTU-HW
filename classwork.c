#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int task0();
int task1();
int task1a();
int task2();
int task3();

int stroka(int n, char c1, char c2);
int summa(int m, int n);
double stepen(int i);
double tabf(double x);
double ryad(double a, int n);

int main()
{
    setlocale(LC_ALL, ".UTF8");

    task0();
    task1();
    task1a();
    task2();
    task3();
    return 0;
}

int task0()
{
    int n;
    char c1, c2;

    printf("Задание 0:\n");
    printf("Введите количество символов: ");
    scanf("%d", &n);
    printf("Введите первый и второй символ: ");
    scanf(" %c %c", &c1, &c2);

    stroka(n, c1, c2);
    return 0;
}

int task1()
{
    int m, n, s;

    printf("\nЗадание 1:\n");
    printf("Введите m и n (m >= n): ");
    scanf("%d %d", &m, &n);

    s = summa(m, n);

    printf("результат %d\n", s);
    return 0;
}

int task1a()
{
    int m, i;
    double res, resk;

    printf("\nЗадание 1А:\n");
    printf("Введите степень m: ");
    scanf("%d", &m);

    res = 1.0;
    for (i = 0; i <= m; i++)
    {
        res = stepen(i);
        printf("2^%2d = %10.0lf\n", i, res);
    }

    resk = res / 1024.0;
    printf("Результат: %.1lfK\n", resk);
    return 0;
}

int task2()
{
    double a, b, h, x, y;

    a = 0.2;
    b = 2.2;

    printf("\nЗадание 2:\n");
    printf("Функция: y = 1.8 * x^2 - sin(10 * x) на интервале [0.2; 2.2]\n");
    printf("Введите шаг табуляции: ");
    scanf("%lf", &h);

    printf("_____________________\n");
    printf("|   x   |    f(x)   |\n");
    printf("---------------------\n");

    for (x = a; x <= b + 0.0001; x += h)
    {
        y = tabf(x);
        printf("| %5.2lf | %9.4lf |\n", x, y);
    }
    printf("---------------------\n");
    return 0;
}

int task3()
{
    double a, res;
    int n;

    printf("\nЗадание 3 (ДЗ):\n");
    printf("Введите число a (a != 0): ");
    scanf("%lf", &a);
    printf("Введите целое число n (n >= 0): ");
    scanf("%d", &n);

    if (a == 0.0 || n < 0)
    {
        printf("Ошибка: некорректные входные данные\n");
    }
    else
    {
        res = ryad(a, n);
        printf("Сумма ряда: %.6lf\n", res);
    }
    return 0;
}

int stroka(int n, char c1, char c2)
{
    int i;

    putchar('+');
    for (i = 1; i <= n; i++)
    {
        if (i <= n / 2)
        {
            putchar(c1);
        }
        else
        {
            putchar(c2);
        }
        putchar('!');
    }
    putchar('+');
    putchar('\n');
    return 0;
}

int summa(int m, int n)
{
    int i, s, k;

    s = 0;
    k = 1;
    for (i = m; i >= n; i--)
    {
        s += i;
        printf("выполнено %d раз\n", k++);
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
