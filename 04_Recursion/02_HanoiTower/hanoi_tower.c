#include <stdio.h>
#include <stdlib.h>

void hanoi_tower(int n, char from, char temp, char to);

int main(int argc, char **argv)
{
    char from = 'A';
    char temp = 'B';
    char to = 'C';

    hanoi_tower(atoi(argv[1]), from, temp, to);
    return 0;
}

void hanoi_tower(int n, char from, char temp, char to)
{
    if (n < 1)
    {
        printf("잘못된 입력\n");
    }
    else if (n == 1)
    {
        printf("원판 1: %c -> %c\n", from, to);
    }
    else{
        hanoi_tower(n - 1, from, to, temp);
        printf("원판 %d: %c -> %c\n", n, from, to);
        hanoi_tower(n - 1, temp, from, to);
    }
}
