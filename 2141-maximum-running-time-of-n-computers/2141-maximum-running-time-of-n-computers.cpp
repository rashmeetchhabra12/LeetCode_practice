class Solution {
public: 
    // possible batayega ki itne minute tak battery chalegi ke nahi
    bool possible(int n,vector<int>& batteries,long long minutes){
        long long sum=0;
        for(auto bat:batteries) sum+=min(1LL*bat,minutes);

         if(sum>=(long long)n*minutes) return true;
         return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        // minutes ki range --> 1 to total_sum
        // given range me se maximum nikalna hai --> Binary Search

        long long sum=0;
        for(auto bat:batteries) sum+=bat;
        long long low=1; long long high=sum;
        long long ans=1;
        
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(possible(n,batteries,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};