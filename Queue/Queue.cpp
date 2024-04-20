#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    void enqueue(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            cout << "Enqueued: " << value << endl;
        } else {
            cout << "Antrian sudah penuh. Tidak dapat mengantre: " << value << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            int value = arr[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
            cout << "Dequeued: " << value << endl;
        } else {
            cout << "Antrian kosong. Tidak dapat menghapus antrean." << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            int i = front;
            cout << "Queue elements: ";
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << arr[rear] << endl;
        }
    }
};

int main() {
    Queue myQueue(5);

    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60);

    myQueue.display();

    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.display();

    myQueue.enqueue(70);
    myQueue.enqueue(80);

    myQueue.display();

    return 0;
}
