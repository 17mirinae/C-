#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void Sorting(int *[]); // ������ ������������ �����ͺ��� ���� ������� �����ϴ� �Լ�
void Calculate(int *[], char *[]); // ������ ����ϴ� �Լ�
void PrintArray(int *[], char *[]); // ���ǿ� ���缭 [���,����,����]���� ����ϴ� �Լ�

int main(void) {
    int *student[SIZE]; // �л����� ������ �������� �Է¹��� �迭
    char *credit[SIZE]; // �л����� ������ ����� ���� �迭

    srand((unsigned)time(NULL));
    for (int i = 0; i < SIZE; i++) { // �������� ���� ����
        *(student + i) = (rand() % 101); // 0~100���� ������ ���ڰ� �迭�� ���ʴ�� ����
    }
    Sorting(student); // ������������ �迭 ����
    Calculate(student, credit); // �������� ������ ���
    PrintArray(student, credit); // ���ǿ� ���߾� ���, ����, ���� ���
    return 0;
}
void Sorting(int *student[]) { // ������������ �迭�� �������ϴ� �Լ�
    int temp; // ����
    for (int i = 0; i < (SIZE - 1); i++) { // �迭 student[98]����
        for (int j = i + 1; j < SIZE; j++) { // �迭 student[i+1]���� student[99]����
            if (*(student + i) < *(student + j)) { // �ڿ� �ִ� �迭�� student[i]���� Ŭ ������ ���� �����Ѵ�.
                temp = student[j];
                student[j] = student[i];
                student[i] = temp;
            }
        }
    }
}
void Calculate(int *student[], char *credit[]) { // ������ ������ִ� �Լ�
    for (int i = 0; i < 100; i++) {
        if (i >= 0 && i < 10) { // 1�� ~ 10�� �̸�
            *(credit + i) = 'A'; // ���� A
        }
        else if (i >= 10 && i < 25) { // 11�� ~ 25�� �̸�
            *(credit + i) = 'B'; // ���� B
        }
        else if (i >= 25 && i < 50) { // 26�� ~ 50�� �̸�
            *(credit + i) = 'C';
        }
        else if (i >= 50 && i < 80) { // 51�� ~ 80�� �̸�
            *(credit + i) = 'D';
        }
        else { // 81�� ~ 100�� �̸�
            *(credit + i) = 'F';
        }
    }
}
void PrintArray(int *student[], char *credit[]) { // ������ ����ϴ� �Լ�
    for (int i = 0; i < SIZE; i++) { // 100���� �л��� ���
        printf("\t%d��  %d��  %c", i + 1, *(student + i), *(credit + i));
        if ((i + 1) % 5 == 0) // 5��° ��������
            printf("\n"); // ���� �ٲ�
    }
}