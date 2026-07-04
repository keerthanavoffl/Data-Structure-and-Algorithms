#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int x) {
        Node* nn = new Node(x);

        if (rear == nullptr) {
            front = rear = nn;
            return;
        }

        rear->next = nn;
        rear = nn;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}