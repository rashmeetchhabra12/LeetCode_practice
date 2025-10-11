class Solution {
public:
    // int recur(vector<int>& energy, int i,int k,bool took,int n,vector<int>&dp){
    //     if(i==n-1 && !took) return dp[i]=energy[i];
    //     if(i>=n) return dp[i]= 0;
         
    //     if(took) return energy[i]+recur(energy,i+k,k,took,n);

    //     return max(energy[i]+recur(energy,i+k,k,true,n),recur(energy,i+1,k,took,n));
    // }
    int maximumEnergy(vector<int>& energy, int k) {
        bool took=false;
        int n=energy.size();
    
        vector<long long> dp(n);
        long long ans = LLONG_MIN;

    for (int i = n - 1; i >= 0; --i) {
        if (i + k < n) dp[i] = energy[i] + dp[i + k];
        else dp[i] = energy[i];
        ans = max(ans, dp[i]);
    }
    return (int)ans;
    }
};