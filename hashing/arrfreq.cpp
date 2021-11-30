#include<bits/stdc++.h>
using namespace std;
void arrfreq(vector<int>a,int n){
    map<int,int>freq;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    map<int,int> :: iterator it;
    for(auto it=freq.begin();it!=freq.end();it++){
        cout<<it->first<<"->"<<it->second<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    arrfreq(a,n);
}
