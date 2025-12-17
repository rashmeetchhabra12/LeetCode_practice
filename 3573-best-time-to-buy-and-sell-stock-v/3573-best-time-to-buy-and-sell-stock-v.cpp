class Solution {
public:
    long long recur(int idx,vector<int>prices,int k,int trans,int last_idx,vector<vector<int>>&dp){
        int n=prices.size();
        if(idx==n-1){
            if(last_idx!=n && trans<k) return dp[idx][last_idx]=abs(prices[idx]-prices[last_idx]);
            else return dp[idx][last_idx]= 0;
        }
        if(dp[idx][last_idx]!=-1) return dp[idx][last_idx];
        if(last_idx==n){
            long long buy=0; long long dont_buy=0;
            buy=recur(idx+1,prices,k,trans,idx,dp);

            dont_buy=recur(idx+1,prices,k,trans,n,dp);
            return dp[idx][last_idx]=max(buy,dont_buy);
        }
        long long sell=0; long long dont_sell=0;
        if(trans<k) sell=abs(prices[idx]-prices[last_idx])+recur(idx+1,prices,k,trans+1,n,dp);

        dont_sell=recur(idx+1,prices,k,trans,last_idx,dp);
        return dp[idx][last_idx]=max(sell,dont_sell);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        // int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return recur(0,prices,k,0,n,dp);

        int n = prices.size();
        const long long NEG = -1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;  
        for (int price : prices) {
            vector<vector<long long>> newdp = dp;
            for (int t = 0; t <= k; t++) {
                if (dp[t][0] != NEG)
                    newdp[t][1] = max(newdp[t][1], dp[t][0] - price);
                if (dp[t][0] != NEG)
                    newdp[t][2] = max(newdp[t][2], dp[t][0] + price);
                if (t < k) {
                    if (dp[t][1] != NEG)
                        newdp[t + 1][0] = max(newdp[t + 1][0], dp[t][1] + price);
                    if (dp[t][2] != NEG)
                        newdp[t + 1][0] = max(newdp[t + 1][0], dp[t][2] - price);
                }
            }
            dp = newdp;
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++)
            ans = max(ans, dp[t][0]);

        return ans;
    }
};