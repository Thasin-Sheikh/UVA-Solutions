#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
using ll=long long int;
char magic[105][105],vis[105][105];
int dr [] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dc [] = {0, 1, 0, -1, 1, 1, -1, -1};
ll n,m;
void dfs (int r, int c)
{
    vis[r][c]=1;
    if(r+1<=n&&magic[r+1][c]=='@'&&vis[r+1][c]==0)
    {
        dfs(r+1,c);
    }
    if(r-1>=1&&magic[r-1][c]=='@'&&vis[r-1][c]==0)
    {
        dfs(r-1,c);
    }
    if(c+1<=m&&magic[r][c+1]=='@'&&vis[r][c+1]==0)
    {
        dfs(r,c+1);
    }
    if(c-1>=1&&magic[r][c-1]=='@'&&vis[r-1][c]==0)
    {
        dfs(r,c-1);
    }
    if(r+1<=n&&c+1<=m&&magic[r+1][c+1]=='@'&&vis[r+1][c+1]==0)
    {
        dfs(r+1,c+1);
    }
    if(r+1<=n&&c-1>=1&&magic[r+1][c-1]=='@'&&vis[r+1][c-1]==0)
    {
        dfs(r+1,c-1);
    }
    if(r-1<=n&&c+1<=m&&magic[r-1][c+1]=='@'&&vis[r-1][c+1]==0)
    {
        dfs(r-1,c+1);
    }
    if(r-1<=n&&c-1>=1&&magic[r-1][c-1]=='@'&&vis[r-1][c-1]==0)
    {
        dfs(r-1,c-1);
    }

}
int main()
{
    ll i,t,j;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
        {
            break;
        }
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; i++)
        {
            string str;
            cin>>str;
            for(j=0; j<str.size(); j++)
            {
                magic[i][j+1]=str[j];
            }
        }
        ll ans=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(magic[i][j]=='@'&&vis[i][j]==0)
                {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<"\n";
    }
}
