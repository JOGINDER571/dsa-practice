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

 void insertHead(node* &head,int k){
     node* temp=head;
     node* n=new node(k);
     if(head==NULL){
         head=n;
         n->next=head;
         return;
     }
     while(temp->next!=head){
         temp=temp->next;
     }
     temp->next=n;
     n->next=head;
     head=n;

 }
 void insertTail(node* &head,int k){
     if(head==NULL){
         insertHead(head,k);
         return;
     }
     node* temp=head;
     node* n=new node(k);
     while(temp->next!=head){
         temp=temp->next;
     }
     temp->next=n;
     n->next=head;

 }
 void deletionHead(node* &head,int pos){
     node* temp=head;
     while(temp->next!=head){
         temp=temp->next;
     }

     node* todel=temp->next;
     temp->next=temp->next->next;
     head=head->next;
     delete(todel);

 }
 void deletion(node* &head,int pos){
     if(pos==1){
         deletionHead(head,pos);
         return;
     }
     int count=1;
     node* temp= head;
     while(count!=pos-1){
         temp=temp->next;
         count++;
     }
     node* todel=temp->next;
     temp->next=temp->next->next;
     delete(todel);
 }
void printData(node* head){
     node* temp=head;
     do
     {
         cout<<temp->data<<"->";
         temp=temp->next;
     } while (temp!=head);
     
     cout<<endl;
 }

  int main()
 {
     node* head=NULL;
     insertTail(head,1);
     insertTail(head,2);
     insertTail(head,3);
     insertTail(head,4);
     insertTail(head,5);
     deletion(head,1);
     printData(head);

 }