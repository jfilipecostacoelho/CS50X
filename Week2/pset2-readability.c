#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int countletters(string text);
int countsentences(string text);
int countwords(string text);
int calculategrade(int letters, int sentences, int words);

int main(void)
{
    // Prompt for text
    string text = get_string("Text: \n");

    // Count letters
    int letters = countletters(text);
    // Count sentences
    int sentences = countsentences(text);
    // Count words
    int words = countwords(text);
    // Calculate grade
    int grade = calculategrade(letters, sentences, words);
    
    if (grade <= 16 && grade > 1)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

   
}


// Function to count number of letters in the text
int countletters(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (toupper(text[i]) > 64 && toupper(text[i]) < 91)
        {
            count++;
        }
    }

    return count;
}


// Function to count number of sentences in the text
int countsentences(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count++;
        }
    }

    return count;
}

// Function to count number of words in the text
int countwords(string text)
{
    int count = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            count++;
        }
    }

    return count;
}

// Function to calculate the grade
int calculategrade(int letters, int sentences, int words)
{
    int grade = round(0.0588 * ((float)letters / (float)words * 100) - 0.296 * ((float)sentences / (float)words * 100) - 15.8);
    
    return grade;
}
