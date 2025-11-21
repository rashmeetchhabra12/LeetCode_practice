class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<pair<int,int>>vec(26,{-1,-1});
        
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(vec[idx].first==-1){
                vec[idx].first=i;
                vec[idx].second=i;
            }
            else{
                vec[idx].second=i;
            }
        }
        int ans=0;
        for(auto v:vec){
            if(v.first==v.second) continue;

            unordered_set<char>st;
            for(int i=v.first+1;i<v.second;i++){
                st.insert(s[i]);
            }
            ans+=st.size();
        }
        return ans;
    }
};