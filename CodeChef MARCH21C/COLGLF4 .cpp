#include<bits/stdc++.h>
using namespace std;
#define int long long int

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

int solve(int n,int e,int h,int A,int B,int C)
{
	if(n<=0)
		return 0;
	int res=1e15;

	if(n<=e and n<=h)
	{
		res=min(res,n*C);
	}

	if(3*n <= h)
	{
		res=min(res,n*B);
	}

	if(2*n <= e)
	{
		res=min(res,n*A);
	}

	if(((h-n)/2 >=1) and ((h-n)/2 >=n-e))
	{
		if(B-C < 0)
		{
			int temp=min(n-1,(h-n)/2);
			res=min(res,(B-C)*temp+ n*C);
		}
		else
		{
			int temp=max(1,n-e);
			res=min(res,(B-C)*temp+n*C);
		}
	}

	if(e-n >=1 and e-n >= n-h)
	{
		if(A-C < 0)
		{
			int temp=min(n-1,e-n);
			res=min(res,(A-C)*temp+n*C);
		}
		else
		{
			int temp=max(1,n-h);
			res=min(res,(A-C)*temp + n*C);
		}
	}

	if((e/2 >=1) and (e/2 >= (3*n - h + 2)/3))
	{
		if(A-B < 0)
		{
			int temp=min(n-1,e/2);
			res=min(res,(A-B)*temp+n*B);
		}
		else
		{
			int temp=max(1,(3*n-h+2)/3);
			res=min(res,(A-B)*temp+n*B);
		}
	}

	if((e>=3) and (h >=4) and (n>=3))
	{
		res=min(res,A+B+C+solve(n-3,e-3,h-4,A,B,C));
	}
	return res;
}

signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,e,h,A,B,C;
		cin>>n>>e>>h>>A>>B>>C;
		int res;
		res=solve(n,e,h,A,B,C);

		if(res==1e15)
		{
			cout<<"-1"<<endl;
		}
		
		else
		{
			cout<<res<<endl;
		}	
	}
}