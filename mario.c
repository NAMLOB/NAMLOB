// Creates a pyriamid using hashes (#) as bricks
#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    // Prompts the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Prints a pyramid of that height
    for (int i = n; i > 0; i--)
    {
        // Print row of bricks
        print_row(i - 1, n);
    }
}

void print_row(int spaces, int bricks)
{
    // Prints the spaces
    for (int k = spaces; k > 0; k--)
    {
        printf(" ");
    }

    // Prints the right-aligned pyriamid bricks
    for (int l = bricks; spaces < l; l--)
    {
        printf("#");
    }

    printf("  ");

    // Prints the left-aligned pyriamid bricks
    for (int m = spaces; m < bricks; m++)
    {
        printf("#");
    }
    printf("\n");
}
