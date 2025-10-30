//Approach 1:- Recursive code

int climb_Rec(int cs,int n){
        // +ve base case
        if(cs==n){
            return 1;
        }

        // -ve base case
        if(cs>n){
            return 0;
        }

        //self work + recursive calls
        int jump1=climb_Rec(cs+1,n);
        int jump2=climb_Rec(cs+2,n);

        //ans return 
        return jump1+jump2;
    }
    int climbStairs(int n) {
        int cs=0;
        return climb_Rec(cs,n);
    }


// Approach 2:- Top down Approach

int climbStairs_TD(int cs,int n,vector <int> &dp){
        // +ve base case
        if(cs==n){
            return 1;
        }

        // -ve base case
        if(cs>n){
            return 0;
        }

        //3. already exists case
        if(dp[cs]!=-1){
            return dp[cs];
        }

        //self work + recursive calls
        int jump1=climbStairs_TD(cs+1,n,dp);
        int jump2=climbStairs_TD(cs+2,n,dp);

        //ans return
        dp[cs]=jump1+jump2;
        return dp[cs];
    }

    int climbStairs(int n) {
        int cs=0;
        // 1. create 1d dp array
        vector <int> dp(n+1,-1);

        // 2. Pass dp array
        return climbStairs_TD(cs,n,dp);
    }


// Approach 3:- Bottom Up Approach

int climbStairs_BU(int cs,int n){
        //1. create 1d array
        vector <int> dp(n+1,-1);

        //2. base case fill
        dp[n]=1;
        dp[n-1]=1;

        // 3. iterative
        for(int i=n-2; i>=0; i--){
            //self work + recursive calls
            int jump1=dp[i+1];
            int jump2=dp[i+2];

            //ans return
            dp[i]=jump1+jump2;
        }

        return dp[0];
    }
        

    int climbStairs(int n) {
        return climbStairs_BU(0,n);
    }


// Approach 4:- Bottom up space efficient

int climbStairs_BUSE(int cs,int n){
        //edge case
        if(n==1) return 1;
        //1. creating boxes & fill base cases 
        int curr=-1;
        int next1=1;
        int next2=1;

        // 2. iterative
        for(int i=n-2; i>=0; i--){
            //3. self work + recursive calls
            int jump1=next1;
            int jump2=next2;

            //ans return
            curr=jump1+jump2;

            // 4. shifting
            next2=next1;
            next1=curr;    
        }

        return curr;
    }

    int climbStairs(int n) {
        return climbStairs_BUSE(0,n);
    }