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
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}
int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    preorder(root);
    inorder(root);
    postorder(root);
}
