//https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;
int DP[(long long)1e5+1]={-1};
int solve(vector<int>&arr,int n,int idx){
	if(idx>=n-1){
		return 0;
	}
	if(DP[idx]!=-1) return DP[idx];
	int first=INT_MAX,second=INT_MAX;
	if(idx+1<=n-1){
		first=abs(arr[idx]-arr[idx+1])+solve(arr,n,idx+1);
	}
	if(idx+2<=n-1){
		second=abs(arr[idx]-arr[idx+2])+solve(arr,n,idx+2);
	}
	return DP[idx]=min(first,second);
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n); 
	for(int i=0;i<n;i++) cin>>arr[i];
	memset(DP,-1,sizeof(DP));
	int res=solve(arr,n,0);
	cout<<res;
}
