//Approach 1:- Recursive

int minD_Rec(string word1,int idx1,string word2, int idx2){
        // base case
        if(idx1==word1.length() || idx2==word2.length()){
            return max(word1.length()-idx1,word2.length()-idx2);
        }

        int ans=0;

        if(word1[idx1]==word2[idx2]){
            ans= minD_Rec(word1,idx1+1,word2,idx2+1);
        }
        else{
            // self work +recursive calls
            int insert=minD_Rec(word1,idx1+1,word2,idx2);
            int dlt=minD_Rec(word1,idx1,word2,idx2+1);
            int replace=minD_Rec(word1,idx1+1,word2,idx2+1);

            ans=min(min(insert,dlt),replace)+1;
            //self work done
        }
        
        return ans;
    }

    int minDistance(string word1, string word2) {
        int idx1=0;
        int idx2=0;

        return minD_Rec(word1,idx1,word2,idx2);
    }

// Approach 2:- Topdown approach

int minD_TD(string word1,int idx1,string word2, int idx2,vector<vector<int>> &dp){
        // base case
        if(idx1==word1.length() || idx2==word2.length()){
            return max(word1.length()-idx1,word2.length()-idx2);
        }

        // 3. answer exists?
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }

        int ans=0;

        if(word1[idx1]==word2[idx2]){
            ans= minD_Rec(word1,idx1+1,word2,idx2+1);
            dp[idx1][idx2]=ans;
        }
        else{
            // self work +recursive calls
            int insert=minD_Rec(word1,idx1+1,word2,idx2);
            int dlt=minD_Rec(word1,idx1,word2,idx2+1);
            int replace=minD_Rec(word1,idx1+1,word2,idx2+1);

            ans=min(min(insert,dlt),replace)+1;
            // 2.ans store
            dp[idx1][idx2]=ans;
            //self work done
        }
        
        return ans;
    }

    int minDistance(string word1, string word2) {
        int idx1=0;
        int idx2=0;

        // 1.Create 2d dp array with -1
        vector<vector<int>> dp(word1.length()+1,vector <int> (word2.length()+1,-1));

        // 2.pass dp array
        return minD_TD(word1,idx1,word2,idx2,dp);
    }

// Approach 3:- Bottom Up

int minD_BU(string word1,int idx1,string word2,int idx2){
        // 1.Create 2d dp array
        vector<vector<int>> dp(word1.length()+1, vector <int> (word2.length()+1,-1));

        // 2.Base case fill
        //row fill
        for(int col=0; col<=word2.length(); col++){
            dp[word1.length()][col]=word2.length()-col;
        }

        for(int row=0; row<word1.length(); row++){
            dp[row][word2.length()]=word1.length()-row;
        }

        // 3.  iterative 

        for(int i=word1.length()-1; i>=0; i--){
            for(int j=word2.length()-1; j>=0; j--){

                int ans=0;

                if(word1[i]==word2[j]){
                    dp[i][j]= dp[i+1][j+1];
                }
                else{
                    // self work +recursive calls
                    int insert=dp[i+1][j];
                    int dlt=dp[i][j+1];
                    int replace=dp[i+1][j+1];

                    ans=min(min(insert,dlt),replace)+1;
                    // 2.ans store
                    dp[i][j]=ans;
                    //self work done
                }
            }
        }

        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        return minD_BU(word1,0,word2,0);
    }