class Solution {
public:
    bool rotateString(string s, string goal) {
        string st=s+s;

        int n=s.size();
        for(int i=0;i<n;i++){
            string sub=st.substr(i,n);
            if(sub==goal) return true;
        }
        return false;
    }
};