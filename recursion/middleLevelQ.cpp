 #include<iostream>
 using namespace std;
 //check array is sorted or not
 bool sorted(int a[],int n){
     if(n==1){
         return true;
     }
     
     bool restarray=sorted(a+1,n-1);
     return (a[0]<a[1] && restarray);
 }
 //find the first and last occurence in array
 int first(int arr[],int n,int i,int k){
     if(i==n){
         return -1;
     }
     if(arr[i]==k){
         return i;
     }
     return first(arr,n,i+1,k);

 }
 int second(int a[],int n,int i,int k){
     if(i==n){
         return -1;
     }
     int restarray=second(a,n,i+1,k);
     if(restarray!= -1){
         return restarray;
     }
     if(a[i]==k){
         return i;
     }
     return -1;
 }
 int main(){
     int a[]={1,2,3,4,5,2};
    //  cout<<sorted(a,3);
    // cout<<first(a,6,0,8);
    cout<<second(a,6,0,2);

 }