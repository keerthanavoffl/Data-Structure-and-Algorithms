#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertFront(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* curr = head;

        while (curr->next != NULL)
            curr = curr->next;

        curr->next = newNode;
    }

    void insertAtK(int k, int x) {
        if (k == 0) {
            insertFront(x);
            return;
        }

        Node* curr = head;

        for (int i = 0; i < k - 1; i++) {
            if (curr == NULL)
                return;

            curr = curr->next;
        }

        if (curr == NULL)
            return;

        Node* newNode = new Node(x);

        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteFront() {
        if (head == NULL)
            return;

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    void deleteTail() {
        if (head == NULL)
            return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* curr = head;

        while (curr->next->next != NULL)
            curr = curr->next;

        delete curr->next;
        curr->next = NULL;
    }

    void deleteAtK(int k) {
        if (head == NULL)
            return;

        if (k == 0) {
            deleteFront();
            return;
        }

        Node* curr = head;

        for (int i = 0; i < k - 1; i++) {
            if (curr == NULL)
                return;

            curr = curr->next;
        }

        if (curr == NULL || curr->next == NULL)
            return;

        Node* temp = curr->next;

        curr->next = temp->next;

        delete temp;
    }

    void deleteByValue(int val) {
        if (head == NULL)
            return;

        if (head->data == val) {
            deleteFront();
            return;
        }

        Node* curr = head;

        while (curr->next != NULL &&
               curr->next->data != val) {
            curr = curr->next;
        }

        if (curr->next == NULL)
            return;

        Node* temp = curr->next;

        curr->next = temp->next;

        delete temp;
    }

    void display() {
        Node* curr = head;

        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedList ll;

    ll.insertFront(20);
    ll.insertFront(10);

    ll.insertTail(30);
    ll.insertTail(40);

    ll.display();

    ll.insertAtK(2, 25);
    ll.display();

    ll.deleteFront();
    ll.display();

    ll.deleteTail();
    ll.display();

    ll.deleteAtK(1);
    ll.display();

    ll.deleteByValue(30);
    ll.display();

    return 0;
}