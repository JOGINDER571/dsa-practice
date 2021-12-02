#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>a;
    a.push_back({10,20}); 
    a.push_back({12,15}); 
    a.push_back({20,30}); 
    
    sort(a.begin(),a.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    });
    cout<<a[2][0];
    
}