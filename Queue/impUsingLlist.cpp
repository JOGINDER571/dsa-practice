#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};
class queue
{
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n=new node(x);
        if(front==NULL){
            front=n;
            back=n;
        }
        back->next=n;
        back=n;
    }
    void pop(){
        if(front==NULL){
            cout<<"empty"<<endl;
            return;
        }
        node* todel=front;
        front=front->next;
        delete(todel);
    }
    int peek(){
        if(front==NULL){
            cout<<"empty"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            cout<<"empty"<<endl;
            return true;
        }
        return false;
    }
};
int main()
{
    queue ob;
    ob.push(1);
    ob.push(2);
    ob.push(3);
    cout<<ob.peek();
    ob.pop();
    
    cout<<ob.peek();
    cout<<ob.empty();
}