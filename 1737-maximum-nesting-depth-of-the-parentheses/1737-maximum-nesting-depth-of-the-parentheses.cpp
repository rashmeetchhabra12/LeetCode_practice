class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        stack<int>st;
        int size=0;
        for(auto ch:s){
            if(ch=='('){
                st.push(ch);
                size++;
                ans=max(ans,size);
            }
            else if(ch==')'){
                st.pop();
                size--;
            } 
            else continue;
        }
        return ans;
    }
};