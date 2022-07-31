#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int StringPointer1(char* str);
void Eliminate(char* str, char ch);
int main() {
    char* str1 = malloc(sizeof(char) * 20);

    char aaa;

    printf("문자열을 입력하시오>>>>");
    gets(str1);
    printf("탐색할 문자>>>");
    scanf("%c", &aaa);

    printf("입력된 문자열: %s\n", str1);
    printf("문자열 문자 개수: %d\n", StringPointer1(str1));
    printf("탐색된 문자: %c\n", aaa);
    Eliminate(str1, aaa);
    printf("탐색문자 제외 문자: %s\n", str1);
    printf("탐색문자 제외 문자 개수: %d\n", StringPointer1(str1));





    free(str1);

    return 0;

}
int StringPointer1(char* str) {
    int len = 0;
    while (*str++) {
        len++;
    }
    return len + 1;
}

void Eliminate(char* str, char ch) {
    for (; *str != '\0'; str++) {
        if (*str == ch) {
            strcpy(str, str + 1);
            str--;
        }
    }
}