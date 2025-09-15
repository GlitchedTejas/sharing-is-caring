#include <cs50.h>
#include <stdio.h>
#include <string.h>

char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int lcount(int n, string s);
int scount(int n , string s);
int wcount(int n , string s);

int main(void)
{
    string s1 = get_string("Enter your sentence: ");
    int n = strlen(s1);
    int counts = scount(n , s1);
    int countw = wcount(n , s1);
    int countl = lcount(n , s1);

    float L = (countl * 100)/countw;
    float S = (counts * 100)/countw;

    float index = 0.0588 * L - 0.296 * S - 15.8;
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
        printf("Grade %.0f\n", index);
    }
}


int lcount(int n, string s)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 52; j++)
        {
            if(s[i] == alpha[j])
            {
                count++;
            }
        }
    }
    return count;
}

int scount(int n , string s)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            count++;
        }
    }
    return count;
}

int wcount(int n , string s)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == ' ')
        {
            count++;
        }
    }
    return count;
}
