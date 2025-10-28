class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int>v1(n,0); vector<int>v2(n,0);

        int sum=0;
        for(int i=0;i<n;i++){
            v1[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            v2[i]=sum;
            sum+=nums[i];
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(v1[i]==v2[i]) cnt+=2;
                if(abs(v1[i]-v2[i])==1) cnt+=1;
            }
            
        }
        return cnt;

    }
};