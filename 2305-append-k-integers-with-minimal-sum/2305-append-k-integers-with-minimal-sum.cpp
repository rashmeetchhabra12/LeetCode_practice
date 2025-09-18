class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>vec;
        vec.push_back(0);
        for(auto s:st) vec.push_back(s);
        sort(vec.begin(),vec.end());
        vec.push_back(INT_MAX);
        long long sum=0;
        int n=vec.size();
        for(int i=1;i<n;i++){
            if(k<=0) return sum;

            int diff=vec[i]-vec[i-1]-1;
            int x=vec[i-1]; int y=vec[i]-1;
            if(k>=diff){
                sum+= ( ((long long)y*(y+1))/2 - ((long long)x*(x+1))/2 );
                k-=diff;
            }
            else{
                int p=vec[i-1]+1;
                while(k>0){
                    sum+=p;
                    k--;
                    p++;
                }
            }
        }
        return sum;
    }
};