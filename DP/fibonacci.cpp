// Approach 1:- ( RECURSION )

int fib(int n) {
        // base case
        if(n==0){
            return 0;
        }

        if(n==1){
            return 1;
        }

        // self work( recursive relation )
        int ans=fib(n-1)+fib(n-2);

        // final ans
        return ans;
    }


// yehhhhh DP
// Approach 2: Recursion + Memoization ( TOP-DOWN APPROACH )

int solveUsingMemo(int n,vector <int> dp){
        // base case
        if(n==0){
            return 0;
        }

        if(n==1){
            return 1;
        }

        // 3. check if ans is already exists
        if(dp[n]!=-1){
            return dp[n];
        }

        // self work( recursive relation )
        int ans=fib(n-1)+fib(n-2);
        // 2. storing the ans in dp array
        dp[n]=ans;

        // final ans
        return dp[n];
    }
    int fib(int n) {
        // 1. Create dp array and intialize it with -1 and pass it in helper function
        vector <int> dp(n+100,-1);

        int ans=solveUsingMemo(n,dp);
        return ans;
    }



// Approach 3:Bottom up approach(iterative /tabular approach)

 int solveUsingTabular(int n){
        // 1. Creating the dp array and acc to detected size
        vector <int> dp(n+1,-1);

        // star case :- if n==0 or n==1 dp[1] will cause runtime
        if(n==0) return 0;
        if(n==1) return 1;

        // 2. base case analyze and fill them in dp array(taaki aage wale aaske)
        dp[0]=0;
        dp[1]=1;

        // 3.iterative logic (doesnt include jo hochuka )
        for(int i=2; i<=n; i++){
            // logic -copy paste

            // recursion ko swap with the dp array jo sab yaad rkhta h
            int ans=dp[i-1]+dp[i-2];
            dp[i]=ans;
        }

        // 4. return dp[i] coz jo variable main function se pass kraya h wahi return kro
        return dp[n];

    }
    int fib(int n) {
        int final_ans=solveUsingTabular(n);

        return final_ans;
    }




// Approach 4:- Optimal k baap( hume dp array me bhi jitna use hoga utna chhant lia )

    int solveOptimal(int n){
        // 1. Creating the dp array and acc to detected size
        // vector <int> dp(n+1,-1);

        // star case :- if n==0 or n==1 dp[1] will cause runtime
        if(n==0) return 0;
        if(n==1) return 1;

        // 2. base case analyze and fill them in dp array(taaki aage wale aaske)
        // dp[0]=0;
        // dp[1]=1;
        int prev2=0;
        int prev1=1;
        int curr=-1;

        // 3.iterative logic (doesnt include jo hochuka )
        for(int i=2; i<=n; i++){
            // logic -copy paste

            // recursion ko swap with the dp array jo sab yaad rkhta h
            // int ans=dp[i-1]+dp[i-2];
            // dp[i]=ans;
            curr=prev1+prev2;

            // new step shifting wala
            prev2=prev1;
            prev1=curr;
        }

        // 4. return dp[i] coz jo variable main function se pass kraya h wahi return kro
        // return dp[n];

        // changed
        return curr;
    }


    int fib(int n) {
        return solveOptimal(n);
    }
