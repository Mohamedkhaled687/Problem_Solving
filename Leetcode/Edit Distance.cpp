// link : https://leetcode.com/problems/edit-distance/description/

class Solution {
    int dp[505][505];
    string s1;
    string s2;
public:
    int minDistance(string word1, string word2) {
        memset(dp , -1 , sizeof(dp));
        s1 = word1 , s2 = word2;

        return min_edit(0 , 0);
    }
    
    int min_edit(int idx1 , int idx2){
        if(idx1 == s1.size()){
            return s2.size() - idx2;
        }
        if(idx2 == s2.size())
            return s1.size() - idx1;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        if(s1[idx1] == s2[idx2])
            return min_edit(idx1 + 1 , idx2 + 1);
        
        int insert = 1 + min_edit(idx1 , idx2 + 1);
        int del = 1 + min_edit(idx1 + 1 , idx2);
        int replace = 1 + min_edit(idx1 + 1 , idx2 + 1);

        return dp[idx1][idx2] = min({insert , del , replace});
    }
};
