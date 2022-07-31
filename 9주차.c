#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void Sorting(int *[]); // 성적을 내림차순으로 높은것부터 낮은 순서대로 정렬하는 함수
void Calculate(int *[], char *[]); // 학점을 계산하는 함수
void PrintArray(int *[], char *[]); // 조건에 맞춰서 [등수,학점,성적]으로 출력하는 함수

int main(void) {
    int *student[SIZE]; // 학생들의 성적을 랜덤으로 입력받을 배열
    char *credit[SIZE]; // 학생들의 학점을 계산을 받을 배열

    srand((unsigned)time(NULL));
    for (int i = 0; i < SIZE; i++) { // 랜덤으로 점수 대입
        *(student + i) = (rand() % 101); // 0~100점의 랜덤한 숫자가 배열에 차례대로 대입
    }
    Sorting(student); // 내림차순으로 배열 변경
    Calculate(student, credit); // 성적으로 학점을 계산
    PrintArray(student, credit); // 조건에 맞추어 등수, 학점, 성적 출력
    return 0;
}
void Sorting(int *student[]) { // 내림차순으로 배열을 재정렬하는 함수
    int temp; // 공백
    for (int i = 0; i < (SIZE - 1); i++) { // 배열 student[98]까지
        for (int j = i + 1; j < SIZE; j++) { // 배열 student[i+1]부터 student[99]까지
            if (*(student + i) < *(student + j)) { // 뒤에 있는 배열이 student[i]보다 클 때마다 값을 변경한다.
                temp = student[j];
                student[j] = student[i];
                student[i] = temp;
            }
        }
    }
}
void Calculate(int *student[], char *credit[]) { // 학점을 계산해주는 함수
    for (int i = 0; i < 100; i++) {
        if (i >= 0 && i < 10) { // 1등 ~ 10등 이면
            *(credit + i) = 'A'; // 학점 A
        }
        else if (i >= 10 && i < 25) { // 11등 ~ 25등 이면
            *(credit + i) = 'B'; // 학점 B
        }
        else if (i >= 25 && i < 50) { // 26등 ~ 50등 이면
            *(credit + i) = 'C';
        }
        else if (i >= 50 && i < 80) { // 51등 ~ 80등 이면
            *(credit + i) = 'D';
        }
        else { // 81등 ~ 100등 이면
            *(credit + i) = 'F';
        }
    }
}
void PrintArray(int *student[], char *credit[]) { // 성적을 출력하는 함수
    for (int i = 0; i < SIZE; i++) { // 100명의 학생을 출력
        printf("\t%d등  %d점  %c", i + 1, *(student + i), *(credit + i));
        if ((i + 1) % 5 == 0) // 5번째 순서마다
            printf("\n"); // 줄을 바꿈
    }
}