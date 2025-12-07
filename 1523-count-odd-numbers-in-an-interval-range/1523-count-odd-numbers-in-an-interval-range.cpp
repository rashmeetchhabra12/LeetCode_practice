class Solution {
public:
    int countOdds(int low, int high) {
        int l_odd=low; int h_odd=high;
        if(low%2==0) l_odd++;
        if(high%2==0) h_odd--;

        return (h_odd-l_odd)/2+1;
    }
};