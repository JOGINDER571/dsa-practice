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
int search(int in[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in[i]==curr){
            return i;
        }
    }
    return -1;
}
Node* buildtree(int post[],int in[],int start,int end){
    static int idx=4;
    if(start>end){
        return NULL;
    }
    int curr=post[idx];
    idx--;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }

    int pos=search(in,start,end,curr);
    node->right=buildtree(post,in,pos+1,end);
    node->left=buildtree(post,in,start,pos-1);
    

    return node;
    
}
void printinorder(Node* root){
    if(root==NULL){
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}
int main()
{
    int post[]={4,2,5,3,1};
    int in[]={4,2,1,5,3};
    Node* root=buildtree(post,in,0,4);
    printinorder(root);

    return 0;
}