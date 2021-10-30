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
void printData(node* head){
     node* temp=head;
     while(temp!=NULL){
         cout<<temp->data<<"->";
         temp=temp->next;
     }
     cout<<"NULL"<<endl;
 }
 node* mergelist(node* &head1,node* &head2){
     
     node* p1=head1;
     node* p2=head2;
     node* dummy=new node(-1);
     node* p3=dummy;
     while(p1!=NULL && p2!=NULL){
         if(p1->data<p2->data){
             p3->next=p1;
             p1=p1->next;
         }else{
             p3->next=p2;
             p2=p2->next;
         }
         p3=p3->next;
     }

     while(p1!=NULL){
         p3->next=p1;
         p1=p1->next;
         p3=p3->next;
     }

     while(p2!=NULL){
         p3->next=p2;
         p2=p2->next;
         p3=p3->next;
     }
     return dummy->next;
 }
 //solve by recurson
  node* recursion(node* &head1,node* &head2){
      if(head1==NULL){
          return head2;
      }
      if(head2==NULL){
          return head1;
      }
      node* result;
      if(head1->data<head2->data){
          result=head1;
          result->next=recursion(head1->next,head2);
      }
      else{
          result=head2;
          result->next=recursion(head1,head2->next);
      }
      return result;
  }


  int main()
 {
     node* head1=NULL;
     insertAtEnd(head1,1);
     insertAtEnd(head1,3);
     insertAtEnd(head1,5);
     insertAtEnd(head1,7);

     node* head2=NULL;
     insertAtEnd(head2,2);
     insertAtEnd(head2,4);
     insertAtEnd(head2,6);

     printData(head1);
     printData(head2);
    //  node* dnode=mergelist(head1,head2);
     node* dnode=recursion(head1,head2);
     
     printData(dnode);

 }