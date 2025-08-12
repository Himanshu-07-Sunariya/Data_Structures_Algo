// approach 1

// kud kud ke seeedhi chadhenge steps can be 1,2,3 
#include <bits/stdc++.h>
using namespace std;

void climbing_stairs(int n,int cs,string way){
    // +ve base case
    if(cs==n){
        // yehhh hum shi seedhi pr phunch gye ab apne raste ke baare me btao yaani print the way..
        cout<<way<<endl;
        return;
    }
    // -ve base case
    if(cs>n){
        // zyda seedhi chdh gye bc
        return;
    }

    climbing_stairs(n,cs+1,way+"1");
    climbing_stairs(n,cs+2,way+"2");
    climbing_stairs(n,cs+3,way+"3");
}

int main(){
    int n=5;
    climbing_stairs(n,0,"");
    return 0;
}




// for leetcode
// https://leetcode.com/problems/climbing-stairs/submissions/1731952673/?utm_source=chatgpt.com

// Approach 1 :- brute force (recursion only)

void climbing_stairs(int n,int cs,int &count){
        // +ve base case
        if(cs==n){
            // yehhh hum shi seedhi pr phunch gye ab apne raste ke baare me btao yaani print the way..
            count++;
            return;
        }
        // -ve base case
        if(cs>n){
            // zyda seedhi chdh gye bc
            return;
        }

        climbing_stairs(n,cs+1,count);
        climbing_stairs(n,cs+2,count);
        // climbing_stairs(n,cs+3,count);
    }
    int climbStairs(int n) {
        int count=0;
        climbing_stairs(n,0,count);

        return count;
    }


// Approach 2:TopDown Approach(Recursion + Memoization)

    int cnt_way=0;

    void jump_stairs(int cs,int n,vector <int> &dp){
        // +ve base case
        if(cs==n){
            cnt_way++;
            dp[cs]=cnt_way;
            return;
        }
        // -ve base case
        if(cs>n){
            return;
        }

        if(dp[cs]!=-1){
            cnt_way+=dp[cs];
        }

        // recursive calls to each to jump
        jump_stairs(cs+1,n,dp);
        jump_stairs(cs+2,n,dp);
    }
    int climbStairs(int n) {
        // step1 for the dp
        // 1.Create,intialize and pass the 1d dp array
        vector <int> dp(n+1,-1);

        jump_stairs(0,n,dp);
        

        return cnt_way;
    }


// Approach 3:- Bottom Down Approach(iterative/tabular approach)

int solveUsingTabular(int n){
        // 1. Creating the dp array,intialize
        vector <int> dp(n+1,-1);

        // 2. analyze base case
        dp[n]=1;
        dp[n-1]=1;

        // 3. for loop logic
        for(int i=n-2; i>=0; i--){
            dp[i]=dp[i+1]+dp[i+2];
        }

        return dp[0];
    }


    int climbStairs(int n) {
        
        return solveUsingTabular(n);
    }


// Approach 4:- most optimal O(n) O(1)

int solveUsingPattern(int n){
        // 1. and 2. step will be in one frame

        // one common mistake when prev1 ho hi na
        if(n==1) return 1;

        int prev2=1;
        int prev1=1;

        int curr=-1;

        // 3. for loop copy paste logic
        for(int i=n-2; i>=0; i--){
            curr=prev1+prev2;

            // 4. shifting to krde veere
            prev2=prev1;
            prev1=curr;
        }

        return curr;
    }
    int climbStairs(int n) {
        
        return solveUsingPattern(n);
    }


    // fibonacci jaisa tha