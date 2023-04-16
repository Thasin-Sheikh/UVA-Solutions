#include<bits/stdc++.h>
using namespace std;
using ll= long long int ;
ll magic[30][30];
ll vis[30][30],n;
void dfs(ll r,ll c)
{
    vis[r][c]=1;
    ll i,j,k;
    if(r+1<=n&&magic[r+1][c]==1&&vis[r+1][c]==0)
    {
        dfs(r+1,c);
    }
    if(r-1>=1&&magic[r-1][c]==1&&vis[r-1][c]==0)
    {
        dfs(r-1,c);
    }
    if(c+1<=n&&magic[r][c+1]==1&&vis[r][c+1]==0)
    {
        dfs(r,c+1);
    }
    if(c-1>=1&&magic[r][c-1]==1&&vis[r][c-1]==0)
    {
        dfs(r,c-1);
    }
    if(r-1>=1&&c-1>=1&&magic[r-1][c-1]==1&&vis[r-1][c-1]==0)
    {
        dfs(r-1,c-1);

    }
    if(r-1>=1&&c+1<=n&&magic[r-1][c+1]==1&&vis[r-1][c+1]==0)
    {
        dfs(r-1,c+1);

    }
    if(r+1<=n&&c-1>=1&&magic[r+1][c-1]==1&&vis[r+1][c-1]==0)
    {
        dfs(r+1,c-1);
    }
    if(r+1<=n&&c+1<=n&&magic[r+1][c+1]==1&&vis[r+1][c+1]==0)
    {
        dfs(r+1,c+1);

    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll i,j;
    ll c=0;
    while(cin>>n)
    {
       // cin>>n;
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; i++)
        {
            string ch;
            cin>>ch;
            for( j=0; j<n; j++)
            {
                magic[i][j+1]=ch[j]-'0';
            }
        }
        ll ans=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(magic[i][j]&&vis[i][j]==0)
                {
                    dfs(i,j);
                 //   cout<<i<<" "<<j<<"\n";
                    ans++;

                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", ++c, ans);

    }
}
