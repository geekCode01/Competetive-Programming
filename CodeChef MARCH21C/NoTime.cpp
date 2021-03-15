#include<bits/stdc++.h>
using namespace std;
bool check(int n,int need_hrs,int actual_hrs,int t[])
{
	int res=0;
	for(int i=0;i<n;i++){
		if(actual_hrs+t[i] == need_hrs)
            return true;
	}
	return false;
}

int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("c1.txt","r",stdin);
	// 	freopen("c1o.txt","w",stdout);
	// #endif
	int t[100000];
	int n,need_hrs,actual_hrs;
	cin>>n;
	cin>>need_hrs>>actual_hrs;
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
	}

	if(check(n,need_hrs,actual_hrs,t)?cout<<"YES"<<endl:cout<<"NO"<<endl);
}