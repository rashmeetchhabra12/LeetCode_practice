class Solution {
public:
int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    a = abs(a);
    b = abs(b);
    return (a / gcd(a, b)) * b; 
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(st.empty()){ 
                st.push(nums[i]);
                continue;
            }
            int a=st.top(); int b=nums[i];
            int curr=nums[i]; 
            while (!st.empty() && gcd(st.top(), curr) > 1) {
                curr = lcm(st.top(), curr);
                st.pop();
            }
            st.push(curr);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }  
        reverse(ans.begin(),ans.end());
        return ans;
    }
};