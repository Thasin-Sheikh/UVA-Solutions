///*Bismillahir Rahmanir Rahim***///
///**Author thasin_sheikh**///
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using myset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define MAX 1e6+10
#define MOD 1000000007
#define PI acos(-1)
#define R 510
#define makefast__  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using ll=long long int ;
using dl =double;
using ld=long double;
using ull=unsigned long long;
const long N = 3e5 + 10;
const long maxn=5e5+10;
const long long  maxval=1e18;
const long long minval=-1e18;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>os;
ll aarray[N];
ll magic[R][R];
vector<ll>primes;
//bool check[1000001];
//ll large[10000005];
//int dx[] = {-1 , 0 , 1 , 0};
//int dy[] = {0 , 1 , 0 , -1};
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
ll vis[1200];
vector<ll>ed[N];
map<ll,ll>mp;
//priority_queue<ll>pq;// from max to min
vector<ll>v;
ll dp[200][20][1200];
ll k,n,m;
ll ddp(ll i,ll j,ll sum)
{
    if(i>v.size()||sum>n)
    {
        return 0 ;
    }
    if(dp[i][j][sum]!=-1)
    {
        return dp[i][j][sum];
    }
    if(sum==n)
    {
        if(j==m)
        {
            return 1;
        }
        return 0;
    }

    if(j==m)
    {
        return 0;
    }


    ll a=0;
    a=ddp(i+1,j+1,sum+v[i]);
    ll b=0;
    b=ddp(i+1,j,sum);
    return dp[i][j][sum]=a+b;


}
void solve()
{
    ll i,j,l,r,q,p,ans,sum=0,a,b,c,d,mi=maxval,ma=minval;
    string str;
    bool yes=true;
    //cout<<v.size()<<"\n";
    memset(dp,-1,sizeof(dp));
    ans=ddp(0,0,0);
    cout<<ans<<"\n";

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //tle khaite chas to endl use kor
    //check test case in interactive , idiot
    //never use pow func directly
    //add and subtract

    makefast__
    string str;
    ll i,j,k,t;
    memset(vis,1,sizeof vis);
    vis[0]=vis[1]=0;
    for(i=2; i<=1120; i++)
    {
        if(vis[i])
        {
            v.push_back(i);
            for(j=2*i; j<=1120; j+=i)
            {
                vis[j]=0;
            }
        }
    }


    while(cin>>n>>m)
    {
        if(n==0&&m==0)
        {
            break;
        }
        else
            solve();
    }


    return 0;
}




