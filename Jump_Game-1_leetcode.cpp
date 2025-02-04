//https://leetcode.com/problems/jump-game/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    long long DP[10001];
    bool solve(vector<int>&nums,int idx){
        if(idx>=nums.size()-1) return true;
        if(nums[idx]==0) return false;
        if(DP[idx]!=0){
            if(DP[idx]==1) return true;
            return false;
        }
        bool ans=false;
        for(int i=idx+1;i<nums.size() && i<=idx+nums[idx];i++){
            ans=(ans||solve(nums,i));
            // cout<<nums[idx]<<' '<<nums[i]<<endl;
        }
        if(ans==true) DP[idx]=1;
        else DP[idx]=-1;
        return ans;
    }
    bool canJump(vector<int>& nums) {
        memset(DP,0,sizeof(DP));
        return solve(nums,0);
    }
};
