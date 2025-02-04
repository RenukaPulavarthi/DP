//https://leetcode.com/problems/house-robber/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    long long DP[101];
    long long solve(vector<int>&nums,int idx){
        if(idx>=nums.size()) return 0;
        if(DP[idx]!=-1) return DP[idx];
        long long ans=0;
        for(int i=idx+2;i<nums.size();i++){
            ans=max(ans,solve(nums,i));
        }
        return DP[idx]=ans+nums[idx];
    }
    int rob(vector<int>& nums) {
        memset(DP,-1,sizeof(DP));
        return max(solve(nums,0),solve(nums,1));
    }
};
