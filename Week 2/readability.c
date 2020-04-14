#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;
    int period = 46;
    string text = get_string("Text?\n");

    // STEP 1
    //Loop over the user input (text)
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        // STEP 2
        //Checks for the number of letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // STEP 3
        // Checks for the number of words
        if (isspace(text[i]))
        {
            words++;
        }

        // STEP 4
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // STEP 5
    // Calculate the average number of letters and sentences per 100 words in the text.
    float averageLettersPerHundred = ((float)letters / (float)words) * 100;
    float averageSentencesPerHundred = ((float)sentences / (float)words) * 100;
    float index = (0.0588 * averageLettersPerHundred) - (0.296 * averageSentencesPerHundred) - 15.8;
    int grade = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
