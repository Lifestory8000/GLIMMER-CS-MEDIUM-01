#include <stdio.h>

int main() {
    int a, b;
    printf("Enter a num: ");
    scanf("%d", &a);
    printf("Enter a \'n\': ");
    scanf("%d", &b);
    int c=2*(b-1);
    int d= a & c;
    int e= d/(2*(b-1));
    printf("answer: %d", e);
}