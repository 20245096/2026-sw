#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void cirShift(int *a, int *b, int *c, int *d) {
    swap(a, b);
    swap(a, c);
    swap(a, d);  
}

int main() {
    int a = 3, b = 5, c = 7, d = 9;
    
    printf("이동 전의 변수값: a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    
    cirShift(&a, &b, &c, &d);
    
    printf("이동 후의 변수값: a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    
    return 0;
}