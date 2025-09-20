class Solution {
public: //  min(max)
        // binary search ---> check karenge ki yeh jo sum hai itne mein k part mein array split ho sakta hai ya nahi , make sure karna ahi ki koi sum isse zyada na ho

    int possible(vector<int>& nums,int largest_sum,int k){
        int n=nums.size();
        int split=0;
        int sum=0;

        for(int i=0;i<n;i++){
            if(sum+nums[i]<=largest_sum){
                sum+=nums[i];
            }
            else{
                split++;
                sum=nums[i];
            }
        }
        return split<k; 
    }    
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=nums[0];
        int sum=0;  
        for(auto num:nums){
            sum+=num;
            maxi=max(maxi,num);
        }
        int low=maxi; int high=sum;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(possible(nums,mid,k)){
               high=mid-1;
               ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};