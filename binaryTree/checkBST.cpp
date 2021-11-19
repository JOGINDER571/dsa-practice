#include<iostream>
using namespace std;
struct Node
{
    /* data */
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left =NULL;
        right =NULL;
    }
};
//check for bst
bool checkBST(Node* root,Node* min=NULL,Node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL &&root->data<min->data){
        return false;
    }
    if(max!=NULL &&root->data>max->data){
        return false;
    }
    bool leftvalid=checkBST(root->left,min,root);
    bool rightvalid=checkBST(root->right,root,max);
    return leftvalid && rightvalid;
}
int main()
{
    Node* root1=new Node(5);
    root1->left=new Node(3);
    root1->right=new Node(10);
    root1->left->left=new Node(2);
    root1->left->right=new Node(4);
    root1->right->left=new Node(6);
    root1->right->right=new Node(12);
    cout<<checkBST(root1,NULL,NULL);
}