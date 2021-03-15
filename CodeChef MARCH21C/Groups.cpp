#include<bits/stdc++.h>
using namespace std;
int solve(string s,int n)
{
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')
        {
            count++;
            while(s[i]=='1')
            {
                i++;
            }
        }
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        cout<<solve(s,n)<<endl;
    }
}