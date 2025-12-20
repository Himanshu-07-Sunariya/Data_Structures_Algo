// Recursive approach
#include <iostream>
using namespace std;

int catalannumber(int n){
    if(n<=1) return 1;

    int ans=0;
    // ith node se
    for(int i=1; i<=n; i++){
        int xbsts=catalannumber(i-1);
        int ybsts=catalannumber(n-i);

        ans+=xbsts*ybsts;
    }

    return ans;
}


int catalan_TD(int n,vector <int> &dp){
    if(n<=1) return 1;

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans=0;
    // ith node se
    for(int i=1; i<=n; i++){
        int xbsts=catalan_TD(i-1,dp);
        int ybsts=catalan_TD(n-i,dp);

        ans+=xbsts*ybsts;
        dp[n]=ans;
        
    }

    dp[n]=ans;
    return ans;
}

int catalan_BU(int n){
    vector <int> dp(n+1,-1);

    dp[0]=1;
    dp[1]=1;

    for(int j=2; j<=n; j++){
        int ans=0;
        // ith node se
        for(int i=1; i<=n; i++){
            int xbsts=dp[i-1];
            int ybsts=dp[j-i];

            ans+=xbsts*ybsts;
            dp[j]=ans;
        }
    }

    return dp[n];
}

int main(){
    int n=3;
    // cout<<catalannumber(n);

    // vector <int> dp(n+1,-1);
    // cout<<catalan_TD(n,dp);

    cout<<catalan_BU(n);
    return 0;
}