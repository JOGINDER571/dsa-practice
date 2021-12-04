#include<bits/stdc++.h>
using namespace std;
int optimalmergepattern(priority_queue<int,vector<int>,greater<int> >minheap){
    int ans=0;
    while(minheap.size()!=1){
        int e1=minheap.top();
        minheap.pop();
        int e2=minheap.top();
        minheap.pop();
        ans+=e1+e2;
        minheap.push(e1+e2);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    priority_queue<int,vector<int>,greater<int> >minheap;
    for(int i=0;i<n;i++){
        minheap.push(v[i]);
    }
    cout<<optimalmergepattern(minheap);

    return 0;
}