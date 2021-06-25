#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool validatekeyletters(string cipher);

int main(int argc, string argv[])
{

    // Are there two arguments?
    if (argc == 2 && validatekeyletters(argv[1]))
    {
      
        string key = argv[1];
        // Prompts user for the text to cipher
        string text = get_string("plaintext: ");

        char ciphertext[strlen(text)];

        // Starts ciphering
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Is it a space?
            if (text[i] != 32)
            {
                // For lower chars
                if (islower(text[i]))
                {
                    ciphertext[i] = tolower(key[text[i] - 97]);

                }
                // For upper chars
                else if (isupper(text[i]))
                {
                    ciphertext[i] = toupper(key[text[i] - 65]);
                }
                else
                {
                    // It isn't a letter
                    ciphertext[i] = text[i];
                }
            }
            else
            {
                // For other characters
                ciphertext[i] = text[i];
            }
        }

        // Add end sentence
        ciphertext[strlen(text)] = '\0';

        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        printf("Invalid argument(s)\n");
        return 1;
    }

}

// Check if there are only different letters in the key
bool validatekeyletters(string cipher)
{
    for (int i = 0, n = strlen(cipher); i < n; i++)
    {
        if ((cipher[i] < 65) || (cipher[i] > 90 && cipher[i] < 97) || (cipher[i] > 122))
        {
            return false;
        }
        
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (cipher[j] == cipher[i])
                {
                    return false;
                }
            }
        }
    }
    
    if (strlen(cipher) != 26)
    {
        return false;
    }
    else
    {
        return true;
    }      
}
