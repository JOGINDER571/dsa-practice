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
 bool search(node *head,int k){
     if(head==NULL){
         cout<<"empty";
         return false;
     }
     node *temp=head;
     while(temp!=NULL){
         if(temp->data==k){
             return true;
         }
         temp=temp->next;
     }
     return false;
 }
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
 void deleteDataBeg(node* &head,int k){
     if(head==NULL){
         cout<<"empty";
         return;
     }
     //delete at beginning
     head=head->next;
 }
 
  void deleteData(node* &head,int k){
     if(head==NULL){
         cout<<"empty";
         return;
     }
     if(head->data==k){
         deleteDataBeg(head,k);
         return;
     }
     node* temp=head;
     while(temp->next->data!=k){
         temp=temp->next;
     }
     node* todelete=temp->next;
     temp->next=temp->next->next;
     delete(todelete);
     
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
     insertAtBeg(head,0);
     deleteData(head,3);
     printData(head);
    //  cout<<search(head,2);
     return 0;
 }