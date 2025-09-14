#include <cs50.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int get_score(string a);
void upper(string s);

int main(void)
{
    string p1 = get_string("Player1: ");
    string p2 = get_string("Player2: ");

    upper(p1);
    upper(p2);
    int score1 = get_score(p1);
    int score2 = get_score(p2);

    if( score1 > score2 )
    {
        printf("Player1 is the winner!\n");
    }
    else if( score1 == score2 )
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player2 is the Winner!\n");
    }
}



int get_score(string a)
{

    int score = 0;
    for(int i = 0; i < strlen(a) ; i++)
    {
         if (a[i] >= 'A' && a[i] <= 'Z')
        {
            score += points[a[i] - 'A'];
        }
    }
    return score;
}

void upper(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - ('a' - 'A');
        }
    }
}
