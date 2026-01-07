class Solution {
public:
    int helper_Rec(int cr,int cc,vector<vector<int>> &matrix){
        // +ve base case
        // if(cr==matrix.size()-1){
        //     int c1=INT_MAX;
        //     int c3=INT_MAX;
        //     int c2=matrix[cr][cc];
        //     if(cc-1>=0){
        //         c1=matrix[cr][cc-1];
        //     }

        //     if(cc+1<matrix[0].size()){
        //         c3=matrix[cr][cc+1];
        //     }

        //     return min(c1,min(c2,c3));
        // }

        //CHOICE BAAR BAAR CHOOSE MT KRO LAST RECURSIVE CALL IS JUST... CHOICE IS ALREADY CHOOSED ..
        // -ve base case if exists
        if(cc<0 || cc>matrix[0].size()) return INT_MAX;
        

        // +ve base case
        if(cr==matrix.size()-1){
            return matrix[cr][cc];
        }

        

        // recursive calls
        // int choice1=INT_MAX;
        // if(cc-1>=0){
        //     choice1=helper_Rec(cr+1,cc-1,matrix);
        // }
        // int choice2=helper_Rec(cr+1,cc,matrix);
        // int choice3=INT_MAX;

        // if(cc+1<matrix[0].size()){
        //     choice3=helper_Rec(cr+1,cc+1,matrix);
        // }

        int choice1=helper_Rec(cr+1,cc-1,matrix);
        int choice2=helper_Rec(cr+1,cc,matrix);
        int choice3=helper_Rec(cr+1,cc+1,matrix);

        // khudko path me consider kro and add it
        return min(choice1,min(choice2,choice3))+matrix[cr][cc];
    }

    int helper_BU(vector<vector<int>>& matrix){
        // dp array
        vector<vector<int>> dp(matrix.size(), vector <int> (matrix[0].size(),INT_MAX));

        // base case fill
        for(int c=0; c<matrix[0].size(); c++){
            dp[matrix.size()-1][c]=matrix[matrix.size()-1][c];
        }

        // cell meaning 
        // storing the minimum sum path from three choices
        
        // iterative approach
        for(int cr=matrix.size()-2; cr>=0; cr--){
            for(int cc=0; cc<matrix[0].size(); cc++){
                int choice1=INT_MAX;
                if(cc-1>=0){
                    choice1=dp[cr+1][cc-1];
                }

                int choice2=dp[cr+1][cc];

                int choice3=INT_MAX;

                if(cc+1<matrix[0].size()){
                    choice3=dp[cr+1][cc+1];
                }

                int mini=min(choice1,choice2);
                // khudki value add nahi ki
                dp[cr][cc]=min(choice3,mini)+matrix[cr][cc];
            }
        }

        // ans is in first row
        int mini=INT_MAX;
        for(int i=0; i<matrix[0].size(); i++){
            mini=min(dp[0][i],mini);
        }

        return mini;
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // return helper_BU(matrix);
        return helper_Rec(0,0,matrix);
    }
};