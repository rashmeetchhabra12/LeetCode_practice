class Solution {
public:
bool ismagic(int i,int j,vector<vector<int>>grid){
    set<int>st;
    for(int p=i;p<=i+2;p++){
        int sum=0;
        for(int q=j;q<=j+2;q++){
           sum+=grid[p][q];
           if(grid[p][q]==0) return false;
           st.insert(grid[p][q]);
        }
        if(sum!=15) return false;
    }
    if(st.size()!=9) return false;
    for(int p=j;p<=j+2;p++){
        int sum=0;
        for(int q=i;q<=i+2;q++){
           sum+=grid[q][p];
        }
        if(sum!=15) return false;
    }
    int sum1=0; int sum2=0;
    if((grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2])!=15) return false;
    if((grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2])!=15) return false;

    return true;

}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        if(n<3 || m<3) return 0;
        int ans=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
               if(ismagic(i,j,grid)) ans++;
            }
        }
        return ans;
    }
};