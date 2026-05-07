#include <stdio.h>


void backward(char in[], char out[]) {
   
    int len = 0;
    while (in[len] != '\0') {
        len++;
    }

    
    for (int i = 0; i < len; i++) {
        out[i] = in[len - 1 - i];
    }
    out[len] = '\0'; 
}

int main() {
    char in[100]; 
    char out[100]; 

    
    printf("문자열을 입력하세요: ");
    scanf("%99s", in); // 최대 99자 입력받고 마지막에 null 문자 추가

    
    backward(in, out);

    
    printf("입력 문자열: %s\n", in);
    printf("역순으로 변환된 문자열: %s\n", out);

    return 0;
}