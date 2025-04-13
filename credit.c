// This program checks the validity of a credit card number
// Furthermore it determines whether the credit card is a Visa, Mastercard or American Express card
#include <cs50.h>
#include <math.h>
#include <stdio.h>

#define DIV 10

int check_sum(long num);

int main(void)
{
    // Prompt the user to enter the credit card number
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (false);

    // Determines if the number is valid
    int sum = check_sum(num);

    if (sum % 10 == 0)
    {
        // Checks whether the credit card is a Visa, Mastercard or American Express card and prints result
        int card_v = num / pow(DIV, 15);
        int card_v2 = num / pow(DIV, 12);
        int card_m = num / pow(DIV, 14);
        int card_a = num / pow(DIV, 13);

        if (card_v == 4 || card_v2 == 4)
        {
            printf("VISA\n");
        }
        else if (card_m == 51 || card_m == 52 || card_m == 53 || card_m == 54 || card_m == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (card_a == 34 || card_a == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int check_sum(long num)
{
    // The loop below, including the algorithm, is necassary for determining the validity of the number
    int num_n_l = 0;
    int num_n_r = 0;
    int T = 2;
    int num_sum_l = 0;
    int num_sum_r = 0;
    int sum = 0;
    long num_r = num;

    // Part 1: Adds the digits that are multiplied by 2
    num = num / DIV;
    while (num > 0)
    {
        num_n_l = (num % DIV) * 2;
        if ((num_n_l / DIV) > 0)
        {
            num_n_l = (num_n_l % DIV) + (num_n_l / DIV);
        }

        num_sum_l = num_sum_l + num_n_l;
        num = num / pow(DIV, T);
    }

    // Part 2: Adds the digits that are not multiplied by 2
    while (num_r > 0)
    {
        num_n_r = (num_r % DIV);

        num_sum_r = num_sum_r + num_n_r;
        num_r = num_r / pow(DIV, T);
    }

    // Part 3: Returns the sum of Part 1 and Part 2
    sum = num_sum_l + num_sum_r;
    return sum;
}
