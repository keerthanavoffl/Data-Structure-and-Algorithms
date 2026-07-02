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


        void print_it_dude(){
            int curr = head;
            while(curr != -1){
                cout<< data[curr] <<" ";
                curr = next[curr];
            }
        }
};

int main(){
    Linkedlist_array list;

    list.insertatbeginning(10);
    list.insertatbeginning(30);
    list.insertatend(70);
    list.insertatk(15,2);
    list.insertatk(22, 0);
    list.insertatk(33, 2);
    list.insertbeforek(3,15);
    list.print_it_dude();
}
