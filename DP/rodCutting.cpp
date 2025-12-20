// recursive method

int cutRodRec(vector <int> &price, int n){
        // 0 waala case as base case bcoz not given
        if(n==0) return 0;
        
        int left=1;
        int right=n-1;
        
        int ans=0;
        
        while(left<=right){
            int lp=cutRodRec(price,left);
            int rp=cutRodRec(price,right);
            
            ans=max(ans,lp+rp);
            
            left++;
            right--;
        }
        
        return max(ans,price[n-1]);
    }
    
    int cutRod(vector<int> &price) {
        return cutRodRec(price,price.size());
    }

// Top down Approach

int cutRodTD(vector <int> &price, int n,vector <int> &dp){
        // 0 waala case as base case bcoz not given
        if(n==0) return 0;
        
        // 2. existing k use
        if(dp[n]!=-1) return dp[n];
        
        int left=1;
        int right=n-1;
        
        int ans=0;
        
        while(left<=right){
            int lp=cutRodTD(price,left,dp);
            int rp=cutRodTD(price,right,dp);
            
            ans=max(ans,lp+rp);
            
            // 3.dp ans store
            dp[n]=ans;
            
            left++;
            right--;
        }
        
        dp[n]=max(ans,price[n-1]);
        return dp[n];
    }
    
    int cutRod(vector<int> &price) {
        // return cutRodRec(price,price.size());
        //1. Create dp array
        vector<int> dp(price.size()+1,-1);
        
        return cutRodTD(price,price.size(),dp);
    }



#include <bits/stdc++.h>
using namespace std;

int rodcutting(int prices[],int n){
    int ans=0;

    for(int i=1; i<=n/2; i++){
        int leftcut=rodcutting(prices,i);
        int rightcut=rodcutting(prices,n-i);

        
    }
}

int main(){
    int prices[9]={0,1,5,8,9,10,17,17,20};
    cout<<rodcutting(prices,8);
}