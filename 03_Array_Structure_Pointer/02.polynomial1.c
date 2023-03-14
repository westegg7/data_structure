#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

typedef struct
{
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;                     // 결과 다항식
    int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
    int degree_a = A.degree;
    int degree_b = B.degree;

    C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

    while (Apos <= A.degree && Bpos <= B.degree)
    {
        if (degree_a > degree_b)
        {
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b)
        {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--;
            degree_b--;
        }
        else
        {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

void print_poly(polynomial p)
{
    for (int i = 0; i < p.degree; i++)
    {
        if (p.coef[i] != 0)
        {
            printf("%3.1f^%d + ", p.coef[i], p.degree - i);
        }
    }
    if (p.coef[p.degree] != 0)
        printf("%3.1f \n", p.coef[p.degree]);
}

int main()
{
    polynomial a = {5, {3, 6, 0, 0, 0, 10}};
    polynomial b = {4, {7, 0, 5, 0, 1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c = poly_add1(a, b);
    print_poly(c);

    return 0;
}