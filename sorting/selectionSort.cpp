// find the smallest element in the array and its swap with
// its correct position

#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int temp=0;
            if(arr[j]<arr[i]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        
    }
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
}
int main()
{
    int arr[]={8,4,5,6,3,2,1};
    int n= 7;
    selectionSort(arr,n); 

}