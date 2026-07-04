#include<iostream>
using namespace std;

class Linkedlist_array{
    private:
        static const int size = 200;
        int data[size];
        int next[size];

        int head;
        int freehead;

    public:
        Linkedlist_array(){
            head = -1;
            freehead = 0;
        }
        void insertatbeginning(int x){
            data[freehead] = x;
            next[freehead] = head;
            head = freehead;
            freehead++;
        }                  
        void insertatk(int val, int k){
            if( k == 0 || head == -1){
                data[freehead] = val;
                next[freehead] = head;
                head = freehead;
                freehead++;
                return;
            }
            int curr = head;
            for(int i = 0; i<k-1; i++){
                if(curr == -1) return;
                curr = next[curr];
            }
            data[freehead] = val;
            next[freehead] = next[curr];
            next[curr] = freehead;
            freehead++;
        }
        void insertatend(int val){
            if(head == -1){
                insertatbeginning(val);
                return;                 
            }
            int curr = head;
            while(next[curr] != -1){
                curr = next[curr];
            }
            data[freehead] = val;
            next[freehead] = -1;
            next[curr] = freehead;
            freehead++;
        }
        
        void insertbeforek(int val, int kv){
            if(head == -1){
                return;
            }
            int curr = head;
            int prev = -1;
            while( curr != -1 && data[curr] != kv){
                prev = curr;
                curr = next[curr];
            }
            if(curr == -1){
                return;
            }
            else if(prev == -1){
                data[freehead] = val;
                next[freehead] = head;
                head = freehead;
                freehead++;
                return;
            }
            else{
            data[freehead] = val;
            next[freehead] = curr;
            next[prev] = freehead;
            freehead++;
            }
        }

        void deleteatbeginning(){
            if(head == -1) return;
            head = next[head];
        }

        void deleteatend(){
            if(head == -1) return; 
            if(next[head] == -1){
                head = -1;
                return;
            }
            int curr = head;
            int prev = -1;
            while(next[curr] != -1){
                prev = curr;
                curr = next[curr];
            }
            next[prev] = -1;
        }

        void deleteatk(int k){
            if(head == -1) return;
            if(k == 0){
                head = next[head];
                return;
            }
            int curr = head;
            for(int i = 0; i < k-1; i++){
                if(curr == -1) return;
                curr = next[curr];
            }
             if (curr == -1 || next[curr] == -1) return;
            int v = next[curr];
            next[curr] = next[v];
        }

        void deletetheval(int v){
            if(head == -1) return;
            if(data[head] == v){
                head = next[head];
                return;
            }
            int curr = head;
            int prev = -1;
            while(curr != -1){
                if(data[curr] == v){
                    int nn = next[curr];
                    next[prev] = nn;
                    return;
                }
                prev = curr;
                curr = next[curr];
            }
        }

        void display(){
            int curr = head;
            while(curr != -1){
                cout<< data[curr] << " ";
                curr = next[curr];
            }
            cout<<"\n";
        }
};
int main() {
    Linkedlist_array list;

    list.insertatend(10);
    list.insertatend(20);
    list.insertatend(30);
    list.insertatend(40);
    list.insertatend(50);
    list.insertatend(60);
    list.insertatend(70);
    list.insertatend(80);
    list.insertatend(90);
    list.insertatend(100);

    cout << "Original List: ";
    list.display();

    list.deleteatbeginning();
    cout << "After deleteatbeginning(): ";
    list.display();

    list.deleteatend();
    cout << "After deleteatend(): ";
    list.display();

    list.deleteatk(4);
    cout << "After deleteatk(4): ";
    list.display();

    list.deleteatk(0);
    cout << "After deleteatk(0): ";
    list.display();

    list.deletetheval(50);
    cout << "After deletetheval(50): ";
    list.display();

    return 0;
}