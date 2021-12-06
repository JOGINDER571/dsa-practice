#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
vi adjl[100];
int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);

    }
    
    for(int i=1;i<n+1;i++){
        cout<<i<<" "<<"->";
        vi ::iterator it;
        for(it=adjl[i].begin();it!=adjl[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }

}