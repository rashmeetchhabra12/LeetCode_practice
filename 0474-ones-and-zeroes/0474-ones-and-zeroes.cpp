class Solution {
public:
    int recur(vector<string>& strs, int m, int n,int zeroes,int ones,int idx,vector<vector<vector<int>>>&dp){

        int sze=strs.size();
        if(idx==sze) return dp[idx][zeroes][ones]=0;

        if(dp[idx][zeroes][ones]!=-1) return dp[idx][zeroes][ones];

        int pick=0;
        int dont_pick=recur(strs,m,n,zeroes,ones,idx+1,dp);

        int curr_ones=0; int curr_zeroes=0;
        for(auto ch:strs[idx]){
            if(ch=='0') curr_zeroes++;
            else curr_ones++;
        }
        if(zeroes+curr_zeroes<=m && ones+curr_ones<=n){
            pick=recur(strs,m,n,zeroes+curr_zeroes,ones+curr_ones,idx+1,dp)+1;
        }
        return dp[idx][zeroes][ones]= max(pick,dont_pick);

    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sze=strs.size();
        
        vector<vector<vector<int>>>dp(sze+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return recur(strs,m,n,0,0,0,dp);
    
    }
};