class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs.size();
        int m = strs[0].size();

        for (int j = 0; j < m; j++) {
            for (int i = 0; i + 1 < n; i++) {
                if (strs[i][j] > strs[i+1][j]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};