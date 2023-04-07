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
ll vis[N];
vector<ll>ed[N];
map<ll,ll>mp;
//priority_queue<ll>pq;// from max to min
ll dp[205][50][15];
ll st=0;
ll ddp(ll in,ll sum,ll tot,ll n,ll e,ll d)
{
    if(in>n+1)
    {
        return 0;
    }

    if(tot==e)
    {
        if(sum==0)
        {
            //cout<<sum<<"\n";
            return 1;
        }
        return 0;
    }
    if(dp[in][sum][tot]!=-1)
    {
        return dp[in][sum][tot];
    }
    ll ans=ddp(in+1,(sum+aarray[in])%d,tot+1,n,e,d)+ddp(in+1,sum%d,tot,n,e,d);
    return dp[in][sum][tot]=ans;
}
void solve(ll n,ll q)
{
    ll i,j,k,m,l,r,p,ans,sum=0,a,b,c,d,mi=maxval,ma=minval;
    string str;
    bool yes=true;
    vector<ll>v;
    for(i=1; i<=n; i++)
    {
        cin>>aarray[i];
    }
    st++;
    ll e;
    ll qu=0;
    cout<<"SET "<<st<<":"<<"\n";
    while(q--)
    {
        qu++;
        cin>>d>>e;

        memset(dp,-1,sizeof dp);
        ans= ddp(1,0,0LL,n,e,d);
        cout<<"QUERY "<<qu<<":"<<" "<<ans<<"\n";
    }

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
    ll i,j,n,m,k,t;
    ll q;
    t=1;
    while(cin>>n>>q)
    {


        if(n==0&&q==0)
            break;
        solve(n,q);
    }

    return 0;
}




