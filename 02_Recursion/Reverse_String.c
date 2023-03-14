#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_string(char *str)
{
    int length = strlen(str);
    char *reversed = (char *)malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';

    return reversed;
}

int main()
{
    char *str = "hello, world!";

    char *reversed_str = reverse_string(str);

    printf("%s\n\n", str);
    printf("%s\n\n", reversed_str);

    free(reversed_str);
    return 0;
}