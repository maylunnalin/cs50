#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Get the key
//Ensure single command-line argument
int main(int argc, string argv[])
{
    string k = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Make sure argument contains 26 characters
    if (strlen(k) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Make sure argument contains only alphabets
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    //Make sure argument does not contain repeated characters
    for (int i = 0; i < strlen(k) - 1; i++)
    {
        for (int j = i + 1; j < strlen(k); j++)
        {
            if (k[i] == k[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    string s = get_string("plaintext: "); //Get plaintext

    printf("ciphertext: ");

    //Encipher the plaintext
    for (int i = 0; i < strlen(s); i++)
    {
        if (islower(s[i])) //If lower case, shift plaintext character by key
        {
            printf("%c", tolower(k[s[i] - 97]));
        }
        else if (isupper(s[i])) //If upper case, shift plaintext character by key
        {
            printf("%c", toupper(k[s[i] - 65]));
        }
        else
        {
            printf("%c", s[i]); //If not alphabetic, leave the character as-is
        }
    }
    printf("\n");
    return 0;
}