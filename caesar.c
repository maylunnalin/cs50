#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Get the key
//Ensure single command-line argument
//Make sure argument contains only digit characters
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int k = atoi(argv[1]); //Convert a string into an integer
    
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string s = get_string("plaintext: "); //Get plaintext
    
    printf("ciphertext: ");
    
    //Encipher the plaintext
    //Print ciphertext, Formula = c(i) = (p(i) + k) % 26
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i])) //If lower case, shift plaintext character by key
        {
            printf("%c", ((s[i] - 97 + k) % 26) + 97);
        }
        else if (isupper(s[i])) //If upper case, shift plaintext character by key
        {
            printf("%c", ((s[i] - 65 + k) % 26) + 65);
        }
        else
        {
            printf("%c", s[i]); //If not alphabetic, leave the character as-is
        }
    }
printf("\n");
return 0;
}