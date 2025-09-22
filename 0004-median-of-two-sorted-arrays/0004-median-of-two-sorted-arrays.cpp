class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0; int j=0;
        int m=nums1.size(); int n=nums2.size();
        vector<int>merged;
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else{
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            merged.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            merged.push_back(nums2[j]);
            j++;
        }
        double ans;
        if((m+n)%2){
            ans=double(merged[(m+n)/2]);
        }
        else{
            ans=(double(merged[(m+n)/2-1])+double(merged[(m+n)/2]))/2;
        }
        return ans;
    }
};