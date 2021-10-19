#include<iostream>
using namespace std;
int binarySearch(int arr[],int l,int r,int k){ //o(logn)
    while(l<=r){
        int mid=(l+r)/2;
        if(k==arr[mid]){
            return mid;
        }else if(k<arr[mid]){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    // if(k==arr[r]){
    //     return r;
    // }
    return -1;
}

int main(){
    int arr[]={2,3,4,5,6,8,9};
    int l=0,r=7,k=6;
    cout<<binarySearch(arr,l,r,k);
}