#include <stdio.h>
#include <stdlib.h>

int fib(int n);
int fib_iter(int n);

int main(int arc, char **argv)
{
    int n = atoi(argv[1]);
    printf("fibonacci %dth num: %d\n", n, fib_iter(n));
    return 0;
}

int fib(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n < 2)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fib_iter(int n)
{
    int result = 0;
    int pre1 = 1;
    int pre2 = 0;
    int i = 0;

    if (n < 0)
    {
        return -1;
    }
    else if (n < 2)
    {
        return n;
    }

    for (i = 0; i < n - 1; i++)
    {
        result = pre1 + pre2;
        pre2 = pre1;
        pre1 = result;
    }
    return result;
}
