#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //x = get user input
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x >= 9);

    //assign number of rows acording to user imput
    for (int r = 0; r >= 0 && r < x; r++)
    {
        int c = x;
        while (c > r + 1)
        {
            printf(" ");
            c--;
        }
        for (c = r; c >= 0; c--)
        {
            printf("#");
        }
        printf("\n");
    }
}