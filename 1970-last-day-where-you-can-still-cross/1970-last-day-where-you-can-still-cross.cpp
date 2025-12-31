class Solution {
public:
    // yeh to tay hai ki kabhi na kabhi pura 1 ho jayega , maxi(ans)=no. of days,
    // binary search--> agar mid pe bach gya to ans update nhi to high-1

    int cancross(int mid,int row,int col,vector<vector<int>>cells){
        vector<vector<int>>grid(row,vector<int>(col,0));
        for(int i=0;i<mid;i++){
            int x=cells[i][0]-1; int y=cells[i][1]-1;
            grid[x][y]=1;
        }

        queue<pair<int,int>>q;
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i=0;i<col;i++){
            if(grid[0][i]==0){
              q.push({0,i});
              visited[0][i]=1;
            }
        }

        while(!q.empty()){
            int x=q.front().first; int y=q.front().second;
            q.pop();
            if(x==row-1) return true;

            if(x+1<row && !visited[x+1][y] && grid[x+1][y]==0){
                 q.push({x+1,y});
                 visited[x+1][y]=1;
            }
            if(y+1<col && !visited[x][y+1] && grid[x][y+1]==0){
                 q.push({x,y+1});
                  visited[x][y+1]=1;
            }
            if(x-1>=0 && !visited[x-1][y] && grid[x-1][y]==0){
                 q.push({x-1,y}); visited[x-1][y]=1;
            }
            if(y-1>=0 && !visited[x][y-1] && grid[x][y-1]==0){
                 q.push({x,y-1});
                  visited[x][y-1]=1;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
        int low=1; int high=cells.size();  
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(cancross(mid,row,col,cells)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;   
    }
};