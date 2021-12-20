#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> v[N];
bool vis[N];
bool dfs(int vertex,int parent){
    bool isloopexists=false;
    vis[vertex]=true;
    for(int child:v[vertex]){
        if(vis[child] &&child==parent) continue;
        if(vis[child]) return true;

        isloopexists |=dfs(child,vertex);
    }
    return isloopexists;
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
    bool isloopexist=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,0)){
                isloopexist=true;
                break;
            }
        }
    }
    cout<<isloopexist;
    
}