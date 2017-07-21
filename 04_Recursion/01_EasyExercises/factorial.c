#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(int arc, char **argv)
{
    int n = atoi(argv[1]);
    printf("factorial %d: %d\n", n, factorial(n));
    return 0;
}

int factorial(int n)
{
    int result = 0;

    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
