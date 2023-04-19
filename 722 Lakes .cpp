#include<iostream>
#include<string.h>
using namespace std;
using ll=long long int;
ll matrix[105][105];
ll vis[105][105];
ll r=0,col,ans=0;
void dfs(ll row,ll cl)
{
    vis[row][cl]=1;
    //cout<<row<<" "<<cl<<"\n";
    if(row+1<=r&&matrix[row+1][cl]==0&&vis[row+1][cl]==0)
    {
        ans++;
        dfs(row+1,cl);

    }
    if(row-1>=1&&matrix[row-1][cl]==0&&vis[row-1][cl]==0)
    {
        ans++;
        dfs(row-1,cl);
    }
    if(cl+1<=col&&matrix[row][cl+1]==0&&vis[row][cl+1]==0)
    {
        ans++;
        dfs(row,cl+1);
    }
    if(cl-1>=1&&matrix[row][cl-1]==0&&vis[row][cl-1]==0)
    {
        ans++;
        dfs(row,cl-1);
    }


}
int main()
{
    string str;
    ll n,m,i,j;
    cin>>n;
    cin.ignore();
    cin.ignore();

    while(n--)
    {
        string a,b;
        getline(cin,a);
        ll c=0,d=0,k=0;
        for(i=0; i<a.size(); i++)
        {
            if(a[i]==' ')
            {
                k++;
            }
            else
            {
                if(!k)
                {
                    c*=10;
                    c+=(a[i]-'0');
                }
                else
                {
                    d*=10;
                    d+=(a[i]-'0');

                }
            }
        }
        ll tm=7;
        r=0;
        while(getline(cin,str))
        {
            if(str=="")
            {
                break;
            }
            r++;
            col=str.size();
            for(i=0; i<str.size(); i++)
            {
                matrix[r][i+1]=(str[i]-'0');

            }
        }
        ans=0;
        //cout<<c<<" "<<d<<"\n";
        dfs(c,d);
        memset(vis,0,sizeof(vis));
        cout<<ans+1<<"\n";
        if(n)
        {
            cout<<"\n";
        }
    }

}
