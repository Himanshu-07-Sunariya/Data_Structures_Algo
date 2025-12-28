// Recursive approach

class Solution {
public:
    int climbStairs(int n) {
        //+ve base case
        if(n==0) return 1;
        // -ve base case
        if(n<0) return 0;

        // recursive calls
        int jump1=climbStairs(n-1);
        int jump2=climbStairs(n-2);

        return jump1+jump2;
    }
};


// Top down approach
int climbStairs_TD(int n,vector <int> &dp){
        //+ve base case
        if(n==0) return 1;

        // -ve base case
        if(n<0) return 0;

        //dp step 2
        if(dp[n]!=-1) return dp[n];

        // recursive calls
        int jump1=climbStairs_TD(n-1,dp);
        int jump2=climbStairs_TD(n-2,dp);

        dp[n]=jump1+jump2;
        return dp[n];
    }

    int climbStairs(int n) {
        // //+ve base case
        // if(n==0) return 1;
        // // -ve base case
        // if(n<0) return 0;

        // // recursive calls
        // int jump1=climbStairs(n-1);
        // int jump2=climbStairs(n-2);

        // return jump1+jump2;

        //1. Create dp array
        // vector<int> dp(n+1,-1);

        // return climbStairs_TD(n,dp);

        // Bottom Up approach
        if(n==0||n==1) return 1;
        // 1. Create dp array
        vector <int> dp(n+1,-1);

        // 2.base case fill
        // if(n<0) return 0;
        dp[0]=1;
        dp[1]=1;
        // negative index access k khel me base case hi new bnalo ans khud se nikaalke

        // 3. iterative approach
        for(int i=2; i<=n; i++){

            // recursive calls
            int jump1=dp[i-1];
            int jump2=dp[i-2];

            dp[i]=jump1+jump2;
        }

        return dp[n];
    }