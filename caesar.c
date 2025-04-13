#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string digit_check);
char rotate(char p_text, int k);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    bool digit_checked = only_digits(argv[1]);

    if (digit_checked != true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // For each character in the plaintext:
    int m = strlen(plaintext);
    printf("ciphertext: ");
    for (int j = 0; j < m; j++)
    {
        // Rotate the character if it's a letter
        char ciphertext = rotate(plaintext[j], key);
        printf("%c", ciphertext);
    }
    printf("\n");
}

bool only_digits(string digit_check)
{
    int n = strlen(digit_check);
    bool d_check;

    for (int i = 0; i < n; i++)
    {
        // Check if argv[1] is a digit
        if (isdigit(digit_check[i]))
        {
            d_check = true;
        }
        else
        {
            d_check = false;
        }
    }
    return d_check;
}

char rotate(char p_text, int k)
{
    // c_text is an imaginary alphabetical index charater (Range: 0 - 25)
    char c_text;

    if (isalpha(p_text))
    {
        if (isupper(p_text))
        {
            // Convert ASCII to alphabetical index & shift character
            c_text = (p_text - 'A' + k) % 26;
            // Convert result back to ASCII
            c_text = c_text + 'A';
        }
        else
        {
            // Convert ASCII to alphabetical index & shift character
            c_text = (p_text - 'a' + k) % 26;
            // Convert result back to ASCII
            c_text = c_text + 'a';
        }
    }
    else
    {
        // Non-alphabetical characters remain the same
        c_text = p_text;
    }
    return c_text;
}
