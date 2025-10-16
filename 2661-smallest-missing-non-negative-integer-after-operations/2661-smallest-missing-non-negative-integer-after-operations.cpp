class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        vector<int>freq(value,0);
       for (int x : nums) {
            int r = ((x % value) + value) % value;
            freq[r]++;
        }
        int m = INT_MAX;
        for (int i = 0; i < value; ++i) m = min(m, freq[i]);

        for (int i = 0; i < value; ++i) {
            freq[i] -= m;
            if (freq[i] == 0) return (int)(m * value + i);
        }
        return (int)((m + 1) * value);
    }
};