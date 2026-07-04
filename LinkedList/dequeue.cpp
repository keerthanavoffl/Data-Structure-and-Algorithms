#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int x) {
        Node* nn = new Node(x);

        if (isEmpty()) {
            front = rear = nn;
            return;
        }

        nn->next = front;
        front->prev = nn;
        front = nn;
    }

    void insertRear(int x) {
        Node* nn = new Node(x);

        if (isEmpty()) {
            front = rear = nn;
            return;
        }

        rear->next = nn;
        nn->prev = rear;
        rear = nn;
    }

    void deleteFront() {
        if (isEmpty()) return;

        Node* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) return;

        Node* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->data;
    }

    int getRear() {
        if (isEmpty()) return -1;
        return rear->data;
    }

    void display() {
        Node* curr = front;

        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertFront(20);
    dq.insertFront(10);
    dq.insertRear(30);
    dq.insertRear(40);

    dq.display();

    dq.deleteFront();
    dq.display();

    dq.deleteRear();
    dq.display();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear : " << dq.getRear() << endl;
}