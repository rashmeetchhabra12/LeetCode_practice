class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int i=0; int j=0;
        int n=prices.size();
        long long ans=0;
        while(j<n){
            while(j+1<n && prices[j+1]==prices[j]-1) j++;
            
            long long k=j-i+1;
            long long l=k*(k+1);
            l/=2;
            ans+=l;
            i=j+1; j=i;
        }
        return ans;
    }
};