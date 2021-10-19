
#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            int temp=0;
            if(arr[j+1]<arr[j]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
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
    bubbleSort(arr,n); 

}