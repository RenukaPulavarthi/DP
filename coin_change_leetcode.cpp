//https://leetcode.com/problems/coin-change/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    long long DP[13][10001];
    long long solve(vector<int>&coins,int sum,int idx){
        if(sum==0){
            return 0;
        }
        if(sum<0 || idx>=coins.size()){
            return INT_MAX;
        }
        if(DP[idx][sum]!=-1) return DP[idx][sum];
        long long pick=INT_MAX, unpick=INT_MAX;
        pick=1+solve(coins,sum-coins[idx],idx);
        unpick=solve(coins,sum,idx+1);
        return DP[idx][sum]=min(pick,unpick);
    }
    int coinChange(vector<int>& coins, int sum) {
        sort(coins.rbegin(),coins.rend());
        memset(DP,-1,sizeof(DP));
        long long res=solve(coins,sum,0);
        if(res<INT_MAX)
            return res;
        else
            return -1;
    }
};
