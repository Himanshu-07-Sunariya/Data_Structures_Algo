// Approach 1:- saari recursion ki mehnt is done in the copy refer it

 int countWays(int n, int k) {
        // base case
        if(n==1) return k;
        
        if(n==2) return k*k;
        
        
        // formula derived from table method for adjacency wali cheez
        // ans=same color+ different colored
        return (countWays(n-1,k)+countWays(n-2,k))*(k-1);
    }

// Approach 2: 1d dp top down approach

    int solveUsingMem(int n,int k,vector <int>&dp){
        // base case
        if(n==1) return k;
        
        if(n==2) return k*k;
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        
        // formula derived from table method for adjacency wali cheez
        // ans=same color+ different colored
        int ans= (countWays(n-1,k)+countWays(n-2,k))*(k-1);
        dp[n]=ans;
        return dp[n];
    }
    
    int countWays(int n, int k) {
        vector <int> dp(n+1,-1);
        
        return solveUsingMem(n,k,dp);
    }


// Approach 3:Bottom up approach

// O(n) space jarha h so...space optimization

int solveUsingTabulation(int n,int k){
        // 1.Create 1d dp array
        vector <int> dp(n+1,-1);
        
        // 2.base case analyze
        dp[1]=k;
        dp[2]=k*k;
        
        // 3. reverse the logic
        for(int N=3;N<=n; N++){
            dp[N]= (dp[N-1]+dp[N-2])*(k-1);
        }
        
        // 4.return whatever u passed
        return dp[n];
    }
    
    int countWays(int n, int k) {
        // vector <int> dp(n+1,-1);
        
        return solveUsingTabulation(n,k);
    }


// Approach 4:- Space Optimization Using Tabulation


    int solveUsingTabulationSO(int n,int k){
        // 1.Create 1d dp array
        // vector <int> dp(n+1,-1);
        
        // alag se edge case handle
        if(n==1) return k;
        if(n==2) return k*k;
        
        // 2.base case analyze
        int prev2=k;
        int prev1=k*k;
        
        int curr=0;
        
        // 3. reverse the logic
        for(int N=3;N<=n; N++){
            curr= (prev1+prev2)*(k-1);
            
            // shifting
            
            prev2=prev1;
            prev1=curr;
        }
        
        // 4.return whatever u passed
        return curr;
    }
    
    int countWays(int n, int k) {
        // vector <int> dp(n+1,-1);
        
        return solveUsingTabulationSO(n,k);
    }


