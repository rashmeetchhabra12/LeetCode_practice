class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
       vector<int> ans;

       for (int i = 0; i < n; ++i) {
            int idx = nums[i] % n; // original value
            nums[idx] += n;        // mark visit by adding n
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] / n >= 2)  // value added twice → duplicate
                ans.push_back(i);
        }
        return ans;
    }
};