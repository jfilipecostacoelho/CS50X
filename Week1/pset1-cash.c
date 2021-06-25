#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if there are two arguments and if it is a numbar
    if (argc == 2 && isdigit(*argv[1]))
    {
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: ");

        char cyphertext[strlen(plaintext)];

        // Starts ciphering
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            
            // Is it a space?
            if (plaintext[i] != 32)
            {
                // to lower chars
                if (islower(plaintext[i]))
                {
                    cyphertext[i] = ((plaintext[i] + key - 97) % 26) + 97 ;
                  
                }
                // to upper chars
                else if (isupper(plaintext[i]))
                {
                    cyphertext[i] = ((plaintext[i] + key - 65) % 26) + 65 ;
                }
                else
                {
                    // if it isn't a letter
                    cyphertext[i] = plaintext[i];
                }
            }
            else
            {
                // if it isn't a letter
                cyphertext[i] = plaintext[i];
            }
        }

        printf("plaintext: %s\n", plaintext);
        printf("ciphertext: %s\n", cyphertext);
        return 0;
    }
    else
    {
        // If the input is not a number
        printf("Something went wrong!\n");
        return 1;
    }
}
