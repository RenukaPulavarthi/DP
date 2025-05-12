//https://leetcode.com/problems/target-sum/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    int solve(vector<int>&nums,int t,int idx,int s,map<pair<int,int>,int>&dp){
        if(idx==nums.size()){
            if(s==t) return 1;
            else return 0;
        }
        if(dp.find({idx,s})!=dp.end()) return dp[{idx,s}];
        dp[{idx,s}]=solve(nums,t,idx+1,s+nums[idx],dp)+solve(nums,t,idx+1,s-nums[idx],dp);
        return dp[{idx,s}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>dp;
        return solve(nums,target,0,0,dp);
    }
};
