#include<iostream>
using namespace std;
class Node
{
    public:
    char data;
    int prno;
    Node* next;
    Node(char x,int pr){
        data=x;
        prno=pr;
        next=NULL;
    }
};
class PQ
{
    public:
    Node* front,*rear;
    PQ(){
        front=rear=NULL;
    }
    void insert(char data,int pr){
        Node* n=new Node(data,pr);
        if(front==NULL || front->prno>pr){
            n->next=front;
            front=n;
            return;
        }
        else{
            Node* temp=front;
            while(temp->next!=NULL && temp->next->prno<=pr){
                temp=temp->next;
            }
            if(temp->next==NULL){
                rear=n;
            }
            n->next=temp->next;
            temp->next=n;
        }
    }
    void deletion(){
        if(front==NULL){
            cout<<"empty"<<endl;
            return;
        }
        Node* temp=front;
        front=front->next;
        delete(temp);
    }
    void first()
    {
        if(front==NULL){
            cout<<"empty"<<endl;
            return;
        }
        cout<<front->data<<endl;
    }
    void print(){
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};
int main()
{
    PQ ob;
    ob.insert('A',1);
    ob.insert('B',2);
    ob.insert('C',3);
    ob.insert('d',4);
    ob.insert('e',5);
    ob.deletion();
    ob.print();

}