class Solution {
public:      //  arr[i]-i-1 batata hai ki kitne miss ho gye yaha tak 
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0; int high=n-1;
    
        while(low<=high){ 
            int mid=low+(high-low)/2;
            
            int missing_at_mid=arr[mid]-mid-1;
            
            if(k>missing_at_mid){
                low=mid+1;
            }
            else{
                 high=mid-1;
            }
        }
        return high+1+k;
    }
};