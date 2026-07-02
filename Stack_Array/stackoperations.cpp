#include<iostream>
using namespace std;

class Stack{
    private:
        static const int size = 500;
        int arr[size];
        int top;
    public:
        Stack(){
            top = -1;
        }
        void print_it_dude(){
            if(top == -1){
                cout<<"Stack is underflow"<<"\n";
                return;
            }
            for(int i = top ; i >= 0; i--){
                cout<< arr[i] << " ";
            }
            cout<<endl;
            return;
        }

        void push(int v){
            if(top == size -1){
                cout<<"Stack overflow"<<"\n";
                return;
            }
            top++;
            arr[top] = v;
        }
        int peek(){
            if(top == -1){
                cout<<"Stack underflow"<<"\n";
                return -1;
            }
            return arr[top];
        }
        int pop(){
            if(top == -1){
                cout<<"Stack underflow"<<"\n";
                return -1;
            }
            int r = arr[top];
            top--;
            return r; 
        }
        int Size(){
            return top + 1;
        }
        bool isempty(){
            if(top == -1){
                return 1;
            }
            return 0;
        }
        bool isfull(){
            if( top == size -1){
                return true;
            }
            return false;
        }
};
int main(){
    Stack s;
    cout<<s.isempty()<<"\n";
    s.pop();
    s.push(10);
    s.push(20);
    s.push(40);
    cout<< s.pop()<<" is removed"<<"\n";
    cout << s.peek()<<"\n";
    s.push(30);
    cout << s.isempty()<<"\n";
    s.print_it_dude();

}
