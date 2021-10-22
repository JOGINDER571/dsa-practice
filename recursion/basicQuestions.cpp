#include<iostream>
using namespace std;
//find sum
int sum(int n){
    if(n==0){
        return 0;
    }
    int sums=sum(n-1);
    return n+sums;
}
//power
int powerofn(int n,int p){
    if(p==0){
        return 1;
    }
    int product=powerofn(n,p-1);
    return n*product;
}
//factorial
int  fact(int n){
    if(n==0 ||n==1){
        return 1;
    }
    return n* fact(n-1);
}
//fibonacci series
int fib(int n){
    
    if(n==0 ||n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
int main(){
    // cout<<sum(4);
    // cout<<powerofn(2,3);
    // cout<<fact(5);
    cout<<fib(5);
}