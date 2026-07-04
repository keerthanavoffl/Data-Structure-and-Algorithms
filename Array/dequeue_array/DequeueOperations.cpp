#include <bits/stdc++.h>
using namespace std;

class Deque {
    int *arr;
    int front, rear, size;

public:
    Deque(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }

        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};
int main(){
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    dq.deleteFront();
    cout << "After deleteFront()" << endl;
    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    dq.deleteRear();
    cout << "After deleteRear()" << endl;
    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    return 0;
}
