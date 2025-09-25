class Solution {
public:
    // int recur(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp){
    //     int n=triangle.size();
    //     if(i==n-1) return dp[i][j]=triangle[i][j];

    //     if(dp[i][j]!=INT_MIN) return dp[i][j];

    //     int curr=recur(triangle,i+1,j,dp)+triangle[i][j];

    //     int next=recur(triangle,i+1,j+1,dp)+triangle[i][j];
    //     return dp[i][j]=min(curr,next);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(); int m=triangle[n-1].size();
    //    vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
 
        vector<int>curr(m); vector<int>prev(m,INT_MIN);

        for(int j=0;j<m;j++) curr[j]=triangle[n-1][j];

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                 int a=curr[j]+triangle[i][j];
                 int b=curr[j+1]+triangle[i][j];
                 prev[j]=min(a,b);
            }
            curr=prev;
        }

        return curr[0];
    }
};