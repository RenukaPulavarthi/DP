// https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int cal(string &s1,string &s2,int i,int j,vector<vector<int>>&DP){
        if(j>=s2.length()){
            return (s1.length()-i);
        }
        if(i>=s1.length()){
            return (s2.length()-j);
        }
        if(DP[i][j]!=-1) return DP[i][j];
        if(s1[i]==s2[j]){
            return DP[i][j]=cal(s1,s2,i+1,j+1,DP);
            // return cal(s1,s2,i+1,j+1);
        }
        return DP[i][j]=1+min(cal(s1,s2,i+1,j+1,DP),min(cal(s1,s2,i+1,j,DP),cal(s1,s2,i,j+1,DP)));
        // return 1+min(cal(s1,s2,i+1,j+1),min(cal(s1,s2,i+1,j),cal(s1,s2,i,j+1)));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>DP(501,vector<int>(501,-1));
        return cal(word1,word2,0,0,DP);
    }
};
