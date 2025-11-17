class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        if(!k) return true;
        int i=0;
        int zeroes=0;
        int mto=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1] && nums[i]) return false;
        }
        while(i<n && !nums[i]) i++;
        while(i<n){
            while(i<n && nums[i]) i++;

            while(i<n && !nums[i]){
                zeroes++;
                i++;
            }
            if(zeroes){
                
                if(i<n && zeroes<k) return false;
            }
            zeroes=0;
        }
        return true;
    }
};