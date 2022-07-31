#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void get_command(string& com);
void get_size(int& size);
int** gen_matrix(int size);
void swap(int* a, int* b);
void sort_array(int* ary, int size);
void sort_matrix_row(int** matrix, int size);
void print_matrix(int** matrix, int size);
void save_matrix(int** matrix, int size);
void free_matrix(int** matrix, int size);

int main() {
    string command;
    int** matrix = NULL;
    int size = 0;

    while (1) {
        get_command(command);
        if (command == "1") {
            get_size(size);
            matrix = gen_matrix(size);
        }
        else if (command == "2") {
            print_matrix(matrix, size);
        }
        else if (command == "3") {
            sort_matrix_row(matrix, size);
        }
        else if (command == "4") {
            save_matrix(matrix, size);
        }
        else if (command == "0") {
            free_matrix(matrix, size);
            cout << "Exit the program.." << endl;
            exit(104);
        }
        else {
            cout << "Wrong command" << endl << endl;
        }
    }

    return 0;
}

void get_command(string& com) {
    cout << "1. Generate matrix\n2. Print matrix\n3. Sort matrix" << '\n';
    cout << "4. Save matrix\n0.Exit program" << endl;

    cout << ">>";
    cin >> com;

}
void get_size(int& size) {
    cout << "Enter the size in (size x size) : ";
    cin >> size;
}
int** gen_matrix(int size) {
    int** matrix = new int* [size];

    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++)
            matrix[r][c] = rand() % 101;
    }

    return matrix;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort_array(int* ary, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < i; j++) {
            if (ary[j] > ary[j + 1])
                swap(ary[j], ary[j + 1]);
        }
    }
}
void sort_matrix_row(int** matrix, int size) {
    int *ary = new int [size];
    for (int i = 0; i < size; i++) {
        sort_array(matrix[i], size);
    }

    cout << "Completed" << endl;
}
void print_matrix(int** matrix, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++)
            cout << setw(4) << matrix[row][col];
        cout << endl;
    }
}
void save_matrix(int** matrix, int size) {
    ofstream fout("matrix.txt");
    fout << size << endl;
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++)
            fout << matrix[r][c] << '\t';
        fout << endl;
    }

    cout << "Saved" << endl;
    fout.close();
}
void free_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}