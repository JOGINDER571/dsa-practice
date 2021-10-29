#include<iostream>
 using namespace std;

 class node
 {
     public:
     int data;
     node *next;
     node(int val){
         data=val;
         next=NULL;
     }
 };

 void insertAtBeg(node* &head,int x){
     node *n=new node(x);
     if(head==NULL){
         head=n;
         return;
     }
     n->next=head;
     head=n;
 }
 void insertAtEnd(node* &head,int x){
     node *n=new node(x);
     if(head==NULL){
         head=n;
         return;
     }
     node *temp=head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=n;
 }
 //making cycle
 void cycle(node* &head){
     node* temp=head;
     while(temp->data!=3){
         temp=temp->next;
     }
     node* p=head;
     while(p->next!=NULL){
         p=p->next;
     }
     p->next=temp->next;
 }
 bool floydAlgo(node* &head){
     node* fast=head;
     node* slow=head;
     while(fast!=NULL && fast->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
         if(fast==slow){
             return true;
             
         }
     }
     return false;
 }
 void removecycle(node* &head){
    node* fast=head;
    node* slow=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    fast=head;
    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    
 }

  void printData(node* head){
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
     insertAtEnd(head,1);
     insertAtEnd(head,2);
     insertAtEnd(head,3);
     insertAtEnd(head,4);
     insertAtEnd(head,5);
     insertAtEnd(head,6);
     insertAtEnd(head,7);
     insertAtEnd(head,8);
     insertAtEnd(head,9);
     cycle(head);
     cout<<floydAlgo(head)<<endl;
     removecycle(head);
     cout<<floydAlgo(head)<<endl;
     printData(head);


 }