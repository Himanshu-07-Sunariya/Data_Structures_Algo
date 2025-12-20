#include <bits/stdc++.h>
using namespace std;

int rodCut_Rec(int n,vector <int> &prices){
    // base cases
    if(n==0) return prices[0];
    if(n==1) return prices[1];

    int ans=INT_MIN;
    //cutting of rod
    for(int i=1; i<=n/2; i++){
        int t=rodCut_Rec(i,prices)+rodCut_Rec(n-i,prices);

        ans=max(ans,t);
    }

    return max(prices[n],ans);
}

int rodCut_TD(int n,vector <int> &prices,vector <int> &dp){
    // base cases
    if(n==0) return prices[0];
    if(n==1) return prices[1];

    // dp step2
    if(dp[n]!=-1) return dp[n];

    int ans=INT_MIN;

    // rod cutting and max profit achieve step
    for(int i=1; i<=n/2; i++){
        int t=rodCut_TD(i,prices,dp)+rodCut_TD(n-i,prices,dp);

        ans=max(ans,t);
    }

    dp[n]=max(ans,prices[n]);

    return dp[n];
}

int rodCut_BU(int n,vector <int> &prices){
    // 1. create dp array
    vector <int> dp(n+1,-1);

    // 2. base case fill
    dp[0]=prices[0];
    dp[1]=prices[1];

    // 3. iterative case filling
    // cell meaning:-if we cut the rod of ith index length then wht is the max profit for it
    for(int j=2; j<=n; j++){
        int ans=INT_MIN;

        // rod cutting and max profit achieve step
        for(int i=1; i<=j/2; i++){
            int t=rodCut_TD(i,prices,dp)+rodCut_TD(j-i,prices,dp);

            ans=max(ans,t);
        }

        dp[j]=max(ans,prices[j]);
    }

    return dp[n];
}

int main(){
    vector <int> prices={0,1,5,8,9,10,17,17,20};
    int n=8;
    // cout<<rodCut_Rec(n,prices);

    // vector <int> dp(n+1,-1);

    // cout<<rodCut_TD(n,prices,dp)<<endl; 

    cout<<rodCut_BU(n,prices);
    
    return 0;
}