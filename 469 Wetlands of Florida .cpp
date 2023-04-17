#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
using ll=long long int;
char magic[105][105];
ll sz;
ll ans=0;
ll vis[105][105],n,lb;
int dr [] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dc [] = {0, 1, 0, -1, 1, 1, -1, -1};

void dfs (int r, int c)
{
    if ( r >n || r < 1 || c >sz || c < 1 || magic [r] [c] == 'L' || vis [r] [c] ) return;
    vis [r] [c] = true;
    ans++;

    for ( int i = 0; i < 8; i++ )
        dfs (r + dr [i], c + dc [i]);
}
void solve()
{
    string str;
    ll i,j,k,m;
    n=0;
    while(getline(cin,str)&&str!="")
    {
        if(str[0]=='L'||str[0]=='W')
        {
            n++;
            sz=str.size();
            for(i=0; i<str.size(); i++)
            {
                magic[n][i+1]=str[i];
            }
        }
        else
        {
            ans=0;
            ll a=0,b=0;
            bool ok=false;
            for(i=0; i<str.size(); i++)
            {
                if(str[i]==' ')
                {
                    ok=true;
                    continue;
                }
                if(ok)
                {
                    b=b*10+(str[i]-'0');
                }
                else
                {
                    a=a*10+(str[i]-'0');
                }
            }
            dfs(a,b);
            memset(vis,0,sizeof vis);
            cout<<ans<<"\n";

        }
    }
    lb--;
    if(lb)
    {
        cout<<"\n";
    }

}
int main()
{
    ll i,j,t;
    cin>>t;
    cin.ignore();
    cin.ignore();
    lb=t;
    while(t--)
    {
        solve();
    }

}
