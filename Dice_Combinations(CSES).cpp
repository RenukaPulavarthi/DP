//https://cses.fi/problemset/task/1633

#include<bits/stdc++.h>
using namespace std;
long long DP[(long long)1e6+1];
long long solve(long long n){
	if(n<0) return 0;
	if(n==0) return 1;
	if(DP[n]!=-1) return DP[n];
	long long mod=1e9+7;
	long long ans=solve(n-1)%mod;
	ans+=solve(n-2)%mod;
	ans+=solve(n-3)%mod;
	ans+=solve(n-4)%mod;
	ans+=solve(n-5)%mod;
	ans+=solve(n-6)%mod;
	return DP[n]=ans%mod;
}
int main(){
	long long n;
	cin>>n;
	memset(DP,-1,sizeof(DP));
	long long res=solve(n);
	cout<<res;
}
