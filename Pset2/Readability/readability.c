#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string passage);
int count_words(string passage);
int count_sentences(string passage);

int main(void)
{
    //Ask for text
    string passage = get_string("Text: ");

    //Calculates Coleman-Liau Index of passage
    float l = (float) count_letters(passage) / (float) count_words(passage) * 100;
    float s = (float) count_sentences(passage) / (float) count_words(passage) * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    // Print reading grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Function for counting letters
int count_letters(string passage)
{
    int letters = 0;
    for (int i = 0, n = strlen(passage); i < n; i++)
    {
        if (isalpha(passage[i]))
        {
            letters++;
        }
    }
    return letters;
}
//Function for counting words
int count_words(string passage)
{
    int words = 0;
    for (int i = 0, n = strlen(passage); i < n; i++)
    {
        if (isblank(passage[i]))
        {
            words++;
        }
    }
    return words + 1;
}
//Function for counting sentences
int count_sentences(string passage)
{
    int sentences = 0;
    for (int i = 0, n = strlen(passage); i < n; i++)
    {
        if (passage[i] == 46 || passage[i] == 33 || passage[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}