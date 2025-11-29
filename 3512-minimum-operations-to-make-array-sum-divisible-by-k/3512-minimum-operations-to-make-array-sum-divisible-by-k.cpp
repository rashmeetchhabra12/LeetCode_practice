class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(auto num:nums) sum+=num;

        int des=(sum/k)*k;
        return sum-des;
    }
};