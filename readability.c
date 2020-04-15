#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //Prompt for input
    string text = get_string("Text: ");
    
    //Count letters, words, sentences
    float letters = 0, words = 1, sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i])) //Count letters
        {
            letters++;
        }
        if (isspace(text[i])) //Count words
        {
            words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') //Count sentences
        {
            sentences++;
        }
    }
    
    //Coleman-Liau index
    float L = letters * 100 / words; //L = Average number of letters per 100 words in the text.
    float S = sentences * 100 / words; //S = Average number of sentences per 100 words in the text.
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    //Round the grades
    int index_rounded = round(index);
    
    //Sort the grades
    if (index_rounded < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index_rounded >= 1 && index_rounded <= 16)
    {
        printf("Grade %i\n", index_rounded);
    }
    if (index_rounded > 16)
    {
        printf("Grade 16+\n");
    }
}
