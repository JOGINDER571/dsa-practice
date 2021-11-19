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
Node* sortedArrToBST(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);
    root->left=sortedArrToBST(arr,start,mid-1);
    
    root->right=sortedArrToBST(arr,mid+1,end); 

    return root;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int arr[]={1,2,3,4,5};
    Node* root=sortedArrToBST(arr,0,4);
    preorder(root);
}