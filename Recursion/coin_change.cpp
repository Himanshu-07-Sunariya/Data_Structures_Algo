// Approach 1: Recursion

  int mincoin=INT_MAX;
    
    void coin_counter(vector <int> &coins, int amount, int count){
        // +ve base case
        if(amount==0){
            mincoin=min(mincoin,count);
            return;
        }
        // -ve base case
        if(amount<0){
            return;
        }

        // self work

        for(int i=0; i<coins.size(); i++){
            // mistake
            coin_counter(coins,amount-coins[i],count+1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        // map<string,vector<string>> mp;

        int count=0;
        
        coin_counter(coins,amount,count);
        
        if(mincoin==INT_MAX) return -1;
        return mincoin;
    }

// Approach 2:- Recursion(method 2)