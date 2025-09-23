class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        for(auto ch:s){
            v1[ch-'a']++;
        }
        for(auto ch:t){
            v2[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};