//https://atcoder.jp/contests/dp/tasks/dp_e

#include<bits/stdc++.h>
using namespace std;
int DP[(long long)1e5+1][101];
long long solve(long long cost,vector<long long>&wt,vector<long long>&val,long long idx,long long n){
    
	if(idx>=n){
		if(cost==0) return 0;
		return INT_MAX;
	}
	if(DP[cost][idx]!=-1) return DP[cost][idx];
	long long pick=INT_MAX,unpick=INT_MAX;
	if(cost>=val[idx]) pick=wt[idx]+solve(cost-val[idx],wt,val,idx+1,n);
	unpick=solve(cost,wt,val,idx+1,n);
	return DP[cost][idx]=min(pick,unpick);
	
}
int main(){
	long long n,w;
	cin>>n>>w;
	vector<long long>wt(n);
	vector<long long>pro(n);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>wt[i]>>pro[i];
		sum+=pro[i];
	}
	long long res=INT_MAX;
	memset(DP,-1,sizeof(DP));
	for(long long i=sum;i>=0;i--){
		long long min_w=solve(i,wt,pro,0,n);
		if(min_w<=w){
			res=i;
			break;
		}
	}
	cout<<res;
	
}
