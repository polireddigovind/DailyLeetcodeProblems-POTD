class Solution {
public:
    int mod=1e9+7;
    int dp[501][501];
    int solve(int i,int j,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        if(i==n-1&&j==m-1)return 1;
        if(i<0||i==n||j<0||j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=0,left=0;
        int l=i,r=j+1,d=1;
        while(l>=0&&l<n&&r>=0&&r<m&&grid[l][r]==1){
            if(d==1)l++;
            else r++;
            d=1-d;
        }
        right=solve(l,r,grid);
        l=i+1,r=j,d=0;
        while(l>=0&&l<n&&r>=0&&r<m&&grid[l][r]==1){
            if(d==1)l++;
            else r++;
            d=1-d;
        }
        left=solve(l,r,grid);
        return dp[i][j]=(right+left)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};