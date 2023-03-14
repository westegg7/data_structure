#include <stdio.h>

void reverse_string() 
{
    int ch;
    if ((ch = getchar()) != '\n') 
        reverse_string();
    putchar(ch);
}


int main()
{
    reverse_string();
    printf("\n\n");

    return 0;
}