#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    // Compute the Coleman-Lia index
    float l = (letters / words) * 100;
    float s = (sentences / words) * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text_l)
{
    int n = strlen(text_l);
    int sum_l = 0;

    // Return the number of letters in text
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text_l[i]))
        {
            sum_l++;
        }
    }
    return sum_l;
}

int count_words(string text_w)
{
    int n = strlen(text_w);
    int sum_w = 1;

    // Return the number of words in text
    for (int j = 0; j < n; j++)
    {
        if (isblank(text_w[j]))
        {
            sum_w++;
        }
    }
    return sum_w;
}

int count_sentences(string text_s)
{
    int n = strlen(text_s);
    int sum_s = 0;

    // Return the number of sentences in text
    for (int k = 0; k < n; k++)
    {
        if (text_s[k] == '.' || text_s[k] == '!' || text_s[k] == '?')
        {
            sum_s++;
        }
    }
    return sum_s;
}
