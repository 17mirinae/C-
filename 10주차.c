#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int StringPointer1(char* str);
void Eliminate(char* str, char ch);
int main() {
    char* str1 = malloc(sizeof(char) * 20);

    char aaa;

    printf("���ڿ��� �Է��Ͻÿ�>>>>");
    gets(str1);
    printf("Ž���� ����>>>");
    scanf("%c", &aaa);

    printf("�Էµ� ���ڿ�: %s\n", str1);
    printf("���ڿ� ���� ����: %d\n", StringPointer1(str1));
    printf("Ž���� ����: %c\n", aaa);
    Eliminate(str1, aaa);
    printf("Ž������ ���� ����: %s\n", str1);
    printf("Ž������ ���� ���� ����: %d\n", StringPointer1(str1));





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