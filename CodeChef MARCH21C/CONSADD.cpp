#include<bits/stdc++.h>
using namespace std;
#define int long long int
int a[1000][1000];
int b[1000][1000];

void inputA(int r,int c,int i,int j)
{
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
}

void inputB(int r,int c,int i,int j)
{
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin>>b[i][j];
		}
	}
}

bool ans(int r,int c)
{
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j] != b[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,r,c,x;
		cin>>r>>c>>x;
		//int a[1001][1001],b[1001][1001];

		

		inputA(r,c,i,j);
		inputB(r,c,i,j);

		if(r<x and c<x)
		{
			if(ans(r,c))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}

		else if(r<x)
		{
			for(i=0;i<r;i++){
				for(j=0;j<=(c-x);j++){
					if(a[i][j] == b[i][j])
					{
						continue;
					}
					else
					{
						int diff=b[i][j]-a[i][j];
						a[i][j] += diff;
						int k=1;
						while(k<x)
						{
							a[i][j+k] +=diff;
							k++;
						}
					}
				}
			}
			if(ans(r,c))
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}

		else if(c<x)
		{
			for(i=0;i<c;i++)
			{
				for(j=0;j<=(r-x);j++)
				{
					if(a[j][i] == b[j][i])
					{
						continue;
					}
					else
					{
						int diff=b[j][i]-a[j][i];
						a[j][i] += diff;
						int k=1;
						while(k<x)
						{
							a[j+k][i] += diff;
							k++;
						}
					}
				}
			}

			if(ans(r,c))
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}

		else if(c>=x and r>=x)
		{
			for(i=0;i<r;i++){
				for(j=0;j<=(c-x);j++){
					if(a[i][j] == b[i][j])
					{
						continue;
					}
					else
					{
						int diff=b[i][j]-a[i][j];
						a[i][j] += diff;
						int k=1;
						while(k<x)
						{
							a[i][j+k] += diff;
							k++;
						}
					}
				}
			}

			for(i=0;i<c;i++)
			{
				for(j=0;j<=(r-x);j++)
				{
					if(a[j][i] == b[j][i])
					{
						continue;
					}
					else
					{
						int diff=b[j][i]-a[j][i];
						a[j][i] += diff;
						int k=1;
						while(k<x)
						{
							a[j+k][i] += diff;
							k++;
						}
					}
				}
			}
			if(ans(r,c))
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
}

