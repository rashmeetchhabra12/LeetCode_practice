class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int target = total_sum % p;
        if (target == 0) return 0; // No subarray needs to be removed if total_sum is already divisible by p
        
        unordered_map<int, int> prev_mod; // Store (prefix_sum % p) -> index
        prev_mod[0] = -1; // Initialize to handle cases where the subarray starts from index 0
        
        long long  curr_sum = 0;
        int ans = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i];
            int mod = curr_sum % p;
            
            // Check if we have seen a prefix sum that gives us the required subarray
            int needed_mod = (mod - target + p) % p;
            
            if (prev_mod.find(needed_mod) != prev_mod.end()) {
                ans = min(ans, i - prev_mod[needed_mod]);
            }
            
            // Update the map with the current modulo and index
            prev_mod[mod] = i;
        }
        
        return ans == nums.size() ? -1 : ans;
    }
};