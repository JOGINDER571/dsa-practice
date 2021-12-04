#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    double v1= p1.first/p1.second;
    double v2= p2.first/p2.second;
    return v1>v2;
}
int main()
{
    int n;
    cin>>n;
    int w;
    cin>>w;
    vector<pair<int,int>>vii(n);
    
    for(int i=0;i<n;i++){
        cin>>vii[i].first>>vii[i].second;
    }
    sort(vii.begin(),vii.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        if(w>vii[i].second){
            ans+=vii[i].first;
            w-=vii[i].second;
            continue;
        }
        double vw=vii[i].first/vii[i].second;
        ans+=vw*w;
        w=0;
        break;
    }
    cout<<ans;

    return 0;

}