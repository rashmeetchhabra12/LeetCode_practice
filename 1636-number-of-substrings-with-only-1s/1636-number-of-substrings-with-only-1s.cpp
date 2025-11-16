class Solution {
public:  // n*(n+1)/2
    int mod=1000000007;
    int numSub(string s) {
        int n=s.size();
        int i=0; long long ans=0; long long curr=0;
        while(i<n){
            while(s[i]=='1'){
                curr++;
                i++;
            }
            if(curr){ 
                long long k=((curr*(curr+1))/2)%mod;
                ans+=k;
            }
            curr=0;

            while(s[i]=='0') i++;
        }
        return (int)ans%mod;
    }
};