//https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;
int DP[(long long)1e5+1]={-1};
int solve(vector<int>&arr,int &n,int idx,int &k){
	if(idx>=n-1){
		return 0;
	}
	if(DP[idx]!=-1) return DP[idx];
	int ans=INT_MAX;
	for(int i=idx+1;i<=idx+k;i++){
		if(i>n-1){
			break;
		}
		ans=min(ans,abs(arr[idx]-arr[i])+solve(arr,n,i,k));
	}
	
	return DP[idx]=ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n); 
	for(int i=0;i<n;i++) cin>>arr[i];
	memset(DP,-1,sizeof(DP));
	int res=solve(arr,n,0,k);
	cout<<res;
}
