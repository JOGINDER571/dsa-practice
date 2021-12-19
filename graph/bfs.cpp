#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> v[N];
bool vis[N];
bool leval[N];
void bfs(int vertex){
    queue<int>q;
    q.push(vertex);
    vis[vertex]=1;
    while (!q.empty())
    {
        /* code */
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        vector<int> ::iterator it;
        for(it=v[cur].begin();it!=v[cur].end();it++){
            if(!vis[*it]){
                vis[*it]=1;
                q.push(*it);
                leval[*it]=leval[cur]+1;
            }
        }
    }
    
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int v1,v2;
        cin>>v1>>v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<i<<":"<<leval[i]<<endl;
    }
}