#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int k){ //o(n)
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,3,4,5};
    cout<<linearSearch(arr,4,5);
}