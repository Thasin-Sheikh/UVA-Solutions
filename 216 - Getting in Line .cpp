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
ll nt=0;
void solve(ll n)
{
    ll i,j,k,m,l,r,q,p,sum=0,c,d,mi=maxval,ma=minval;
    string str;
    bool yes=true;
    vector<pair<ll,ll>>v;
    vector<ll>aa,ans;
    ll a[n+1],b[n+1];
    nt++;
    for(i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        aa.push_back(i);
    }
    dl tot=maxval;
    do
    {
        ll cura, curb;
        cura=a[aa[0]];
        curb=b[aa[0]];
        dl dd=0.0;
        for(i=1; i<aa.size(); i++)
        {
            dd+=sqrt(((cura-a[aa[i]])*(cura-a[aa[i]]))+((curb-b[aa[i]])*(curb-b[aa[i]])));
            cura=a[aa[i]];
            curb=b[aa[i]];
        }
        if(dd<tot)
        {
            tot=dd;
            ans=aa;
        }

    }
    while(next_permutation(aa.begin(),aa.end()));
    //printf("%.2f\n",tot);
    cout<<"**********************************************************"<<"\n";
    cout<<"Network"<<" "<<"#"<<nt<<"\n";
    for(i=1; i<ans.size(); i++)
    {
        dl dd;
        dd=sqrt(((a[ans[i]]-a[ans[i-1]])*(a[ans[i]]-a[ans[i-1]]))+((b[ans[i]]-b[ans[i-1]])*(b[ans[i]]-b[ans[i-1]])));
        dd+=16;
        cout<<"Cable requirement to connect ("<<a[ans[i-1]]<<","<<b[ans[i-1]]<<")"<<" to ("<<a[ans[i]]<<","<<b[ans[i]]<<")"<<" is ";
        printf("%.2lf",dd);
        cout<<" feet."<<"\n";
    }
    tot+=(n-1)*16;
    cout<<"Number of feet of cable required is ";
    printf("%.2lf",tot);
    cout<<"."<<"\n";

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //tle khaite chas to endl use kor
    //check test case in interactive , idiot
    //never use pow func directly
    //add and subtract

    //makefast__
    string str;
    ll i,j,n,m,k,t;

    while(cin>>t)
    {
        if(t)
            solve(t);
        else break;
    }

    return 0;
}




