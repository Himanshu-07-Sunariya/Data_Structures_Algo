https://leetcode.com/problems/house-robber/

// Approach 1:- recursive approach(include -exclude)

int robbery(vector<int> &nums,int index){
        // base case(koi ghar hi nahi bacha chori karne ko)
        if(index>=nums.size()){
            return 0;
        }

        // ek ghar ke aage khade h ab socho chori kru ya na kru
        int include=nums[index]+robbery(nums,index+2);
        int exclude=0+robbery(nums,index+1);

        int maxchori=max(include,exclude);

        return maxchori;
    }

    int rob(vector<int>& nums) {
        int index=0;

        int ans=robbery(nums,index);
        return ans;
    }

// Approach 2:-Topdown(rec+memoization)

int solveUsingMemo(vector<int>& nums,int index,vector <int>& dp){
        // base case(koi ghar hi nahi bacha chori karne ko)
        if(index>=nums.size()){
            return 0;
        }

        // step3 of dp
        if(dp[index]!=-1){
            return dp[index];
        }

        // ek ghar ke aage khade h ab socho chori kru ya na kru
        int include=nums[index]+solveUsingMemo(nums,index+2,dp);
        int exclude=0+solveUsingMemo(nums,index+1,dp);

        int maxchori=max(include,exclude);
        // step 2 of dp
        dp[index]=maxchori;

        return dp[index];
    }



// Approach 3:- Bottom Up(Tabular method)


    int solveUsingTabular(vector<int>& nums,int index,int n){
        // step1:-dp array initialize
        vector <int> dp(nums.size()+1,-1);

        // step2:- base case analyze
        dp[n]=0;

        // step3:- reverse flow logic
        for(int i=n-1; i>=0; i--){
            int temp=0;
            if(i+2<=n){
                temp=dp[i+2];
            }
            int include=nums[i]+temp;
            int exclude=0+dp[i+1];

            dp[i]=max(include,exclude);
        }

        // step4:-return statement
        return dp[0];
    }

    int rob(vector<int>& nums) {
        // vector <int> dp(nums.size()+1,-1);
        int index=0;

        // int ans=solveUsingMemo(nums,index,dp);

        int n=nums.size();

        int ans=solveUsingTabular(nums,index,n);
        return ans;
    }

// Approach 4:- Reducing space complexity( O(1) )

int solveUsingOptimal(vector <int> &nums,int index,int n){
        // step1&2:-dp array swap it with the two dependent box & do it acc to base case

        // next1 humara dp[n] hai aur dp[n+1] is next2 haai jo out of the box h pr depend in do box pr hi hai

        // like dono ka max hi ans hoga acc to recursion logic

        int next1=0;
        int next2=0;

        int curr=-1;

        // step3:- reverse flow logic
        for(int i=n-1; i>=0; i--){
            int temp=0;
            if(i+2<=n){
                temp=next2;
            }
            int include=nums[i]+temp;
            int exclude=0+next1;

            curr=max(include,exclude);

            // step4:- shifting to krade
            next2=next1;
            next1=curr;
        }

        // step4:-return statement
        return curr;
    }

    int rob(vector<int>& nums) {
        // vector <int> dp(nums.size()+1,-1);
        int index=0;

        // int ans=solveUsingMemo(nums,index,dp);

        int n=nums.size();

        // int ans=solveUsingTabular(nums,index,n);

        int ans=solveUsingOptimal(nums,index,n);
        return ans;
    }



// REVISION

int helper(int ind,vector <int> &nums){
        // base case
        if(ind>=nums.size()) return 0;

        // pick/not pick
        // glt index access n ho isliye ...if condition so use it in BU approach
        int include=nums[ind]+helper(ind+2,nums);

        int exclude=helper(ind+1,nums);

        return max(include,exclude);
    }

    int helper_TD(int ind,vector <int> &nums,vector <int> &dp){
        // base case
        if(ind>=nums.size()) return 0;

        // dp step2
        if(dp[ind]!=-1) return dp[ind];

        // pick/not pick
        // glt index access n ho isliye ...if condition so use it in BU approach
        int include=nums[ind]+helper_TD(ind+2,nums,dp);

        int exclude=helper_TD(ind+1,nums,dp);

        dp[ind]=max(include,exclude);
        return dp[ind];
    }

    int helper_BU(vector <int> &nums){
        // 1.Create dp array
        vector <int> dp(nums.size()+1,-1);

        // 2. base case fill
        dp[nums.size()]=0;

        // 3. Cell meaning
        // consider array from ith index to n (considering only those houses) and stores max profit that can be decided if we want to include or exclude that house to do chori...

        // 4.iterative work
        for(int i=nums.size()-1; i>=0; i--){
            // pick/not pick
            // glt index access n ho isliye ...if condition so use it in BU approach
            int include=nums[i];
            // nice step

            if(i+2<nums.size()){
                include=nums[i]+dp[i+2];
            }

            int exclude=dp[i+1];

            dp[i]=max(include,exclude);
        }

        return dp[0];
    }

    int helper_BUSO(vector <int> &nums){
        // 1.Create dp array
        // vector <int> dp(nums.size()+1,-1);

        int next1=0;
        int next2=0;
        int curr;

        // 2. base case fill
        // dp[nums.size()]=0;

        // 3. Cell meaning
        // consider array from ith index to n (considering only those houses) and stores max profit that can be decided if we want to include or exclude that house to do chori...

        // 4.iterative work
        for(int i=nums.size()-1; i>=0; i--){
            // pick/not pick
            // glt index access n ho isliye ...if condition so use it in BU approach
            int include=nums[i];
            // nice step

            if(i+2<nums.size()){
                include=nums[i]+next2;
            }

            int exclude=next1;

            curr=max(include,exclude);

            // shifting dhng se kr no extra change wali bc
            next2=next1;
            next1=curr;
        }

        return curr;
    }

    int rob(vector<int>& nums) {
        // int ind=0;
        // return helper(ind,nums);
        // vector <int> dp(nums.size()+1,-1);
        // return helper_TD(ind,nums,dp);

        // there is no use of index variable here in Bottom Up

        return helper_BUSO(nums);
    }