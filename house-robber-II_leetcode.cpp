//https://leetcode.com/problems/house-robber-ii/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    int solve(vector<int>&nums,int idx,int n,vector<vector<int>>&dp){
        if(idx>=n) return 0;
        if(dp[idx][n]!=-1) return dp[idx][n];
        int ans=0;
        for(int i=idx+2;i<n;i++){
            ans=max(ans,solve(nums,i,n,dp));
        }
        return dp[idx][n]=ans+nums[idx];
    }
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(101,vector<int>(101,-1));
        if(nums.size()==1) return nums[0];
        int start=max(solve(nums,0,nums.size()-1,dp),solve(nums,1,nums.size()-1,dp));
        int end=max(solve(nums,1,nums.size(),dp),solve(nums,2,nums.size(),dp));
        return max(start,end);
    }
};
