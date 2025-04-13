#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LEN 26

char make_key(string key, char p_text);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Make sure the command-line argument key has 26 characters
    if (strlen(argv[1]) != LEN)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Make sure the command-line argument has only alphabetic characters
    for (int i = 0; i < LEN; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabeitc characters.\n");
            return 1;
        }

        // Make sure the command-line argument key has no repeated characters
        for (int j = i + 1; j < LEN; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Get plaintext
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);

    // Print ciphertext:
    printf("ciphertext: ");
    for (int l = 0; l < length; l++)
    {
        char ciphertext = make_key(argv[1], plaintext[l]);
        printf("%c", ciphertext);
    }
    printf("\n");
}

char make_key(string key, char p_text)
{
    char c_text;

    for (int k = 0; k < LEN; k++)
    {
        // Check plaintext alphabetic character
        if (isalpha(p_text))
        {
            // Maintain upper case
            if (isupper(p_text))
            {
                if (p_text == 65 + k)
                {
                    c_text = toupper(key[k]);
                }
            }
            // Maintain lower case
            else
            {
                if (p_text == 97 + k)
                {
                    c_text = tolower(key[k]);
                }
            }
        }
        else
        {
            // Non-alphabetical characters remain the same
            c_text = p_text;
        }
    }
    return c_text;
}
