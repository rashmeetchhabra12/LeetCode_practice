class Solution {
public://  1*1+3*1;    current_ones*
    int maxOperations(string s) {
        int n=s.size();
        vector<int>vec;
        int curr=0;
        int i=0;
        while(i<n){
            while(s[i]=='1'){
                curr++;
                i++;
            }
            if(curr) vec.push_back(curr);
            curr=0;
            while(s[i]=='0') i++;
        }
        if(vec.size()==0) return 0;
        if(vec.size()==1){
            if(s[n-1]=='0') return vec[0];
        }
        
        int sum=0; int ans=0;
        if(s[n-1]=='0'){
            for(int i=0;i<vec.size();i++){
            sum+=vec[i];
            ans+=(sum);
            }
        
        }
        else{
        for(int i=0;i<vec.size()-1;i++){
            sum+=vec[i];
            ans+=(sum);
        }
        }
        return ans;
    }
};