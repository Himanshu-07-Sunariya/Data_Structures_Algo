// Approach 1:- Recursion

int ans=0;
    
    int solveUsingRecursion(int capacity,vector <int>&val,vector <int> &wt,int index){
        // base case
        if(index>=wt.size()){
            return 0;
        }
        
        // include-exclude principle
        int includeAns=0;
        if(wt[index]<=capacity){
            includeAns=val[index]+ solveUsingRecursion(capacity-wt[index],val,wt,index+1);
        }
        
        int excludeAns=0 + solveUsingRecursion(capacity,val,wt,index+1);
        
        ans=max(includeAns,excludeAns);
        
        return ans;
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       int index=0;
       
       return solveUsingRecursion(W,val,wt,index);
    }

// Approach 2 :- Rec+Mem

 
    int solveUsingMem(int capacity,vector <int>&val,vector <int> &wt,int index,vector<vector<int>> &dp){
        // base case
        if(index>=wt.size()){
            return 0;
        }
        
        if(dp[capacity][index]!=-1){
            return dp[capacity][index];
        }
        
        // include-exclude principle
        int includeAns=0;
        if(wt[index]<=capacity){
            includeAns=val[index]+solveUsingMem(capacity-wt[index],val,wt,index+1,dp);
        }
        
        int excludeAns=0 + solveUsingMem(capacity,val,wt,index+1,dp);
        
        
        dp[capacity][index]=max(includeAns,excludeAns);
        
        return dp[capacity][index]; 
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       int index=0;
       
       vector<vector<int>> dp(W+1,vector<int>(wt.size()+1,-1));
       
       return solveUsingMem(W,val,wt,index,dp);
    }

// Approach3:- Bottom up approach(tabulation method)

//int solveUsingTabulation(int capacity,vector <int>&val,vector <int>&wt, int index){
        // 1.Create dp array
        // 2. base case for this we will be analyzing the whole 2d array with zero 
        // bcoz the base case says that the column dp[any capacity][but col n]=zero
        
        int n=wt.size();
        vector<vector<int>> dp(capacity+1,vector <int> (n+1,0));
        
        // 3. reverse flow logic 
        for(int c=0; c<=capacity; c++){
            for(int i=n-1; i>=0; i--){
                int includeAns=0;
                if(wt[i]<=c){
                    includeAns=val[i]+dp[c-wt[i]][i+1];
                }
                
                int excludeAns=0 + dp[c][i+1];
                
                
                dp[c][i]=max(includeAns,excludeAns);
            }
        }
        
        // 4. return the ans
        
        return dp[capacity][index];
        
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       int index=0;
       
       vector<vector<int>> dp(W+1,vector<int>(wt.size()+1,-1));
       
       return solveUsingTabulation(W,val,wt,index);
    }


// Approach4:- Tabulation method Space Optimized

int solveUsingTabulationSO(int capacity,vector <int>&val,vector <int>&wt, int index){
        
        int n=wt.size();
        // vector<vector<int>> dp(capacity+1,vector <int> (n+1,0));
        
        
        //converting it to 2 1d array dp
        vector <int> curr(capacity+1,0);
        vector <int> next(capacity+1,0);
        
        // 3. reverse flow logic 
        
        // loop interchange also required here
        for(int i=n-1; i>=0; i--){
            for(int c=0; c<=capacity; c++){
                int includeAns=0;
                if(wt[i]<=c){
                    includeAns=val[i]+next[c-wt[i]];
                }
                
                int excludeAns=0 + next[c];
                
                
                curr[c]=max(includeAns,excludeAns);
            }
            
            // shifting
            next=curr;
        }
        
        // 4. return the ans
        
        return curr[capacity];
        
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       int index=0;
       
       vector<vector<int>> dp(W+1,vector<int>(wt.size()+1,-1));
       
       return solveUsingTabulationSO(W,val,wt,index);
    }