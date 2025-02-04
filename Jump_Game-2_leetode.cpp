//https://leetcode.com/problems/jump-game-ii/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    long long DP[10001];
    long long solve(vector<int>&nums,int idx){
        if(idx>=nums.size()-1) return 0;
        if(DP[idx]!=-1) return DP[idx];
        long long ans=INT_MAX;
        for(int i=idx+1;i<nums.size() && i<=idx+nums[idx];i++){
            ans=min(ans,1+solve(nums,i));
        }
        return DP[idx]=ans;
    }
    int jump(vector<int>& nums) {
        memset(DP,-1,sizeof(DP));
        return solve(nums,0);
    }
};
