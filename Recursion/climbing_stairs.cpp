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


// Approach 2:- Top down approach(recursion+ memoization)
