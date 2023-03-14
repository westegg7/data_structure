#include <stdio.h>

int try = 0;
void hanoi(int n, char from, char tmp, char to) {
    if (n == 1) {
        printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
        try++;
    } else {
        hanoi(n - 1, from, to, tmp);
        printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from, to);
        try++;
        hanoi(n - 1, tmp, from, to);
    }
}

int main() {
    hanoi(4, 'A', 'B', 'C');

    printf("\n%d회의 이동\n\n", try);

    return 0;
}