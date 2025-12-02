class Solution {
public: 
    int mod=1000000007;
    // nC2*mC2 = (n(n-1)/2)*(m*(m-1)/2)
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for(auto poi:points){
            mp[poi[1]]++;
        }
        vector<long long>vec;
        for(auto m:mp){
            long long b=m.second;
            vec.push_back((long long)(b*(b-1)/2));
        }
        int n=vec.size();
        vector<long long>pref(n,0);
        long long sum=0; long long ans=0;

        for(int i=0;i<n;i++){
            pref[i]=sum;
            sum+=(vec[i])%mod;
            sum=sum%mod;

            ans+=(pref[i]*vec[i])%mod;
            ans=ans%mod;
        }
        
        
        return ans;
        
    }
};