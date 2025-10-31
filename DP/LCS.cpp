// Approach 1:- Recursive

int LCS_Rec(string text1,int idx1,string text2,int idx2){
        // -ve base case
        if(idx1>=text1.length() || idx2>=text2.length()){
            return 0;
        }

        // +ve base case
        if(text1[idx1]==text2[idx2]){
            return LCS_Rec(text1,idx1+1,text2,idx2+1)+1;
        }

        // self work + recursive calls
        int leftpart=LCS_Rec(text1,idx1,text2,idx2+1);
        int rightpart=LCS_Rec(text1,idx1+1,text2,idx2);

        return max(leftpart,rightpart);
    }

// Approach 2:-  Topdown approach

int LCS_TD(string text1,int idx1,string text2,int idx2, vector<vector<int>> &dp){
        // -ve base case
        if(idx1>=text1.length() || idx2>=text2.length()){
            return 0;
        }
        
        // +ve base case
        if(text1[idx1]==text2[idx2]){
            return LCS_TD(text1,idx1+1,text2,idx2+1,dp)+1;
        }

        // 3. ans exits already
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }

        // self work + recursive calls
        int leftpart=LCS_TD(text1,idx1,text2,idx2+1,dp);
        int rightpart=LCS_TD(text1,idx1+1,text2,idx2,dp);


        // 2. ans store
        dp[0][0]=max(leftpart,rightpart);

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // 1. create dp array
        vector<vector<int>> dp(text1.length()+1,vector <int> (text2.length()+1,-1));

        // 2. pass dp array
        return LCS_TD(text1,0,text2,0,dp);
    }


// Approach 3:- Bottom Up Approach

int LCS_BU(string text1, int idx1, string text2, int idx2){
        // 1. create dp array && 2. base case fill
        vector<vector<int>> dp(text1.length()+1, vector <int> (text2.length()+1,0));

        // 3. iterative code
        for(int row=text1.length()-1; row>=0; row--){
            for(int col=text2.length()-1; col>=0; col--){
                int matchcase=INT_MIN;
                if(text1[row]==text2[col]){
                    // dp[row][col]=dp[row+1][col+1]+1;
                    matchcase=dp[row+1][col+1]+1;
                }

                // self work + recursive calls
                int leftpart=dp[row][col+1];
                int rightpart=dp[row+1][col];


                // 2. ans store
                int ans=max(matchcase,leftpart);
                dp[row][col]=max(ans,rightpart);
            }
        }

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return LCS_BU(text1,0,text2,0);
    }


// bottom up 
int LCS_BU(string text1, int idx1, string text2, int idx2){
        // 1. create dp array && 2. base case fill
        vector<vector<int>> dp(text1.length()+1, vector <int> (text2.length()+1,0));

        // 3. iterative code
        for(int row=text1.length()-1; row>=0; row--){
            for(int col=text2.length()-1; col>=0; col--){
                int matchcase=INT_MIN;
                if(text1[row]==text2[col]){
                    // dp[row][col]=dp[row+1][col+1]+1;
                    dp[row][col]=dp[row+1][col+1]+1;
                }
                else{
                    // self work + recursive calls
                    int leftpart=dp[row][col+1];
                    int rightpart=dp[row+1][col];


                    // 2. ans store
                    dp[row][col]=max(leftpart,rightpart);
                }
            }
        }

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return LCS_BU(text1,0,text2,0);
    }

