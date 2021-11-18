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
Node* insertBST(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
bool search(Node* root,int k){
    if(root==NULL){
        return false;
    }
    if(k==root->data){
        return true;
    }
    else if(k<root->data){
        search(root->left,k);
    }else{
        search(root->right,k);
    }
}
Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr &&curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* deletion(Node* root,int k){
    if(k<root->data){
        root->left=deletion(root->left,k);
    }else if(k>root->data){
        root->right=deletion(root->right,k);
    }else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deletion(root->right,temp->data);
    }
    return root;
}
void print(Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    
    print(root->right);
}
int main()
{
    Node* root=NULL;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    // cout<<search(root,0);
    print(root);
    cout<<endl;
    Node* node=deletion(root,3);
    print(node);
    return 0;
}