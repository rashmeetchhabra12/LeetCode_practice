class Solution {
public:
    static const int MOD = 1000000007;
    
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 0), prefix_sum(n + 1, 0);
        dp[0] = 1;
        prefix_sum[0] = 1;  //  0 se har index tak ka prefix no. of partitions

        deque<int> dq_max, dq_min;
        int left = 0;

        for (int i = 1; i <= n; i++) {
            while (!dq_max.empty() && nums[dq_max.back()] <= nums[i - 1])
                dq_max.pop_back();
            dq_max.push_back(i - 1);

            while (!dq_min.empty() && nums[dq_min.back()] >= nums[i - 1])
                dq_min.pop_back();
            dq_min.push_back(i - 1);

            while (!dq_max.empty() && !dq_min.empty() &&
                   nums[dq_max.front()] - nums[dq_min.front()] > k) {
                if (dq_max.front() == left)
                    dq_max.pop_front();
                if (dq_min.front() == left)
                    dq_min.pop_front();
                left++;
            }
            int sum_range = prefix_sum[i - 1];  // sum of parts in this range
            if (left > 0) {
                sum_range = (sum_range - prefix_sum[left - 1] + MOD) % MOD;
            }
            dp[i] = sum_range;
            prefix_sum[i] = (prefix_sum[i - 1] + dp[i]) % MOD;
        }

        return dp[n];
    }
};