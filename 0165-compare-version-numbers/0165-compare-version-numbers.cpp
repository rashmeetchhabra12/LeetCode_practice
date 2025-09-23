class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(); int m=version2.size();
        int curr1=0; int curr2=0;
        int i=0; int j=0;
        while(i<n || j<m){
            while(i<n && version1[i]!='.'){
                curr1=curr1*10+(version1[i]-'0');
                i++;
            }
            i++;
             while(j<m && version2[j]!='.'){
                curr2=curr2*10+(version2[j]-'0');
                j++;
            }
            j++;
            if(curr1>curr2) return 1;
            else if(curr1<curr2) return -1;
            else{
                curr1=0; curr2=0;
            }
        }
        return 0;
    }
};