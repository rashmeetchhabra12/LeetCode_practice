class Solution {
public:
    int smallestNumber(int n) {
        int k=0;
        while(n>0){
            k++;
            n/=2;
        }
        return pow(2,k)-1;
    }
};