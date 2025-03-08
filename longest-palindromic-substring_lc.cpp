// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        int i=0,j=0;
        for(j=0;j<s.size();j++){
            int k=i,l=j;
            while(k<s.size() && l<s.size()){
                if(k==l) dp[k][l]=1;
                else if(k+1==l && s[k]==s[l]) dp[k][l]=1; 
                else if(s[k]==s[l] && dp[k+1][l-1]==1) dp[k][l]=1;
                k++;
                l++;
            }
        }
        for(i=s.size()-1;i>=0;i--){
            int k=0,l=i;
            while(k<s.size() && l<s.size()){
                if(dp[k][l]==1) return s.substr(k,l-k+1);
                k++;
                l++;
            }
        }
        return "";
    }
};
