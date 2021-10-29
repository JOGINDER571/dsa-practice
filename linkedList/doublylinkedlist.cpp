#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;
    node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};
void insertHead(node* &head,int x){
    node* n=new node(x);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}
void insertTail(node* &head,int x){
    node* n=new node(x);
    if(head==NULL){
        insertHead(head,x);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void deletionhead(node* &head,int k){
    node* temp=head;
    head=temp->next;
    head->prev=NULL;
    delete(temp);
}
void deletion(node* &head,int k){
    if(head->data==k){
        deletionhead(head,k);
        return;
    }

    node* temp=head;
    while(temp->data!=k){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete(temp);

}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* head=NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    deletion(head,1);
    display(head);
}