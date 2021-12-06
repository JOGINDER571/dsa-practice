#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>


int main()
{
    int n,m;
    cin>>n>>m;
    vvi adjm(n+1,vi(n+1,0));
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }

}