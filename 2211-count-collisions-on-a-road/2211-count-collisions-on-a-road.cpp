class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int i=0;  int j=n-1;
        while(i<n && directions[i]=='L') i++;
        while(j>=0 && directions[j]=='R') j--;
        int col=0;

        if(i>j) return 0;

        for(int k=i;k<=j;k++){
            if(directions[k]!='S') col++;
        }
        return col;
    }
};