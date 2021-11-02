#include<iostream>
using namespace std;
class queue
{
    public:
    int arr[10];
    int front;
    int rear;
    queue(){
        front =-1;
        rear =-1;
    }
    void enqueue(int x){
        if(rear==9){
            cout<<"overflow";
            return;
        }
        if(front==-1){
            front++;
        }
        rear++;
        arr[rear]=x;
        
    }
    void dequeue(){
        if(front==-1 ||front>rear){
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 ||front>rear){
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front==-1 ||front>rear){
            return true;
        }
        return false;
    }
};
int main()
{
    queue ob;
    ob.enqueue(1);
    ob.enqueue(2);
    ob.enqueue(3);
    // cout<<ob.peek();
    ob.dequeue();
    cout<<ob.peek();
    cout<<ob.empty();
}
