#include <stdio.h>
#include <stdlib.h>


int main() {
    int num = 1012;

    if (num % 2) {
        printf("%d 는 홀수 입니다.\n", num);
    } else {
        printf("%d 는 짝수 입니다.\n", num);
    }


    return 0;
}