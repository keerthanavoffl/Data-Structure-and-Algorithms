#include<iostream>
using namespace std;
class Queue{
    private:
        static const int Size = 500;
        int arr[Size];

        int rear;
        int front;
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        void enqueue(int val){
            if(rear == Size - 1){
                cout << "Queue overflow\n";
                return;
            }

            if(front == -1){
                front = rear = 0;
            }
            else{
                rear++;
            }

            arr[rear] = val;
        }

        int deque(){
            if(front == -1){
                cout<<"Queue underflow"<<"\n";
                return -1;
            }

            int r = arr[front];

            if(front == rear){
                front = rear = -1;
            }
            else{
                front++;
            }
            return r;
        }

        bool isempty(){
            if(front == -1){
                return 1;
            }
            else{
                return 0;
            }
        }

        int peek(){
            if(front == -1){
                cout<<"queue underflow"<<"\n";
                return -1;
            }
            return arr[front];
        }
        int size(){
            if(front == -1){
                return 0;
            }
            return rear - front + 1;
        }
        void print_it_dude(){
            if(front == -1){
                cout<<"Queue is empty"<<"\n";
                return;
            }
            cout<<"The queue elements: ";
            for(int i = front; i <= rear; i++){
                cout<<arr[i] <<" ";
            }
            cout<<endl;
            return;
        }
        
};
int main() {
    Queue q;

    cout << q.isempty() << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print_it_dude();

    cout << "Front element: " << q.peek() << endl;
    cout << "Size: " << q.size() << endl;

    cout << q.deque() << " is removed" << endl;

    q.print_it_dude();

    q.enqueue(40);

    q.print_it_dude();

    cout << "Front element: " << q.peek() << endl;
    cout << "Size: " << q.size() << endl;

    cout << "Is Empty: " << q.isempty() << endl;

    return 0;
}
