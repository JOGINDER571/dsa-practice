#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int position(int arr[],int l,int r){
    int i=l-1;
    int pivot=arr[r];
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);

        }
    }
    swap(arr,i+1,r);
    return i+1;
}
void quick_sort(int arr[],int l,int r){
    if(l<r){
        int pi=position(arr,l,r);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,r);
    }
}

int main(){
    int arr[]={3,4,2,1,6,9,7};
    quick_sort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}