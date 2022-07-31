#include <iostream>

using namespace std;

template<class T>
class Queue {
private:
    T* p_list;
    int size;
    int MAX_SIZE;

public:
    Queue() {
        MAX_SIZE = 1000;
        p_list = new T[1000];
        size = 0;
    }

    ~Queue() {
        delete[] p_list;
    }

    int find_index(T _item) {
        for (int i = 0; i < size; i++) {
            if (_item == p_list[i]) {
                return i;
            }
        }
        return -1;
    }


    void Enqueue(T _item) {
        if (size < MAX_SIZE) {
            if (find_index(_item) == -1) {
                p_list[size] = _item;
                size++;
            }
        }
        else {
            cout << "Error, out of memory" << endl;
        }
    }

    T Dequeue() {
        T a = p_list[0];
        if (size == 0) {
            cout << "Error No item exist in the list" << endl;
            return NULL;

        }
        else {
            for (int i = 0; i < size; i++) {
                p_list[i] = p_list[i + 1];
            }
            size--;
            return a;
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << p_list[i] << '\t';
        }
        cout << endl;
    }

    int get_size() {
        return size;
    }

    T get_item(int _index) {
        return p_list[_index];
    }

};

int main_(void) {

    Queue<int> int_queue;
    Queue<float> float_queue;
    Queue<char> char_queue;

    int_queue.Enqueue(1);
    int_queue.Enqueue(2);
    int_queue.Enqueue(2);
    int_queue.Enqueue(5);

    float_queue.Enqueue(4.3);
    float_queue.Enqueue(2.5);
    float_queue.Enqueue(3.7);
    float_queue.Enqueue(3.7);

    char_queue.Enqueue('b');
    char_queue.Enqueue('b');
    char_queue.Enqueue('c');
    char_queue.Enqueue('a');


    cout << "<Before Dequeue>" << endl;
    int_queue.print();
    float_queue.print();
    char_queue.print();
    int_queue.Dequeue();
    float_queue.Dequeue();
    float_queue.Dequeue();
    char_queue.Dequeue();
    char_queue.Dequeue();
    char_queue.Dequeue();
    char_queue.Dequeue();

    cout << "<After Dequeue>" << endl;
    int_queue.print();
    float_queue.print();
    char_queue.print();

    return 0;
}

