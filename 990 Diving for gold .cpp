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

/*ll ddp(ll curin,ll remtm)
{
    if(curin>n)
    {
        return 0;
    }
    if(dp[curin][remtm]!=-1)
    {
        return dp[curin][remtm];
    }
    ll ans1=0,ans2=0;
    ll a=w*b[curin]+2*b[curin]*w;
    if(a<=remtm)
    {
        ans1=v[curin]+ddp(curin+1,remtm-a);
    }
    ans2=ddp(curin+1,remtm);
    return dp[curin][remtm]=max(ans1,ans2);

}*/
ll End=0;
ll dp[35][1005];
ll n;
ll b[35],v[35];
void solve(ll bc,ll w)
{
    ll i,j,k,m,l,r,q,p,sum=0,c,d,mi=maxval,ma=minval;
    string str;
    bool yes=true;
    set<ll>s;
    ll ans[40];
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>b[i]>>v[i];
    }
    for (j=0; j<=bc; j++) dp[0][j] = 0;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=bc; j++)
        {
            ll a=3*w*b[i];
            if(a<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a]+v[i]);
            }
            else
                dp[i][j]=dp[i-1][j];

        }
    }
    k=0;
    sum=0;
    ll a;
    a=sum=dp[n][bc];
    for(i=n;i>0&&a>0;i--)
    {
        if (dp[i][bc]!=dp[i-1][bc])
        {
            ans[k++] = i;
            bc -= 3*b[i]*w;

        }
    }
    if(End)
    {
        cout<<endl;

    }
    End=1;
    cout<<sum<<endl;
    cout<<k<<endl;
    for (i=k-1; i>=0; i--)
       cout<<b[ans[i]]<<" "<<v[ans[i]]<<endl;

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
    while(cin>>t>>m)
    {
        solve(t,m);
    }

    return 0;
}




