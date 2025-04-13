#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Scrabble points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score_calc(string word);

int main(void)
{
    // Prompt the user for two words
    string word_1 = get_string("Player 1: ");
    string word_2 = get_string("Player 2: ");

    // Determine the score of each word
    int score_1 = score_calc(word_1);
    int score_2 = score_calc(word_2);

    // Print winner result
    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }

    else if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie!\n");
    }
}

int score_calc(string word)
{
    int sum = 0;
    int n = strlen(word);

    // Calculate the points of each character and determine the score
    for (int i = 0; i < n; i++)
    {
        // Check for the correct domain
        if (word[i] >= 65 && word[i] <= 122)
        {
            // Change lower case to upper case
            word[i] = toupper(word[i]);
            // Subtract 65 ('A') to map from ASCII value to scrabble points. Add points together
            sum = sum + POINTS[word[i] - 65];
        }
    }

    return sum;
}
