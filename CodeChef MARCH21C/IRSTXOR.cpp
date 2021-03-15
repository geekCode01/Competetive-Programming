#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long int

ll solve(ll n)
{
    ll x=n;
    int o=0,size=0;
    while(x>0)
    {
        if(x%2==1)
        {
            o++;
        }
        x/=2;
        size++;
    }

    int a1[size],a2[size];
    int v=size;
    x=n;
    int ind=0;
    
    while(x>0)
    {
        if(x%2==0)
        {
            a1[ind]=1;
            a2[ind]=1;
        }
        else
        {
            if(o==1)
            {
                a1[ind]=1;
                a2[ind]=0;
            }
            else{
                a1[ind]=0;
                a2[ind]=1;
            }
            o--;
        }
        ind++;
        x/=2;
    }

    ll v1=0,v2=0;
    ll p=1;
    for(int i=0;i<v;i++){
        v1=v1+p*a1[i];
        v2=v2+p*a2[i];
        p=p*2;
    }
    return v1*v2*1ll;
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}