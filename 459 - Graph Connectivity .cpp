#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
using ll=long long int;
vector<ll>ed[30];
ll vis[30];
void dfs(ll nd)
{
    vis[nd]=1;
    ll i,k;
    for(i=0;i<ed[nd].size();i++)
    {
        k=ed[nd][i];
        if(vis[k])
        {
            continue;
        }
        dfs(k);
    }
}
ll ln=0;
void solve()
{
    ll i,j,k,l;
    char ch;
    cin>>ch;
    k=ch-'A';
    k++;
    for(i=1;i<=k;i++)
    {
        vis[i]=0;
        ed[i].clear();
    }
    ll a,b;
    string str;
    cin.ignore();
    ln--;
    while(getline(cin,str)&&str!="")
    {
        a=str[0]-'A';
        a++;
        b=str[1]-'A';
        b++;
        ed[a].push_back(b);
        ed[b].push_back(a);

    }
    ll ans=0;
    for(i=1;i<=k;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<"\n";
    if(ln)
    cout<<"\n";
}
int main()
{
    int n,t;

    cin>>t;
    ln=t;
    while(t--)
    {
        solve();
    }

}
