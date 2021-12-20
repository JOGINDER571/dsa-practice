#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> v[N];
vector<vector<int>>cc;
vector<int>current_c;
bool vis[N];
int dfs(int vertex){
    // cout<<vertex<<endl;
    vis[vertex]=true;
    current_c.push_back(vertex);
    for(int child:v[vertex]){
        // cout<<"par"<<vertex<<",child"<<child<<endl;
        if(vis[child]) continue;

        dfs(child);
    }
    return 1;
    
}
int main()
{
    int m,n;
    cin>>n>>m;
    for(int i=0;i<m;i++){ 
        int v1,v2;
        cin>>v1>>v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    int comp,ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            current_c.clear();
            comp=dfs(i);
            ans+=comp;
            cc.push_back(current_c);
        }
    }
    cout<<ans<<endl;
    for(auto c_cc:cc){
        for(int vertex:c_cc){
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
    
}