#include<iostream>
using namespace std;
class Linkedlist_array{
    public:
        static const int size = 300;
        int data[300];
        int next[300];

        int head;
        int freehead;
    public:
        Linkedlist_array(){
            head = -1;
            freehead = 0;
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
int main(){
    Linkedlist_array list;

    for (int i = 0; i < 10; i++) {
        list.data[i] = (i + 1) * 10;
    }
    for (int i = 0; i < 9; i++) {
        list.next[i] = i + 1;
    }
    list.next[9] = -1;

    list.head = 0;    

    list.display();
    list.deleteatbeginning();
    list.display();
    list.deleteatend();
    list.display();
    list.deleteatk(4);
    list.display();
    list.deleteatk(0);
    list.display();
    list.deletetheval(50);
    list.display();
}