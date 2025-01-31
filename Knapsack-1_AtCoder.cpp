//https://atcoder.jp/contests/dp/tasks/dp_d

#include<bits/stdc++.h>
using namespace std;
long long DP[(long long)1e5+1][101]={0};
long long solve(vector<long long>&wt,vector<long long>&pro,long long w,long long idx){
	if(idx>=wt.size()) return 0;
	if(DP[w][idx]!=0) return DP[w][idx];
	long long pick=0;
	if(wt[idx]<=w){ 
		pick=pro[idx]+solve(wt,pro,w-wt[idx],idx+1);
	}
	long long unpick=solve(wt,pro,w,idx+1);
	return DP[w][idx]=max(pick,unpick);
}
int main(){
	long long n,w;
	cin>>n>>w;
	vector<long long>wt(n);
	vector<long long>pro(n);
	for(int i=0;i<n;i++) cin>>wt[i]>>pro[i];
	long long res=solve(wt,pro,w,0);
	cout<<res;
}
