class Solution {
public: 
    int mod=1000000007;
    int recur(int i,int j,int rem,vector<vector<int>>& grid, int k,vector<vector<vector<int>>>&dp){
        int m=grid.size(); int n=grid[0].size();

        if(dp[i][j][rem]!=-1) return dp[i][j][rem];

        if(i==m-1 && j==n-1){
            if(rem%k==0) return dp[i][j][rem]= 1;
            return dp[i][j][rem]=0;
        }
        int down=0,right=0;
        if(i<m-1){
            down=recur(i+1,j,(rem+grid[i+1][j])%k,grid,k,dp);
        }
        if(j<n-1){
            right=recur(i,j+1,(rem+grid[i][j+1])%k,grid,k,dp);
        }
        return dp[i][j][rem]=(down+right)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(); int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return recur(0,0,grid[0][0]%k,grid,k,dp);
    }
};