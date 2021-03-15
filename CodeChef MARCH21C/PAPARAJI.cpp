#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void get(ll t);

int main()
{
    ll t;
    cin>>t;
    get(t); 
}

void get(ll t)
{
    while(t--)
    {
        ll x;
        cin>>x;
        vector<pair<ll,ll>>vec,st;
        for(ll i=0;i<x;i++)
        {
            ll v;
            cin>>v;
            vec.pb({i+1,v});
        }
        if(x==2)
        {
            cout<<"1"<<endl;
            continue;
        }

        st.pb(vec[0]);
        st.pb(vec[1]);
        ll res=1,len=st.size();
        for(ll i=2;i<x;i++)
        {
            while(st.size() >= 2)
            {
                double stsec1,stsec2,stfir1,stfir2;
                stsec1=(double)st[len-1].second;
                stsec2=(double)st[len-2].second;

                stfir1=(double)st[len-1].first;
                stfir2=(double)st[len-2].first;
                
                double s1=(stsec1 - stsec2)/(stfir1 - stfir2);

                double vecfir,vecsec;
                vecfir=(double)vec[i].first;
                vecsec=(double)vec[i].second;

                double s2=(vecsec - stsec1)/(vecfir - stfir1);
                if(s1 <= s2)
                {
                    st.pop_back();
                    len--;
                }
                else
                    break;
            }
            st.pb(vec[i]);
            len++;
            res=max(res,st[len-1].first-st[len-2].first);
        }
        cout<<res<<endl;
    }
}