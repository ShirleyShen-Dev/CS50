#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // Check for number of command line inputs from user
    if (argc == 2)
    {
        int digit_test = 0;
        
        // Ensure input key is digit
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
                digit_test = 0;
            }
            else
            {
                digit_test = 1;
            }
        }

        // Cipher
        if (digit_test == 0)
        {
            // Convert input string into integer and preserve letter case
            string cipher_string = argv[1];
            int cipher_int = atoi(cipher_string);

            // Prompt for plaintext
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");

            // Convert string with cipher_int
            for (int i = 0; i < strlen(plaintext); i++)
            {
                // Uppercase text scenario
                if (plaintext[i] >= 65 && plaintext[i] < 65 + 26)
                {
                    printf("%c", ((plaintext[i] % 65) + cipher_int) % 26 + 65);
                }
                // Lowercase text scenario
                else if (plaintext[i] >= 97 && plaintext[i] < 97 + 26)
                {
                    printf("%c", ((plaintext[i] % 97) + cipher_int) % 26 + 97);
                    
                }
                // All other text scenario
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
