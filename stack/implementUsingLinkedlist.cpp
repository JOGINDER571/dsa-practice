#include<iostream>
using namespace std;
class stack{
    public:
    int data;
    stack* next;
    stack(int x){
        data=x;
        next=NULL;
    }
};
void push(stack* &start,int x){
    stack* node=new stack(x);
    if(start==NULL){
        start=node;
        return;
    }
    node->next=start;
    start=node; 

}
void pop(stack* &start){
    if(start==NULL){
        cout<<"empty"<<endl;
        return;
    }
    stack* todel=start;
    start=start->next;
    delete(todel);
}
void top(stack* &start){
    if(start==NULL){
        cout<<"empty"<<endl;
        return;
    }
    cout<<start->data<<endl;
}
bool empty(stack* &start){
    return start;
}
int main()
{
    stack* start=NULL;
    push(start,1);
    push(start,2);
    top(start);
    pop(start);
    top(start);
    pop(start);
    cout<<empty(start)<<endl;
    // pop(start);
    top(start);
}