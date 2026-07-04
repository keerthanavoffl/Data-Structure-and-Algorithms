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

class Stack {
    Node* topnode;

public:
    Stack() {
        topnode = nullptr;
    }

    void push(int x) {
        Node* nn = new Node(x);
        nn->next = topnode;
        topnode = nn;
        cout << x << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topnode;
        topnode = topnode->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topnode->data;
    }

    bool isEmpty() {
        return topnode == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = topnode;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "topnode element: " << s.peek() << endl;

    s.pop();
    s.display();

    return 0;
}