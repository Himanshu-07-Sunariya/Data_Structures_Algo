class Solution {
public:
    int helper(int cr,int cc,vector<vector<int>>& grid){
        //+ve base case
        if(cr==grid.size()-1 && cc==grid[0].size()-1) return grid[cr][cc];

        // -ve base case
        if(cr>grid.size()-1 || cc>grid[0].size()-1) return 999999;

        // recursive call
        int down=helper(cr+1,cc,grid)+grid[cr][cc];
        int right=helper(cr,cc+1,grid)+grid[cr][cc];

        return min(down,right);
    }

    int helper_TD(int cr,int cc,vector<vector<int>>& grid,vector<vector<int>> &dp){
        //+ve base case
        if(cr==grid.size()-1 && cc==grid[0].size()-1) return grid[cr][cc];

        // -ve base case
        if(cr>grid.size()-1 || cc>grid[0].size()-1) return 999999;

        // dp step2
        if(dp[cr][cc]!=-1) return dp[cr][cc];
        // recursive call
        int down=helper_TD(cr+1,cc,grid,dp)+grid[cr][cc];
        int right=helper_TD(cr,cc+1,grid,dp)+grid[cr][cc];

        return min(down,right);
    }

    int helper_BU(int cr,int cc,vector<vector<int>> &grid){
        // 1.Create dp array
        vector<vector<int>> dp(grid.size(), vector <int> (grid[0].size(),-1));

        // 2. base case fill
        // last row fill
        int sum1=0;
        for(int c=dp[0].size()-1; c>=0; c--){
            sum1+=grid[grid.size()-1][c];
            dp[grid.size()-1][c]=sum1;
        }

        // last col fill
        int sum2=0;
        for(int r=dp.size()-1; r>=0; r--){
            sum2+=grid[r][grid[0].size()-1];
            dp[r][grid[0].size()-1]=sum2;
        }

        // cell meaning:- is cell se hume last cell pr pahunchne k liye min sum path konsa h aur
        // min sum kya hoga wo store
        for(int cr=grid.size()-2; cr>=0; cr--){
            for(int cc=grid[0].size()-2; cc>=0; cc--){
                int down=dp[cr+1][cc]+grid[cr][cc];
                int right=dp[cr][cc+1]+grid[cr][cc];

                dp[cr][cc]=min(down,right);
            }
        }

        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size(), vector <int> (grid[0].size(),-1));
        // return helper_TD(0,0,grid,dp);
        return helper_BU(0,0,grid);
    }
};