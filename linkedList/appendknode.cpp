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
 node* appendKNodes(node* &head,int k){
     
     int count=0;
     node* temp=head;

     while(temp!=NULL){
         count++;
         temp=temp->next;
     }
     if(count==k){
         return head;
     }
     count-=k;
     node* p=head;
     temp=head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     while(count>1){
         p=p->next;
         count--;
     }
     temp->next=head;
     head=p->next;
     p->next=NULL;

     return head;
     

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
     printData(head);
     node* knode=appendKNodes(head,2);
     printData(knode);


 }