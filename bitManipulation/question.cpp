#include<iostream>
using namespace std;
//wap to check given no is power of 2

int powerof2(int n){
    return (n && !(n &(n-1)));
}
//wap to check how many one's in a binary representation
int count(int n){
    int c=0;
    while(n){
        n=n &(n-1);
        c++;
    }
    return c;
}
//print all sets in array
void sets(int arr[],int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}
//find the unique no in the array
int unique(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }
    return xorsum;
}
int main()
{
    // cout<<powerof2(32);
    // cout<<count(15);
    int arr[]={1,2,3,4,2,3,4};
    int n=7;
    // sets(arr,n);
    cout<<unique(arr,n);
}