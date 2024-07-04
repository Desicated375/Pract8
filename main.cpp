#include <stdio.h>
#include <string.h>
#include <ctype.h>

int fac(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fac(n - 1);
}

int count(char *word)
{
    int len = strlen(word);
    int freq[26] = {0};
    int i;
    for (i = 0; i < len; i++)
    {
        char c = toupper(word[i]);
        freq[c - 'A']++;
    }

    int unique = 1;
    for (i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            unique *= fac(freq[i]);
        }
    }

    int total = fac(len) / unique;
    return total;
}

int main()
{
    char word[15];
    printf("Enter the word: ");
    scanf("%s", word);

    int result = count(word);
    printf("%d\n", result);

    return 0;
}
