class Solution {
public:
    int helper(int cr,int cc,vector<vector<int>>& triangle){
        // +ve base case
        if(cr==triangle.size()-1) return triangle[cr][cc];

        // -ve base case:- not exist
        
        // recursive calls
        int down_i=helper(cr+1,cc,triangle)+triangle[cr][cc];
        int down_iplus1=helper(cr+1,cc+1,triangle)+triangle[cr][cc];

        return min(down_i,down_iplus1);
    }

    int helper_TD(int cr,int cc,vector<vector<int>>& triangle,vector<vector<int>> &dp){
        // +ve base case
        if(cr==triangle.size()-1) return triangle[cr][cc];

        // -ve base case:- not exist

        // dp step2
        if(dp[cr][cc]!=-1) return dp[cr][cc];

        // recursive calls
        int down_i=helper_TD(cr+1,cc,triangle,dp)+triangle[cr][cc];
        int down_iplus1=helper_TD(cr+1,cc+1,triangle,dp)+triangle[cr][cc];

        dp[cr][cc]=min(down_i,down_iplus1);
        return dp[cr][cc];
    }

    int helper_BU(vector<vector<int>> &triangle){
        // 1. create dp array
        int col=triangle[triangle.size()-1].size();
        vector<vector<int>> dp(triangle.size(), vector <int> (col,-1));

        // 2. base case fill
        for(int c=col-1; c>=0; c--){
            dp[triangle.size()-1][c]=triangle[triangle.size()-1][c];
        }

        // 3.cell meaning:- storing the min value possible by moving i or i+1

        // 4. iterative work
        // int i=0;
        for(int cr=triangle.size()-2; cr>=0; cr--){
            for(int cc=0; cc<=cr; cc++){
                
                int down_i=dp[cr+1][cc]+triangle[cr][cc];
                int down_iplus1=dp[cr+1][cc+1]+triangle[cr][cc];

                dp[cr][cc]=min(down_i,down_iplus1);
            }
        }

        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int i=0;
        int j=0;
        // return helper(i,j,triangle);
        // last col size
        int col=triangle[triangle.size()-1].size();
        // vector<vector<int>> dp(triangle.size(), vector <int> (col,-1));
        return helper_BU(triangle);
    }
};