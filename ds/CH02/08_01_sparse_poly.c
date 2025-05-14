#include <stdio.h>
#include <math.h>

#define MAX_TERMS 80

typedef struct {
    int expo; // 지수
    float coef; // 계수
} Term;

typedef struct {
    int nTerms; // 항의 개수
    Term term[MAX_TERMS]; // 항의 배열
} SparsePoly;

float evaluate(SparsePoly a, float x);
SparsePoly add(SparsePoly a, SparsePoly b);
void print_spoly(SparsePoly p, char* str);


int main(void){
    SparsePoly a = { 2, {{100, 10.0f}, {0, 6.0f}} };
    SparsePoly b = { 2, {{50, 1.1f}, {3, 2.0f}} };
    SparsePoly c = add(a, b);
    print_spoly(a, " A = ");
    print_spoly(b, " B = ");
    print_spoly(c, "A+B= ");
    printf("A(1)= %f\n", evaluate(a, 1.0f));
    printf("B(2)= %f\n", evaluate(b, 2.0f));
    
    return 0;
}

float evaluate(SparsePoly a, float x) { // 미지수 x를 대입해 계산한 결과를 반환
    float result = 0;
    for (int i = 0; i < a.nTerms; i++)
        result += (float)(a.term[i].coef * pow(x, a.term[i].expo)); // a.term[i].coef * ( x ^ a.term[i].expo
    return result;
}

SparsePoly add(SparsePoly a, SparsePoly b) { // 다항식 a와 b의 합을 구해 반환
    SparsePoly c;
    c.nTerms = 0;
    for (int i = 0, j = 0; i < a.nTerms || j < b.nTerms;) {
        if (i == a.nTerms || a.term[i].expo < b.term[j].expo)   // i 가 a.nterms와 같거나 a.term[i].expo가 b.terms[i].expo 보다 작으면
            c.term[c.nTerms++] = b.term[j++];                   // c.nterms는 1증가, c.term[c.nterms] 의 값은 j 를 1증가시킨 b.term[j] 하고 continue
        else if (j == b.nTerms || a.term[i].expo > b.term[j].expo)
            c.term[c.nTerms++] = a.term[i++];
        else {
            c.term[c.nTerms] = a.term[i++];
            c.term[c.nTerms++].coef += b.term[j++].coef;
        }
    }
    return c;
}

void print_spoly(SparsePoly p, char* str) { // 희소 다항식을 화면에 보기 좋게 출력
    printf("%s", str);
    for (int i = 0; i < p.nTerms; i++) {
        printf("%5.1f", p.term[i].coef);
        if (p.term[i].expo > 0) {
            printf(" x^%d ", p.term[i].expo);
            if (i != p.nTerms - 1) printf("+ ");
        }
    }
    printf("\n");
}
