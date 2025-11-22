class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto num:nums){
            int k=(num - (num/3)*3);
            ans+=min(k,3-k);
        }
        return ans;
    }
};