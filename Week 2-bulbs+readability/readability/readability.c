#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
double calculate_grade(int letters, int words, int sentences);
int main(void)
{
//prompt user for string of text
    string text = get_string("Text: ");
    int letters = count_letters(text);  //detect how many letters
    int words = count_words(text);      //detect how many words
    int sentences = count_sentences(text);  //detect how many sentences
    double index = calculate_grade(letters, words, sentences); //Apply Coleman-Liau index, rounding to the closest.

    //Print grade. if higher or equal 16, "Grade 16+", if lower 1 "Before Grade 1"
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
        printf("Grade %i\n", (int) round(index));
    }

}

int count_letters(string text)
{
    int letters = 0;
    for (int x = 0; text[x] != ispunct(text[x]); x++)  //counter to the end of text
    {
        if (isalpha(text[x]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int x = 0; text[x] != ispunct(text[x]); x++)  //counter to the end of text
    {
        if (isblank(text[x]))
        {
            words++;
        }
    }
    words++;    //for the last word after the punctuation that wasn't counting
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int x = 0; text[x] != ispunct(text[x]); x++)  //counter to the end of text
    {
        if (((text[x]) == '.') || ((text[x]) == '!') || ((text[x]) == '?'))
        {
            sentences++;
        }
    }
    return sentences;
}

double calculate_grade(int letters, int words, int sentences)
{
    double L = (double) letters / words * 100;
    double S = (double) sentences / words * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}