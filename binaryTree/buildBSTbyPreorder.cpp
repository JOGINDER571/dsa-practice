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
Node* buildBST(int pre[],int* preorderidx ,int k,int min,int max,int n){
    Node *root=NULL;
    if(k>min &&k<max){
        
    }
}