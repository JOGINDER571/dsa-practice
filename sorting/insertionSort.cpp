// insert an element from an unsorted array to its correct position
// to the sorted array

#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int j=i-1;
        while(arr[j]>curr &&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    } 
}

int main()
{
    int arr[]={87,4,5,6,3,2,1};
    int n= 7;
    insertionSort(arr,n); 

}