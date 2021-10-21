#include<iostream>
using namespace std;
int getbit(int n,int pos){
    return (n & (1<<pos))!=0;
}
int setbit(int n,int pos){
    return (n | (1<<pos));
}
int clearbit(int n,int pos){
    int mask=~(1<<pos);
    return (n & mask);
}
int updatebit(int n,int pos ,int k){
    int a=clearbit(n,pos);
    return (a | (k<<pos));
    
}
int main(){
    // cout<<getbit(5,1);
    // cout<<setbit(6,0);
    cout<<updatebit(5,0,0); 
}