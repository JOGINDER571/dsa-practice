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
 node* reverse(node* &head){
     node* n;
     node* c=head;
     node* p=NULL;
     while(c!=NULL){
         n=c->next;
         c->next=p;
         p=c;
         c=n;
     }
     return p;
    //  delete(n);
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
     node* rehead=reverse(head);
     printData(rehead);
    //  printData(head);

 }